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
class state_machine;

class subjob : public producer {
public:
	state_machine const & machine;
	concurrent_forward_list<context> contexts;
	std::list<permutation> queued_permutations;
	std::mutex mutex;
	std::atomic<uint16_t> lifetime_counter;

	explicit subjob(state_machine const & machine);
	subjob(subjob const & other) = delete;
	virtual ~subjob();

	void start(job & j, uint32_t const myId, uint32_t documentPosition);
	context const & construct_stepped_context(context const* const prior, match const & fromTransition, leaf const * l);
	void on(job & j, uint16_t const recognizerIndex, context const & c, uint32_t const myId, uint8_t const nextDfaState, leaf const * l);
	void accept(job & j, match_class const & subjobInfo, context const & c);
	// for special use by the parser to seed the queue
	context const & construct_start_state_context(uint32_t const documentPosition);
	void finish_creation(job & j, uint32_t const myId);
	void begin_work_queue_reference();
	void end_work_queue_reference(job & j, uint32_t const myId);
	void flush(job & j, match_class const & myInfo);
	void begin_subscription_reference();
	void end_subscription_reference(job & j, uint32_t const myId);
private:
	void increment_lifetime();
	void decrement_lifetime(job & j, uint32_t const myId);
};

} // namespace detail
} // namespace parlex

#endif //SUBJOB_HPP
