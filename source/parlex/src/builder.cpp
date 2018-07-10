#include "parlex/builder.hpp"

#include <iterator>
#include <sstream>

#include "utf.hpp"
#include "graphviz_dot.hpp"
#include "covariant_invoke.hpp"
#include "coherent_queue.hpp"

namespace parlex {
namespace detail {

node::node(std::initializer_list<erased<node>> const & children) : children(children) {}

node::node(std::string const & tag, std::initializer_list<erased<node>> const & children) : tag(tag), children(children) {}

void node::add_child(erased<node> const & child) {
	children.push_back(child);
	children.back()->parent = this;
}

void node::compute_leaf_paths() {
	for (auto & child : children) {
		auto const childPtr = &*child;
		child->compute_leaf_paths();
		for (auto & childLeafPath : child->leaf_paths) {
			leaf_paths[childLeafPath.first] = childPtr;
		}
		if (child->is_leaf()) {
			leaf_paths[static_cast<leaf const *>(childPtr)] = childPtr;  // NOLINT
		}
	}
}

automaton node::compile() {
	compute_leaf_paths();
	auto temp = to_nfa();
	return temp.minimal_dfa().map_to_uints();
}

bool node::is_leaf() const { return false; }

node const * node::follow_or_nullptr(leaf const * l) const {
	auto const i = leaf_paths.find(l);
	if (i == leaf_paths.end()) {
		return nullptr;
	}
	return i->second;
}

leaf::leaf(std::string const & tag) : node(tag, {}), recognizer_index(std::numeric_limits<uint16_t>::max()) {}

bool leaf::is_leaf() const { return true; }

} // namespace detail

literal::literal(std::u32string const & content) : leaf(to_utf8(content)), content(content) {}

literal::literal(std::string const & tag, std::u32string const & content) : leaf(tag), content(content) {}

reference::reference(std::string const & target) : leaf(""), target(target) {}

reference::reference(std::string const & tag, std::string const & target) : leaf(tag), target(target) {
}

production::production(std::string const & name, erased<detail::node> const & behavior, associativity const assoc /*= associativity::none*/, filter_function const & filter /*= filter_function()*/, std::set<std::string> const & precedences /*= set<string>() */) : name(name), behavior(behavior), filter(filter), assoc(assoc), precedences(precedences) {
	this->behavior->tag = name;
}

namespace detail {

static std::string node_to_name(node const * n) {
	std::stringstream result;

#define DO_AS(name) [](name const & v) { return #name + (!v.tag.empty() ? " " + v.tag : ""); }

	result << covariant_invoke<std::string>(*n,
		[](literal const & v) { return to_utf8(v.content); },
		[](reference const & v) { return v.target; },
		DO_AS(choice),
		DO_AS(optional),
		DO_AS(repetition),
		DO_AS(sequence)
		);

#undef DO_AS

	result << " " << n;
	return result.str();
}

} // namespace detail

void production::extract_string_literals(std::set<std::u32string> & results) const {
	collections::coherent_queue<detail::node const *> pending;
	pending.push(&*behavior);
	while (!pending.empty()) {
		auto const nodePtr = pending.pop();
		auto const asLiteralPtr = dynamic_cast<literal const *>(nodePtr);
		if (asLiteralPtr != nullptr) {
			results.insert(asLiteralPtr->content);
		}
		for (auto const & child : nodePtr->children) {
			pending.push(&*child);
		}
	}
}

std::string production::to_dot() const {
	return directed_graph<detail::node const *>(
		&*behavior, detail::node_to_name,
		[&](detail::node const * n)
		{
			auto asSequence = dynamic_cast<sequence const *>(n);
			std::vector<std::pair<std::string, detail::node const *>> edges;
			for (size_t childIndex = 0; childIndex < n->children.size(); ++childIndex) {
				auto const & erasedChild = n->children[childIndex];
				auto edgeName = asSequence != nullptr ? "label=" + std::to_string(childIndex) : "";
				edges.emplace_back(edgeName, &*erasedChild);
			}
			return edges;
		}
	);
}

sub_builder::sub_builder(std::vector<production> const & productions) : productions(productions) { }

std::set<std::u32string> sub_builder::extract_string_literals() const {
	std::set<std::u32string> results;
	for (const auto & production : productions) {
		production.extract_string_literals(results);
	}
	return results;
}

builder::builder(std::string const & rootName, std::vector<production> const & productions) : sub_builder(productions), root_name(rootName) {
}

detail::automaton detail::leaf::to_nfa() const {
	automaton result;
	result.states.emplace_back(0);
	result.states.emplace_back(1);
	result.start_states.insert(0);
	result.accept_states.insert(1);
	result.states[0].out_transitions[this].insert(1);
	return result;
}

detail::automaton choice::to_nfa() const {
	std::vector<detail::automaton> parts;
	for (auto const & child : children) {
		parts.push_back(child->to_nfa());
	}
	return detail::automaton::union_(parts);
}

detail::automaton optional::to_nfa() const {
	auto result = children[0]->to_nfa();
	for (auto startStateIndex : result.start_states) {
		result.accept_states.insert(startStateIndex);
	}
	return result;
}

detail::automaton repetition::to_nfa() const {
	auto result = children[0]->to_nfa();
	auto originalTransitions = result.get_transitions();

	//copy transitions (start_state, symbol, to_state) to (accept_state, symbol, to_state)
	for (auto startStateIndex : result.start_states) {
		for (auto & symbolAndToStates : result.states[startStateIndex].out_transitions) {
			for (auto toState : symbolAndToStates.second) {
				for (auto acceptState : result.accept_states) {
					result.states[acceptState].out_transitions[symbolAndToStates.first].insert(toState);
				}
			}
		}
	}

	result.accept_states.insert(result.start_states.begin(), result.start_states.end());

	return result;
}

detail::automaton sequence::to_nfa() const {
	detail::automaton result;
	result.states.emplace_back(0);
	result.start_states.insert(0);
	result.accept_states.insert(0);
	for (auto const & child : children) {
		auto part = child->to_nfa();
		auto const newStateIndexOffset = result.states.size();

		//true if any part's start state is also an accept state
		bool partAcceptsStart;
		{
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
				for (auto toStateOfPart : symbolAndToStateIndicesOfPart.second) {
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

		for (auto partAcceptStateIndex : part.accept_states) {
			result.accept_states.insert(partAcceptStateIndex + newStateIndexOffset);
		}
	}

	return result;
}

} // namespace parlex
