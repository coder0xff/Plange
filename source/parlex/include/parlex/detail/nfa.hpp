﻿#ifndef NFA_H
#define NFA_H

#include <map>
#include <set>
#include <string>
#include <vector>

#include "auto_map_c.hpp"
#include "graphviz_dot.hpp"
#include "utils.hpp"


namespace parlex {
namespace detail {

/// <summary>
/// A nondeterministic finite automaton (∪-Nfa) with labeled states
/// </summary>
/// <typeparam name="alphabet_t">The domain of the transition function is S x alphabet_t, where S is the set of states.</typeparam>
/// <typeparam name="label_t">The type of state labels.</typeparam>
template <typename alphabet_t, typename label_t, typename compare = std::less<alphabet_t>>
struct nfa {

	template <typename X, typename Y, typename Z>
	friend struct nfa;

	using state_indices_t = std::set<size_t>;

	struct state {
		label_t label;
		std::map<alphabet_t, state_indices_t, compare> out_transitions;

		state(label_t label) : label(label) {
		};
	};

	state_indices_t acceptStates;
	state_indices_t startStates;
	std::vector<state> states;

	int add_state(label_t label, bool isAcceptState, bool isStartState) {
		states.emplace_back(label);
		int result = states.size() - 1;
		if (isAcceptState) {
			acceptStates.insert(result);
		}
		if (isStartState) {
			startStates.insert(result);
		}
		return result;
	}

	state_indices_t get_start_states() const {
		return startStates;
	}

	state_indices_t get_accept_states() const {
		return acceptStates;
	}

	struct transition {
		size_t from;
		alphabet_t symbol;
		size_t to;

		transition(size_t from, alphabet_t symbol, size_t to) : from(from), symbol(symbol), to(to) {
		}
	};

	std::vector<transition> get_transitions() const {
		std::vector<transition> result;
		int fromState = 0;
		for (state s : states) {
			for (auto transitionAndToStates : s.out_transitions) {
				for (auto toState : transitionAndToStates.second) {
					result.emplace_back(fromState, transitionAndToStates.first, toState);
				}
			}
			fromState++;
		}
		return result;
	}

	std::string to_dot(std::function<std::string (label_t const &)> getLabelName, std::function<std::string (alphabet_t const &)> getTransitionName) const {
		std::vector<int> vertices;
		for (size_t i = 0; i < states.size(); ++i) { vertices.push_back(i); }
		return directed_graph<int>(
			vertices,
			[&](int i) { return getLabelName(states[i].label); },
			[&](int i) {
				std::vector<std::pair<std::string, int>> edges;
				for (auto transitionAndToStates : states[i].out_transitions) {
					for (auto toState : transitionAndToStates.second) {
						auto const & transition = transitionAndToStates.first;
						std::string properties = "label=" + enquote(getTransitionName(transition));
						edges.push_back(std::make_pair(properties, toState));
					}
				}
				return edges;
			},
			[&](int i) {
				std::string properties;
				if (startStates.count(i) > 0) {
					properties = "color=red";
				}
				if (acceptStates.count(i) > 0) {
					if (!properties.empty()) {
						properties += ", ";
					}
					properties += "shape=doublecircle";
				}
				return properties;
			}
		);
	}

	state_indices_t transition_function_extended(state_indices_t fromStateIndices, alphabet_t input) const {
		std::set<size_t> result;
		for (size_t fromStateIndex : fromStateIndices) {
			throw_assert(fromStateIndex < states.size());
			auto i = states[fromStateIndex].out_transitions.find(input);
			if (i != states[fromStateIndex].out_transitions.end()) {
				for (int toStateIndex : i->second) {
					result.insert(toStateIndex);
				}
			}
		}
		return result;
	}

