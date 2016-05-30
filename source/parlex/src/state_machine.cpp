#include <algorithm>

#include "parlex/details/context.hpp"
#include "logging.hpp"
#include "parlex/state_machine.hpp"
#include "parlex/details/subjob.hpp"

namespace parlex {

state_machine::state_machine(std::string id, size_t startState, size_t acceptStateCount, associativity assoc) :
	id(id),
	start_state(startState),
	accept_state_count(acceptStateCount),
	filter(nullptr),
	assoc(assoc)
{}

state_machine::state_machine(std::string id, size_t startState, size_t acceptStateCount, filter_function const & filter, associativity assoc) :
	id(id),
	start_state(startState),
	accept_state_count(acceptStateCount),
	filter(&filter),
	assoc(assoc)
{}

void state_machine::start(details::subjob & sj, size_t const documentPosition) const {
	process(sj.construct_start_state_context(documentPosition), start_state);
}

void state_machine::process(details::context_ref const & c, size_t const s) const {
	//DBG("processing '", get_id(), "' s:", s, " p:", c.current_document_position());
	if (s >= states.size() - accept_state_count) {
		c.owner().accept(c);
	}
	for (auto const & kvp : states[s]) {
		recognizer const & transition = kvp.first;
		int const next_state = kvp.second;
		//DBG("'", get_id(), "' state ", s, " position ", c.current_document_position(), " subscribes to '", transition.get_id(), "' position ", c.current_document_position());
		c.owner().on(c, transition, next_state);
	}
}

std::string state_machine::get_id() const {
	return id;
}

size_t state_machine::get_start_state() const {
	return start_state;
}

size_t state_machine::get_accept_state_count() const {
    return accept_state_count;
}

filter_function const * state_machine::get_filter() const {
	return filter;
}

associativity state_machine::get_associativity() const {
	return assoc;
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
