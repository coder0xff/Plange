#include "parlex/details/behavior.hpp"

#include <cassert>
#include <iterator>

#include "parlex/builtins/string_terminal.hpp"
#include "parlex/state_machine.hpp"

namespace parlex {
namespace details {

intermediate_nfa choice::to_intermediate_nfa() const
{
	std::vector<intermediate_nfa> parts;
	for (std::shared_ptr<behavior_node> const & child : children) {
		parts.push_back(child->to_intermediate_nfa());
	}
	return intermediate_nfa::union_(parts);
}

literal::literal(std::u32string contents) : contents(contents) {}

intermediate_nfa literal::to_intermediate_nfa() const
{
	intermediate_nfa result;
	result.states.emplace_back(0);
	result.states.emplace_back(1);
	result.startStates.insert(0);
	result.acceptStates.insert(1);
	result.states[0].out_transitions[shared_from_this()].insert(1);
	return result;
}

recognizer const & literal::get_recognizer(std::map<std::string, parlex::state_machine> const & productions, std::vector<builtins::string_terminal> & literals, std::map<std::u32string, int> literals_map) const {
    auto const status = literals_map.insert(std::pair<std::u32string, int>(contents, literals.size()));
    if (status.second) {
        literals.push_back(contents);
    }
    return literals[status.first->second];
}

optional::optional(std::shared_ptr<behavior_node> && child) : child(std::move(child)) { child.reset(); }

intermediate_nfa optional::to_intermediate_nfa() const
{
	intermediate_nfa result = child->to_intermediate_nfa();
	for (int startStateIndex : result.startStates) {
		result.acceptStates.insert(startStateIndex);
	}
	return result;
}

production::production(std::string name) : name(name) {}

intermediate_nfa production::to_intermediate_nfa() const
{
	intermediate_nfa result;
	result.states.emplace_back(0);
	result.states.emplace_back(1);
	result.startStates.insert(0);
	result.acceptStates.insert(1);
	result.states[0].out_transitions[shared_from_this()].insert(1);
	return result;
}

recognizer const & production::get_recognizer(std::map<std::string, state_machine> const & productions, std::vector<builtins::string_terminal> & literals, std::map<std::u32string, int> literals_map) const {
    assert(productions.count(name) == 1);
    return productions.find(name)->second;
}

repetition::repetition(std::shared_ptr<behavior_node> && child) : child(std::move(child)) { child.reset(); }

intermediate_nfa repetition::to_intermediate_nfa() const
{
	intermediate_nfa result = child->to_intermediate_nfa();
	auto originalTransitions = result.get_transitions();
	for (int acceptStateIndex : result.acceptStates) {

		//copy transitions (accept_state, symbol, to_state) to (start_state, symbol, to_state) for each start_state
		for (auto & symbolAndToStates : result.states[acceptStateIndex].out_transitions) {
			for (int toState : symbolAndToStates.second) {
				for (int startState : result.startStates) {
					result.states[startState].out_transitions[symbolAndToStates.first].insert(toState);
				}
			}
		}

		//copy transitions (from_state, symbol, accept_state) to (from_state, symbol, start_state) for each start_state
		for (intermediate_nfa::state fromState : result.states) {
			for (auto & symbolAndToStatesIndices : result.states[acceptStateIndex].out_transitions) {
				for (int toStateIndex : symbolAndToStatesIndices.second) {
					if (result.acceptStates.count(toStateIndex)) {
						for (int startState : result.startStates) {
							fromState.out_transitions[symbolAndToStatesIndices.first].insert(startState);
						}
					}
				}
			}
		}

		//remove original accepts states, and all incoming/outgoing transitions to/from them

		//make a map from original indices to new indices where accept states have been removed
		std::vector<int> indexMap;
		for (unsigned int newIndex = 0, originalIndex = 0; originalIndex < result.states.size(); ++originalIndex) {
			if (result.acceptStates.count(originalIndex)) {
				result.states.erase(result.states.begin() + originalIndex); //remove state
			} else {
				indexMap.push_back(newIndex++); //add map element and increment counter
			}
		}

		result.acceptStates.clear();

		//update all to-state indices using the indexMap
		for (intermediate_nfa::state & fromState : result.states) {
			for (auto i = fromState.out_transitions.begin(); i != fromState.out_transitions.end(); ++i) {
				std::set<int> temp;
				temp.swap(i->second);
				for (unsigned int toStateIndex : temp) {
					if (toStateIndex < indexMap.size()) {
						i->second.insert(indexMap[toStateIndex]);
					}
				}
			}
		}

		result.acceptStates = result.startStates;

	}
	return result;
}

intermediate_nfa sequence::to_intermediate_nfa() const
{
	intermediate_nfa result;
	result.states.emplace_back(0);
	result.startStates.insert(0);
	result.acceptStates.insert(0);
	for (std::shared_ptr<behavior_node> const & child : children) {
		bool anyOriginalStartIsAccept = false;
		{
			std::set<int> intersection;
			std::set_intersection(result.startStates.begin(), result.startStates.end(),
				result.acceptStates.begin(), result.acceptStates.end(), std::inserter(intersection, intersection.begin()));
			anyOriginalStartIsAccept = !intersection.empty();
		}

		int newStateIndexOffset = result.states.size();

		auto part = child->to_intermediate_nfa();

		//add the part's states
		for (intermediate_nfa::state const & partFromState : part.states) {
			result.states.emplace_back(partFromState.label);
			intermediate_nfa::state & newState = result.states.back();
			for (auto & symbolAndToStateIndices : partFromState.out_transitions) {
				for (int toStateIndex : symbolAndToStateIndices.second) {
					newState.out_transitions[symbolAndToStateIndices.first].insert(toStateIndex + newStateIndexOffset);
				}
			}
		}

		std::set<int> originalAcceptStateIndices;
		std::swap(originalAcceptStateIndices, result.acceptStates);
		//for each (originalFromState, symbol, originalAcceptState) create for each partStartState (originalFromState, symbol, partStartState)
        for (int originalStateIndex = 0; originalStateIndex < newStateIndexOffset; ++originalStateIndex) {
            intermediate_nfa::state & fromState = result.states[originalStateIndex];
            for (auto & symbolAndToStateIndices : fromState.out_transitions) {
                std::set<int> toStatesIntersectionOriginalAcceptStates;
                std::set_intersection(
                    symbolAndToStateIndices.second.begin(), symbolAndToStateIndices.second.end(),
                    originalAcceptStateIndices.begin(), originalAcceptStateIndices.end(),
                    std::inserter(toStatesIntersectionOriginalAcceptStates, toStatesIntersectionOriginalAcceptStates.begin()));
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
}
