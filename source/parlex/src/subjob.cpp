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
	state_machine_base const & machine,
	int documentPosition
):
	producer(owner, machine, documentPosition),
	machine(machine),
	lifetimeCounter(1) //see finish_creation
{
	//DBG("constructed subjob b:", documentPosition, " m:", machine);
}

subjob::~subjob() {
	//DBG("destructing subjob b:", documentPosition, " m:", machine);
}

void subjob::start() {
	{
		std::unique_lock<std::mutex> lock(mutex);
		contexts.emplace_back(*this, context_ref(), document_position, nullptr);
	}
	machine.start(*this, document_position);
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
	if (c.current_document_position() >= c.owner().owner.document.length()) {
		return;
	}
	increment_lifetime(); //reference code C
	owner.connect(match_class(r, c.current_document_position()), c, nextDfaState);
}

void subjob::accept(context_ref const & c) {
	int len = c.current_document_position() - c.owner().document_position;
	if (!len) {
		return;
	}
	throw_assert(&c.owner() == this);
	permutation p = c.result();
	//DBG("Accepting r:", r.id, " p:", documentPosition, " l:", c.current_document_position() - documentPosition);
	if (!machine.filter) {
		enque_permutation(len, p);
	} else {
		std::unique_lock<std::mutex> lock(mutex);
		queuedPermutations.push_back(p);
	}
}

void subjob::decrement_lifetime() {
	int temp = --lifetimeCounter;
	//DBG("decrement_lifetime m:", machine, " b:", documentPosition, " r:", temp);
	if (temp > 0) {
		return;
	}
	flush();
	terminate();
}

void subjob::end_dependency()
{
	//DBG("end_dependency m:", machine, " b:", documentPosition);
	decrement_lifetime();
}

void subjob::finish_creation() {
	//DBG("finish_creation m:", machine, " b:", documentPosition);
	decrement_lifetime();
}

void subjob::increment_lifetime() {
	int temp = ++lifetimeCounter;
	throw_assert(temp > 1);
	//DBG("increment_lifetime m:", machine, " b:", documentPosition, " r:", temp);
}

void subjob::flush() {
	///DBG("flush m:", machine, " b:", documentPosition);
	if (machine.filter != nullptr) {
		std::unique_lock<std::mutex> lock(mutex);
		if (queuedPermutations.size() == 0) {
			return;
		}
		std::set<int> selections = (*machine.filter)(owner.document, queuedPermutations);
		int counter = 0;
		for (auto const & permutation : queuedPermutations) {
			if (selections.count(counter) > 0) {
				int len = permutation.size() > 0 ? permutation.back().document_position + permutation.back().consumed_character_count - document_position : 0;
				enque_permutation(len, permutation);
			}
			counter++;
		}
	}
}

}
}
