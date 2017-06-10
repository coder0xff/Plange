#include "parlex/state_machine2.hpp"

#include "parlex/associativity.hpp"

namespace parlex {

state_machine2::state_machine2(std::string id, behavior2::nfa const & dfa, filter_function const & filter, associativity assoc) : state_machine_base2(id), filter(filter), assoc(assoc), start_state(-1), accept_state_count(-1) {
	behavior2::nfa reordered = reorder(dfa);
	auto transitions = dfa.get_transitions();
	for (auto const & t : transitions) {
		behavior2::leaf const * r = t.symbol;
		states[t.from][r] = t.to;
	}
	start_state = *reordered.startStates.begin();
	accept_state_count = reordered.acceptStates.size();
}

state_machine2::state_machine2(std::string id, behavior2::nfa const & dfa, associativity assoc) : state_machine2(id, dfa, filter_function(), assoc) {}

void state_machine2::process(details::context_ref const & c, size_t const s) const {
	//DBG("processing '", get_id(), "' s:", s, " p:", c.current_document_position());
	if (s >= states.size() - accept_state_count) {
		accept(c);
	}
	for (auto const & kvp : states[s]) {
		behavior2::leaf const * transition = kvp.first;
		int const next_state = kvp.second;
		//DBG("'", get_id(), "' state ", s, " position ", c.current_document_position(), " subscribes to '", transition.id, "' position ", c.current_document_position());
		on(c, transition, next_state);
	}
}

behavior2::nfa state_machine2::reorder(behavior2::nfa const & original) {
	behavior2::nfa dfa = original.minimal_dfa().relabel();
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
	behavior2::nfa reordered;
	unsigned int firstAcceptState = dfa.states.size() - dfa.acceptStates.size();
	for (unsigned int i = 0; i < dfa.states.size(); ++i) {
		unsigned int const dual = stateMapDual[i];
		behavior2::nfa::state const & dfa_state = dfa.states[dual];
		reordered.add_state(i, i >= firstAcceptState, dual == startState);
		behavior2::nfa::state & reordered_state = reordered.states[i];
		for (auto out_transition : dfa_state.out_transitions) {
			reordered_state.out_transitions[out_transition.first] = { stateMap[*out_transition.second.begin()] };
		}
	}
	return reordered;
}

bool state_machine2::is_terminal() const {
	return false;
}

int state_machine2::get_start_state() const {
	return start_state;
}

filter_function state_machine2::get_filter() const {
	return filter;
}

associativity state_machine2::get_assoc() const {
	return assoc;
}

}
