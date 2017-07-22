#include "parlex/details/state_machine.hpp"

#include "parlex/associativity.hpp"

#include "parlex/details/behavior.hpp"

namespace parlex {
namespace details {

state_machine::state_machine(std::string const & id, filter_function const & filter, associativity assoc) : state_machine_base(id), filter(filter), assoc(assoc), behavior(nullptr), start_state(-1), accept_state_count(-1) {
}

void state_machine::set_behavior(behavior::node const & behavior) {
	static_assert(std::is_same_v<behavior::nfa2, details::nfa<behavior::leaf const *, size_t>>, "these should be the same");
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

void state_machine::process(details::context_ref const & c, size_t const s) const {
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

behavior::nfa2 state_machine::reorder(behavior::nfa2 dfa) {
	//construct a map from dfa states to reordered states
	std::string check = nfa2_to_dot(dfa); //todo: disable debug code
	std::map<size_t, size_t> stateMap;
	size_t startState = *dfa.startStates.begin();
	bool startIsAccept = dfa.acceptStates.count(startState) > 0;
	if (!startIsAccept) {
		stateMap[*dfa.startStates.begin()] = 0;
	}
	for (size_t i = 0; i < dfa.states.size(); ++i) {
		//all the un-added non-accept states
		if (i != startState && dfa.acceptStates.count(i) == 0) {
			stateMap[i] = stateMap.size();
		}
	}
	if (startIsAccept) {
		stateMap[*dfa.startStates.begin()] = stateMap.size();
	}
	for (size_t i = 0; i < dfa.states.size(); ++i) {
		//all the un-added accept states
		if (i != startState && dfa.acceptStates.count(i) > 0) {
			stateMap[i] = stateMap.size();
		}
	}

	//it's a bimap, construct reverse lookup
	std::map<size_t, size_t> stateMapDual;
	for (auto const & i : stateMap) {
		stateMapDual[i.second] = i.first;
	}

	//construct the reordered dfa
	behavior::nfa2 reordered;
	size_t firstAcceptState = dfa.states.size() - dfa.acceptStates.size();
	for (size_t i = 0; i < dfa.states.size(); ++i) {
		size_t const dual = stateMapDual[i];
		behavior::nfa2::state const & dfa_state = dfa.states[dual];
		reordered.add_state(i, i >= firstAcceptState, dual == startState);
		behavior::nfa2::state & reordered_state = reordered.states[i];
		for (auto out_transition : dfa_state.out_transitions) {
			reordered_state.out_transitions[out_transition.first] = { stateMap[*out_transition.second.begin()] };
		}
	}
	return reordered;
}

bool state_machine::is_terminal() const {
	return false;
}

int state_machine::get_start_state() const {
	return start_state;
}

filter_function state_machine::get_filter() const {
	return filter;
}

associativity state_machine::get_assoc() const {
	return assoc;
}

std::string state_machine::to_dot() const {
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

} // namespace details
} // namespace parlex
