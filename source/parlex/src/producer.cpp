#include <cassert>
#include <mutex>

#include "job.hpp"
#include "logging.hpp"
#include "parser.hpp"
#include "producer.hpp"
#include "subjob.hpp"

namespace parlex {
namespace details {

producer::producer(job & owner, recognizer const & r, size_t const documentPosition) :
	owner(owner),
	r(r),
	documentPosition(documentPosition),
	completed(false) {}


void producer::add_subscription(context_ref const & c, size_t nextDfaState) {
	{
		std::unique_lock<std::mutex> lock(mutex);
		consumers.emplace_back(c, nextDfaState);
	}  //release the lock
	do_events();
}

void producer::do_events() {
	auto & parser = owner.owner;
	std::unique_lock<std::mutex> lock(mutex);
	start:
	auto i = consumers.begin();
	while (i != consumers.end()) {
		auto subscription = *i;
		auto & targetSubjob = subscription.c.owner();

		{ //scope for lock on targetSubjob.mutex
			std::unique_lock<std::mutex> targetLock(targetSubjob.mutex);
			//if the subjob is completed
			if (targetSubjob.completed) {
				if (i == consumers.begin()) {
					consumers.pop_front(); //remove the subscription
					goto start; //and restart
				} else {
					auto j = i--; //save the iterator
					consumers.erase(j); //remove the subscription
					++i; //restore the iterator
					continue;
				}
			}
		}

		while (subscription.next_index < match_to_permutations.size()) {
			auto match = matches[subscription.next_index];
			subscription.next_index++;
			context_ref next = targetSubjob.construct_stepped_context(subscription.c, match);
			parser.schedule(next, subscription.next_dfa_state);
		};
		if (completed) { 
			{
				std::unique_lock<std::mutex> targetLock(targetSubjob.mutex);
				if (--targetSubjob.subscriptionCounter == 0) {
					DBG("halting the subjob at document position ", targetSubjob.documentPosition, " using machine '", targetSubjob.machine, "' ");
					targetSubjob.completed = true;
					targetSubjob.do_events();
				}
			}				
		}
		++i;
	}
}

void producer::enque_permutation(size_t consumedCharacterCount, permutation const & p) {
	bool newMatch = false;
	{
		std::unique_lock<std::mutex> lock(mutex);
		match m(match_class(r, documentPosition), consumedCharacterCount);
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

}
}
