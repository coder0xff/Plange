#include "parlex/details/behavior2.hpp"
#include <algorithm>
#include <iterator>

namespace parlex {

void behavior2::node::add_child(erased<node> child) {
	children.push_back(child);
	children.back()->parent = this;
}

behavior2::node::children_t const& behavior2::node::get_children() const {
	return children;
}

behavior2::node::node(node const & other) : tag(other.tag), children(other.children) {
	for (auto & child : children) {
		child->parent = this;
	}
}

behavior2::nfa behavior2::compile(erased<node> const root) {
	return root->to_nfa().minimal_dfa().relabel();
}

behavior2::leaf::leaf(recognizer const & r) : r(r) {
}

behavior2::nfa behavior2::leaf::to_nfa() const {
	nfa result;
	result.states.emplace_back(0);
	result.states.emplace_back(1);
	result.startStates.insert(0);
	result.acceptStates.insert(1);
	result.states[0].out_transitions[this].insert(1);
	return result;
}

behavior2::nfa behavior2::choice::to_nfa() const {
	std::vector<nfa> parts;
	for (erased<node> const & child : children) {
		parts.push_back(child->to_nfa());
	}
	return nfa::union_(parts);
}

behavior2::nfa behavior2::optional::to_nfa() const {
	nfa result = children[0]->to_nfa();
	for (int startStateIndex : result.startStates) {
		result.acceptStates.insert(startStateIndex);
	}
	return result;
}

behavior2::nfa behavior2::repetition::to_nfa() const {
	nfa result = children[0]->to_nfa();
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

behavior2::nfa behavior2::sequence::to_nfa() const {
	nfa result;
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
		for (nfa::state const & partFromState : part.states) {
			result.states.emplace_back(partFromState.label);
			nfa::state & newState = result.states.back();
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
			nfa::state & fromState = result.states[originalStateIndex];
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

}
