#include "parlex/detail/subjob.hpp"

#include "parlex/detail/parser.hpp"
#include "parlex/detail/recognizer.hpp"
#include "parlex/detail/state_machine_base.hpp"

#include "parlex/detail/context.hpp"
#include "parlex/detail/job.hpp"

#include "utils.hpp"

namespace parlex {
namespace detail {

subjob::subjob(
	job & owner,
	state_machine_base const & machine,
	int const documentPosition
):
	producer(owner, machine, documentPosition),
	machine(machine),
	lifetime_counter(1) //see finish_creation
{
	//DBG("constructed subjob b:", documentPosition, " m:", machine);
}

subjob::~subjob() {
	//DBG("destructing subjob b:", documentPosition, " m:", machine);
}

void subjob::start() {
	machine.start(construct_start_state_context(document_position));
	finish_creation();
}

context const & subjob::construct_start_state_context(int documentPosition) {
	std::unique_lock<std::mutex> lock(mutex);
	auto const i = contexts.emplace_front(*this, nullptr, documentPosition, std::optional<match>(), nullptr);
	return *i;
}

context const & subjob::construct_stepped_context(context const* const prior, match const & fromTransition, behavior::leaf const * leaf) {
	std::unique_lock<std::mutex> lock(mutex);
	auto const i = contexts.emplace_front(*this, prior, prior->current_document_position + fromTransition.consumed_character_count, std::optional<match>(fromTransition), leaf);
	return *i;
}

void subjob::on(context const & c, recognizer const & r, int const nextDfaState, behavior::leaf const * leaf) {
	if (c.current_document_position >= c.owner.owner.document.length()) {
		return;
	}
	begin_subscription_reference();
	owner.connect(match_class(r, c.current_document_position), c, nextDfaState, leaf);
}

void subjob::accept(context const & c) {
	int const len = c.current_document_position - c.owner.document_position;
	if (len == 0) {
		return;
	}
	throw_assert(&c.owner == this);
	auto const p = c.result();
	if (!machine.get_filter()) {
		//DBG("Accepting r:", r.id, " p:", c.owner().document_position, " l:", c.current_document_position() - c.owner().document_position);
		enque_permutation(len, p);
	} else {
		//DBG("Candidate r:", r.id, " p:", c.owner().document_position, " l:", c.current_document_position() - c.owner().document_position);
		std::unique_lock<std::mutex> lock(mutex);
		queued_permutations.push_back(p);
	}
}

void subjob::increment_lifetime() {
	auto const temp = ++lifetime_counter;
	throw_assert(temp > 1);
	//DBG("increment_lifetime m:", machine, " b:", documentPosition, " r:", temp);
}

void subjob::decrement_lifetime() {
	auto const temp = --lifetime_counter;
	//DBG("decrement_lifetime m:", machine, " b:", documentPosition, " r:", temp);
	if (temp > 0) {
		return;
	}
	flush();
	contexts.clear();
	queued_permutations.clear();
	terminate();
}

void subjob::finish_creation() {
	//corresponds with the constructor's setting of lifetimeCounter to 1
	//DBG("finish_creation m:", machine, " b:", documentPosition);
	decrement_lifetime();
}

void subjob::begin_work_queue_reference() {
	increment_lifetime();
}

void subjob::end_work_queue_reference() {
	decrement_lifetime();
}

void subjob::begin_subscription_reference() {
	increment_lifetime();
}

void subjob::end_subscription_reference() {
	decrement_lifetime();
}

void subjob::flush() {
	///DBG("flush m:", machine, " b:", documentPosition);
	auto const & filter = machine.get_filter();
	if (filter != nullptr) {
		std::unique_lock<std::mutex> lock(mutex);
		if (queued_permutations.size() == 0) {
			return;
		}
		auto selections = (*filter)(owner.document, queued_permutations);
		auto counter = 0;
		for (auto const & permutation : queued_permutations) {
			if (selections.count(counter) > 0) {
				int const len = permutation.size() > 0 ? permutation.back().document_position + permutation.back().consumed_character_count - document_position : 0;
				enque_permutation(len, permutation);
			}
			counter++;
		}
	}
}

} // namespace detail
} // namespace parlex
