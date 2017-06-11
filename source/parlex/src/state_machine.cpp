#include "parlex/state_machine.hpp"

#include "parlex/associativity.hpp"
#include "parlex/behavior2.hpp"

namespace parlex {

state_machine::state_machine(std::string const & id, int startState, int acceptStateCount, filter_function const & filter, associativity assoc) : state_machine_base2(id), start_state(startState), accept_state_count(acceptStateCount), filter(filter), assoc(assoc) {
}

state_machine::state_machine(std::string const & id, filter_function const & filter, associativity assoc) : state_machine_base2(id), filter(filter), assoc(assoc), start_state(-1), accept_state_count(-1) {
}

state_machine::state_machine(std::string const & id, associativity assoc) : state_machine(id, filter_function(), assoc) {
}

void state_machine::process(details::context_ref const & c, size_t const s) const {
	//DBG("processing '", get_id(), "' s:", s, " p:", c.current_document_position());
	if (s >= states.size() - accept_state_count) {
		accept(c);
	}
	for (auto const & kvp : states[s]) {
		recognizer const & r = *kvp.first;
		int const next_state = kvp.second;
		//DBG("'", get_id(), "' state ", s, " position ", c.current_document_position(), " subscribes to '", transition.id, "' position ", c.current_document_position());
		on(c, r, next_state, nullptr);
	}
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

} // namespace state_machine
