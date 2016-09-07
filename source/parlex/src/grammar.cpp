#include "parlex/grammar.hpp"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <sstream>

#include "parlex/builtins.hpp"
#include "parlex/details/behavior.hpp"
#include "utils.hpp"

namespace parlex {

	grammar::grammar(std::string const & nameOfMain) : main_production_name(nameOfMain) {}

	grammar::grammar(std::string const & nameOfMain, std::map<std::string, std::shared_ptr<details::behavior_node>> const & trees, std::map<std::string, associativity> const & associativities, std::set<std::string> const & greedyNames) : main_production_name(nameOfMain)
	{
		std::map<std::string, details::intermediate_nfa> dfas;
		for (auto const & nameAndBehaviorNode : trees) {
			auto temp = nameAndBehaviorNode.second->to_intermediate_nfa().minimal_dfa().relabel();
			dfas[nameAndBehaviorNode.first] = temp;
			//std::string check = parlex::details::to_dot(temp);
		}

		assert(dfas.count(main_production_name) == 1);

		std::map<std::string, details::intermediate_nfa> reorderedDfas;

		for (auto const & nameAndDfa : dfas) {
			std::string const & name = nameAndDfa.first;
			details::intermediate_nfa const & dfa = nameAndDfa.second;
			//construct a map from dfa states to reordered states
			std::map<int, int> stateMap;
			unsigned int startState = *dfa.startStates.begin();
			bool startIsAccept = dfa.acceptStates.count(startState) > 0;
			if (!startIsAccept) {
				stateMap[*dfa.startStates.begin()] = 0;
			}
			for (unsigned int i = 0; i < dfa.states.size(); ++i) {
				//all the un-added non-accept states
				if (i != startState && dfa.acceptStates.count(i) == 0) {
					stateMap[i] = stateMap.size();
				}
			}
			if (startIsAccept) {
				stateMap[*dfa.startStates.begin()] = stateMap.size();
			}
			for (unsigned int i = 0; i < dfa.states.size(); ++i) {
				//all the un-added accept states
				if (i != startState && dfa.acceptStates.count(i) > 0) {
					stateMap[i] = stateMap.size();
				}
			}

			//it's a bimap, construct reverse lookup
			std::map<int, int> stateMapDual;
			for (auto const & i : stateMap) {
				stateMapDual[i.second] = i.first;
			}

			//construct the reordered dfa
			details::intermediate_nfa reordered;
			unsigned int firstAcceptState = dfa.states.size() - dfa.acceptStates.size();
			for (unsigned int i = 0; i < dfa.states.size(); ++i) {
				unsigned int const dual = stateMapDual[i];
				details::intermediate_nfa::state const & dfa_state = dfa.states[dual];
				reordered.add_state(i, i >= firstAcceptState, dual == startState);
				details::intermediate_nfa::state & reordered_state = reordered.states[i];
				for (auto out_transition : dfa_state.out_transitions) {
					reordered_state.out_transitions[out_transition.first] = { stateMap[*out_transition.second.begin()] };
				}
			}

			reorderedDfas[name] = reordered;
		}

		//construct all the productions, without transitions
		for (auto const & nameAndDfa : reorderedDfas) {
			std::string const & name = nameAndDfa.first;
			details::intermediate_nfa const & dfa = nameAndDfa.second;
			associativity assoc = none;
			auto const & i = associativities.find(name);
			if (i != associativities.end()) {
				assoc = i->second;
			}
			if (greedyNames.count(name) > 0) {
				productions.emplace(std::piecewise_construct, forward_as_tuple(name), forward_as_tuple(name, *dfa.startStates.begin(), dfa.acceptStates.size(), &builtins::greedy, assoc));
			}
			else {
				productions.emplace(std::piecewise_construct, forward_as_tuple(name), forward_as_tuple(name, *dfa.startStates.begin(), dfa.acceptStates.size(), assoc));
			}
		}

		//add transitions, linking productions
		for (auto const & nameAndDfa : reorderedDfas) {
			std::string const & name = nameAndDfa.first;
			details::intermediate_nfa const & dfa = nameAndDfa.second;
			state_machine & sm = productions.find(name)->second;
			auto transitions = dfa.get_transitions();
			for (auto const & t : transitions) {
				recognizer const & r = t.symbol->get_recognizer(productions, literals);
				sm.add_transition(t.from, r, t.to);
			}
		}
	}

