#ifndef SUBJOB_HPP
#define SUBJOB_HPP

#include <list>
#include <mutex>
#include <atomic>

#include "concurrent_forward_list.hpp"

#include "parlex/detail/permutation.hpp"
#include "parlex/detail/configuration.hpp"
#include "parlex/detail/producer.hpp"

namespace parlex {
namespace detail {

class job;
class acceptor;

class subjob : public producer {
public:
	acceptor const & machine;
	concurrent_forward_list<configuration> configurations;
	std::list<permutation> queued_permutations;
	std::mutex mutex;
	std::atomic<uint16_t> lifetime_counter;

	explicit subjob(acceptor const & machine);
	subjob(subjob const & other) = delete;
	virtual ~subjob();

	void start(job & j, match_class const & myId);
	configuration const & construct_stepped_configuration(configuration const* const prior, match const & fromTransition, leaf const * l);
	void on(job & j, match_class const & myId, uint16_t const recognizerIndex, configuration const & c, uint8_t const nextDfaState, leaf const * l);
	void accept(job & j, match_class const & myInfo, configuration const & c);
	// for special use by the parser to seed the queue
	configuration const & construct_start_state_configuration(uint32_t const documentPosition);
	void finish_creation(job & j, match_class const & myId);
	void begin_work_queue_reference();
	void end_work_queue_reference(job & j, match_class const & myId);
	void flush(job & j, match_class const & myId);
	void begin_subscription_reference();
	void end_subscription_reference(job & j, match_class const & myId);
private:
	void increment_lifetime();
	void decrement_lifetime(job & j, match_class const & myId);
};

} // namespace detail
} // namespace parlex

#endif //SUBJOB_HPP
