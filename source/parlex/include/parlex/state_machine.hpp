#ifndef STATE_MACHINE_HPP
#define STATE_MACHINE_HPP

#include <memory>

#include "parlex/recognizer.hpp"
#include "filter_function.hpp"

namespace parlex {
namespace details {

class context_ref;

}

class parser;

//simulates a dfa
//State 0 is the start state
//States from N-a to N-1 are the accept states, where N is states.size() and a is accept_state_count
class state_machine : public recognizer {
public:
	state_machine(std::string id, size_t acceptStateCount);
	state_machine(std::string id, size_t acceptStateCount, filter_function filter);
	virtual ~state_machine() = default;
	void start(details::subjob & sj, size_t documentPosition) const;
	void add_transition(size_t fromState, recognizer const & recognizer, size_t toState);
	virtual std::string get_id() const final;
	filter_function get_filter() const;

private:
	friend class parser;

	std::string const id;
	size_t const accept_state_count; //must be greater than 0
	typedef std::vector<std::map<std::reference_wrapper<recognizer const>, size_t, details::recognizer_reference_comparer>> states_t;
	states_t states;
	filter_function const filter;

	void process(details::context_ref const & c, size_t dfaState) const;
};

}

#endif
