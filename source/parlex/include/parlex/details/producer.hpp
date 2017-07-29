#ifndef PRODUCER_HPP
#define PRODUCER_HPP

#include <list>
#include <map>
#include <vector>
#include <set>
#include <mutex>

#include "parlex/details/context.hpp"
#include "parlex/details/permutation.hpp"

namespace parlex {
namespace details {
namespace behavior {

class leaf;

} // namespace behavior

class parser;
class job;

class producer {
public:
	virtual ~producer() = default;

	struct subscription {
		size_t next_index;
		context const& c;
		size_t next_dfa_state;
		behavior::leaf const * leaf;
		subscription(context const & c, size_t const nextDfaState, behavior::leaf const * leaf);
	};

	void do_events();

	job & owner;
	recognizer const & r;
	int const document_position;
	bool completed;
	std::list<subscription> consumers;
	std::vector<fast_match> matches;
	std::map<fast_match, std::set<permutation>> match_to_permutations;
	std::mutex mutex;

	producer(job & owner, recognizer const & r, size_t const documentPosition);
	void add_subscription(context const & c, size_t const nextDfaState, behavior::leaf const * leaf);
	void enque_permutation(size_t consumedCharacterCount, permutation const & p);
	void terminate();
};

} // namespace details
} // namespace parlex

#endif //PRODUCER_HPP
