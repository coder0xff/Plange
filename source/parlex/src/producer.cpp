#include "parlex/detail/producer.hpp"

#include <mutex>

#include "parlex/detail/behavior.hpp"
#include "parlex/detail/job.hpp"
#include "parlex/detail/parser.hpp"
#include "parlex/detail/subjob.hpp"

namespace parlex {
namespace detail {

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
			parser.schedule(next, subscription.next_dfa_state);
		}
	}
	if (completed) {
		std::list<subscription> temp;
		swap(temp, consumers);
		lock.unlock();
		for (subscription & subscription : temp) {
			subjob & targetSubjob = subscription.c.owner;
			targetSubjob.end_subscription_reference();
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

} // namespace detail
} // namespace parlex
