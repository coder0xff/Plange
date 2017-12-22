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
		behavior::leaf const * const l;
		subscription(context const & c, size_t const nextDfaState, behavior::leaf const * const l);
	};

	void do_events();

	job & owner;
	recognizer const & r;
	int const document_position;
	bool completed;
	std::list<subscription> consumers;
	std::vector<match> matches;
	std::map<match, std::set<permutation>> match_to_permutations;
	std::mutex mutex;

	producer(job & owner, recognizer const & r, size_t const documentPosition);
	void add_subscription(context const & c, size_t const nextDfaState, behavior::leaf const * l);
	void enque_permutation(size_t consumedCharacterCount, permutation const & p);
	void terminate();
};

} // namespace detail
} // namespace parlex

#endif //PRODUCER_HPP