	// Creates a new Nfa that has only one transition for each input symbol for each state - i.e. it is deterministic
	nfa<alphabet_t, state_indices_t> determinize() const {
		nfa<alphabet_t, state_indices_t> result;
		std::map<state_indices_t, int> stateSetToIndex;
		result.add_state(startStates, false, true);
		stateSetToIndex[startStates] = 0;

		//perform subset construction
		for (unsigned int processCounter = 0; processCounter < result.states.size(); ++processCounter) {
			state_indices_t fromIndices = result.states[processCounter].label; //must be copied due to modifying result.states
			std::set<alphabet_t> out_symbols;
			for (int fromIndex : fromIndices) {
				for (std::pair<alphabet_t, state_indices_t> trans : states[fromIndex].out_transitions) {
					out_symbols.insert(trans.first);
				}
			}
			for (alphabet_t symbol : out_symbols) {
				auto next_set = transition_function_extended(fromIndices, symbol);
				int to_state_index;
				auto i = stateSetToIndex.find(next_set);
				if (i == stateSetToIndex.end()) {
					to_state_index = stateSetToIndex[next_set] = result.states.size();
					result.states.emplace_back(next_set);
				} else {
					to_state_index = i->second;
				}
				result.states[processCounter].out_transitions[symbol].insert(to_state_index);
			}
		}

		// set accept states
		for (auto pair : stateSetToIndex) {
			for (int s : pair.first) {
				if (acceptStates.count(s)) {
					result.acceptStates.insert(pair.second);
					break;
				}
			}
		}

		return result;
	}

	nfa<alphabet_t, state_indices_t> minimal_dfa() const {
		//TODO: create a correct implementation of Hopcroft's algorithm - the pseudocode on wikipedia is bunk
		return dual().determinize().dual().determinize();
	}

	nfa<alphabet_t, size_t> map_to_uints() {
		nfa<alphabet_t, size_t> result;
		for (size_t i = 0; i < states.size(); ++i) {
			result.states.emplace_back(i);
			result.states[i].out_transitions = states[i].out_transitions;
		}
		result.startStates = startStates;
		result.acceptStates = acceptStates;
		return result;
	}

	/// <summary>
	///     Creates a new Nfa that recognizes the reversed language
	/// </summary>
	/// <returns>The new Nfa</returns>
	nfa dual() const {
		nfa result;
		result.startStates = acceptStates;
		result.acceptStates = startStates;
		for (unsigned int state_index = 0; state_index < states.size(); ++state_index) {
			result.states.emplace_back(states[state_index].label);
		}
		for (unsigned int from_state_index = 0; from_state_index < states.size(); ++from_state_index) {
			for (auto symbolAndToStates : states[from_state_index].out_transitions) {
				for (int to_state_index : symbolAndToStates.second) {
					result.states[to_state_index].out_transitions[symbolAndToStates.first].insert(from_state_index);
				}
			}
		}
		return result;
	}

	nfa() = default;

	nfa(nfa const & other) = default;

	class state_map {
		std::vector<state_indices_t> storage;
		int row_count, column_count;
	public:
		state_map(size_t row_count, size_t column_count) : row_count(row_count), column_count(column_count) {
			storage.resize(row_count * column_count);
		}

		state_indices_t& operator()(size_t row, size_t column) {
			return storage[row * column_count + column];
		}
	};

	static nfa union_(std::vector<nfa> const & nfas) {
		nfa result;
		for (nfa const & n : nfas) {
			int indexTranslation = result.states.size();
			for (unsigned int stateIndex = 0; stateIndex < n.states.size(); ++stateIndex) {
				state const & oldFrom = n.states[stateIndex];
				result.states.emplace_back(oldFrom.label);
				state & newFrom = result.states.back();
				for (auto const & transitionAndTos : oldFrom.out_transitions) {
					auto & newOutTransitions = newFrom.out_transitions[transitionAndTos.first];
					for (int to : transitionAndTos.second) {
						newOutTransitions.insert(to + indexTranslation);
					}
				}
			}
			for (int startState : n.startStates) {
				result.startStates.insert(startState + indexTranslation);
			}
			for (int acceptState : n.acceptStates) {
				result.acceptStates.insert(acceptState + indexTranslation);
			}
		}
		return result;
	}

};

} // namespace detail
} // namespace parlex

#endif //NFA_H