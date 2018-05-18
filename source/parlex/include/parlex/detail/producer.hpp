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
		configuration const & c;
		leaf const * const l;
		subjob & subscriber;
		match_class subscriber_id;
		uint16_t next_transmit_index;
		uint8_t next_dfa_state;
		subscription(subjob & subscriber, match_class const & subscriberId, configuration const & c, uint8_t const nextDfaState, leaf const * const l);
	};

	void do_events(job & j, match_class const & myId);

	std::vector<subscription> consumers;
	std::vector<uint32_t> match_lengths;
	std::map<uint32_t, std::set<derivation>> match_length_to_derivations;
	std::mutex mutex;
	bool completed;

	producer();
	void add_subscription(job & j, match_class const & myId, subjob & subscriber, match_class const & subscriberId, configuration const & c, uint8_t nextDfaState, leaf const * l);
	void enque_derivation(job & j, match_class const & myId, uint32_t const consumedCharacterCount, derivation const & p);
	void terminate(job & j, match_class const & myId);
};

} // namespace detail
} // namespace parlex

#endif //PRODUCER_HPP
