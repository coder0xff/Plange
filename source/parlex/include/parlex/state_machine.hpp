#ifndef STATE_MACHINE_HPP
#define STATE_MACHINE_HPP

#include <map>

#include "parlex/recognizer.hpp"
#include "parlex/filter_function.hpp"
#include "parlex/associativity.hpp"
#include "parlex/state_machine_base2.hpp"
#include "details/nfa.hpp"

namespace parlex {
namespace behavior2 {

class node;
class leaf;
using nfa2 = details::nfa<leaf const *, int>;

} // namespace behavior2

namespace details {

class context_ref;
class subjob;

} // namespace details

class parser;

//simulates a dfa
//State 0 is the start state
//States from N-a to N-1 are the accept states, where N is states.size() and a is accept_state_count
class state_machine : public state_machine_base2 {
public:
	typedef std::vector<std::map<recognizer const *, size_t>> states_t;

	state_machine(std::string const & id, int startState, int acceptStateCount, filter_function const & filter, associativity = associativity::none);
	state_machine(std::string const & id, filter_function const & filter, associativity = associativity::none);
	state_machine(std::string const & id, associativity = associativity::none);
	virtual ~state_machine() = default;

	filter_function filter;
	associativity assoc;
	states_t states;
	int start_state;
	size_t accept_state_count; //must be greater than 0
private:
	friend class parser;
	friend class details::subjob;

	void process(details::context_ref const & c, size_t dfaState) const override;

public:
	bool is_terminal() const override;
	int get_start_state() const override;
	filter_function get_filter() const override;
	associativity get_assoc() const override;
};

} // namespace parlex

#endif //STATE_MACHINE_HPP
