#include "parlex/state_machine.hpp"

#include <algorithm>

#include "parlex/details/context.hpp"
#include "parlex/details/subjob.hpp"

namespace parlex {

state_machine::state_machine(std::string id, size_t startState, size_t acceptStateCount, associativity assoc) :
	state_machine_base(id, startState, assoc),
	accept_state_count(acceptStateCount)
{}

state_machine::state_machine(std::string id, size_t startState, size_t acceptStateCount, filter_function const & filter, associativity assoc) :
	state_machine_base(id, startState, filter, assoc),
	accept_state_count(acceptStateCount)
{}

void state_machine::process(details::context_ref const & c, size_t const s) const {
	//DBG("processing '", get_id(), "' s:", s, " p:", c.current_document_position());
	if (s >= states.size() - accept_state_count) {
		accept(c);
	}
	for (auto const & kvp : states[s]) {
		recognizer const & transition = kvp.first;
		int const next_state = kvp.second;
		//DBG("'", get_id(), "' state ", s, " position ", c.current_document_position(), " subscribes to '", transition.id, "' position ", c.current_document_position());
		on(c, transition, next_state);
	}
}

void state_machine::add_transition(size_t fromState, recognizer const & recognizer, size_t toState) {
	size_t impliedStateCount = std::max(fromState, toState) + 1;
	while (states.size() < impliedStateCount) {
		states.emplace_back();
	}
	if (!states[fromState].insert(states_t::value_type::value_type(recognizer, toState)).second) {
		throw std::logic_error("duplicate key");
	}
}

state_machine::states_t state_machine::get_states() const {
	return states;
}

}
