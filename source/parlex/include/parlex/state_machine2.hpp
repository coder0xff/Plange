#ifndef STATE_MACHINE2_HPP
#define STATE_MACHINE2_HPP

#include <map>

#include "parlex/details/behavior2.hpp"
#include "recognizer.hpp"
#include "filter_function.hpp"
#include "associativity.hpp"
#include "state_machine_base.hpp"
#include "state_machine_base2.hpp"

namespace parlex {
namespace details {

class context_ref;
class subjob;

}

class parser;

//simulates a dfa
//State 0 is the start state
//States from N-a to N-1 are the accept states, where N is states.size() and a is accept_state_count
class state_machine2 : public state_machine_base2 {
public:
	typedef std::vector<std::map<behavior2::leaf const *, size_t>> states_t;

	state_machine2(std::string id, behavior2::nfa const & dfa, filter_function const & filter, associativity = associativity::none);
	state_machine2(std::string id, behavior2::nfa const & dfa, associativity = associativity::none);
	virtual ~state_machine2() = default;

	filter_function filter;
	associativity assoc;
	int start_state;
	size_t accept_state_count; //must be greater than 0
	states_t states;

private:
	friend class parser;
	friend class details::subjob;

	void process(details::context_ref const & c, size_t dfaState) const override;
	static behavior2::nfa reorder(behavior2::nfa const & original);
public:
	bool is_terminal() const override;
	int get_start_state() const override;
	filter_function get_filter() const override;
	associativity get_assoc() const override;
};

}

#endif
