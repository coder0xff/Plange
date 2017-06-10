#ifndef STATE_MACHINE_HPP
#define STATE_MACHINE_HPP

#include <map>

#include "recognizer.hpp"
#include "filter_function.hpp"
#include "associativity.hpp"
#include "state_machine_base.hpp"

namespace parlex {
namespace details {

class context_ref;
class subjob;

}

class parser;

//simulates a dfa
//State 0 is the start state
//States from N-a to N-1 are the accept states, where N is states.size() and a is accept_state_count
class state_machine : public state_machine_base {
public:
	size_t const accept_state_count; //must be greater than 0

	state_machine(std::string id, size_t startState, size_t acceptStateCount, associativity assoc = associativity::none);
	state_machine(std::string id, size_t startState, size_t acceptStateCount, filter_function const & filter, associativity assoc = associativity::none);
	virtual ~state_machine() = default;
	void add_transition(size_t fromState, recognizer const & recognizer, size_t toState);
	typedef std::vector<std::map<std::reference_wrapper<recognizer const>, size_t, details::recognizer_reference_comparer>> states_t;
	states_t get_states() const;
private:
	friend class parser;
	friend class details::subjob;

	states_t states;

	void process(details::context_ref const & c, size_t dfaState) const override;
};

}

#endif
