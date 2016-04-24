#include "parlex/grammar.hpp"

#include <cassert>
#include <iostream>

#include "parlex/details/behavior.hpp"

namespace parlex {

grammar::grammar(std::string nameOfMain, std::map<std::string, std::shared_ptr<details::behavior_node>> const & trees) : main_production_name(nameOfMain)
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
        productions.emplace(std::piecewise_construct, std::forward_as_tuple(name), std::forward_as_tuple(name, intermediate_nfa.acceptStates.size()));
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
			if (intermediate_nfa.acceptStates.count(i) > 0) {
				stateMap[i] = stateMap.size();
			}
		}
		state_machine & sm = productions.find(name)->second;
		auto transitions = intermediate_nfa.get_transitions();
        for (auto const & t : transitions) {
            recognizer const & r = t.symbol->get_recognizer(productions, literals, literalsMap);
			if (dynamic_cast<state_machine const *>(&r) != nullptr)
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

}
