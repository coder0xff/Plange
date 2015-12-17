#include <iostream>

#include "state_machine.hpp"
#include "context.hpp"
#include "subjob.hpp"

namespace parlex {

state_machine::state_machine(std::string id, int acceptStateCount) :
	id(id),
	accept_state_count(acceptStateCount)
{}

state_machine::state_machine(std::string id, int acceptStateCount, filter_function filter) :
	id(id),
	accept_state_count(acceptStateCount),
	filter(filter)
{}

void state_machine::start(details::subjob & sj, int const documentPosition) const {
	process(sj.construct_context(documentPosition), 0);
}

void state_machine::process(details::context_ref const & c, int const s) const {
	std::cout << "processing " << get_id() << " state " << s << " document position " << c.current_document_position() << std::endl;
	if (s >= states.size() - accept_state_count) {
		c.owner().accept(c);
	}
	for (auto const & kvp : states[s]) {
		recognizer const & transition = kvp.first;
		int const next_state = kvp.second;
		std::cout << get_id() << " state " << s << " position " << c.owner().contexts.front().current_document_position << " subscribes to " << transition.get_id() << " position " << c.current_document_position() << std::endl;
		c.owner().on(c, transition, next_state);
	}
}

std::string state_machine::get_id() const {
	return id;
}

filter_function state_machine::get_filter() const {
	return filter;
}

void state_machine::add_transition(int fromState, recognizer const & recognizer, int toState) {
	int impliedStateCount = std::max(fromState, toState) + 1;
	while (states.size() < impliedStateCount) {
		states.emplace_back();
	}
	if (!states[fromState].insert(decltype(states)::value_type::value_type(recognizer, toState)).second) {
		throw "duplicate key";
	}
}

}
