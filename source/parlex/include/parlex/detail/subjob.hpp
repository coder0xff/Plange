#ifndef SUBJOB_HPP
#define SUBJOB_HPP

#include <list>
#include <mutex>
#include <atomic>

#include "concurrent_forward_list.hpp"

#include "parlex/detail/derivation.hpp"
#include "parlex/detail/configuration.hpp"
#include "parlex/detail/producer.hpp"

namespace parlex {
namespace detail {

class job;
class acceptor;

struct transition_record {
	transition_record(transition const & data, transition_record const * const prior)
		: data(data),
		prior(prior) {}

	transition const data;
	transition_record const * const prior;
};

class subjob : public producer {
public:

	acceptor const & machine;
	concurrent_forward_list<transition_record> transition_records;
	std::list<derivation> queued_derivations;
	std::mutex mutex;
	std::atomic<uint16_t> lifetime_counter;

	explicit subjob(acceptor const & machine);
	subjob(subjob const & other) = delete;
	virtual ~subjob();

	void start(job & j, match_class const & myId);
	void on(job & j, match_class const & myId, match_class const & matchClass, uint8_t const nextDfaState, leaf const * l, transition_record const * history);
	void accept(job & j, match_class const & myId, configuration const & c);
	// for special use by the parser to seed the queue
	configuration construct_start_state_configuration(uint32_t const documentPosition) const;
	configuration construct_stepped_configuration(uint8_t dfaState, uint32_t documentPosition, transition_record const * history, transition const & t);
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
