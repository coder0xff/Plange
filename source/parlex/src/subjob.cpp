#include "parlex/detail/subjob.hpp"

#include "parlex/detail/configuration.hpp"
#include "parlex/detail/job.hpp"
#include "parlex/detail/match_class.hpp"
#include "parlex/detail/parser.hpp"
#include "parlex/detail/acceptor.hpp"

#include "utils.hpp"
// ReSharper disable once CppUnusedIncludeDirective
#include "logging.hpp"

namespace parlex {
namespace detail {

subjob::subjob(acceptor const & machine) :
	machine(machine),
	lifetime_counter(1) //see finish_creation
{
	//DBG("constructed subjob p:", documentPosition, " m:", machine);
}

subjob::~subjob() {
	//DBG("destructing subjob p:", document_position, " m:", machine);
}

void subjob::start(job & j, match_class const & myId) {
	machine.process(j, *this, myId, construct_start_state_configuration(myId.document_position));
	finish_creation(j, myId);
}

configuration subjob::construct_start_state_configuration(uint32_t const documentPosition) const {
	return configuration(machine.start_state, documentPosition, nullptr);
}

configuration subjob::construct_stepped_configuration(uint8_t dfaState, uint32_t documentPosition, transition_record const * history, transition const & t) {
	auto const ptr = &*transition_records.emplace_front(t, history);
	return configuration(dfaState, documentPosition, ptr);
}

void subjob::on(job & j, match_class const & myId, match_class const & matchClass, uint8_t const nextDfaState, leaf const * l, transition_record const * history) {
	if (matchClass.document_position >= j.document.length()) {
		return;
	}
	begin_subscription_reference();
	j.connect(matchClass, *this, myId, nextDfaState, l, history);
}

void subjob::accept(job & j, match_class const & myId, configuration const & c) {
	int const len = c.current_document_position - myId.document_position;
	if (len == 0) {
		return;
	}
	auto const p = c.result();
	if (!machine.get_filter()) {
		//DBG("Accepting r:", r.name, " p:", c.owner().document_position, " l:", c.current_document_position() - c.owner().document_position);
		enque_derivation(j, myId, len, p);
	} else {
		//DBG("Candidate r:", r.name, " p:", c.owner().document_position, " l:", c.current_document_position() - c.owner().document_position);
		std::unique_lock<std::mutex> lock(mutex);
		queued_derivations.push_back(p);
	}
}

void subjob::increment_lifetime() {
	auto const temp = ++lifetime_counter;
	throw_assert(temp > 1);
	//DBG("increment_lifetime m:", machine, " b:", documentPosition, " r:", temp);
}

void subjob::decrement_lifetime(job & j, match_class const & myId) {
	auto const temp = --lifetime_counter;
	//DBG("decrement_lifetime m:", machine, " b:", documentPosition, " r:", temp);
	if (temp > 0) {
		return;
	}
	flush(j, myId);
	transition_records.clear();
	queued_derivations.clear();
	terminate(j, myId);
}

void subjob::finish_creation(job & j, match_class const & myId) {
	//corresponds with the constructor's setting of lifetimeCounter to 1
	//DBG("finish_creation m:", machine, " b:", documentPosition);
	decrement_lifetime(j, myId);
}

void subjob::begin_work_queue_reference() {
	increment_lifetime();
}

void subjob::end_work_queue_reference(job & j, match_class const & myId) {
	decrement_lifetime(j, myId);
}

void subjob::begin_subscription_reference() {
	increment_lifetime();
}

void subjob::end_subscription_reference(job & j, match_class const & myId) {
	decrement_lifetime(j, myId);
}

void subjob::flush(job & j, match_class const & myId) {
	///DBG("flush m:", machine, " b:", documentPosition);
	auto const & filter = machine.get_filter();
	if (filter != nullptr) {
		std::unique_lock<std::mutex> lock(mutex);
		if (queued_derivations.empty()) {
			return;
		}
		auto selections = (*filter)(j.document, queued_derivations);
		auto counter = 0;
		for (auto const & derivation : queued_derivations) {
			if (selections.count(counter) > 0) {
				auto & lastChild = derivation.back();
				int const len = !derivation.empty() ? lastChild.document_position + lastChild.consumed_character_count - myId.document_position : 0;
				enque_derivation(j, myId, len, derivation);
			}
			counter++;
		}
	}
	queued_derivations.clear();
}

} // namespace detail
} // namespace parlex
