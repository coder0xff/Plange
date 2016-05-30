#include "parlex/grammar.hpp"

#include <cassert>
#include <iostream>
#include <sstream>

#include "parlex/builtins.hpp"
#include "parlex/details/behavior.hpp"
#include "utils.hpp"

namespace parlex {

grammar::grammar(std::string nameOfMain) : main_production_name(nameOfMain) {}

grammar::grammar(std::string nameOfMain, std::map<std::string, std::shared_ptr<details::behavior_node>> const & trees, std::set<std::string> greedyNames) : main_production_name(nameOfMain)
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
		int startState = *dfa.startStates.begin();
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
		for (auto const & i: stateMap) {
			stateMapDual[i.second] = i.first;
		}

		//construct the reordered dfa
		details::intermediate_nfa reordered;
		unsigned int firstAcceptState = dfa.states.size() - dfa.acceptStates.size();
		for (unsigned int i = 0; i < dfa.states.size(); ++i) {
			int const dual = stateMapDual[i];
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
		if (greedyNames.count(name) > 0) {
			productions.emplace(std::piecewise_construct, std::forward_as_tuple(name), std::forward_as_tuple(name, *dfa.startStates.begin(), dfa.acceptStates.size(), builtins::greedy));
		} else {
			productions.emplace(std::piecewise_construct, std::forward_as_tuple(name), std::forward_as_tuple(name, *dfa.startStates.begin(), dfa.acceptStates.size()));
		}
	}

	//add transitions, linking productions
	for (auto const & nameAndDfa : reorderedDfas) {
        std::string const & name = nameAndDfa.first;
        details::intermediate_nfa const & dfa = nameAndDfa.second;
		state_machine & sm = productions.find(name)->second;
		auto transitions = dfa.get_transitions();
		std::map<std::u32string, builtins::string_terminal *> literalsMap;
        for (auto const & t : transitions) {
            recognizer const & r = t.symbol->get_recognizer(productions, literals, literalsMap);
            sm.add_transition(t.from, r, t.to);
        }
	}
}

grammar::grammar(grammar const & other) : main_production_name(other.main_production_name), literals(other.literals) {
	std::map<recognizer const *, recognizer const *> recognizersMap;
	for (std::list<parlex::builtins::string_terminal>::const_iterator i = other.literals.begin(), j = literals.begin(); j != literals.end();) {
		recognizersMap[(recognizer *)&(*(i++))] = (recognizer *)&(*(j++));
	}

    for (auto const & nameAndStateMachine : other.productions) {
		std::string name = nameAndStateMachine.first;
		state_machine const & sm = nameAndStateMachine.second;
		std::pair<std::map<std::string, state_machine>::iterator, bool> emplaceResult;
		if (sm.get_filter() != nullptr) {
			emplaceResult = productions.emplace(
				std::piecewise_construct,
				std::forward_as_tuple(name),
				std::forward_as_tuple(name, sm.get_start_state(), sm.get_accept_state_count(), *sm.get_filter(), sm.get_associativity()));
		}
		else {
			emplaceResult = productions.emplace(
				std::piecewise_construct,
				std::forward_as_tuple(name),
				std::forward_as_tuple(name, sm.get_accept_state_count(), sm.get_associativity()));
		}
		recognizersMap[(recognizer *)&sm] = (recognizer *)&(emplaceResult.first->second);
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
	literals.emplace_back(contents);
	return literals.back();
}

state_machine & grammar::add_production(std::string id, size_t startState, size_t acceptStateCount, associativity assoc) {
	return productions.emplace(std::piecewise_construct, std::forward_as_tuple(id), std::forward_as_tuple(id, startState, acceptStateCount, assoc)).first->second;
}

state_machine & grammar::add_production(std::string id, size_t startState, size_t acceptStateCount, filter_function const & filter, associativity assoc) {
	return productions.emplace(std::piecewise_construct, std::forward_as_tuple(id), std::forward_as_tuple(id, startState, acceptStateCount, filter, assoc)).first->second;
}

void grammar::generate_cpp(std::string grammarName, std::string nameOfMain, std::ostream & cpp, std::ostream & hpp) const {
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

	std::map<recognizer *, std::string> recognizerToStringMap;
	for (auto const & entry : builtins::get_builtins_table()) {
		recognizerToStringMap[entry.second] = "parlex::builtins::" + entry.first;
	}

	cpp << "/************ This file was generated by parlex ************/\n";
	cpp << "\n";
	cpp << "#include \"" << grammarName << "_grammar.hpp\"\n";
	cpp << "\n";
	cpp << "parlex::grammar const & get_" << grammarName << "() {\n";
	cpp << "\tstatic parlex::grammar g(" << enquote(nameOfMain) << ");\n";
	cpp << "\n";

	int i = 0;
	for (parlex::builtins::string_terminal const & literal : literals) {
		std::ostringstream nameStream;
		nameStream << "literal" << i;
		cpp << "\tstatic parlex::builtins::string_terminal & " << nameStream.str() << " = g.add_literal(U" << enquote(to_utf8(literal.get_content())) << ");\n";
		recognizerToStringMap[(recognizer *)&literal] = nameStream.str();
		i++;
	}
	cpp << "\n";

	for (auto const & production : productions) {
		std::string const & id = production.first;
		state_machine const & sm = production.second;
		if (sm.get_filter() == &builtins::greedy) {
			cpp << "\tstatic parlex::state_machine & " << id << " = g.add_production(\"" << id << "\", " << sm.get_start_state() << ", " << sm.get_accept_state_count() << ", parlex::builtins::greedy);\n";
		} else {
			cpp << "\tstatic parlex::state_machine & " << id << " = g.add_production(\"" << id << "\", " << sm.get_start_state() << ", " << sm.get_accept_state_count() << ");\n";
		}
		recognizerToStringMap[(recognizer *)&sm] = id;
	}
	cpp << "\n";

	cpp << "\tstatic bool initialized = false;\n";
	cpp << "\tif (!initialized) {\n";
	cpp << "\t\tinitialized = true;\n";

	for (auto const & production : productions) {
		cpp << "\n";
		std::string const & id = production.first;
		state_machine const & sm = production.second;
		auto const states = sm.get_states();
		for (unsigned int i = 0; i < states.size(); ++i) {
			auto const & state = states[i];
			for (auto const & transitionAndToState : state) {
				recognizer const & transition = transitionAndToState.first;
				auto const & toState = transitionAndToState.second;
				cpp << "\t\t" << id << ".add_transition(" << i << ", " << recognizerToStringMap[const_cast<recognizer *>(&transition)] << ", " << toState << ");\n";
			}
		}
	}

	cpp << "\t}\n";
	cpp << "\n";
	cpp << "\treturn g;\n";
	cpp << "}\n";
	cpp << "\n";
}

}
