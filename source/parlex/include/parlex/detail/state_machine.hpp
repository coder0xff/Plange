#ifndef CORRELATED_STATE_MACHINE_HPP
#define CORRELATED_STATE_MACHINE_HPP

#include <map>

#include "parlex/associativity.hpp"
#include "parlex/filter_function.hpp"

#include "parlex/detail/nfa.hpp"
#include "parlex/detail/state_machine_base.hpp"
#include "coherent_map.hpp"


namespace parlex {
namespace detail {

struct leaf;
struct node;
using automaton = nfa<leaf const *, size_t>;

class parser;
class subjob;

//simulates a dfa
//State 0 is the start state
//States from N-a to N-1 are the accept states, where N is states.size() and a is accept_state_count
class state_machine : public state_machine_base {
public:
	struct transition_info_t {
		leaf const * l;
		size_t recognizer_index;

		bool operator<(transition_info_t const & rhs) const {
			return l < rhs.l;
		}
	};

	typedef std::vector<collections::coherent_map<transition_info_t, size_t>> states_t;

	state_machine(std::string const & name, filter_function const & filter, associativity assoc);
	virtual ~state_machine() = default;

	filter_function const filter;
	associativity const assoc;
	node const * behavior;
	int start_state;
	size_t accept_state_count; //must be greater than 0
	void set_behavior(std::map<recognizer const *, size_t> const & recognizerLookup, node & behavior);
	std::string to_dot(std::vector<recognizer const *> const & recognizers) const;
private:
	friend class parser;
	friend class subjob;

	states_t states;

	void process(context const & c, size_t dfaState) const override;
	static automaton reorder(automaton const & dfa);

public:
	bool is_terminal() const override;
	int get_start_state() const override;
	filter_function get_filter() const override;
	associativity get_assoc() const override;
};

} // namespace detail
} // namespace parlex

#endif //CORRELATED_STATE_MACHINE_HPP
