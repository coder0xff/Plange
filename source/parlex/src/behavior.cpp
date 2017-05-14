#include "parlex/details/behavior.hpp"

#include <algorithm>
#include <cassert>
#include <iterator>
#include <sstream>
#include <string>

#include "parlex/builtins/string_terminal.hpp"
#include "parlex/state_machine.hpp"
#include "parlex/builtins.hpp"
#include "utils.hpp"

namespace parlex {
namespace details {


std::vector<std::shared_ptr<behavior_node>> behavior_leaf::get_children() {
	return {};
}

choice::~choice() {

}

intermediate_nfa choice::to_intermediate_nfa() const {
	std::vector<intermediate_nfa> parts;
	for (std::shared_ptr<behavior_node> const & child : children) {
		parts.push_back(child->to_intermediate_nfa());
	}
	return intermediate_nfa::union_(parts);
}

std::vector<std::shared_ptr<behavior_node>> choice::get_children() {
	return children;
}

literal::literal(std::u32string contents) : contents(contents) {
}

intermediate_nfa literal::to_intermediate_nfa() const {
	intermediate_nfa result;
	result.states.emplace_back(0);
	result.states.emplace_back(1);
	result.startStates.insert(0);
	result.acceptStates.insert(1);
	result.states[0].out_transitions[shared_from_this()].insert(1);
	return result;
}

recognizer const& literal::get_recognizer(std::map<std::string, state_machine> const &, std::map<std::u32string, builtins::string_terminal> & literals) const {
	auto i = literals.find(contents);
	if (i == literals.end()) {
		return literals.emplace(std::piecewise_construct, forward_as_tuple(contents), forward_as_tuple(contents)).first->second;
	} else {
		return i->second;
	}
}

std::string literal::get_id() const {
	return to_utf8(contents);
}


optional::~optional() {

}

optional::optional(std::shared_ptr<behavior_node> && child) : child(move(child)) { child.reset(); }

intermediate_nfa optional::to_intermediate_nfa() const {
	intermediate_nfa result = child->to_intermediate_nfa();
	for (int startStateIndex : result.startStates) {
		result.acceptStates.insert(startStateIndex);
	}
	return result;
}

std::vector<std::shared_ptr<behavior_node>> optional::get_children() {
	return { child };
}

production::production(std::string name) : name(name) {
}

intermediate_nfa production::to_intermediate_nfa() const {
	intermediate_nfa result;
	result.states.emplace_back(0);
	result.states.emplace_back(1);
	result.startStates.insert(0);
	result.acceptStates.insert(1);
	result.states[0].out_transitions[shared_from_this()].insert(1);
	return result;
}

recognizer const& production::get_recognizer(std::map<std::string, state_machine> const & productions, std::map<std::u32string, builtins::string_terminal> &) const {
	recognizer const * builtin_ptr;
	if (builtins::resolve_builtin(name, builtin_ptr)) {
		return *builtin_ptr;
	}
	assert(productions.count(name) == 1);
	recognizer const & result = productions.find(name)->second;
	return result;
}

std::string production::get_id() const {
	return name;
}


repetition::~repetition() {

}

repetition::repetition(std::shared_ptr<behavior_node> && child) : child(move(child)) { child.reset(); }

intermediate_nfa repetition::to_intermediate_nfa() const {
	intermediate_nfa result = child->to_intermediate_nfa();
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

std::vector<std::shared_ptr<behavior_node>> repetition::get_children() {
	return { child };
}

std::vector<std::shared_ptr<behavior_node>> sequence::get_children() {
	return children;
}


sequence::~sequence() {

}

intermediate_nfa sequence::to_intermediate_nfa() const {
	intermediate_nfa result;
	result.states.emplace_back(0);
	result.startStates.insert(0);
	result.acceptStates.insert(0);
	for (std::shared_ptr<behavior_node> const & child : children) {
		bool anyOriginalStartIsAccept; {
			std::set<int> intersection;
			set_intersection(result.startStates.begin(), result.startStates.end(),
			                 result.acceptStates.begin(), result.acceptStates.end(), inserter(intersection, intersection.begin()));
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
		swap(originalAcceptStateIndices, result.acceptStates);
		//for each (originalFromState, symbol, originalAcceptState) create for each partStartState (originalFromState, symbol, partStartState)
		for (int originalStateIndex = 0; originalStateIndex < newStateIndexOffset; ++originalStateIndex) {
			intermediate_nfa::state & fromState = result.states[originalStateIndex];
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

std::string to_dot(intermediate_nfa const & nfa) {
	std::stringstream result;
	result << "digraph nfa {\n";
	result << "\trankdir=LR;\n";
	result << "\tsize=\"8,5\";\n";
	result << "\tnode[shape = point]; start;";
	result << "\tnode [shape = doublecircle];";
	for (int acceptState : nfa.acceptStates) {
		result << " " << std::to_string(acceptState);
	}
	result << ";\n";
	result << "\tnode [shape = circle];\n";
	for (int startState : nfa.startStates) {
		result << "\tstart -> " << std::to_string(startState) << ";\n";
	}
	for (auto t : nfa.get_transitions()) {
		result << "\t" << std::to_string(t.from) << " -> " << std::to_string(t.to) << " [ label = \"" << t.symbol->get_id() << "\" ];\n";
	}
	result << "}\n";
	return result.str();
}


behavior_leaf::~behavior_leaf() {

}


behavior_node::~behavior_node() {

}

}
}
