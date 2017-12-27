#ifndef PRODUCER_HPP
#define PRODUCER_HPP

#include <list>
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
		size_t next_transmit_index;
		context const& c;
		size_t next_dfa_state;
		leaf const * const l;
		subscription(context const & c, size_t const nextDfaState, leaf const * const l);
	};

	void do_events();

	job & owner;
	int const document_position;
	size_t recognizer_index;
	bool completed;
	std::list<subscription> consumers;
	std::vector<match> matches;
	std::map<match, std::set<permutation>> match_to_permutations;
	std::mutex mutex;

	producer(job & owner, size_t const documentPosition, size_t const recognizerIndex, size_t const dummy);
	void add_subscription(context const & c, size_t const nextDfaState, leaf const * l);
	void enque_permutation(size_t consumedCharacterCount, permutation const & p);
	void terminate();
};

} // namespace detail
} // namespace parlex

#endif //PRODUCER_HPP
