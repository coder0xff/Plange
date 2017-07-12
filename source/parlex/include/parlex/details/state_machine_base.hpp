#ifndef STATE_MACHINE_BASE_HPP
#define STATE_MACHINE_BASE_HPP

#include "parlex/filter_function.hpp"
#include "parlex/associativity.hpp"

#include "parlex/details/recognizer.hpp"

namespace parlex {
namespace behavior {

class node;

} // namespace behavior

namespace details {

class context;
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

	state_machine_base(std::string const & id);
	void start(subjob & sj, size_t documentPosition) const;
	virtual void process(context* const & c, size_t dfaState) const = 0;
	static void on(context* const & c, recognizer const & r, int nextDfaState, behavior::leaf const * leaf);
	static void accept(context* const & c);
};

} // namespace details
} // namespace parlex

#endif // STATE_MACHINE_BASE_HPP
