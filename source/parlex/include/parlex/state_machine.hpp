#ifndef STATE_MACHINE_HPP
#define STATE_MACHINE_HPP

#include <memory>

#include "parlex/recognizer.hpp"
#include "parlex/filter_function.hpp"
#include "parlex/associativity.hpp"

namespace parlex {
namespace details {

class context_ref;
class subjob;

}

class parser;

//simulates a dfa
//State 0 is the start state
//States from N-a to N-1 are the accept states, where N is states.size() and a is accept_state_count
class state_machine : public recognizer {
public:
	state_machine(std::string id, size_t startState, size_t acceptStateCount, associativity assoc=associativity::none);
	state_machine(std::string id, size_t startState, size_t acceptStateCount, filter_function const & filter, associativity assoc = associativity::none);
	virtual ~state_machine() = default;
	void add_transition(size_t fromState, recognizer const & recognizer, size_t toState);
	virtual std::string get_id() const final;
	size_t get_start_state() const;
 	size_t get_accept_state_count() const;
	filter_function const * get_filter() const;
	associativity get_associativity() const;

	typedef std::vector<std::map<std::reference_wrapper<recognizer const>, size_t, details::recognizer_reference_comparer>> states_t;
 	states_t get_states() const;
private:
	friend class parser;
	friend class details::subjob;

	std::string const id;
	size_t const start_state;
	size_t const accept_state_count; //must be greater than 0
	states_t states;
	filter_function const * const filter;
	associativity const assoc;

	void start(details::subjob & sj, size_t documentPosition) const;
	void process(details::context_ref const & c, size_t dfaState) const;
};

}

#endif