	grammar::grammar(std::string const & nameOfMain, std::map<std::string, production_def> const & defs) : main_production_name(nameOfMain) {
		std::map<std::string, details::intermediate_nfa> dfas;
		for (auto const & nameAndDef : defs) {
			auto temp = nameAndDef.second.tree->to_intermediate_nfa().minimal_dfa().relabel();
			dfas[nameAndDef.first] = temp;
		}

		assert(dfas.count(main_production_name) == 1);

		std::map<std::string, details::intermediate_nfa> reorderedDfas;

		for (auto const & nameAndDfa : dfas) {
			std::string const & name = nameAndDfa.first;
			details::intermediate_nfa const & dfa = nameAndDfa.second;
			//construct a map from dfa states to reordered states
			std::map<int, int> stateMap;
			unsigned int startState = *dfa.startStates.begin();
			bool startIsAccept = dfa.acceptStates.count(startState) > 0;
			if (!startIsAccept) {
				stateMap[*dfa.startStates.begin()] = 0;
			}
			for (unsigned int i = 0; i < dfa.states.size(); ++i) {
				//all the un-added non-accept states
				if (i != startState && dfa.acceptStates.count(i) == 0) {
					stateMap[i] = stateMap.size();
				}
			}
			if (startIsAccept) {
				stateMap[*dfa.startStates.begin()] = stateMap.size();
			}
			for (unsigned int i = 0; i < dfa.states.size(); ++i) {
				//all the un-added accept states
				if (i != startState && dfa.acceptStates.count(i) > 0) {
					stateMap[i] = stateMap.size();
				}
			}

			//it's a bimap, construct reverse lookup
			std::map<int, int> stateMapDual;
			for (auto const & i : stateMap) {
				stateMapDual[i.second] = i.first;
			}

			//construct the reordered dfa
			details::intermediate_nfa reordered;
			unsigned int firstAcceptState = dfa.states.size() - dfa.acceptStates.size();
			for (unsigned int i = 0; i < dfa.states.size(); ++i) {
				unsigned int const dual = stateMapDual[i];
				details::intermediate_nfa::state const & dfa_state = dfa.states[dual];
				reordered.add_state(i, i >= firstAcceptState, dual == startState);
				details::intermediate_nfa::state & reordered_state = reordered.states[i];
				for (auto out_transition : dfa_state.out_transitions) {
					reordered_state.out_transitions[out_transition.first] = { stateMap[*out_transition.second.begin()] };
				}
			}

			reorderedDfas[name] = reordered;
		}

		//construct all the productions, without transitions
		for (auto const & nameAndDfa : reorderedDfas) {
			std::string const & name = nameAndDfa.first;
			details::intermediate_nfa const & dfa = nameAndDfa.second;
			associativity assoc = defs.find(name)->second.assoc;
			filter_function const * filter = defs.find(name)->second.filter;
			productions.emplace(std::piecewise_construct, forward_as_tuple(name), forward_as_tuple(name, *dfa.startStates.begin(), dfa.acceptStates.size(), filter, assoc));
		}

		//add transitions, "link" productions, add precedences
		for (auto const & nameAndDfa : reorderedDfas) {
			std::string const & name = nameAndDfa.first;
			details::intermediate_nfa const & dfa = nameAndDfa.second;
			state_machine & sm = productions.find(name)->second;
			auto transitions = dfa.get_transitions();
			for (auto const & t : transitions) {
				recognizer const & r = t.symbol->get_recognizer(productions, literals);
				sm.add_transition(t.from, r, t.to);
			}
			production_def const & def = defs.find(name)->second;
			for (std::string i : def.precedences) {
				add_precedence(sm, productions.find(i)->second);
			}
		}
	}

