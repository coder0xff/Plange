#include <algorithm>
#include <iterator>

#include "parlex/behavior.hpp"

#include "graphviz_dot.hpp"

namespace parlex {
namespace behavior {

std::string nfa2_to_dot(nfa2 const & nfa) {
	return nfa.to_dot([](int x) { return std::to_string(x); }, [](leaf const * x) { return x->id; });
}

void node::add_child(erased<node> child) {
	children.push_back(child);
	children.back()->parent = this;
}

node::children_t const& node::get_children() const {
	return children;
}

node::node(node const & other) : tag(other.tag), children(other.children) {
	for (auto & child : children) {
		child->parent = this;
	}
}

static std::string node_to_name(node const * n) {
	///////////////////////////////////////////////////////////////////////////////////////////
#define DO_AS(name)                                                                       \
	name const * as_##name = dynamic_cast<name const *>(n);      \
	if (as_##name != nullptr)                                                               \
/////////////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////
#define DO_AS2(name)                    \
	DO_AS(name) {                        \
		result << #name << " ";           \
		if (as_##name->tag != "") {        \
			result << as_##name->tag;       \
		} else {                             \
			result << as_##name;              \
		}                                      \
	}                                           \
/////////////////////////////////////////////////

	std::stringstream result;
	DO_AS(leaf) {
		result << as_leaf->id;
	}
	DO_AS2(choice)
		DO_AS2(optional)
		DO_AS2(repetition)
		DO_AS2(sequence)
#undef DO_AS2
#undef DO_AS

	result << " " << n;
	return result.str();

}


std::string node::to_dot() const {
	return directed_graph<node const *>(
		this, node_to_name,
		[&](node const * n)
		{
			sequence const * as_sequence = dynamic_cast<sequence const *>(n);
			std::vector<std::pair<std::string, node const *>> edges;
			for (size_t childIndex = 0; childIndex < n->children.size(); ++childIndex) {
				auto const & erasedChild = n->children[childIndex];
				std::string edgeName = as_sequence != nullptr ? "label=" + std::to_string(childIndex) : "";
				edges.push_back(make_pair(edgeName, &*erasedChild));
			}
			return edges;
		}
	);
}

nfa2 node::compile() const {
	auto temp = to_nfa();
	std::string check = nfa2_to_dot(temp); //todo: disable debug code
	return temp.minimal_dfa().map_to_ints();
}

leaf::leaf(recognizer const & r) : r(r), id(r.id) {
}

nfa2 leaf::to_nfa() const {
	nfa2 result;
	result.states.emplace_back(0);
	result.states.emplace_back(1);
	result.startStates.insert(0);
	result.acceptStates.insert(1);
	result.states[0].out_transitions[this].insert(1);
	return result;
}

nfa2 choice::to_nfa() const {
	std::vector<nfa2> parts;
	for (erased<node> const & child : children) {
		parts.push_back(child->to_nfa());
	}
	return nfa2::union_(parts);
}

nfa2 optional::to_nfa() const {
	nfa2 result = children[0]->to_nfa();
	for (int startStateIndex : result.startStates) {
		result.acceptStates.insert(startStateIndex);
	}
	return result;
}

nfa2 repetition::to_nfa() const {
	nfa2 result = children[0]->to_nfa();
	auto originalTransitions = result.get_transitions();

	//copy transitions (start_state, symbol, to_state) to (accept_state, symbol, to_state)
	for (int startStateIndex : result.startStates) {
		for (auto & symbolAndToStates : result.states[startStateIndex].out_transitions) {
			for (int toState : symbolAndToStates.second) {
				for (int acceptState : result.acceptStates) {
					result.states[acceptState].out_transitions[symbolAndToStates.first].insert(toState);
				}
			}
		}
	}

	result.acceptStates.insert(result.startStates.begin(), result.startStates.end());

	return result;
}

nfa2 sequence::to_nfa() const {
	nfa2 result;
	result.states.emplace_back(0);
	result.startStates.insert(0);
	result.acceptStates.insert(0);
	for (erased<node> const & child : children) {
		bool anyOriginalStartIsAccept; {
			std::set<int> intersection;
			set_intersection(result.startStates.begin(), result.startStates.end(),
			                 result.acceptStates.begin(), result.acceptStates.end(), inserter(intersection, intersection.begin()));
			anyOriginalStartIsAccept = !intersection.empty();
		}

		int newStateIndexOffset = result.states.size();

		auto part = child->to_nfa();

		//add the part's states
		for (nfa2::state const & partFromState : part.states) {
			result.states.emplace_back(partFromState.label);
			nfa2::state & newState = result.states.back();
			for (auto & symbolAndToStateIndices : partFromState.out_transitions) {
				for (int toStateIndex : symbolAndToStateIndices.second) {
					newState.out_transitions[symbolAndToStateIndices.first].insert(toStateIndex + newStateIndexOffset);
				}
			}
		}

		std::set<int> originalAcceptStateIndices;
		swap(originalAcceptStateIndices, result.acceptStates);
		//for each (originalFromState, symbol, originalAcceptState) create for each partStartState (originalFromState, symbol, partStartState)
		for (int originalStateIndex = 0; originalStateIndex < newStateIndexOffset; ++originalStateIndex) {
			nfa2::state & fromState = result.states[originalStateIndex];
			for (auto & symbolAndToStateIndices : fromState.out_transitions) {
				std::set<int> toStatesIntersectionOriginalAcceptStates;
				set_intersection(
					symbolAndToStateIndices.second.begin(), symbolAndToStateIndices.second.end(),
					originalAcceptStateIndices.begin(), originalAcceptStateIndices.end(),
					inserter(toStatesIntersectionOriginalAcceptStates, toStatesIntersectionOriginalAcceptStates.begin()));
				if (!toStatesIntersectionOriginalAcceptStates.empty()) {
					for (int partStartIndex : part.startStates) {
						fromState.out_transitions[symbolAndToStateIndices.first].insert(partStartIndex + newStateIndexOffset);
					}
				}
			}
		}

		if (anyOriginalStartIsAccept) {
			for (int partStartStateIndex : part.startStates) {
				result.startStates.insert(partStartStateIndex + newStateIndexOffset);
			}
		}

		for (int partAcceptStateIndex : part.acceptStates) {
			result.acceptStates.insert(partAcceptStateIndex + newStateIndexOffset);
		}
	}

	return result;
}

} //namespace behavior
} //namespace parlex
