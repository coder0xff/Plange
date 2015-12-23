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
	std::set<subjob*> consumers;
	state_machine const & machine;
	std::list<context> contexts;
	std::list<permutation> queuedPermutations;
	std::set<subjob*> producers;
	int dependencyCounter;
	std::mutex mutex;

	subjob(job & owner, state_machine const & machine, int const documentPosition);
	subjob(subjob const & other) = delete;
	subjob(subjob&& move) = default;

	void start();
	context_ref step(context_ref const & prior, match const fromTransition);
	void on(context_ref const & c, recognizer const & r, int nextDfaState);
	void accept(context_ref const & c);
	context_ref construct_context(int documentPosition);
	void halt_for_deadlock();
};

}
}

#endif
