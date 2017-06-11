#ifndef STATE_MACHINE2_HPP
#define STATE_MACHINE2_HPP

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

struct state_machine2_info {
	state_machine2_info(std::string const & id, filter_function const & filter, associativity assoc = associativity::none);
	state_machine2_info(std::string const & id, associativity assoc = associativity::none);

	std::string const id;
	filter_function const filter;
	associativity const assoc;

};
//simulates a dfa
//State 0 is the start state
//States from N-a to N-1 are the accept states, where N is states.size() and a is accept_state_count
class state_machine2 : public state_machine_base2 {
public:
	typedef std::vector<std::map<behavior2::leaf const *, size_t>> states_t;

	state_machine2(state_machine2_info const & info);
	virtual ~state_machine2() = default;

	filter_function const filter;
	associativity const assoc;
	behavior2::node const * behavior;
	states_t states;
	int start_state;
	size_t accept_state_count; //must be greater than 0
	void set_behavior(behavior2::node const & behavior);
private:
	friend class parser;
	friend class details::subjob;

	void process(details::context_ref const & c, size_t dfaState) const override;
	static behavior2::nfa2 reorder(behavior2::nfa2 const & original);

public:
	bool is_terminal() const override;
	int get_start_state() const override;
	filter_function get_filter() const override;
	associativity get_assoc() const override;
};

} // namespace parlex

#endif //STATE_MACHINE2_HPP
