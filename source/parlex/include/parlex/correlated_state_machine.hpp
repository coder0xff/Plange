#ifndef CORRELATED_STATE_MACHINE_HPP
#define CORRELATED_STATE_MACHINE_HPP

#include <map>

#include "parlex/associativity.hpp"
#include "parlex/filter_function.hpp"
#include "parlex/state_machine_base.hpp"

#include "parlex/details/nfa.hpp"

namespace parlex {
namespace behavior {

class node;
class leaf;
using nfa2 = details::nfa<leaf const *, size_t>;

} // namespace behavior

namespace details {

class context_ref;
class subjob;

} // namespace details

class parser;

//simulates a dfa
//State 0 is the start state
//States from N-a to N-1 are the accept states, where N is states.size() and a is accept_state_count
class correlated_state_machine : public state_machine_base {
public:
	typedef std::vector<std::map<behavior::leaf const *, size_t>> states_t;

	correlated_state_machine(std::string const & id, filter_function const & filter, associativity assoc);
	virtual ~correlated_state_machine() = default;

	filter_function const filter;
	associativity const assoc;
	behavior::node const * behavior;
	int start_state;
	size_t accept_state_count; //must be greater than 0
	void set_behavior(behavior::node const & behavior);
	std::string to_dot() const;
private:
	friend class parser;
	friend class details::subjob;

	states_t states;

	void process(details::context_ref const & c, size_t dfaState) const override;
	static behavior::nfa2 reorder(behavior::nfa2 dfa);

public:
	bool is_terminal() const override;
	int get_start_state() const override;
	filter_function get_filter() const override;
	associativity get_assoc() const override;
};

} // namespace parlex

#endif //CORRELATED_STATE_MACHINE_HPP
