/*
* References:
* [1] Kameda, T. ; IEEE ; Weiner, Peter
*      "On the State Minimization of Nondeterministic Finite Automata"
*      Computers, IEEE Transactions on  (Volume:C-19 ,  Issue: 7 )
*/

#ifndef NFA_H
#define NFA_H


#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <list>
#include <iterator>

#include "parlex/details/auto_map.hpp"

namespace parlex {
namespace details {

		/// <summary>
		/// A nondeterministic finite automaton (∪-Nfa) with labeled states
		/// </summary>
		/// <typeparam name="alphabet_t">The domain of the transition function is S x alphabet_t, where S is the set of states.</typeparam>
		/// <typeparam name="label_t">The type of state labels.</typeparam>
		template<typename alphabet_t, typename label_t, typename compare = std::less<alphabet_t>>
		struct nfa {

            template<typename X, typename Y, typename Z>
            friend struct nfa;

			typedef std::set<int> state_indices_t;

			struct state {
				label_t label;
				std::map<alphabet_t, state_indices_t, compare> out_transitions;

				inline state(label_t label) : label(label) {};
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
				int from;
				alphabet_t symbol;
				int to;

				inline transition(int from, alphabet_t symbol, int to) : from(from), symbol(symbol), to(to) {}
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

			std::string to_dot() const {
				std::string result;
				auto_map<int, std::string> nodeNames([](int x) { return "state" + std::to_string(x); });

				result.append("digraph nfa {\n");
				result.append("\trankdir=LR\n;");
				result.append("\tsize=\"8,5\"\n");
				result.append("\tnode [shape = point]; start;\n");

				result.append("\tnode [shape = doublecircle];");
				for (int acceptState : acceptStates) {
					result.append(" ");
					result.append(nodeNames(acceptState));
				}
				result.append(";\n");
				result.append("\tnode [shape = circle];\n");
				for (int startState : startStates) {
					result.append("\tstart -> ");
					result.append(nodeNames(startState));
					result.append(";\n");
				}
				for (transition t : get_transitions()) {
					result.append("\t");
					result.append(nodeNames(t.from));
					result.append(" -> ");
					result.append(nodeNames(t.to));
					result.append(" [ label = \"");
					result.append(t.symbol.to_string());
					result.append("\" ];\n");
				}
				result.append("}\n");

				return result;
			}

