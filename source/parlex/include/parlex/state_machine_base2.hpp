#ifndef STATE_MACHINE_BASE2_HPP
#define STATE_MACHINE_BASE2_HPP

#include "parlex/recognizer.hpp"
#include "parlex/filter_function.hpp"
#include "parlex/associativity.hpp"

namespace parlex {
namespace behavior2 {

class node;

} // namespace behavior2

namespace details {

class context_ref;
class subjob;

} // namespace details

class parser;

//simulates a dfa
//State 0 is the start state
//States from N-a to N-1 are the accept states, where N is states.size() and a is accept_state_count
class state_machine_base2 : public recognizer {
public:
	state_machine_base2(std::string const & id);
	virtual ~state_machine_base2() = default;
	virtual int get_start_state() const = 0;
	virtual filter_function get_filter() const = 0;
	virtual associativity get_assoc() const = 0;
protected:
	friend class parser;
	friend class details::subjob;

	void start(details::subjob & sj, size_t documentPosition) const;
	virtual void process(details::context_ref const & c, size_t dfaState) const = 0;
	static void on(details::context_ref const & c, recognizer const & r, int nextDfaState, behavior2::leaf const * leaf);
	static void accept(details::context_ref const & c);
};

} // namespace parlex

#endif // STATE_MACHINE_BASE2_HPP