#ifndef PRODUCER_HPP
#define PRODUCER_HPP

#include <list>
#include <map>
#include <vector>
#include <set>
#include <mutex>

#include "parlex/details/context.hpp"
#include "parlex/permutation.hpp"

namespace parlex {

class parser;

namespace details {

class job;

class producer {
public:
	struct subscription {
		size_t next_index;
		context_ref const c;
		size_t next_dfa_state;
		inline subscription(context_ref const & c, size_t const nextDfaState) : next_index(0), c(c), next_dfa_state(nextDfaState) {}
	};

	void do_events();

	job & owner;
	recognizer const & r;
	int const documentPosition;
	bool completed;
	std::list<subscription> consumers;
	std::vector<match> matches;
	std::map<match, std::set<permutation>> match_to_permutations;
	std::mutex mutex;

	void add_subscription(context_ref const & c, size_t const nextDfaState);
	producer(job & owner, recognizer const & r, size_t const documentPosition);
	void enque_permutation(size_t consumedCharacterCount, permutation const & p);
	void terminate();
};

}
}

#endif //PRODUCER_HPP
