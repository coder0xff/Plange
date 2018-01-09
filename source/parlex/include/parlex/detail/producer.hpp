#ifndef PRODUCER_HPP
#define PRODUCER_HPP

#include <map>
#include <vector>
#include <set>
#include <mutex>

#include "parlex/detail/context.hpp"
#include "parlex/detail/permutation.hpp"

namespace parlex {
namespace detail {

class parser;
class job;

class producer {
public:
	virtual ~producer() = default;

	struct subscription {
		context const & c;
		leaf const * const l;
		uint32_t id;
		uint16_t next_transmit_index;
		uint8_t next_dfa_state;
		subscription(uint32_t const producerId, context const & c, uint8_t const nextDfaState, leaf const * const l);
	};

	void do_events(job & j, match_class const & myInfo);

	std::vector<subscription> consumers;
	std::vector<uint32_t> match_lengths;
	std::map<uint32_t, std::set<permutation>> match_length_to_permutations;
	std::mutex mutex;
	bool completed;

	producer();
	void add_subscription(job & j, match_class const & myInfo, uint32_t const subscriberId, context const & c, uint8_t nextDfaState, leaf const * l);
	void enque_permutation(job & j, match_class const & myInfo, uint32_t const consumedCharacterCount, permutation const & p);
	void terminate(job & j, match_class const & myInfo);
};

} // namespace detail
} // namespace parlex

#endif //PRODUCER_HPP
