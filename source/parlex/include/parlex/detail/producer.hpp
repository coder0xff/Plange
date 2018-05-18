#ifndef PRODUCER_HPP
#define PRODUCER_HPP

#include <map>
#include <vector>
#include <set>
#include <mutex>

#include "parlex/detail/configuration.hpp"
#include "parlex/detail/derivation.hpp"

namespace parlex {
namespace detail {

class parser;
class job;

class producer {
public:
	virtual ~producer() = default;

	struct subscription {
		subscription(uint8_t nextDfaState, leaf const * l, transition_record const * history, subjob & subscriber, match_class const & subscriberId);

		uint8_t const next_dfa_state;
		leaf const * const l;
		transition_record const * const history;
		subjob & subscriber;
		match_class const subscriber_id;
		uint16_t next_transmit_index;
	};

	void do_events(job & j, match_class const & myId);

	std::vector<subscription> consumers;
	std::vector<uint32_t> match_lengths;
	std::map<uint32_t, std::set<derivation>> match_length_to_derivations;
	std::mutex mutex;
	bool completed;

	producer();
	void add_subscription(uint8_t nextDfaState, leaf const * l, transition_record const * history, subjob & subscriber, match_class const & subscriberId, match_class const & myId, job & j);
	void enque_derivation(job & j, match_class const & myId, uint32_t const consumedCharacterCount, derivation const & p);
	void terminate(job & j, match_class const & myId);
};

} // namespace detail
} // namespace parlex

#endif //PRODUCER_HPP
