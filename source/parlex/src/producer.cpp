#include "parlex/detail/producer.hpp"

#include <mutex>

#include "parlex/detail/job.hpp"
#include "parlex/detail/parser.hpp"
#include "parlex/detail/subjob.hpp"

namespace parlex {
namespace detail {

producer::producer() : completed(false) { }

void producer::add_subscription(job & j, match_class const & myId, subjob & subscriber, match_class const & subscriberId, configuration const & c, uint8_t nextDfaState, leaf const * l) {
	{
		std::unique_lock<std::mutex> lock(mutex);
		consumers.emplace_back(subscriber, subscriberId, c, nextDfaState, l);
	} //release the lock
	do_events(j, myId);
}

void producer::do_events(job & j, match_class const & myInfo) {
	std::unique_lock<std::mutex> lock(mutex);
	for (auto & subscription : consumers) {
		while (subscription.next_transmit_index < match_length_to_derivations.size()) {
			auto const matchLength = match_lengths[subscription.next_transmit_index];
			subscription.next_transmit_index++;
			auto const & next = subscription.subscriber.construct_stepped_configuration(&subscription.c, match(myInfo, matchLength), subscription.l);
			j.owner->schedule(subscription.subscriber_id, next, subscription.next_dfa_state);
		}
	}
	if (completed) {
		std::vector<subscription> temp;
		swap(temp, consumers);
		lock.unlock();
		for (auto & subscription : temp) {
			subscription.subscriber.end_subscription_reference(j, subscription.subscriber_id);
		}
		lock.lock();
		if (!consumers.empty()) {
			lock.unlock();
			do_events(j, myInfo);
		}
	}
}

void producer::enque_derivation(job & j, match_class const & myId, uint32_t const consumedCharacterCount, derivation const & p) {
	auto newMatch = false; {
		std::unique_lock<std::mutex> lock(mutex);
		throw_assert(!completed);
		if (!match_length_to_derivations.count(consumedCharacterCount)) {
			match_length_to_derivations[consumedCharacterCount] = std::set<derivation>();
			match_lengths.push_back(consumedCharacterCount);
			newMatch = true;
		}
		match_length_to_derivations[consumedCharacterCount].insert(p);
	}
	if (newMatch) {
		do_events(j, myId);
	}
}

void producer::terminate(job & j, match_class const & myInfo) {
	completed = true;
	do_events(j, myInfo);
}


producer::subscription::subscription(subjob & subscriber, match_class const & subscriberId, configuration const & c, uint8_t const nextDfaState, leaf const * l) :
	c(c),
	l(l),
	subscriber(subscriber),
	subscriber_id(subscriberId), 
	next_transmit_index(0), 
	next_dfa_state(nextDfaState)
{}

} // namespace detail
} // namespace parlex