			state_indices_t transition_function_extended(state_indices_t fromStateIndices, alphabet_t input) const {
				std::set<int> result;
				for (int fromStateIndex : fromStateIndices) {
					assert(fromStateIndex < (int)states.size());
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
					state_indices_t const & fromIndices = result.states[processCounter].label;
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
						}
						else {
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

        private:
            // Minimize an already-determinized automaton
			nfa<alphabet_t, state_indices_t> minimize_determinized() const {
                //https://en.wikipedia.org/wiki/DFA_minimization#Hopcroft.27s_algorithm

                nfa<alphabet_t, label_t> d(dual());

                std::set<alphabet_t> sigma;
                for (state const & s : states) {
                    for (std::pair<alphabet_t, state_indices_t> const & j : s.out_transitions) {
                        sigma.insert(j.first);
                    }
                }

                //P := {F, Q \ F};
                std::vector<state_indices_t> P;
                P.push_back(acceptStates);
                {
                    std::set<int> QLessF;
                    for (unsigned int i = 0; i < states.size(); ++i) {
                        if (acceptStates.count(i) == 0) {
                            QLessF.insert(i);
                        }
                    }
                    P.push_back(QLessF);
                }

                //W := {F};
                std::list<state_indices_t> W;
                W.push_back(acceptStates);

                //while (W is not empty) do
                while (W.size() > 0) {

                    //choose and remove a set A from W
                    state_indices_t A(W.front());
                    W.pop_front();

                    //for each c in Σ do
                    for (alphabet_t const & symbol : sigma) {

                        //let X be the set of states for which a transition on c leads to a state in A
                        state_indices_t X;
                        {
                            for (int const & i : A) {
                                typename std::map<alphabet_t, state_indices_t>::iterator j = d.states[i].out_transitions.find(symbol);
                                if (j != d.states[i].out_transitions.end()) {
                                    for (int const & k : j->second) {
                                        X.insert(k);
                                    }
                                }
                            }
                        }

                        //for each set Y in P
                        for (unsigned int i = 0; i < P.size(); ++i) {
                            state_indices_t Y(P[i]);

                            std::set<int> XIntersectY;
                            std::set_intersection(X.begin(), X.end(), Y.begin(), Y.end(), std::inserter(XIntersectY, XIntersectY.begin()));

                            std::set<int> YLessX;
                            std::set_difference(Y.begin(), Y.end(), X.begin(), X.end(), std::inserter(YLessX, YLessX.begin()));

                            //for which X ∩ Y is nonempty and Y \ X is nonempty do
                            if (XIntersectY.size() == 0 || YLessX.size() == 0) {
                                continue;
                            }

                            //replace Y in P by the two sets X ∩ Y and Y \ X
                            P[i] = XIntersectY;
                            P.insert(P.begin() + i + 1, YLessX);
                            ++i;

                            //if Y is in W
                            for (std::list<state_indices_t>::iterator j = W.begin(); j != W.end();) {
                                if (std::equal(Y.begin(), Y.end(), j->begin())) {
                                    //replace Y in W by the same two sets
                                    *j = XIntersectY;
                                    ++j;
                                    W.insert(j, YLessX);
                                    ++j;
                                    continue;
                                }
                            }
                            //else
                            //if |X ∩ Y| <= |Y \ X|
                            if (XIntersectY.size() <= YLessX.size()) {
                                //add X ∩ Y to W
                                W.push_back(XIntersectY);
                            } else {
                                //add Y \ X to W
                                W.push_back(YLessX);
                            }
                        }

                    }
                } //while (W.size() > 0)

                nfa<alphabet_t, state_indices_t> result;

                std::vector<int> indexMap;
                indexMap.resize(states.size());
                for (unsigned int i = 0; i < P.size(); ++i) {
                        for (int j : P[i]) {
                        indexMap[j] = i;
                    }
                    result.states.emplace_back(P[i]);
                }

                for (transition const & t : get_transitions()) {
                    result.states[indexMap[t.from]].out_transitions[t.symbol].insert(indexMap[t.to]);
                }

                assert(startStates.size() == 1);
                result.startStates.insert(indexMap[*startStates.begin()]);

                for (int acceptState : acceptStates) {
                    result.acceptStates.insert(indexMap[acceptState]);
                }

                return result;
			}

        public:

            nfa<alphabet_t, state_indices_t> minimal_dfa() const {
                return determinize().minimize_determinized();
            }

            nfa<alphabet_t, int> relabel() {
                nfa<alphabet_t, int> result;
                for (unsigned int i = 0; i < states.size(); ++i) {
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

			nfa() { }

			nfa(nfa const & other) = default;

			class state_map {
				std::vector<state_indices_t> storage;
				int row_count, column_count;
			public:
				state_map(size_t row_count, size_t column_count) : row_count(row_count), column_count(column_count) {
					storage.resize(row_count * column_count);
				}
				state_indices_t & operator()(size_t row, size_t column) {
					return storage[row * column_count + column];
				}
			};

        private:
			/// <summary>
			///     Creates a state map (SM) as described in [1]
			/// </summary>
			/// <returns></returns>
			std::tuple<state_map, nfa<alphabet_t, state_indices_t> /*determinized*/, nfa<alphabet_t, state_indices_t> /*determinized dual*/> make_state_map() const {
				nfa<alphabet_t, state_indices_t> determinized = determinize();
				nfa<alphabet_t, state_indices_t> determinizedDual = dual().determinize();

				state_map result(determinized.states.size(), determinizedDual.states.size());
				for (int rowIndex = 0; rowIndex < determinized.states.size(); rowIndex++) {
					for (int columnIndex = 0; columnIndex < determinizedDual.states.Count; columnIndex++) {
						state_indices_t & element = result(rowIndex, columnIndex);
						std::set_intersection(determinized.states[rowIndex], determinized.states[columnIndex], std::inserter(element, element.begin()));
					}
				}
				return std::make_tuple(result, determinized, determinizedDual);
			}

			class elementary_automaton_matrix {
                std::vector<bool> storage;
                int row_count, column_count;
            public:
                elementary_automaton_matrix(size_t row_count, size_t column_count) : row_count(row_count), column_count(column_count) {
                    storage.resize(row_count * column_count);
                }
                bool & operator()(size_t row, size_t column) {
                    return storage[row * column_count + column];
                }
			};

			static elementary_automaton_matrix make_elementary_automaton_matrix(state_map stateMap) {
                elementary_automaton_matrix result(stateMap.row_count, stateMap.column_count);
                for (int rowIndex = 0; rowIndex < stateMap.row_count; ++rowIndex) {
                    for (int columnIndex = 0; columnIndex < stateMap.column_count; ++columnIndex) {
                        result(rowIndex, columnIndex) = stateMap(rowIndex, columnIndex).size() > 0;
                    }
                }
			}

			struct reduced_state_map {
				std::vector<state_indices_t> storage;
				std::vector<state_indices_t> rows;
				std::vector<state_indices_t> columns;
			};

			static reduced_state_map reduce_state_map(state_map stateMap, nfa<alphabet_t, state_indices_t> subsetConstructionDfa) {
				elementary_automaton_matrix eam = make_elementary_automaton_matrix(stateMap);

				std::vector<std::set<int>> rowClasses;
				for (int i = 0; i < eam.row_count; ++i) {
					int j;
					for (j = 0; j < rowClasses.size(); ++j) {
						int referenceRow = *rowClasses[j].begin();
						int k;
						for (k = 0; k < eam.column_count; ++k) {
							if (eam(i, k) != eam(referenceRow, k)) {
								break;
							}
						}
						if (k == eam.column_count) {
							rowClasses[j].insert(i);
							break;
						}
					}
					if (j == rowClasses.size()) {
						rowClasses.push_back(std::set<int>({ i }));
					}
				}

				std::vector<std::set<int>> columnClasses;
				for (int i = 0; i < eam.column_count; ++i) {
					int j;
					for (j = 0; j < columnClasses.size(); ++j) {
						int referenceColumn = *columnClasses[j].begin();
						int k;
						for (k = 0; k < eam.row_count; ++k) {
							if (eam(k, i) != eam(k, referenceColumn)) {
								break;
							}
						}
						if (k == eam.row_count) {
							columnClasses[j].insert(i);
							break;
						}
					}
					if (j == columnClasses.size()) {
						columnClasses.push_back(std::set<int>({ i }));
					}
				}


			}

		public:
			static nfa union_(std::vector<nfa> nfas) {
				nfa result;
				for (nfa const & n : nfas) {
					int indexTranslation = result.states.size();
					for (unsigned int stateIndex = 0; stateIndex < n.states.size(); ++stateIndex) {
						state const & oldFrom = n.states[stateIndex];
						result.states.emplace_back(oldFrom.label);
						state &newFrom = result.states.back();
						for (auto const & transitionAndTos : oldFrom.out_transitions) {
							auto newOutTransitions = newFrom.out_transitions[transitionAndTos.first];
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

			//private static ReducedStateMap ReduceStateMap(StateMap stateMap, Nfa<alphabet_t, StateSet> subsetConstructionDfa, out Nfa<alphabet_t, int> minimizedSubsetConstructionDfa) {
			//	//construct an elementary automata matrix (EAM) [1]
			//	bool[, ] elementaryAutomataMatrix = MakeElementaryAutomatonMatrix(stateMap);

			//	//determine which rows can be merged
			//	var rowsToMerge = new List<HashSet<int>>();
			//	{
			//		List<int> unmergedRows = Enumerable.Range(0, stateMap.Rows.Count).ToList();
			//		while (unmergedRows.Count > 0) {
			//			rowsToMerge.Add(new HashSet < int > { unmergedRows[0] });
			//			for (int rowIndex = 1; rowIndex < unmergedRows.Count; rowIndex++) {
			//				int columnIndex;
			//				for (columnIndex = 0; columnIndex < stateMap.Columns.Count; columnIndex++) {
			//					if (elementaryAutomataMatrix[unmergedRows[0], columnIndex] != elementaryAutomataMatrix[unmergedRows[rowIndex], columnIndex]) {
			//						break;
			//					}
			//				}
			//				if (columnIndex != stateMap.Columns.Count) {
			//					continue;
			//				}
			//				rowsToMerge[rowsToMerge.Count - 1].Add(unmergedRows[rowIndex]);
			//				unmergedRows.RemoveAt(rowIndex);
			//				rowIndex--;
			//			}
			//			unmergedRows.RemoveAt(0);
			//		}
			//	}

			//	//determine which columns can be merged
			//	var columnsToMerge = new List<HashSet<int>>();
			//	{
			//		List<int> unmergedColumns = Enumerable.Range(0, stateMap.Columns.Count).ToList();
			//		while (unmergedColumns.Count > 0) {
			//			columnsToMerge.Add(new HashSet < int > { unmergedColumns[0] });
			//			for (int columnIndex = 1; columnIndex < unmergedColumns.Count; columnIndex++) {
			//				int rowIndex;
			//				for (rowIndex = 0; rowIndex < stateMap.Rows.Count; rowIndex++) {
			//					if (elementaryAutomataMatrix[rowIndex, unmergedColumns[0]] != elementaryAutomataMatrix[rowIndex, unmergedColumns[columnIndex]]) {
			//						break;
			//					}
			//				}
			//				if (rowIndex != stateMap.Rows.Count) {
			//					continue;
			//				}
			//				columnsToMerge[columnsToMerge.Count - 1].Add(unmergedColumns[columnIndex]);
			//				unmergedColumns.RemoveAt(columnIndex);
			//				columnIndex--;
			//			}
			//			unmergedColumns.RemoveAt(0);
			//		}
			//	}

			//	var result = new ReducedStateMap(rowsToMerge.Count, columnsToMerge.Count);
			//	var stateSetToEquivalenceClassRowIndex = new Dictionary<StateSet, int>();
			//	for (int equivalenceClassRowIndex = 0; equivalenceClassRowIndex < rowsToMerge.Count; equivalenceClassRowIndex++) {
			//		foreach(int row in rowsToMerge[equivalenceClassRowIndex]) {
			//			stateSetToEquivalenceClassRowIndex[stateMap.Rows.Right[row]] = equivalenceClassRowIndex;
			//		}
			//		var rowName = new ReadOnlyHashSet<int>(rowsToMerge[equivalenceClassRowIndex]);
			//		result.Rows.Left.Add(rowName, equivalenceClassRowIndex);
			//	}
			//	minimizedSubsetConstructionDfa = GenerateEquivalenceClassReducedDfa(subsetConstructionDfa, stateSetToEquivalenceClassRowIndex);

			//	for (int equivalenceClassColumnIndex = 0; equivalenceClassColumnIndex < columnsToMerge.Count; equivalenceClassColumnIndex++) {
			//		var columnName = new ReadOnlyHashSet<int>(columnsToMerge[equivalenceClassColumnIndex]);
			//		result.Columns.Left.Add(columnName, equivalenceClassColumnIndex);
			//	}

			//	for (int equivalenceClassRowIndex = 0; equivalenceClassRowIndex < rowsToMerge.Count; equivalenceClassRowIndex++) {
			//		for (int equivalenceClassColumnIndex = 0; equivalenceClassColumnIndex < columnsToMerge.Count; equivalenceClassColumnIndex++) {
			//			HashSet<State> statesUnion = result.Map[equivalenceClassRowIndex, equivalenceClassColumnIndex] = new HashSet<State>();
			//			foreach(int rowIndex in rowsToMerge[equivalenceClassRowIndex]) {
			//				foreach(int columnIndex in columnsToMerge[equivalenceClassColumnIndex]) {
			//					statesUnion.UnionWith(stateMap.Map[rowIndex, columnIndex]);
			//				}
			//			}
			//		}
			//	}

			//	return result;
			//}

			//private static bool[, ] MakeReducedAutomataMatrix(ReducedStateMap reducedStateMap) {
			//	var result = new bool[reducedStateMap.Rows.Count, reducedStateMap.Columns.Count];
			//	for (int rowIndex = 0; rowIndex < reducedStateMap.Rows.Count; rowIndex++) {
			//		for (int columnIndex = 0; columnIndex < reducedStateMap.Columns.Count; columnIndex++) {
			//			result[rowIndex, columnIndex] = reducedStateMap.Map[rowIndex, columnIndex].Count > 0;
			//		}
			//	}
			//	return result;
			//}

			//private static Grid[] ComputePrimeGrids(bool[, ] reducedAutomataMatrix) {
			//	var gridsToProcess = new DistinctRecursiveAlgorithmProcessor<Grid>();
			//	int rowCount = reducedAutomataMatrix.GetUpperBound(0) + 1;
			//	int columnCount = reducedAutomataMatrix.GetUpperBound(1) + 1;

			//	//make initial grids which contain only one element
			//	for (int rowIndex = 0; rowIndex < rowCount; rowIndex++) {
			//		for (int columnIndex = 0; columnIndex < columnCount; columnIndex++) {
			//			if (reducedAutomataMatrix[rowIndex, columnIndex]) {
			//				var grid = new Grid(new[] {rowIndex}, new[] {columnIndex});
			//				gridsToProcess.Add(grid);
			//			}
			//		}
			//	}

			//	//then, grow them incrementally, adding them back into the queue
			//	//or saving them if they cannot be grown
			//	var results = new ConcurrentSet<Grid>();
			//	gridsToProcess.Run(grid = > {
			//		bool isPrime = true;
			//		//try expanding to other rows
			//		{
			//			int comparisonRow = grid.Rows.First();
			//			foreach(int testRow in Enumerable.Range(0, rowCount).Except(grid.Rows)) {
			//				bool canExpand = grid.Columns.All(columnIndex = > reducedAutomataMatrix[testRow, columnIndex] == reducedAutomataMatrix[comparisonRow, columnIndex]);
			//				if (!canExpand) {
			//					continue;
			//				}
			//				var newGrid = new Grid(grid.Rows.Concat(new[] {testRow}), grid.Columns);
			//				gridsToProcess.Add(newGrid);
			//				isPrime = false;
			//			}
			//		}
			//		//try expanding to other columns
			//	{
			//		int comparisonColumn = grid.Columns.First();
			//		foreach(int testColumn in Enumerable.Range(0, columnCount).Except(grid.Columns)) {
			//			bool canExpand = grid.Rows.All(rowIndex = > reducedAutomataMatrix[rowIndex, testColumn] == reducedAutomataMatrix[rowIndex, comparisonColumn]);
			//			if (!canExpand) {
			//				continue;
			//			}
			//			var newGrid = new Grid(grid.Rows, grid.Columns.Concat(new[] {testColumn}));
			//			gridsToProcess.Add(newGrid);
			//			isPrime = false;
			//		}
			//	}
			//		//if it's prime, then save it to the results
			//		if (isPrime) {
			//			results.TryAdd(grid);
			//		}
			//	});
			//	return results.ToArray();
			//}

			//private static IEnumerable<Cover> EnumerateCovers(Grid[] primeGrids, int firstGridIndex, Dictionary<Grid, HashSet<int>> gridToFlattenedIndicesSet, HashSet<int> flattenedIndicesWithTrue, int gridCount) {
			//	if (gridCount > primeGrids.Length - firstGridIndex) { //can't reach gridCount == 0 before the recursion runs out of grids
			//		yield break;
			//	}
			//	for (int gridIndex = firstGridIndex; gridIndex < primeGrids.Length; gridIndex++) {
			//		Grid primeGrid = primeGrids[gridIndex];
			//		var primeGridAsEnumerable = new[] {primeGrid};
			//		var remainingFlattenedIndicesWithTrueToSatisfy = new HashSet<int>(flattenedIndicesWithTrue);
			//		remainingFlattenedIndicesWithTrueToSatisfy.ExceptWith(gridToFlattenedIndicesSet[primeGrid]);
			//		if (gridCount == 1) {
			//			if (remainingFlattenedIndicesWithTrueToSatisfy.Count == 0) {
			//				yield return new Cover(primeGridAsEnumerable);
			//			}
			//		}
			//		else {
			//			foreach(Cover enumerateCover in EnumerateCovers(primeGrids, gridIndex + 1, gridToFlattenedIndicesSet, remainingFlattenedIndicesWithTrueToSatisfy, gridCount - 1)) {
			//				yield return new Cover(enumerateCover.Concat(primeGridAsEnumerable));
			//			}
			//		}
			//	}
			//}

			//private static IEnumerable<Cover> EnumerateCovers(bool[, ] reducedAutomataMatrix, Grid[] primeGrids) {
			//	int rowCount = reducedAutomataMatrix.GetUpperBound(0) + 1;
			//	int columnCount = reducedAutomataMatrix.GetUpperBound(1) + 1;

			//	var flattenedIndicesWithTrue = new HashSet<int>();
			//	for (int row = 0; row < rowCount; row++) {
			//		for (int column = 0; column < columnCount; column++) {
			//			if (reducedAutomataMatrix[row, column]) {
			//				flattenedIndicesWithTrue.Add(column*rowCount + row);
			//			}
			//		}
			//	}

			//	if (flattenedIndicesWithTrue.Count == 0) {
			//		yield break;
			//	}

			//	Dictionary<Grid, HashSet<int>> gridToFlattenedIndicesSet = primeGrids.ToDictionary(grid = > grid, grid = > {
			//		var flattenedIndices = new HashSet<int>();
			//		foreach(int row in grid.Rows) {
			//			foreach(int column in grid.Columns) {
			//				flattenedIndices.Add(column*rowCount + row);
			//			}
			//		}
			//		return flattenedIndices;
			//	});

			//	for (int gridCount = 1; gridCount <= primeGrids.Length; gridCount++) {
			//		foreach(Cover enumerateCover in EnumerateCovers(primeGrids, 0, gridToFlattenedIndicesSet, flattenedIndicesWithTrue, gridCount)) {
			//			yield return enumerateCover;
			//		}
			//	}
			//}

			//private static AutoDictionary<int, HashSet<Grid>> MakeSubsetAssignmentFunction(Cover cover) {
			//	var result = new AutoDictionary<int, HashSet<Grid>>(dontCare0 = > new HashSet<Grid>());
			//	foreach(Grid grid in cover) {
			//		foreach(int row in grid.Rows) {
			//			result[row].Add(grid);
			//		}
			//	}
			//	return result;
			//}

			//private static Nfa<alphabet_t, int> FromIntersectionRule(Nfa<alphabet_t, int> reducedDfa, Cover cover, out Bimap<int, Grid> orderedGrids) {
			//	List<Nfa<alphabet_t, int>.State> orderedReducedDfaStates = reducedDfa._states.OrderBy(x = > x.Value).ToList();
			//	AutoDictionary<int, HashSet<Grid>> subsetAssignmentFunction = MakeSubsetAssignmentFunction(cover);
			//	int counter = 0;
			//	Bimap<int, Grid> orderedGridsTemp = cover.ToBimap(x = > counter++, x = > x);
			//	var result = new Nfa<alphabet_t, int>();
			//	var intToResultState = new AutoDictionary<int, Nfa<alphabet_t, int>.State>(i = > new Nfa<alphabet_t, int>.State(i));
			//	for (int resultStateIndex = 0; resultStateIndex < orderedGridsTemp.Count; resultStateIndex++) {
			//		Grid grid = orderedGridsTemp.Left[resultStateIndex];
			//		Nfa<alphabet_t, int>.State resultState = intToResultState[resultStateIndex];
			//		JaggedAutoDictionary<alphabet_t, HashSet<Nfa<alphabet_t, int>.State>> resultTransitionPartialLambda = result._transitionFunction[resultState];
			//		IEnumerable<Nfa<alphabet_t, int>.State> rows = grid.Rows.Select(rowIndex = > orderedReducedDfaStates[rowIndex]);
			//		ReadOnlyHashSet<alphabet_t> symbols = ReadOnlyHashSet<alphabet_t>.IntersectMany(rows.Select(row = > reducedDfa._transitionFunction[row].Keys));
			//		foreach(alphabet_t symbol in symbols) {
			//			alphabet_t symbol1 = symbol;
			//			IEnumerable<HashSet<Grid>> gridSets = rows.Select(row = > subsetAssignmentFunction[reducedDfa._transitionFunction[row][symbol1].First().Value]);
			//			ReadOnlyHashSet<Grid> nextGrids = ReadOnlyHashSet<Grid>.IntersectMany(gridSets);
			//			IEnumerable<int> nextIndices = nextGrids.Select(nextGrid = > orderedGridsTemp.Right[nextGrid]);
			//			IEnumerable<Nfa<alphabet_t, int>.State> nextStates = nextIndices.Select(gridIndex = > intToResultState[gridIndex]);
			//			resultTransitionPartialLambda[symbol].UnionWith(nextStates);
			//		}
			//		if (grid.Columns.Contains(0)) {
			//			result._acceptStates.Add(resultState);
			//		}
			//		if (grid.Rows.Contains(0)) {
			//			result._startStates.Add(resultState);
			//		}
			//	}

			//	result._states.UnionWith(intToResultState.Values);
			//	orderedGrids = orderedGridsTemp;
			//	return result;
			//}

			//private static bool GridSetSpansRow(Bimap<int, Grid> orderedGrids, IEnumerable<int> gridIndices, bool[, ] reducedAutomataMatrix, int rowIndex) {
			//	var neededColumns = new HashSet<int>(Enumerable.Range(0, reducedAutomataMatrix.GetUpperBound(1) + 1).Where(columnIndex = > reducedAutomataMatrix[rowIndex, columnIndex]));
			//	foreach(int gridIndex in gridIndices) {
			//		Grid grid = orderedGrids.Left[gridIndex];
			//		if (grid.Rows.Contains(rowIndex)) {
			//			neededColumns.ExceptWith(grid.Columns);
			//			if (neededColumns.Count == 0) {
			//				break;
			//			}
			//		}
			//	}
			//	return neededColumns.Count == 0;
			//}

			//private static bool SubsetAssignmentIsLegitimate(Nfa<alphabet_t, int> intersectionRuleNfa, Nfa<alphabet_t, int> minimizedDfa, bool[, ] reducedAutomataMatrix, Bimap<int, Grid> orderedGrids) {
			//	Nfa<alphabet_t, Nfa<alphabet_t, int>.StateSet> intersectionRuleDfa = intersectionRuleNfa.Determinize();
			//	List<Nfa<alphabet_t, Nfa<alphabet_t, int>.StateSet>.State> intersectionRuleDfaOrderedStates = intersectionRuleDfa.States.ToList();
			//	intersectionRuleDfaOrderedStates.Remove(intersectionRuleDfa.StartStates.First());
			//	intersectionRuleDfaOrderedStates.Insert(0, intersectionRuleDfa.StartStates.First());

			//	var processor = new DistinctRecursiveAlgorithmProcessor<KeyValuePair<Nfa<alphabet_t, int>.State /*minimized*/, Nfa<alphabet_t, Nfa<alphabet_t, int>.StateSet>.State /*intersection rule*/>>();
			//	processor.Add(new KeyValuePair<Nfa<alphabet_t, int>.State, Nfa<alphabet_t, Nfa<alphabet_t, int>.StateSet>.State>(minimizedDfa.StartStates.First(), intersectionRuleDfa.StartStates.First()));
			//	bool isLegitimate = true;
			//	processor.Run(pair = > {
			//		if (isLegitimate) {
			//			Nfa<alphabet_t, int>.State minimizedDfaState = pair.Key;
			//			Nfa<alphabet_t, Nfa<alphabet_t, int>.StateSet>.State intersectionRuleDfaState = pair.Value;
			//			IEnumerable<alphabet_t> inputSymbols = minimizedDfa.TransitionFunction[minimizedDfaState].Keys;
			//			foreach(alphabet_t inputSymbol in inputSymbols) {
			//				if (!intersectionRuleDfa.TransitionFunction[intersectionRuleDfaState][inputSymbol].Any()) {
			//					isLegitimate = false;
			//					continue;
			//				}
			//				Nfa<alphabet_t, Nfa<alphabet_t, int>.StateSet>.State nextIntersectionRuleDfaState = intersectionRuleDfa.TransitionFunction[intersectionRuleDfaState][inputSymbol].First();
			//				Nfa<alphabet_t, int>.State nextMinimizedDfaState = minimizedDfa.TransitionFunction[minimizedDfaState][inputSymbol].First();
			//				if (!intersectionRuleDfa.AcceptStates.Contains(nextIntersectionRuleDfaState) && minimizedDfa.AcceptStates.Contains(nextMinimizedDfaState)) {
			//					isLegitimate = false;
			//				}
			//				else if (!GridSetSpansRow(orderedGrids, nextIntersectionRuleDfaState.Value.Select(s = > s.Value), reducedAutomataMatrix, nextMinimizedDfaState.Value)) {
			//					isLegitimate = false;
			//				}
			//				else {
			//					processor.Add(new KeyValuePair<Nfa<alphabet_t, int>.State, Nfa<alphabet_t, Nfa<alphabet_t, int>.StateSet>.State>(nextMinimizedDfaState, nextIntersectionRuleDfaState));
			//				}
			//			}
			//		}
			//	});
			//	return isLegitimate;
			//}

			//public Nfa<alphabet_t, TAssignment2> Reassign<TAssignment2>(Func<State, TAssignment2> func) {
			//	var result = new Nfa<alphabet_t, TAssignment2>();
			//	var stateMapper = new AutoDictionary<State, Nfa<alphabet_t, TAssignment2>.State>(state = > new Nfa<alphabet_t, TAssignment2>.State(func(state)));
			//	foreach(State state in _states) {
			//		stateMapper.EnsureCreated(state);
			//	}
			//	foreach(State state in _transitionFunction.Keys) {
			//		JaggedAutoDictionary<alphabet_t, HashSet<State>> sourcePartialEvaluation0 = _transitionFunction[state];
			//		JaggedAutoDictionary<alphabet_t, HashSet<Nfa<alphabet_t, TAssignment2>.State>> targetPartialEvaluation0 = result._transitionFunction[stateMapper[state]];
			//		foreach(alphabet_t inputSymbol in _transitionFunction[state].Keys) {
			//			HashSet<State> sourcePartialEvaluation1 = sourcePartialEvaluation0[inputSymbol];
			//			HashSet<Nfa<alphabet_t, TAssignment2>.State> targetPartialEvaluation1 = targetPartialEvaluation0[inputSymbol];
			//			foreach(State state1 in sourcePartialEvaluation1) {
			//				targetPartialEvaluation1.Add(stateMapper[state1]);
			//			}
			//		}
			//	}
			//	result._startStates.UnionWith(_startStates.Select(state = > stateMapper[state]));
			//	result._acceptStates.UnionWith(_acceptStates.Select(state = > stateMapper[state]));
			//	result._states.UnionWith(stateMapper.Values);
			//	return result;
			//}

			//public Nfa<alphabet_t> Reassign() {
			//	var result = new Nfa<alphabet_t>();
			//	var stateMapper = new AutoDictionary<State, Nfa<alphabet_t>.State>(state = > new Nfa<alphabet_t>.State());
			//	foreach(State state in _states) {
			//		stateMapper.EnsureCreated(state);
			//	}
			//	foreach(var fromStateKeyValuePair in TransitionFunction) {
			//		foreach(var transitionKeyValuePair in fromStateKeyValuePair.Value) {
			//			foreach(State toState in transitionKeyValuePair.Value) {
			//				result.TransitionFunction[stateMapper[fromStateKeyValuePair.Key]][transitionKeyValuePair.Key].Add(stateMapper[toState]);
			//			}
			//		}
			//	}
			//	result.StartStates.UnionWith(_startStates.Select(state = > stateMapper[state]));
			//	result.AcceptStates.UnionWith(_acceptStates.Select(state = > stateMapper[state]));
			//	result.States.UnionWith(stateMapper.Values);
			//	return result;
			//}

			///// <summary>
			/////     If there are any nodes that cannot be reached or cannot reach an accept state then remove them
			/////     iff a transition can be removed without changing the behavior, remove it
			///// </summary>
			//public void RemoveRedundancies() {
			//start:
			//	foreach(State state in States.ToArray()) {
			//		if (StartStates.Select(x = > GetRoutes(x, state).Any()).All(x = > x != true) &&
			//			AcceptStates.Select(x = > GetRoutes(state, x).Any()).All(x = > x != true)) {
			//			States.Remove(state);
			//			AcceptStates.Remove(state);
			//			StartStates.Remove(state);
			//			_transitionFunction.TryRemove(state);
			//			State state1 = state;
			//			foreach(Transition transition in GetTransitions().Where(x = > x.ToState == state1)) {
			//				_transitionFunction[transition.FromState][transition.Symbol].Remove(state);
			//				if (!_transitionFunction[transition.FromState][transition.Symbol].Any()) {
			//					_transitionFunction[transition.FromState].TryRemove(transition.Symbol);
			//				}
			//			}
			//			goto start;
			//		}
			//	}
			//	TrimTransitions();
			//	TrimStartAccepts();
			//}

			//private void TrimTransitions() {
			//	var copy = new Nfa<alphabet_t, label_t>(this);
			//	var thatMinDfa = copy.MinimizedDfa();
			//	var allTransitions = GetTransitions().ToArray();
			//	foreach(var transition in allTransitions) {
			//		TransitionFunction[transition.FromState][transition.Symbol].Remove(transition.ToState);
			//		if (!ProprocessedIsEquivalent(thatMinDfa)) {
			//			TransitionFunction[transition.FromState][transition.Symbol].Add(transition.ToState);
			//		}
			//		else {
			//			//System.Diagnostics.Debug.WriteLine("Trimmed transition");
			//		}
			//	}
			//}

			//private void TrimStartAccepts() {
			//	var startAccepts = StartStates.Where(startState = > AcceptStates.Contains(startState)).ToArray();
			//	var withFromTransitions = startAccepts.Where(state = > TransitionFunction[state].Any(symbolListPair = > symbolListPair.Value.Count > 0)).ToArray();
			//	var withoutFromTransitions = startAccepts.Except(withFromTransitions);
			//	if (withFromTransitions.Any()) {
			//		foreach(var withoutFromTransition in withoutFromTransitions) {
			//			StartStates.Remove(withoutFromTransition);
			//		}
			//	}
			//}

			///// <summary>
			/////     Minimize this Nfa using the Kameda-Weiner algorithm [1]
			///// </summary>
			///// <returns>A minimal-state Nfa accepting the same language</returns>
			//public Nfa<alphabet_t, int> Minimized() {
			//	Nfa<alphabet_t, StateSet> determinized;
			//	StateMap sm = MakeStateMap(out determinized);
			//	Nfa<alphabet_t, int> minimizedSubsetConstructionDfa;
			//	ReducedStateMap rsm = ReduceStateMap(sm, determinized, out minimizedSubsetConstructionDfa);
			//	bool[, ] ram = MakeReducedAutomataMatrix(rsm);
			//	Grid[] primeGrids = ComputePrimeGrids(ram);
			//	IEnumerable<Cover> covers = EnumerateCovers(ram, primeGrids);
			//	foreach(Cover cover in covers) {
			//		if (cover.Count >= _states.Count || cover.Count >= determinized.States.Count) {
			//			break;
			//		}
			//		Bimap<int, Grid> orderedGrids;
			//		Nfa<alphabet_t, int> minNFA = FromIntersectionRule(minimizedSubsetConstructionDfa, cover, out orderedGrids);
			//		bool isLegitimate = SubsetAssignmentIsLegitimate(minNFA, minimizedSubsetConstructionDfa, ram, orderedGrids);
			//		if (isLegitimate) {
			//			minNFA.RemoveRedundancies();
			//			return minNFA;
			//		}
			//	}
			//	int stateCount = 0;
			//	if (determinized.States.Count <= _states.Count) {
			//		return determinized.Reassign(x = > Interlocked.Increment(ref stateCount));
			//	}
			//	else {
			//		return Reassign(x = > Interlocked.Increment(ref stateCount)); //did not find a smaller Nfa. Return this;
			//	}
			//}

			//public static Nfa<alphabet_t, label_t> Union(IEnumerable<Nfa<alphabet_t, label_t>> nfas) {
			//	var result = new Nfa<alphabet_t, label_t>();
			//	foreach(var nfa in nfas) {
			//		//don't need to clone the states because they are immutable
			//		result._startStates.UnionWith(nfa._startStates);
			//		result._acceptStates.UnionWith(nfa._acceptStates);
			//		foreach(State fromState in nfa._transitionFunction.Keys) {
			//			foreach(alphabet_t inputSymbol in nfa._transitionFunction[fromState].Keys) {
			//				result._transitionFunction[fromState][inputSymbol].UnionWith(nfa._transitionFunction[fromState][inputSymbol]);
			//			}
			//		}
			//		result._states.UnionWith(nfa._states);
			//	}
			//	return result;
			//}

			//public Nfa<alphabet_t, int> MinimizedDfa() {
			//	Nfa<alphabet_t, StateSet> determinized;
			//	StateMap sm = MakeStateMap(out determinized);
			//	Nfa<alphabet_t, int> minimizedSubsetConstructionDfa;
			//	ReduceStateMap(sm, determinized, out minimizedSubsetConstructionDfa);
			//	return minimizedSubsetConstructionDfa;
			//}

			//public bool IsEquivalent<TAssignment2>(Nfa<alphabet_t, TAssignment2> that) {
			//	Nfa<alphabet_t, int> thatMinDfa = that.MinimizedDfa();
			//	return ProprocessedIsEquivalent(thatMinDfa);
			//}

			//public bool ProprocessedIsEquivalent(Nfa<alphabet_t, int> thatMinDfa) {
			//	Nfa<alphabet_t, int> thisMinDfa = MinimizedDfa();
			//	bool equivalent = true;
			//	var stateMap = new ConcurrentDictionary<Nfa<alphabet_t, int>.State, Nfa<alphabet_t, int>.State>();
			//	var processor = new DistinctRecursiveAlgorithmProcessor<KeyValuePair<Nfa<alphabet_t, int>.State, Nfa<alphabet_t, int>.State>>();
			//	processor.Add(new KeyValuePair<Nfa<alphabet_t, int>.State, Nfa<alphabet_t, int>.State>(thisMinDfa._startStates.First(), thatMinDfa._startStates.First())); //only one start state since it's a min dfa
			//	processor.Run(pair = > {
			//		if (!equivalent) {
			//			return;
			//		}
			//		foreach(var inputSymbol in thisMinDfa._transitionFunction[pair.Key].Keys.Union(thatMinDfa._transitionFunction[pair.Value].Keys)) {
			//			Nfa<alphabet_t, int>.State thisMinDfaNextState = thisMinDfa._transitionFunction[pair.Key][inputSymbol].FirstOrDefault(); //deterministic, so only one state
			//			Nfa<alphabet_t, int>.State thatMinDfaNextState = thatMinDfa._transitionFunction[pair.Value][inputSymbol].FirstOrDefault();
			//			if (thatMinDfaNextState == null || thisMinDfaNextState == null) {
			//				equivalent = false;
			//			}
			//			else {
			//				Nfa<alphabet_t, int>.State mappedThisMinDfaNextState = stateMap.GetOrAdd(thisMinDfaNextState, thisMinDfaNextStateProxy = > {
			//					processor.Add(new KeyValuePair<Nfa<alphabet_t, int>.State, Nfa<alphabet_t, int>.State>(thisMinDfaNextState, thatMinDfaNextState));
			//					return thatMinDfaNextState;
			//				});
			//				if (thatMinDfaNextState != mappedThisMinDfaNextState) {
			//					equivalent = false;
			//				}
			//				if (thatMinDfa.AcceptStates.Contains(thatMinDfaNextState) != thisMinDfa.AcceptStates.Contains(thisMinDfaNextState)) {
			//					equivalent = false;
			//				}
			//			}
			//		}
			//	});
			//	return equivalent;
			//}

			//public static Nfa<alphabet_t, int> Intersect(IEnumerable<Nfa<alphabet_t, label_t>> nfas) {
			//	IEnumerable<Nfa<alphabet_t, int>> minDets = nfas.Select(nfa = > nfa.MinimizedDfa());
			//	Nfa<alphabet_t, int> singleTransitionNFA = Nfa<alphabet_t, int>.Union(minDets);
			//	JaggedAutoDictionary<Nfa<alphabet_t, int>.State, alphabet_t, HashSet<Nfa<alphabet_t, int>.State>> singleTransitionFunction = singleTransitionNFA._transitionFunction;
			//	HashSet<Nfa<alphabet_t, int>.State> singleAcceptStates = singleTransitionNFA._acceptStates;
			//	int stateCount = 0;
			//	var resultStates = new AutoDictionary<ReadOnlyHashSet<Nfa<alphabet_t, int>.State>, Nfa<alphabet_t, int>.State>(x = > new Nfa<alphabet_t, int>.State(Interlocked.Increment(ref stateCount)));
			//	var processor = new DistinctRecursiveAlgorithmProcessor<ReadOnlyHashSet<Nfa<alphabet_t, int>.State>>();
			//	var startStateSet = new ReadOnlyHashSet<Nfa<alphabet_t, int>.State>(minDets.Select(x = > x._startStates.First()));
			//	var result = new Nfa<alphabet_t, int>();
			//	var acceptStates = new ConcurrentSet<Nfa<alphabet_t, int>.State>();
			//	processor.Add(startStateSet);
			//	processor.Run(stateSet = > {
			//		Nfa<alphabet_t, int>.State fromState = resultStates[stateSet];
			//		if (singleAcceptStates.IsSupersetOf(stateSet)) {
			//			acceptStates.TryAdd(fromState);
			//		}
			//		ReadOnlyHashSet<alphabet_t> fromSymbols = ReadOnlyHashSet<alphabet_t>.IntersectMany(stateSet.Select(state = > singleTransitionFunction[state].Keys));
			//		foreach(alphabet_t fromSymbol in fromSymbols) {
			//			alphabet_t symbol = fromSymbol;
			//			var nextStateSet = new ReadOnlyHashSet<Nfa<alphabet_t, int>.State>(stateSet.Select(state = > singleTransitionFunction[state][symbol].First()));
			//			Nfa<alphabet_t, int>.State toState = resultStates[nextStateSet];
			//			processor.Add(nextStateSet);
			//			result._transitionFunction[fromState][fromSymbol].Add(toState);
			//		}
			//	});
			//	result._states.UnionWith(resultStates.Values);
			//	result._startStates.Add(resultStates[startStateSet]);
			//	result._acceptStates.UnionWith(acceptStates);
			//	return result;
			//}

			//public bool Contains(Nfa<alphabet_t, label_t> that) {
			//	return Intersect(new[] {this, that}).IsEquivalent(that);
			//}

			//private IEnumerable<IEnumerable<State>> GetRoutes(State fromState, State toState, HashSet<State> ignoredStates = null) {
			//	if (ignoredStates == null) {
			//		ignoredStates = new HashSet<State>();
			//	}
			//	List<State> subsequentStates = _transitionFunction[fromState].SelectMany(inputSymbolAndToStates = > inputSymbolAndToStates.Value).Distinct().Where(s = > !ignoredStates.Contains(s)).ToList();
			//	foreach(State subsequentState in subsequentStates) {
			//		if (subsequentState == toState) {
			//			yield return new[] {toState};
			//		}
			//		ignoredStates.Add(subsequentState);
			//		foreach(var route in GetRoutes(subsequentState, toState, ignoredStates)) {
			//			yield return new[] {subsequentState}.Concat(route);
			//		}
			//		ignoredStates.Remove(subsequentState);
			//	}
			//}

			//public IEnumerable<IEnumerable<State>> GetCycles() {
			//	return _states.SelectMany(state = > GetRoutes(state, state, new HashSet<State>()));
			//}

			//public string ToString(Func<alphabet_t, String> transitionStringifier) {
			//	var result = new StringBuilder();
			//	int nodeCounter = 0;
			//	var labels = new AutoDictionary<State, int>(_ = > Interlocked.Increment(ref nodeCounter));
			//	result.Append("Start: ");
			//	result.Append(String.Join(", ", StartStates.Select(x = > labels[x]).ToArray()));
			//	//make sure non-accept states are numbered begore accept states
			//	foreach(State nonAccept in States.Except(AcceptStates)) {
			//		labels.EnsureCreated(nonAccept);
			//	}
			//	result.Append(" Accept: ");
			//	result.Append(String.Join(", ", AcceptStates.Select(x = > labels[x]).ToArray()));
			//	result.Append(" Transitions:");
			//	result.Append(Environment.NewLine);

			//	foreach(var fromStateKeyValuePair in TransitionFunction) {
			//		string fromStateBuilder = labels[fromStateKeyValuePair.Key].ToString();
			//		foreach(var transitionKeyValuePair in fromStateKeyValuePair.Value) {
			//			string transitionBuilder = transitionStringifier(transitionKeyValuePair.Key);
			//			foreach(State toState in transitionKeyValuePair.Value) {
			//				result.Append(fromStateBuilder);
			//				result.Append(" -> ");
			//				result.Append(transitionBuilder);
			//				result.Append(" -> ");
			//				result.Append(labels[toState]);
			//				result.Append(Environment.NewLine);
			//			}
			//		}
			//	}
			//	return result.ToString();
			//}

			//public override string ToString() {
			//	return ToString(x = > x.ToString());
			//}

			//private class Cover : ReadOnlyHashSet < Grid > {
			//	public Cover(IEnumerable<Grid> items)
			//		: base(items) {}
			//}

			//private class Grid {
			//	public readonly ReadOnlyHashSet<int> Columns;
			//	public readonly ReadOnlyHashSet<int> Rows;

			//	public Grid(IEnumerable<int> rows, IEnumerable<int> columns) {
			//		Rows = new ReadOnlyHashSet<int>(rows);
			//		Columns = new ReadOnlyHashSet<int>(columns);
			//	}

			//	protected bool Equals(Grid other) {
			//		return Columns.Equals(other.Columns) && Rows.Equals(other.Rows);
			//	}

			//	public override bool Equals(object obj) {
			//		if (ReferenceEquals(null, obj)) {
			//			return false;
			//		}
			//		if (ReferenceEquals(this, obj)) {
			//			return true;
			//		}
			//		if (obj.GetType() != GetType()) {
			//			return false;
			//		}
			//		return Equals((Grid)obj);
			//	}

			//	public override int GetHashCode() {
			//		unchecked{
			//			return (Columns.GetHashCode() * 397) ^ Rows.GetHashCode();
			//		}
			//	}

			//	public static bool operator ==(Grid left, Grid right) {
			//		return Equals(left, right);
			//	}

			//	public static bool operator !=(Grid left, Grid right) {
			//		return !Equals(left, right);
			//	}
			//}

			//private class ReducedStateMap {
			//	public readonly Bimap<ReadOnlyHashSet<int>, int> Columns = new Bimap<ReadOnlyHashSet<int>, int>();
			//	[SuppressMessage("Microsoft.Performance", "CA1814:PreferJaggedArraysOverMultidimensional", MessageId = "Member")] public readonly HashSet<State>[, ] Map;
			//	public readonly Bimap<ReadOnlyHashSet<int>, int> Rows = new Bimap<ReadOnlyHashSet<int>, int>();

			//	public ReducedStateMap(int rowCount, int columnCount) {
			//		Map = new HashSet<State>[rowCount, columnCount];
			//	}
			//}

			///// <summary>
			/////     A State of an Nfa
			///// </summary>
			//class State {
			//	private readonly label_t _value;

			//	public State(label_t value) {
			//		_value = value;
			//	}

			//	public label_t Value{
			//		get{ return _value; }
			//	}

			//	public override string ToString() {
			//			return _value.ToString();
			//		}
			//}

			//private class StateMap {
			//	public readonly Bimap<StateSet, int> Columns = new Bimap<StateSet, int>();
			//	[SuppressMessage("Microsoft.Performance", "CA1814:PreferJaggedArraysOverMultidimensional", MessageId = "Member")] public readonly HashSet<State>[, ] Map;
			//	public readonly Bimap<StateSet, int> Rows = new Bimap<StateSet, int>();

			//	public StateMap(int rowCount, int columnCount) {
			//		Map = new HashSet<State>[rowCount, columnCount];
			//	}
			//}

			///// <summary>
			/////     An immutable set of States that can be quickly tested for inequality
			///// </summary>
			//public class StateSet : ReadOnlyHashSet < State > {
			//	public StateSet(IEnumerable<State> items)
			//		: base(items) {}
			//}

		};

	}

}

#endif
