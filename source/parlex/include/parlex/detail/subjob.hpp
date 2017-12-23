#ifndef SUBJOB_HPP
#define SUBJOB_HPP

#include <list>
#include <mutex>
#include <atomic>

#include "concurrent_forward_list.hpp"

#include "parlex/detail/permutation.hpp"
#include "parlex/detail/context.hpp"
#include "parlex/detail/producer.hpp"

namespace parlex {
namespace detail {

class job;
class state_machine_base;

class subjob : public producer {
public:
	state_machine_base const & machine;
	concurrent_forward_list<context> contexts;
	std::list<permutation> queued_permutations;
	std::mutex mutex;
	std::atomic<int> lifetime_counter;

	subjob(job & owner, state_machine_base const & machine, int const documentPosition);
	subjob(subjob const & other) = delete;
	virtual ~subjob();

	void start();
	context const & construct_stepped_context(context const* const prior, match const & fromTransition, behavior::leaf const * leaf);
	void on(context const & c, recognizer const & r, int nextDfaState, behavior::leaf const * leaf);
	void accept(context const & c);
	// for special use by the parser to seed the queue
	context const & construct_start_state_context(int documentPosition);
	void finish_creation();
	void begin_work_queue_reference();
	void end_work_queue_reference();
	void flush();
	void begin_subscription_reference();
	void end_subscription_reference();
private:
	void increment_lifetime();
	void decrement_lifetime();
};

} // namespace detail
} // namespace parlex

#endif //SUBJOB_HPP
