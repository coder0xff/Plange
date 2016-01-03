#include <algorithm>

#include "parlex/details/context.hpp"
#include "parlex/details/logging.hpp"
#include "parlex/state_machine.hpp"
#include "parlex/details/subjob.hpp"

namespace parlex {

state_machine::state_machine(std::string id, size_t acceptStateCount) :
	id(id),
	accept_state_count(acceptStateCount)
{}

state_machine::state_machine(std::string id, size_t acceptStateCount, filter_function filter) :
	id(id),
	accept_state_count(acceptStateCount),
	filter(filter)
{}

void state_machine::start(details::subjob & sj, size_t const documentPosition) const {
	process(sj.construct_start_state_context(documentPosition), 0);
}

void state_machine::process(details::context_ref const & c, size_t const s) const {
	DBG("processing '", get_id(), "' state ", s, " document position ", c.current_document_position());
	if (s >= states.size() - accept_state_count) {
		c.owner().accept(c);
	}
	for (auto const & kvp : states[s]) {
		recognizer const & transition = kvp.first;
		int const next_state = kvp.second;
		DBG("'", get_id(), "' state ", s, " position ", c.current_document_position(), " subscribes to '", transition.get_id(), "' position ", c.current_document_position());
		c.owner().on(c, transition, next_state);
	}
}

std::string state_machine::get_id() const {
	return id;
}

filter_function state_machine::get_filter() const {
	return filter;
}

void state_machine::add_transition(size_t fromState, recognizer const & recognizer, size_t toState) {
	size_t impliedStateCount = std::max(fromState, toState) + 1;
	while (states.size() < impliedStateCount) {
		states.emplace_back();
	}
	if (!states[fromState].insert(decltype(states)::value_type::value_type(recognizer, toState)).second) {
		throw "duplicate key";
	}
}

}
