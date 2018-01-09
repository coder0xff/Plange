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
	void start(job & j, uint32_t subjobId, subjob & sj, context const & c) const;
	virtual void process(job & j, uint32_t subjobId, subjob & sj, context const & c, uint8_t const dfaState) const = 0;
	static void on(job & j, uint16_t const recognizerIndex, uint32_t const subscriber, subjob & sj, context const & c, uint8_t const nextDfaState, leaf const * leaf);
	static void accept(job & j, subjob & sj, uint32_t const subjobId, context const & c);
};

} // namespace detail
} // namespace parlex

#endif // STATE_MACHINE_BASE_HPP
