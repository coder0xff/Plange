#include "parlex/details/producer.hpp"

#include <mutex>

#include "parlex/details/behavior.hpp"
#include "parlex/details/job.hpp"
#include "parlex/details/parser.hpp"
#include "parlex/details/subjob.hpp"

namespace parlex {
namespace details {

producer::producer(job & owner, recognizer const & r, size_t const documentPosition) :
	owner(owner),
	r(r),
	document_position(documentPosition),
	completed(false) {
}


void producer::add_subscription(context const & c, size_t nextDfaState, behavior::leaf const * leaf) { {
		std::unique_lock<std::mutex> lock(mutex);
		consumers.emplace_back(c, nextDfaState, leaf);
	} //release the lock
	do_events();
}

void producer::do_events() {
	auto & parser = owner.owner;
	std::unique_lock<std::mutex> lock(mutex);
	for (subscription & subscription : consumers) {
		subjob & targetSubjob = subscription.c.owner;
		while (subscription.next_index < match_to_permutations.size()) {
			auto & match = matches[subscription.next_index];
			subscription.next_index++;
			context const & next = targetSubjob.construct_stepped_context(&subscription.c, match, subscription.l);
			targetSubjob.increment_lifetime(); //reference code A - the target may not halt until this is handled
			parser.schedule(next, subscription.next_dfa_state);
		}
	}
	if (completed) {
		std::list<subscription> temp;
		swap(temp, consumers);
		lock.unlock();
		for (subscription & subscription : temp) {
			subjob & targetSubjob = subscription.c.owner;
			targetSubjob.decrement_lifetime(); //reference code C
		}
	}
}

void producer::enque_permutation(size_t consumedCharacterCount, permutation const & p) {
	bool newMatch = false; {
		std::unique_lock<std::mutex> lock(mutex);
		throw_assert(!completed);
		match m(match_class(r, document_position), consumedCharacterCount);
		if (!match_to_permutations.count(m)) {
			match_to_permutations[m] = std::set<permutation>();
			matches.push_back(m);
			newMatch = true;
		}
		match_to_permutations[m].insert(p);
	}
	if (newMatch) {
		do_events();
	}
}

void producer::terminate() {
	completed = true;
	do_events();
}


producer::subscription::subscription(context const & c, size_t const nextDfaState, behavior::leaf const * l) :
	next_index(0), 
	c(c), 
	next_dfa_state(nextDfaState), 
	l(l)
{}

} // namespace details
} // namespace parlex