	grammar::grammar(grammar const & other) : main_production_name(other.main_production_name), literals(other.literals) {
		std::map<recognizer const *, recognizer const *> recognizersMap;
		for (std::map<std::u32string, builtins::string_terminal>::const_iterator i = other.literals.begin(), j = literals.begin(); j != literals.end();) {
			recognizersMap[static_cast<recognizer const *>(&i++->second)] = static_cast<recognizer const *>(&j++->second);
		}

		for (auto const & nameAndStateMachine : other.productions) {
			std::string name = nameAndStateMachine.first;
			state_machine const & sm = nameAndStateMachine.second;
			std::pair<std::map<std::string, state_machine>::iterator, bool> emplaceResult;
			if (sm.get_filter() != nullptr) {
				emplaceResult = productions.emplace(
					std::piecewise_construct,
					forward_as_tuple(name),
					forward_as_tuple(name, sm.get_start_state(), sm.get_accept_state_count(), sm.get_filter(), sm.get_associativity()));
			}
			else {
				emplaceResult = productions.emplace(
					std::piecewise_construct,
					forward_as_tuple(name),
					forward_as_tuple(name, sm.get_accept_state_count(), sm.get_associativity()));
			}
			recognizersMap[static_cast<recognizer const *>(&sm)] = static_cast<recognizer const *>(&emplaceResult.first->second);
		}

		for (auto const & nameAndStateMachine : other.productions) {
			state_machine const & sm = nameAndStateMachine.second;
			state_machine & outProduction = productions.find(nameAndStateMachine.first)->second;
			state_machine::states_t const & othersStates = sm.get_states();
			for (unsigned int j = 0; j < othersStates.size(); ++j) {
				for (auto const & symbolAndToState : othersStates[j]) {
					recognizer const * mappedSymbol = &symbolAndToState.first.get();
					if (recognizersMap.count(mappedSymbol) == 1) {
						mappedSymbol = recognizersMap[mappedSymbol];
					}
					outProduction.add_transition(j, *mappedSymbol, symbolAndToState.second);
				}
			}
		}
	}

	state_machine const & grammar::get_main_production() const {
		auto i = productions.find(main_production_name);
		assert(i != productions.end());
		return i->second;
	}

	std::map<std::string, state_machine> const & grammar::get_productions() const {
		return productions;
	}

	builtins::string_terminal & grammar::add_literal(std::u32string contents) {
		auto result = literals.emplace(std::piecewise_construct, forward_as_tuple(contents), forward_as_tuple(contents));
		if (!result.second) {
			throw "literal already added.";
		}
		return result.first->second;
	}

	void grammar::add_precedence(state_machine const & productionA, state_machine const & productionB)
	{
		assert(productions.find(productionA.get_id()) != productions.end());
		assert(productions.find(productionB.get_id()) != productions.end());
		precedences[&productionA].insert(&productionB);
	}

	bool grammar::test_precedence(state_machine const & productionA, state_machine const & productionB) const
	{
		auto i = precedences.find(&productionA);
		if (i == precedences.end()) {
			return false;
		}
		return i->second.count(&productionB) > 0;
	}

	precedence_collection const & grammar::get_precedences() const
	{
		return precedences;
	}

	std::map<std::u32string, builtins::string_terminal> const & grammar::get_literals() const
	{
		return literals;
	}

	state_machine & grammar::add_production(std::string id, size_t startState, size_t acceptStateCount, associativity assoc) {
		return productions.emplace(std::piecewise_construct, forward_as_tuple(id), forward_as_tuple(id, startState, acceptStateCount, assoc)).first->second;
	}

