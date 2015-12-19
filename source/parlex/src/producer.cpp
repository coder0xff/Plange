#include <mutex>

#include "producer.hpp"
#include "subjob.hpp"
#include "job.hpp"
#include "parser.hpp"

namespace parlex {
namespace details {

producer::producer(job & owner, recognizer const & r, int const documentPosition) :
	owner(owner),
	r(r),
	document_position(documentPosition) {}


void producer::add_subscription(context_ref const & c, int nextDfaState) {
	{
		std::unique_lock<std::mutex> lock(mutex);
		consumers.emplace_back(c, nextDfaState);
	}  //release the lock
	do_events();
}

void producer::do_events() {
	std::unique_lock<std::mutex> lock(mutex);
	for (auto & subscription : consumers) {
		assert(!subscription.c.owner().completed)
		while (subscription.next_index < match_to_permutations.size()) {
			auto match = matches[subscription.next_index];
			subscription.next_index++;
			context_ref next = subscription.c.owner().step(subscription.c, match);
			owner.owner.schedule(next, subscription.next_dfa_state);
		};
		if (completed) {

		}
	}
}

void producer::enque_permutation(int consumedCharacterCount, permutation const & p) {
	//std::cout << "enque_permutation at " << (document_position) << " consuming " << consumedCharacterCount << std::endl;
	bool newMatch = false;
	{
		std::unique_lock<std::mutex> lock(mutex);
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

}
}
