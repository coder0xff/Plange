#include <algorithm>
#include <iterator>

#include "parlex/detail/behavior.hpp"

#include "graphviz_dot.hpp"
#include "parlex/detail/raw_state_machine.hpp"
#include "covariant_invoke.hpp"

namespace parlex {
	namespace detail {
		namespace behavior {

			std::string nfa2_to_dot(nfa2 const & nfa) {
				return nfa.to_dot([](int x) { return std::to_string(x); }, [](leaf const * x) { return x->id; });
			}

			void node::add_child(erased<node> const child) {
				children.push_back(child);
				children.back()->parent = this;
			}

			node::children_t const & node::get_children() const {
				return children;
			}

			node::node(node const & other) : tag(other.tag), children(other.children) {
				if (other.leaf_paths.size() > 0) {
					debugger();
				}
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
					[&](node const * n) {
						auto asSequence = dynamic_cast<sequence const *>(n);
					std::vector<std::pair<std::string, node const *>> edges;
					for (size_t childIndex = 0; childIndex < n->children.size(); ++childIndex) {
						auto const & erasedChild = n->children[childIndex];
						auto edgeName = asSequence != nullptr ? "label=" + std::to_string(childIndex) : "";
						edges.push_back(make_pair(edgeName, &*erasedChild));
					}
					return edges;
				}
				);
			}

			void node::compute_leaf_paths() const {
				for (auto & child : children) {
					auto const childPtr = &*child;
					child->compute_leaf_paths();
					for (auto & childLeafPath : child->leaf_paths) {
						leaf_paths[childLeafPath.first] = childPtr;
					}
					if (child->is_leaf()) {
						leaf_paths[static_cast<leaf const *>(childPtr)] = childPtr;
					}
				}
			}

			nfa2 node::compile() const {
				compute_leaf_paths();
				auto temp = to_nfa();
				return temp.minimal_dfa().map_to_uints();
			}

			node const & node::operator()(int const index) const { return *children[index]; }
			bool node::is_leaf() const { return false; }

			node const * node::follow(leaf const * l) const {
				auto const i = leaf_paths.find(l);
				if (i == leaf_paths.end()) {
					return nullptr;
				}
				return i->second;
			}

			leaf::leaf(recognizer const & r) : r(r), id(r.id) { }

			bool leaf::is_leaf() const { return true; }

			nfa2 leaf::to_nfa() const {
				nfa2 result;
				result.states.emplace_back(0);
				result.states.emplace_back(1);
				result.start_states.insert(0);
				result.accept_states.insert(1);
				result.states[0].out_transitions[this].insert(1);
				return result;
			}

			nfa2 choice::to_nfa() const {
				std::vector<nfa2> parts;
				for (auto const & child : children) {
					parts.push_back(child->to_nfa());
				}
				return nfa2::union_(parts);
			}

			nfa2 optional::to_nfa() const {
				auto result = children[0]->to_nfa();
				for (int startStateIndex : result.start_states) {
					result.accept_states.insert(startStateIndex);
				}
				return result;
			}

			nfa2 repetition::to_nfa() const {
				auto result = children[0]->to_nfa();
				auto originalTransitions = result.get_transitions();

				//copy transitions (start_state, symbol, to_state) to (accept_state, symbol, to_state)
				for (int startStateIndex : result.start_states) {
					for (auto & symbolAndToStates : result.states[startStateIndex].out_transitions) {
						for (int toState : symbolAndToStates.second) {
							for (int acceptState : result.accept_states) {
								result.states[acceptState].out_transitions[symbolAndToStates.first].insert(toState);
							}
						}
					}
				}

				result.accept_states.insert(result.start_states.begin(), result.start_states.end());

				return result;
			}

			nfa2 sequence::to_nfa() const {
				nfa2 result;
				result.states.emplace_back(0);
				result.start_states.insert(0);
				result.accept_states.insert(0);
				for (auto const & child : children) {
					auto part = child->to_nfa();
					auto const newStateIndexOffset = result.states.size();

					//true if any part's start state is also an accept state
					bool partAcceptsStart; {
						std::set<size_t> intersection;
						set_intersection(part.start_states.begin(), part.start_states.end(),
						                 part.accept_states.begin(), part.accept_states.end(), inserter(intersection, intersection.begin()));
						partAcceptsStart = !intersection.empty();
					}

					auto originalAcceptStatesOfResult = result.accept_states;
					if (!partAcceptsStart) {
						result.accept_states.clear();
					}

					//add the part's states
					for (auto const & fromStateOfPart : part.states) {
						result.states.emplace_back(fromStateOfPart.label + newStateIndexOffset);
						auto & newState = result.states.back();
						for (auto & symbolAndToStateIndicesOfPart : fromStateOfPart.out_transitions) {
							for (int toStateOfPart : symbolAndToStateIndicesOfPart.second) {
								newState.out_transitions[symbolAndToStateIndicesOfPart.first].insert(toStateOfPart + newStateIndexOffset);
							}
						}
					}

					//for each transition (startStateOfPart, symbol, stateOfPart) create for each originalAcceptStatesOfResult (originalAcceptStateOfResult, symbol, stateOfPart + newStateIndexOffset) transition
					for (auto startStateOfPart : part.start_states) {
						for (auto const & transition : part.states[startStateOfPart].out_transitions) {
							auto const & symbol = transition.first;
							auto const & toStatesOfPart = transition.second;
							for (auto toStateOfPart : toStatesOfPart) {
								for (auto originalAcceptStateOfResult : originalAcceptStatesOfResult) {
									auto & toStatesOfOriginalAcceptStateOfResult = result.states[originalAcceptStateOfResult].out_transitions[symbol];
									toStatesOfOriginalAcceptStateOfResult.insert(toStateOfPart + newStateIndexOffset);
								}
							}
						}
					}

					for (int partAcceptStateIndex : part.accept_states) {
						result.accept_states.insert(partAcceptStateIndex + newStateIndexOffset);
					}
				}

				return result;
			}

		} // namespace behavior
	} // namespace detail
} // namespace parlex
