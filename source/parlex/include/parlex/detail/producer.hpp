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

struct producer_id_t {
	explicit producer_id_t(size_t const id);

	size_t const id;
};

class producer {
public:
	virtual ~producer() = default;

	struct subscription {
		size_t next_transmit_index;
		producer_id_t id;
		context const& c;
		size_t next_dfa_state;
		leaf const * const l;
		subscription(producer_id_t const producerId, context const & c, size_t const nextDfaState, leaf const * const l);
	};

	void do_events(job & j, match_class const & myInfo);

	std::vector<subscription> consumers;
	std::vector<size_t> match_lengths;
	std::map<size_t, std::set<permutation>> match_length_to_permutations;
	std::mutex mutex;
	bool completed;

	producer();
	void add_subscription(job & j, match_class const & myInfo, producer_id_t const subscriberId, context const & c, size_t nextDfaState, leaf const * l);
	void enque_permutation(job & j, match_class const & myInfo, size_t const consumedCharacterCount, permutation const & p);
	void terminate(job & j, match_class const & myInfo);
};

} // namespace detail
} // namespace parlex

#endif //PRODUCER_HPP
