#include "parlex/detail/raw_state_machine.hpp"

#include "parlex/associativity.hpp"
#include "parlex/detail/job.hpp"

namespace parlex {
namespace detail {

raw_state_machine::raw_state_machine(std::string const & id, uint8_t const startState, uint8_t const acceptStateCount, filter_function const & filter, associativity const assoc) : state_machine_base(id), filter(filter), assoc(assoc), start_state(startState), accept_state_count(acceptStateCount) {
}

void raw_state_machine::add_transition(uint8_t const from, uint16_t const recognizerIndex, uint8_t const to) {
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

void raw_state_machine::process(job & j, producer_id_t const subjobId, subjob & sj, context const & c, uint8_t dfaState) const {
	//DBG("processing '", get_id(), "' s:", s, " p:", c.current_document_position());
	if (dfaState >= states.size() - accept_state_count) {		
		accept(j, sj, subjobId, c);
	}
	for (auto const & kvp : states[dfaState]) {
		auto const & recognizerIndex = kvp.first;
		int const nextState = kvp.second;
		//DBG("'", get_id(), "' state ", s, " position ", c.current_document_position(), " subscribes to '", transition.name, "' position ", c.current_document_position());
		on(j, recognizerIndex, subjobId, sj, c, nextState, nullptr);
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
