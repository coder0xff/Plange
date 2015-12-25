#include <string>

#include "logging.hpp"
#include "subjob.hpp"
#include "context.hpp"
#include "job.hpp"
#include "recognizer.hpp"
#include "parser.hpp"
#include "state_machine.hpp"

namespace parlex {
namespace details {

subjob::subjob(
	job & owner,
	state_machine const & machine,
	int documentPosition
):
	producer(owner, machine, documentPosition),
	machine(machine)
{ 
	DBG("started a subjob at document position ", documentPosition, " using machine '", machine, "'");
}

void subjob::start() {
	{
		std::unique_lock<std::mutex> lock(mutex);
		contexts.emplace_back(*this, context_ref(), documentPosition, nullptr);
	}
	machine.start(*this, documentPosition);
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
	{
		std::unique_lock<std::mutex> lock(mutex);
		subscriptionCounter++;
	}
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

}
}