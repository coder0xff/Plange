#include "parlex/correlated_state_machine.hpp"

#include "parlex/associativity.hpp"
#include "parlex/behavior.hpp"

namespace parlex {

correlated_state_machine::correlated_state_machine(std::string const & id, filter_function const & filter, associativity assoc) : state_machine_base(id), filter(filter), assoc(assoc), behavior(nullptr), start_state(-1), accept_state_count(-1) {
}

void correlated_state_machine::set_behavior(behavior::node const & behavior) {
	static_assert(std::is_same_v<behavior::nfa2, details::nfa<behavior::leaf const *, int>>, "these should be the same");
	this->behavior = &behavior;
	behavior::nfa2 dfa = reorder(behavior.compile());
	auto check = nfa2_to_dot(dfa); //todo: disable debug code
	auto transitions = dfa.get_transitions();
	for (auto const & t : transitions) {
		while (states.size() <= t.to || states.size() <= t.from) {
			states.emplace_back();
		}
		states[t.from][t.symbol] = t.to;
	}
	start_state = *dfa.startStates.begin();
	accept_state_count = dfa.acceptStates.size();
}

void correlated_state_machine::process(details::context_ref const & c, size_t const s) const {
	//DBG("processing '", get_id(), "' s:", s, " p:", c.current_document_position());
	if (s >= states.size() - accept_state_count) {
		accept(c);
	}
	for (auto const & kvp : states[s]) {
		behavior::leaf const & transition = *kvp.first;
		int const next_state = kvp.second;
		recognizer const & r = transition.r;
		//DBG("'", get_id(), "' state ", s, " position ", c.current_document_position(), " subscribes to '", transition.id, "' position ", c.current_document_position());
		on(c, r, next_state, &transition);
	}
}

behavior::nfa2 correlated_state_machine::reorder(behavior::nfa2 const & original) {
	behavior::nfa2 dfa = original.minimal_dfa().map_to_ints();
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
	behavior::nfa2 reordered;
	unsigned int firstAcceptState = dfa.states.size() - dfa.acceptStates.size();
	for (unsigned int i = 0; i < dfa.states.size(); ++i) {
		unsigned int const dual = stateMapDual[i];
		behavior::nfa2::state const & dfa_state = dfa.states[dual];
		reordered.add_state(i, i >= firstAcceptState, dual == startState);
		behavior::nfa2::state & reordered_state = reordered.states[i];
		for (auto out_transition : dfa_state.out_transitions) {
			reordered_state.out_transitions[out_transition.first] = {stateMap[*out_transition.second.begin()]};
		}
	}
	return reordered;
}

bool correlated_state_machine::is_terminal() const {
	return false;
}

int correlated_state_machine::get_start_state() const {
	return start_state;
}

filter_function correlated_state_machine::get_filter() const {
	return filter;
}

associativity correlated_state_machine::get_assoc() const {
	return assoc;
}

std::string correlated_state_machine::to_dot() const {
	std::vector<size_t> stateInts;
	for (size_t i = 0; i < states.size(); ++i) {
		stateInts.push_back(i);
	}

	auto get_name = [&](size_t const & i) { return std::to_string(i); };

	auto get_edges = [&](size_t const & i) {
		std::vector<std::pair<std::string, size_t>> edges;
		for (auto const & edge : states[i]) {
			behavior::leaf const * leaf = edge.first;
			int toState = edge.second;
			edges.push_back(make_pair("label=" + leaf->id, toState));
		}
		return edges;
	};

	auto get_properties = [&](size_t const & i) {
		std::string nodeProperties;
		if (i == start_state) {
			nodeProperties = "color=red";
		}
		if (i >= states.size() - accept_state_count) {
			if (!nodeProperties.empty()) {
				nodeProperties += ", ";
			}
			nodeProperties += "shape=doublecircle";
		}
		return nodeProperties;
	};

	return directed_graph<size_t>(stateInts, get_name, get_edges, get_properties);
	                      
}
} // namespace parlex
