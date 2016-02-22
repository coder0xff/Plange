#include <string>
#include <cassert>

#include "parlex/details/logging.hpp"
#include "parlex/details/subjob.hpp"
#include "parlex/details/context.hpp"
#include "parlex/details/job.hpp"
#include "parlex/recognizer.hpp"
#include "parlex/parser.hpp"
#include "parlex/state_machine.hpp"

namespace parlex {
namespace details {

subjob::subjob(
	job & owner,
	state_machine const & machine,
	int documentPosition
):
	producer(owner, machine, documentPosition),
	machine(machine),
	lifetimeCounter(1) //see finish_creation
{
	DBG("constructed subjob b:", documentPosition, " m:", machine);
}

subjob::~subjob() {
	DBG("destructing subjob b:", documentPosition, " m:", machine);
	assert(lifetimeCounter == 0);
}

void subjob::start() {
	{
		std::unique_lock<std::mutex> lock(mutex);
		contexts.emplace_back(*this, context_ref(), documentPosition, nullptr);
	}
	machine.start(*this, documentPosition);
	end_dependency(); //reference code B
}

context_ref subjob::construct_start_state_context(int documentPosition) {
	std::unique_lock<std::mutex> lock(mutex);
	contexts.emplace_back(*this, context_ref(), documentPosition, nullptr);
	return contexts.back().get_ref();
}

context_ref subjob::construct_stepped_context(context_ref const & prior, match fromTransition) {
	std::unique_lock<std::mutex> lock(mutex);
	contexts.emplace_back(*this, prior, prior.current_document_position() + fromTransition.consumed_character_count, &fromTransition);
	return contexts.back().get_ref();
}

void subjob::on(context_ref const & c, recognizer const & r, int nextDfaState) {
	increment_lifetime(); //reference code C
	owner.connect(match_class(r, c.current_document_position()), c, nextDfaState);
}

void subjob::accept(context_ref const & c) {
	permutation p = c.result();
	if (!machine.get_filter()) {
		int len = c.current_document_position() - c.owner().documentPosition;
		enque_permutation(len, p);
	} else {
		std::unique_lock<std::mutex> lock(mutex);
		queuedPermutations.push_back(p);
	}
}

void subjob::decrement_lifetime() {
	int temp = --lifetimeCounter;
	DBG("decrement_lifetime m:", machine, " b:", documentPosition, " r:", temp);
	if (temp > 0) {
		return;
	}
	flush();
	terminate();
}

void subjob::end_dependency()
{
	DBG("end_dependency m:", machine, " b:", documentPosition);
	decrement_lifetime();
}

void subjob::finish_creation() {
	DBG("finish_creation m:", machine, " b:", documentPosition);
	decrement_lifetime();
}

void subjob::increment_lifetime() {
	int temp = ++lifetimeCounter;
	assert(temp > 1);
	DBG("increment_lifetime m:", machine, " b:", documentPosition, " r:", temp);
}

void subjob::flush() {
	DBG("flush m:", machine, " b:", documentPosition);
	if (machine.get_filter()) {
		std::unique_lock<std::mutex> lock(mutex);
		std::set<int> selections = machine.get_filter()(queuedPermutations);
		int counter = 0;
		for (auto const & permutation : queuedPermutations) {
			if (selections.count(counter) > 0) {
				int len = permutation.back().documentPosition + permutation.back().consumed_character_count - documentPosition;
				enque_permutation(len, permutation);
			}
			counter++;
		}
	}
}

}
}
