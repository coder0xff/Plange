#include "parlex/grammar.hpp"

#include <cassert>
#include <iostream>
#include <sstream>

#include "parlex/builtins.hpp"
#include "parlex/details/behavior.hpp"
#include "parlex/details/utils.hpp"

namespace parlex {

grammar::grammar(std::string nameOfMain) : main_production_name(nameOfMain) {}

grammar::grammar(std::string nameOfMain, std::map<std::string, std::shared_ptr<details::behavior_node>> const & trees, std::set<std::string> greedyNames) : main_production_name(nameOfMain)
{
	std::map<std::string, details::intermediate_nfa> intermediate_nfas;
	for (auto const & nameAndBehaviorNode : trees) {
		auto temp = nameAndBehaviorNode.second->to_intermediate_nfa().minimal_dfa().relabel();
		intermediate_nfas[nameAndBehaviorNode.first] = temp;
		std::string check = parlex::details::to_dot(temp);
	}

	assert(intermediate_nfas.count(main_production_name) == 1);

	std::map<std::u32string, builtins::string_terminal *> literalsMap;

	for (auto const & nameAndIntermediateNfa : intermediate_nfas) {
        std::string const & name = nameAndIntermediateNfa.first;
        details::intermediate_nfa const & intermediate_nfa = nameAndIntermediateNfa.second;
		if (greedyNames.count(name) > 0) {
			productions.emplace(std::piecewise_construct, std::forward_as_tuple(name), std::forward_as_tuple(name, intermediate_nfa.acceptStates.size(), builtins::greedy));
		} else {
			productions.emplace(std::piecewise_construct, std::forward_as_tuple(name), std::forward_as_tuple(name, intermediate_nfa.acceptStates.size()));
		}
	}

	for (auto const & nameAndIntermediateNfa : intermediate_nfas) {
        std::string const & name = nameAndIntermediateNfa.first;
        details::intermediate_nfa const & intermediate_nfa = nameAndIntermediateNfa.second;
		std::map<int, int> stateMap;
		stateMap[*intermediate_nfa.startStates.begin()] = 0;
		for (unsigned int i = 0; i < intermediate_nfa.states.size(); ++i) {
			if (intermediate_nfa.startStates.count(i) > 0 || intermediate_nfa.acceptStates.count(i) > 0) {
				continue;
			}
			stateMap[i] = stateMap.size();
		}
		for (unsigned int i = 0; i < intermediate_nfa.states.size(); ++i) {
			if (intermediate_nfa.acceptStates.count(i) > 0 && intermediate_nfa.startStates.count(i) == 0) {
				stateMap[i] = stateMap.size();
			}
		}
		state_machine & sm = productions.find(name)->second;
		auto transitions = intermediate_nfa.get_transitions();
        for (auto const & t : transitions) {
            recognizer const & r = t.symbol->get_recognizer(productions, literals, literalsMap);
            sm.add_transition(stateMap[t.from], r, stateMap[t.to]);
        }
	}
}

grammar::grammar(grammar const & other) : main_production_name(other.main_production_name), literals(other.literals) {
	std::map<recognizer const *, recognizer const *> recognizersMap;
	for (std::list<parlex::builtins::string_terminal>::const_iterator i = other.literals.begin(), j = literals.begin(); j != literals.end();) {
		recognizersMap[(recognizer *)&(*i)] = (recognizer *)&(*j);
	}

    for (auto const & nameAndStateMachine : other.productions) {
        auto emplaceResult = productions.emplace(
                std::piecewise_construct,
                std::forward_as_tuple(nameAndStateMachine.first),
                std::forward_as_tuple(nameAndStateMachine.first, nameAndStateMachine.second.get_accept_state_count()));
        recognizersMap[(recognizer *)&nameAndStateMachine.second] = (recognizer *)&(emplaceResult.first->second);
    }

	for (auto const & nameAndStateMachine : other.productions) {
		state_machine & outProduction = productions.find(nameAndStateMachine.first)->second;
		state_machine::states_t const & othersStates = nameAndStateMachine.second.get_states();
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

state_machine & grammar::add_production(std::string id, size_t acceptStateCount) {
	return productions.emplace(std::piecewise_construct, std::forward_as_tuple(id), std::forward_as_tuple(id, acceptStateCount)).first->second;
}

state_machine & grammar::add_production(std::string id, size_t acceptStateCount, filter_function const & filter) {
	return productions.emplace(std::piecewise_construct, std::forward_as_tuple(id), std::forward_as_tuple(id, acceptStateCount, filter)).first->second;
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
			cpp << "\tstatic parlex::state_machine & " << id << " = g.add_production(\"" << id << "\", " << sm.get_accept_state_count() << ", parlex::builtins::greedy);\n";
		} else {
			cpp << "\tstatic parlex::state_machine & " << id << " = g.add_production(\"" << id << "\", " << sm.get_accept_state_count() << ");\n";
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
