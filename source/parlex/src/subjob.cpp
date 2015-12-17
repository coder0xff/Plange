#include <iostream>
#include <string>

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
	std::cout << "started a subjob at " << documentPosition << " using " << machine.get_id() << std::endl;
}

void subjob::start() {
	{
		std::unique_lock<std::mutex> lock(mutex);
		contexts.emplace_back(*this, context_ref(), document_position, nullptr);
	}
	machine.start(*this, document_position);
}

context_ref subjob::construct_context(int documentPosition) {
	std::unique_lock<std::mutex> lock(mutex);
	contexts.emplace_back(*this, context_ref(), document_position, nullptr);
	return contexts.back().get_ref();
}

context_ref subjob::step(context_ref const & prior, match fromTransition) {
	std::unique_lock<std::mutex> lock(mutex);
	contexts.emplace_back(*this, prior, prior.current_document_position() + fromTransition.consumed_character_count, &fromTransition);
	return contexts.back().get_ref();
}

void subjob::on(context_ref const & c, recognizer const & r, int nextDfaState) {
	owner.connect(match_class(r, c.current_document_position()), c, nextDfaState);
}

void subjob::accept(context_ref const & c) {
	permutation p = c.result();
	if (!machine.get_filter()) {
		int len = c.current_document_position() - c.owner().document_position;
		enque_permutation(len, p);
	} else {
		std::unique_lock<std::mutex> lock(mutex);
		queued_permutations.push_back(p);
	}
}

void subjob::halt_for_deadlock() {
	
}

}
}
