#include "parlex/detail/state_machine.hpp"

#include "parlex/associativity.hpp"
#include "parlex/builder.hpp"

namespace parlex {
namespace detail {

state_machine::state_machine(std::string const & name, filter_function const & filter, associativity const assoc) : state_machine_base(name), filter(filter), assoc(assoc), behavior(nullptr), start_state(-1), accept_state_count(-1) {
}

void state_machine::set_behavior(std::map<recognizer const *, size_t> const & recognizerLookup, node & behavior) {
	this->behavior = &behavior;
	auto dfa = reorder(behavior.compile());
	auto transitions = dfa.get_transitions();
	for (auto const & t : transitions) {
		while (states.size() <= t.to || states.size() <= t.from) {
			states.emplace_back();
		}
		transition_info_t transitionInfo;
		transitionInfo.l = t.symbol;
		transitionInfo.recognizer_index = t.symbol->recognizer_index;
		states[t.from][transitionInfo] = t.to;
	}
	start_state = *dfa.start_states.begin();
	accept_state_count = dfa.accept_states.size();
}

void state_machine::process(job & j, producer_id_t subjobId, subjob & sj, context const & c, size_t const dfaState) const {
	//DBG("processing '", get_id(), "' dfaState:", dfaState, " p:", c.current_document_position());
	if (dfaState >= states.size() - accept_state_count) {
		accept(j, sj, subjobId, c);
	}
	for (auto const & kvp : states[dfaState]) {
		auto const & transitionInfo = kvp.first;
		int const nextState = kvp.second;
		//DBG("'", get_id(), "' state ", dfaState, " position ", c.current_document_position(), " subscribes to '", transition.name, "' position ", c.current_document_position());
		on(j, transitionInfo.recognizer_index, subjobId, sj, c, nextState, transitionInfo.l);
	}
}

automaton state_machine::reorder(automaton const & dfa) {
	//construct a map from dfa states to reordered states
	std::map<size_t, size_t> stateMap;
	auto const startState = *dfa.start_states.begin();
	auto const startIsAccept = dfa.accept_states.count(startState) > 0;
	if (!startIsAccept) {
		stateMap[*dfa.start_states.begin()] = 0;
	}
	for (size_t i = 0; i < dfa.states.size(); ++i) {
		//all the un-added non-accept states
		if (i != startState && dfa.accept_states.count(i) == 0) {
			stateMap[i] = stateMap.size();
		}
	}
	if (startIsAccept) {
		stateMap[*dfa.start_states.begin()] = stateMap.size();
	}
	for (size_t i = 0; i < dfa.states.size(); ++i) {
		//all the unadded accept states
		if (i != startState && dfa.accept_states.count(i) > 0) {
			stateMap[i] = stateMap.size();
		}
	}

	//it's a bimap, construct reverse lookup
	std::map<size_t, size_t> stateMapDual;
	for (auto const & i : stateMap) {
		stateMapDual[i.second] = i.first;
	}

	//construct the reordered dfa
	automaton reordered;
	auto const firstAcceptState = dfa.states.size() - dfa.accept_states.size();
	for (size_t i = 0; i < dfa.states.size(); ++i) {
		auto const dual = stateMapDual[i];
		auto const & dfaState = dfa.states[dual];
		reordered.add_state(i, i >= firstAcceptState, dual == startState);
		auto & reorderedState = reordered.states[i];
		for (auto outTransition : dfaState.out_transitions) {
			reorderedState.out_transitions[outTransition.first] = { stateMap[*outTransition.second.begin()] };
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

std::string state_machine::to_dot(std::vector<recognizer const *> const & recognizers) const {
	std::vector<size_t> stateInts;
	for (size_t i = 0; i < states.size(); ++i) {
		stateInts.push_back(i);
	}

	auto const getName = [&](size_t const & i) { return std::to_string(i); };

	auto const getEdges = [&](size_t const & i) {
		std::vector<std::pair<std::string, size_t>> edges;
		for (auto const & edge : states[i]) {
			auto transitionInfo = edge.first;
			int toState = edge.second;
			auto const & recognizer = *recognizers[transitionInfo.recognizer_index];
			std::stringstream ss;
			ss << transitionInfo.l;
			edges.push_back(make_pair("label=" + enquote(recognizer.name + " (" + ss.str() + ")"), toState));
		}
		return edges;
	};

	auto const getProperties = [&](size_t const & i) {
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

	return directed_graph<size_t>(stateInts, getName, getEdges, getProperties);

}

} // namespace detail
} // namespace parlex
