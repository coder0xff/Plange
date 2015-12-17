#ifndef STATE_MACHINE_HPP
#define STATE_MACHINE_HPP

#include <memory>

#include "recognizer.hpp"
#include "details/context.hpp"
#include "filter_function.hpp"

namespace parlex {

class parser;

//simulates a dfa
//State 0 is the start state
//States from N-a to N-1 are the accept states, where N is states.size() and a is accept_state_count
class state_machine : public recognizer {
public:
	state_machine(std::string id, int acceptStateCount);
	state_machine(std::string id, int acceptStateCount, filter_function filter);
	virtual ~state_machine() = default;
	void start(details::subjob & sj, int documentPosition) const;
	void add_transition(int fromState, recognizer const & recognizer, int toState);
	virtual std::string get_id() const final;
	filter_function get_filter() const;

private:
	friend class parser;

	std::string const id;
	int const accept_state_count; //must be greater than 0
	std::vector<std::map<std::reference_wrapper<recognizer const>, int, details::recognizer_reference_comparer>> states;
	filter_function const filter;

	void process(details::context_ref const & c, int dfaState) const;
};

}

#endif
