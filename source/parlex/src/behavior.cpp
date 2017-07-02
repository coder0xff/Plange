#include <algorithm>
#include <iterator>

#include "parlex/details/behavior.hpp"

#include "graphviz_dot.hpp"
#include "parlex/details/raw_state_machine.hpp"
#include "covariant_invoke.hpp"

namespace parlex {
namespace details {
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
	std::stringstream result;

#define DO_AS(name) [](name const & v) { return #name + (v.tag != "" ? " " + v.tag : ""); }
	result << covariant_invoke<std::string>(*n,
		[](leaf const & v) { return v.id; },
		DO_AS(choice),
		DO_AS(optional),
		DO_AS(repetition),
		DO_AS(sequence)
	);
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
	return temp.minimal_dfa().map_to_uints();
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
		auto part = child->to_nfa();
		size_t newStateIndexOffset = result.states.size();

		//true if any part's start state is also an accept state
		bool partAcceptsStart; {
			std::set<size_t> intersection;
			set_intersection(part.startStates.begin(), part.startStates.end(),
				part.acceptStates.begin(), part.acceptStates.end(), inserter(intersection, intersection.begin()));
			partAcceptsStart = !intersection.empty();
		}

		std::set<size_t> originalAcceptStatesOfResult = result.acceptStates;
		if (!partAcceptsStart) {
			result.acceptStates.clear();
		}

		//add the part's states
		for (nfa2::state const & fromStateOfPart : part.states) {
			result.states.emplace_back(fromStateOfPart.label + newStateIndexOffset);
			nfa2::state & newState = result.states.back();
			for (auto & symbolAndToStateIndicesOfPart : fromStateOfPart.out_transitions) {
				for (int toStateOfPart : symbolAndToStateIndicesOfPart.second) {
					newState.out_transitions[symbolAndToStateIndicesOfPart.first].insert(toStateOfPart + newStateIndexOffset);
				}
			}
		}
		std::string check = nfa2_to_dot(result); //todo: disable debug code

		//for each transition (startStateOfPart, symbol, stateOfPart) create for each originalAcceptStatesOfResult (originalAcceptStateOfResult, symbol, stateOfPart + newStateIndexOffset) transition
		for (size_t startStateOfPart : part.startStates) {
			for (auto const & transition : part.states[startStateOfPart].out_transitions) {
				auto const & symbol = transition.first;
				auto const & toStatesOfPart = transition.second;
				for (size_t toStateOfPart : toStatesOfPart) {
					for (size_t originalAcceptStateOfResult : originalAcceptStatesOfResult) {
						std::set<size_t> & toStatesOfOriginalAcceptStateOfResult = result.states[originalAcceptStateOfResult].out_transitions[symbol];
						toStatesOfOriginalAcceptStateOfResult.insert(toStateOfPart + newStateIndexOffset);
					}
				}
			}
		}

		for (int partAcceptStateIndex : part.acceptStates) {
			result.acceptStates.insert(partAcceptStateIndex + newStateIndexOffset);
		}
	}

	return result;
}

} // namespace behavior
} // namespace details
} // namespace parlex
