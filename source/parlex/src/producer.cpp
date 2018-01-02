#include "parlex/detail/producer.hpp"

#include <mutex>

#include "parlex/detail/job.hpp"
#include "parlex/detail/parser.hpp"
#include "parlex/detail/subjob.hpp"

namespace parlex {
namespace detail {

producer::producer(job & owner, size_t const documentPosition, size_t const recognizerIndex, size_t const dummy) :
	owner(owner),
	document_position(documentPosition),
	recognizer_index(recognizerIndex),
	completed(false)
{ }


void producer::add_subscription(context const & c, size_t nextDfaState, leaf const * l) {
	{
		std::unique_lock<std::mutex> lock(mutex);
		consumers.emplace_back(c, nextDfaState, l);
	} //release the lock
	do_events();
}

void producer::do_events() {
	auto p = owner.owner;
	std::unique_lock<std::mutex> lock(mutex);
	for (auto & subscription : consumers) {
		auto & targetSubjob = subscription.c.owner;
		while (subscription.next_transmit_index < match_length_to_permutations.size()) {
			auto const matchLength = match_lengths[subscription.next_transmit_index];
			subscription.next_transmit_index++;
			auto const & next = targetSubjob.construct_stepped_context(&subscription.c, match(document_position, recognizer_index, matchLength), subscription.l);
			p->schedule(next, subscription.next_dfa_state);
		}
	}
	if (completed) {
		std::vector<subscription> temp;
		swap(temp, consumers);
		lock.unlock();
		for (auto & subscription : temp) {
			auto & targetSubjob = subscription.c.owner;
			targetSubjob.end_subscription_reference();
		}
		lock.lock();
		if (!consumers.empty()) {
			lock.unlock();
			do_events();
		}
	}
}

void producer::enque_permutation(size_t const consumedCharacterCount, permutation const & p) {
	auto newMatch = false; {
		std::unique_lock<std::mutex> lock(mutex);
		throw_assert(!completed);
		match const m(document_position, recognizer_index, consumedCharacterCount);
		if (!match_length_to_permutations.count(consumedCharacterCount)) {
			match_length_to_permutations[consumedCharacterCount] = std::set<permutation>();
			match_lengths.push_back(consumedCharacterCount);
			newMatch = true;
		}
		match_length_to_permutations[consumedCharacterCount].insert(p);
	}
	if (newMatch) {
		do_events();
	}
}

void producer::terminate() {
	completed = true;
	do_events();
}


producer::subscription::subscription(context const & c, size_t const nextDfaState, leaf const * l) :
	next_transmit_index(0), 
	c(c), 
	next_dfa_state(nextDfaState), 
	l(l)
{}

} // namespace detail
} // namespace parlex