	state_machine & grammar::add_production(std::string id, size_t startState, size_t acceptStateCount, filter_function const * filter, associativity assoc) {
		return productions.emplace(std::piecewise_construct, forward_as_tuple(id), forward_as_tuple(id, startState, acceptStateCount, filter, assoc)).first->second;
	}

void print_sorted_lines(std::ostream & os, std::string lines) {
	std::stringstream ss(lines);
	std::string to;
	std::vector<std::string> splitLines;
	while (getline(ss, to, '\n')) {
		splitLines.push_back(to);
	}
	sort(splitLines.begin(), splitLines.end());
	for (std::string const & s : splitLines) {
		os << s << '\n';
	}
}

void grammar::generate_cpp(std::string grammarName, std::string nameOfMain, std::ostream & cpp, std::ostream & hpp, std::string headerPath) const {
	hpp << "/************ This file was generated by parlex ************/\n";
	hpp << "\n";
	hpp << "#ifndef " << grammarName << "_GRAMMAR_HPP\n";
	hpp << "#define " << grammarName << "_GRAMMAR_HPP\n";
	hpp << "\n";
	hpp << "#include \"parlex/grammar.hpp\"\n";
	hpp << "#include \"parlex/builtins.hpp\"\n";
	hpp << "\n";
	hpp << "parlex::grammar const & get_" << grammarName << "();\n";
	hpp << "\n";
	hpp << "#endif\n";

	std::map<recognizer const *, std::string> recognizerToStringMap;
	std::set<std::string> sortedBuiltInNames;
	for (auto const & entry : builtins::get_builtins_table()) {
		sortedBuiltInNames.insert(entry.first);
	}
	for (std::string const & name : sortedBuiltInNames) {
		auto const & entry = builtins::get_builtins_table().find(name);
		recognizerToStringMap[entry->second] = "parlex::builtins::" + entry->first;
	}

	// start with a BOM for sanity's sake
	cpp << "\xEF\xBB\xBF/************ This file was generated by parlex ************/\n";
	cpp << "\n";
	cpp << "#include \"" << headerPath << grammarName << "_grammar.hpp\"\n";
	cpp << "#include \"one_shot.hpp\"\n";
	cpp << "\n";
	cpp << "parlex::grammar const & get_" << grammarName << "() {\n";
	cpp << "\tstatic parlex::grammar g(" << enquote(nameOfMain) << ");\n";
	cpp << "\n";

	int i = 0;
	std::map<std::u32string, builtins::string_terminal const *> contentToLiterals;
	std::vector<std::u32string> sortedContentStrings;
	for (auto const & entry : literals) {
		contentToLiterals[entry.second.get_content()] = &entry.second;
	}
	for (auto const & entry : contentToLiterals) {
		sortedContentStrings.push_back(entry.first);
	}
	sort(sortedContentStrings.begin(), sortedContentStrings.end());
	for (std::u32string content : sortedContentStrings) {
		builtins::string_terminal const & literal = *contentToLiterals[content];
		std::ostringstream nameStream;
		nameStream << "literal" << i;
		cpp << "\tstatic parlex::builtins::string_terminal & " << nameStream.str() << " = g.add_literal(U" << enquote(to_utf8(literal.get_content())) << ");\n";
		recognizerToStringMap[static_cast<recognizer const *>(&literal)] = nameStream.str();
		i++;
	}
	for (auto const & entry : literals) {
		builtins::string_terminal const & chosenLiteral = *contentToLiterals[entry.second.get_content()];
		std::string chosenName = recognizerToStringMap[static_cast<recognizer const *>(&chosenLiteral)];
		recognizerToStringMap[static_cast<recognizer const *>(&entry.second)] = chosenName;
	}
	cpp << "\n";

	for (auto const & production : productions) {
		std::string const & id = production.first;
		state_machine const & sm = production.second;
		std::string associativityString = "parlex::associativity::";
		switch (sm.get_associativity()) {
		case none:
			associativityString += "none";
			break;
		case any:
			associativityString += "any";
			break;
		case left:
			associativityString += "left";
			break;
		case right:
			associativityString += "right";
			break;
		}
		if (sm.get_filter() == &builtins::greedy) {
			cpp << "\tstatic parlex::state_machine & " << id << " = g.add_production(\"" << id << "\", " << sm.get_start_state() << ", " << sm.get_accept_state_count() << ", &parlex::builtins::greedy, " << associativityString << ");\n";
		} else if (sm.get_filter() == &builtins::super_delimiter) {
			cpp << "\tstatic parlex::state_machine & " << id << " = g.add_production(\"" << id << "\", " << sm.get_start_state() << ", " << sm.get_accept_state_count() << ", &parlex::builtins::super_delimiter, " << associativityString << ");\n";
		} else {
			cpp << "\tstatic parlex::state_machine & " << id << " = g.add_production(\"" << id << "\", " << sm.get_start_state() << ", " << sm.get_accept_state_count() << ", " << associativityString << ");\n";
		}
		recognizerToStringMap[static_cast<recognizer const *>(&sm)] = id;
	}
	cpp << "\n";

	cpp << "\tstatic one_shot oneShot;\n";
	cpp << "\toneShot.go([&](){\n";

	for (auto const & production : productions) {
		std::stringstream buffer;
		buffer << "\n";
		std::string const & id = production.first;
		state_machine const & sm = production.second;
		auto const states = sm.get_states();
		for (unsigned int j = 0; j < states.size(); ++j) {
			auto const & state = states[j];
			for (auto const & transitionAndToState : state) {
				recognizer const & transition = transitionAndToState.first;
				auto const & toState = transitionAndToState.second;
				buffer << "\t\t" << id << ".add_transition(" << j << ", " << recognizerToStringMap[const_cast<recognizer *>(&transition)] << ", " << toState << ");\n";
			}
		}
		print_sorted_lines(cpp, buffer.str());
	}

	std::stringstream buffer;
	if (precedences.size() > 0) {
		buffer << "\n";
		for (decltype(precedences)::value_type const & leftAndRights : precedences) {
			for (auto const & right : leftAndRights.second) {
				buffer << "\n";
				buffer << "\t\tg.add_precedence(" << leftAndRights.first->get_id() << ", " << right->get_id() << ");";
			}
		}
	}
	print_sorted_lines(cpp, buffer.str());

	cpp << "\t});\n";
	cpp << "\n";
	cpp << "\treturn g;\n";
	cpp << "}\n";
	cpp << "\n";
}

}
