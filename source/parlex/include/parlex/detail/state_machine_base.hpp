#ifndef STATE_MACHINE_BASE_HPP
#define STATE_MACHINE_BASE_HPP

#include "parlex/associativity.hpp"
#include "parlex/filter_function.hpp"

#include "parlex/detail/recognizer.hpp"
#include "parlex/detail/producer.hpp"

namespace parlex {
namespace detail {

class context;
class job;
class parser;
class subjob;

//simulates a dfa
//State 0 is the start state
//States from N-a to N-1 are the accept states, where N is states.size() and a is accept_state_count
class state_machine_base : public recognizer {
public:
	virtual ~state_machine_base() = default;
	virtual int get_start_state() const = 0;
	virtual filter_function get_filter() const = 0;
	virtual associativity get_assoc() const = 0;
protected:
	friend class parser;
	friend class subjob;

	explicit state_machine_base(std::string const & name);
	void start(job & j, producer_id_t subjobId, subjob & sj, context const & c) const;
	virtual void process(job & j, producer_id_t subjobId, subjob & sj, context const & c, size_t const dfaState) const = 0;
	static void on(job & j, size_t const recognizerIndex, producer_id_t const subscriber, subjob & sj, context const & c, size_t const nextDfaState, leaf const * leaf);
	static void accept(job & j, subjob & sj, producer_id_t const subjobId, context const & c);
};

} // namespace detail
} // namespace parlex

#endif // STATE_MACHINE_BASE_HPP
