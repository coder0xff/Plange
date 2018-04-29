#ifndef NFA_H
#define NFA_H

#include <map>
#include <set>
#include <string>
#include <vector>

#include "concurrent_auto_map.hpp"
#include "graphviz_dot.hpp"
#include "utils.hpp"


namespace parlex {
namespace detail {

/// <summary>
/// A nondeterministic finite automaton (∪-Nfa) with labeled states
/// </summary>
/// <typeparam name="alphabet_t">The domain of the transition function is S x alphabet_t, where S is the set of states.</typeparam>
/// <typeparam name="label_t">The type of state labels.</typeparam>
template <typename AlphabetT, typename LabelT, typename Compare = std::less<AlphabetT>>
struct nfa {

	template <typename X, typename Y, typename Z>
	friend struct nfa;

	using state_indices_t = std::set<size_t>;

	struct state {
		LabelT label;
		std::map<AlphabetT, state_indices_t, Compare> out_transitions;

		explicit state(LabelT label) : label(label) {
		};
	};

	state_indices_t accept_states;
	state_indices_t start_states;
	std::vector<state> states;

	size_t add_state(LabelT label, bool const isAcceptState, bool const isStartState) {
		states.emplace_back(label);
		size_t const result = states.size() - 1;
		if (isAcceptState) {
			accept_states.insert(result);
		}
		if (isStartState) {
			start_states.insert(result);
		}
		return result;
	}

	state_indices_t get_start_states() const {
		return start_states;
	}

	state_indices_t get_accept_states() const {
		return accept_states;
	}

	struct transition {
		size_t from;
		AlphabetT symbol;
		size_t to;

		transition(size_t const from, AlphabetT symbol, size_t const to) : from(from), symbol(symbol), to(to) {
		}
	};

	std::vector<transition> get_transitions() const {
		std::vector<transition> result;
		auto fromState = 0;
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

	std::string to_dot(std::function<std::string (LabelT const &)> getLabelName, std::function<std::string (AlphabetT const &)> getTransitionName) const {
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
				if (start_states.count(i) > 0) {
					properties = "color=red";
				}
				if (accept_states.count(i) > 0) {
					if (!properties.empty()) {
						properties += ", ";
					}
					properties += "shape=doublecircle";
				}
				return properties;
			}
		);
	}

	state_indices_t transition_function_extended(state_indices_t fromStateIndices, AlphabetT input) const {
		std::set<size_t> result;
		for (auto fromStateIndex : fromStateIndices) {
			throw_assert(fromStateIndex < states.size());
			auto i = states[fromStateIndex].out_transitions.find(input);
			if (i != states[fromStateIndex].out_transitions.end()) {
				for (auto toStateIndex : i->second) {
					result.insert(toStateIndex);
				}
			}
		}
		return result;
	}

	// Creates a new Nfa that has only one transition for each input symbol for each state - i.e. it is deterministic
	nfa<AlphabetT, state_indices_t> determinize() const {
		nfa<AlphabetT, state_indices_t> result;
		std::map<state_indices_t, size_t> stateSetToIndex;
		result.add_state(start_states, false, true);
		stateSetToIndex[start_states] = 0;

		//perform subset construction
		for (unsigned int processCounter = 0; processCounter < result.states.size(); ++processCounter) {
			state_indices_t fromIndices = result.states[processCounter].label; //must be copied due to modifying result.states
			std::set<AlphabetT> outSymbols;
			for (auto fromIndex : fromIndices) {
				for (std::pair<AlphabetT, state_indices_t> trans : states[fromIndex].out_transitions) {
					outSymbols.insert(trans.first);
				}
			}
			for (AlphabetT symbol : outSymbols) {
				auto nextSet = transition_function_extended(fromIndices, symbol);
				size_t toStateIndex;
				auto i = stateSetToIndex.find(nextSet);
				if (i == stateSetToIndex.end()) {
					toStateIndex = stateSetToIndex[nextSet] = result.states.size();
					result.states.emplace_back(nextSet);
				} else {
					toStateIndex = i->second;
				}
				result.states[processCounter].out_transitions[symbol].insert(toStateIndex);
			}
		}

		// set accept states
		for (auto pair : stateSetToIndex) {
			for (auto s : pair.first) {
				if (accept_states.count(s)) {
					result.accept_states.insert(pair.second);
					break;
				}
			}
		}

		return result;
	}

	nfa<AlphabetT, state_indices_t> minimal_dfa() const {
		//TODO: create a correct implementation of Hopcroft's algorithm - the pseudocode on wikipedia is bunk
		return dual().determinize().dual().determinize();
	}

	nfa<AlphabetT, size_t> map_to_uints() {
		nfa<AlphabetT, size_t> result;
		for (size_t i = 0; i < states.size(); ++i) {
			result.states.emplace_back(i);
			result.states[i].out_transitions = states[i].out_transitions;
		}
		result.start_states = start_states;
		result.accept_states = accept_states;
		return result;
	}

	/// <summary>
	///     Creates a new Nfa that recognizes the reversed language
	/// </summary>
	/// <returns>The new Nfa</returns>
	nfa dual() const {
		nfa result;
		result.start_states = accept_states;
		result.accept_states = start_states;
		for (unsigned int stateIndex = 0; stateIndex < states.size(); ++stateIndex) {
			result.states.emplace_back(states[stateIndex].label);
		}
		for (unsigned int fromStateIndex = 0; fromStateIndex < states.size(); ++fromStateIndex) {
			for (auto symbolAndToStates : states[fromStateIndex].out_transitions) {
				for (auto toStateIndex : symbolAndToStates.second) {
					result.states[toStateIndex].out_transitions[symbolAndToStates.first].insert(fromStateIndex);
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
		state_map(size_t const rowCount, size_t const columnCount) : row_count(rowCount), column_count(columnCount) {
			storage.resize(rowCount * columnCount);
		}

		state_indices_t& operator()(size_t const row, size_t const column) {
			return storage[row * column_count + column];
		}
	};

	static nfa union_(std::vector<nfa> const & nfas) {
		nfa result;
		for (nfa const & n : nfas) {
			auto const indexTranslation = result.states.size();
			for (unsigned int stateIndex = 0; stateIndex < n.states.size(); ++stateIndex) {
				state const & oldFrom = n.states[stateIndex];
				result.states.emplace_back(oldFrom.label);
				state & newFrom = result.states.back();
				for (auto const & transitionAndTos : oldFrom.out_transitions) {
					auto & newOutTransitions = newFrom.out_transitions[transitionAndTos.first];
					for (auto to : transitionAndTos.second) {
						newOutTransitions.insert(to + indexTranslation);
					}
				}
			}
			for (auto startState : n.start_states) {
				result.start_states.insert(startState + indexTranslation);
			}
			for (auto acceptState : n.accept_states) {
				result.accept_states.insert(acceptState + indexTranslation);
			}
		}
		return result;
	}

};

} // namespace detail
} // namespace parlex

#endif //NFA_H
