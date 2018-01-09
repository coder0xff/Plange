#include "parlex/detail/producer.hpp"

#include <mutex>

#include "parlex/detail/job.hpp"
#include "parlex/detail/parser.hpp"
#include "parlex/detail/subjob.hpp"

namespace parlex {
namespace detail {

producer::producer() : completed(false) { }


void producer::add_subscription(job & j, match_class const & myInfo, producer_id_t const subscriberId, context const & c, size_t nextDfaState, leaf const * l) {
	{
		std::unique_lock<std::mutex> lock(mutex);
		consumers.emplace_back(subscriberId, c, nextDfaState, l);
	} //release the lock
	do_events(j, myInfo);
}

void producer::do_events(job & j, match_class const & myInfo) {
	std::unique_lock<std::mutex> lock(mutex);
	for (auto & subscription : consumers) {
		auto & targetProducer = j.get_producer(subscription.id);
		auto & targetSubjob = *static_cast<subjob *>(&targetProducer);  // NOLINT will always be a subjob
		while (subscription.next_transmit_index < match_length_to_permutations.size()) {
			auto const matchLength = match_lengths[subscription.next_transmit_index];
			subscription.next_transmit_index++;
			auto const & next = targetSubjob.construct_stepped_context(&subscription.c, match(myInfo, matchLength), subscription.l);
			j.owner->schedule(subscription.id, next, subscription.next_dfa_state);
		}
	}
	if (completed) {
		std::vector<subscription> temp;
		swap(temp, consumers);
		lock.unlock();
		for (auto & subscription : temp) {
			auto & targetProducer = j.get_producer(subscription.id);
			auto & targetSubjob = *static_cast<subjob *>(&targetProducer);  // NOLINT will always be a subjob
			targetSubjob.end_subscription_reference(j, subscription.id);
		}
		lock.lock();
		if (!consumers.empty()) {
			lock.unlock();
			do_events(j, myInfo);
		}
	}
}

void producer::enque_permutation(job & j, match_class const & myInfo, size_t const consumedCharacterCount, permutation const & p) {
	auto newMatch = false; {
		std::unique_lock<std::mutex> lock(mutex);
		throw_assert(!completed);
		if (!match_length_to_permutations.count(consumedCharacterCount)) {
			match_length_to_permutations[consumedCharacterCount] = std::set<permutation>();
			match_lengths.push_back(consumedCharacterCount);
			newMatch = true;
		}
		match_length_to_permutations[consumedCharacterCount].insert(p);
	}
	if (newMatch) {
		do_events(j, myInfo);
	}
}

void producer::terminate(job & j, match_class const & myInfo) {
	completed = true;
	do_events(j, myInfo);
}


producer_id_t::producer_id_t(size_t const id): id(id) {}

producer::subscription::subscription(producer_id_t const producerId, context const & c, size_t const nextDfaState, leaf const * l) :
	next_transmit_index(0),
	id(producerId),
	c(c), 
	next_dfa_state(nextDfaState), 
	l(l)
{}

} // namespace detail
} // namespace parlex
