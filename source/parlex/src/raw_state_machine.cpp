#include "parlex/detail/raw_state_machine.hpp"

#include "parlex/associativity.hpp"

namespace parlex {
namespace detail {

raw_state_machine::raw_state_machine(std::string const & id, int const startState, int const acceptStateCount, filter_function const & filter, associativity const assoc) : state_machine_base(id), filter(filter), assoc(assoc), start_state(startState), accept_state_count(acceptStateCount) {
}

void raw_state_machine::add_transition(size_t const from, size_t const recognizerIndex, size_t const to) {
	while (states.size() <= from || states.size() <= to) {
		states.emplace_back();
	}
	if (states[from].count(recognizerIndex) > 0) {
		throw std::runtime_error("there is already a transition using the specified recognizer");
	}
	states[from][recognizerIndex] = to;
}

raw_state_machine::states_t const& raw_state_machine::get_states() const {
	return states;
}

void raw_state_machine::process(context const & c, size_t const dfaState) const {
	//DBG("processing '", get_id(), "' s:", s, " p:", c.current_document_position());
	if (dfaState >= states.size() - accept_state_count) {
		accept(c);
	}
	for (auto const & kvp : states[dfaState]) {
		auto const & recognizerIndex = kvp.first;
		int const nextState = kvp.second;
		//DBG("'", get_id(), "' state ", s, " position ", c.current_document_position(), " subscribes to '", transition.name, "' position ", c.current_document_position());
		on(c, recognizerIndex, nextState, nullptr);
	}
}

bool raw_state_machine::is_terminal() const {
	return false;
}

int raw_state_machine::get_start_state() const {
	return start_state;
}

filter_function raw_state_machine::get_filter() const {
	return filter;
}

associativity raw_state_machine::get_assoc() const {
	return assoc;
}

} // namespace detail
} // namespace parlex
