#ifndef SUBJOB_HPP
#define SUBJOB_HPP

#include <list>
#include <map>
#include <mutex>
#include <set>
#include <atomic>

#include "match.hpp"
#include "permutation.hpp"
#include "context.hpp"
#include "producer.hpp"

namespace parlex {

class state_machine;

namespace details {

class job;

class subjob : public producer {
public:
	state_machine const & machine;
	std::list<context> contexts;
	std::list<permutation> queuedPermutations;
	std::set<subjob*> producers;
	int subscriptionCounter;
	std::mutex mutex;

	subjob(job & owner, state_machine const & machine, int const documentPosition);
	subjob(subjob const & other) = delete;
	subjob(subjob&& move) = default;

	void start();
	context_ref construct_stepped_context(context_ref const & prior, match const fromTransition);
	void on(context_ref const & c, recognizer const & r, int nextDfaState);
	void accept(context_ref const & c);
	context_ref construct_start_state_context(int documentPosition);
};

}
}

#endif
