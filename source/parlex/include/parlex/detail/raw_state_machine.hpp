#ifndef RAW_STATE_MACHINE_HPP
#define RAW_STATE_MACHINE_HPP

#include <map>

#include "parlex/associativity.hpp"
#include "parlex/filter_function.hpp"

#include "parlex/detail/nfa.hpp"
#include "parlex/detail/state_machine_base.hpp"

namespace parlex {
namespace detail {
namespace behavior {

class node;
class leaf;
using nfa2 = nfa<leaf const *, size_t>;

} // namespace behavior

class context;
class subjob;
class parser;

//simulates a dfa
//State 0 is the start state
//States from N-a to N-1 are the accept states, where N is states.size() and a is accept_state_count
class raw_state_machine : public state_machine_base {
public:
	typedef std::vector<std::map<recognizer const *, size_t>> states_t;

	raw_state_machine(std::string const & id, int startState, int acceptStateCount, filter_function const & filter, associativity = associativity::NONE);
	virtual ~raw_state_machine() = default;

	filter_function const filter;
	associativity const assoc;
	int const start_state;
	size_t const accept_state_count; //must be greater than 0

	void add_transition(size_t from, recognizer const * transition, size_t to);
	states_t const& get_states() const;
private:
	friend class parser;
	friend class subjob;

	states_t states;

	void process(context const & c, size_t dfaState) const override;

public:
	bool is_terminal() const override;
	int get_start_state() const override;
	filter_function get_filter() const override;
	associativity get_assoc() const override;
};


} // namespace detail
} // namespace parlex

#endif //RAW_STATE_MACHINE_HPP
