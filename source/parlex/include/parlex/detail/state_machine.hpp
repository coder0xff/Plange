#ifndef CORRELATED_STATE_MACHINE_HPP
#define CORRELATED_STATE_MACHINE_HPP

#include "coherent_map.hpp"

#include "parlex/associativity.hpp"
#include "parlex/builder.hpp"
#include "parlex/filter_function.hpp"
#include "parlex/detail/nfa.hpp"
#include "parlex/detail/recognizer.hpp"
#include "parlex/detail/state_machine.hpp"


namespace parlex {
namespace detail {
class configuration;
class job;

struct leaf;
struct node;

class parser;
class subjob;

//simulates a dfa
//State 0 is the start state
//States from N-a to N-1 are the accept states, where N is states.size() and a is accept_state_count
class state_machine : public recognizer {
public:
	struct transition_info_t {
		leaf const * l;
		uint16_t recognizer_index;

		bool operator<(transition_info_t const & rhs) const {
			return l < rhs.l;
		}
	};

	typedef std::vector<collections::coherent_map<transition_info_t, uint8_t>> states_t;

	state_machine(std::string const & name, filter_function const & filter, associativity assoc);
	virtual ~state_machine() = default;

	filter_function const filter;
	associativity const assoc;
	node const * behavior;
	uint8_t start_state;
	uint8_t accept_state_count; //must be greater than 0
	void set_behavior(node & behavior);
	std::string to_dot(std::vector<recognizer const *> const & recognizers) const;
	collections::coherent_map<transition_info_t, uint8_t> const & get_transitions(size_t stateIndex) const;
private:
	friend class parser;
	friend class subjob;

	states_t states;

	void process(job & j, subjob & mySubjob, match_class const & mySubjobId, configuration const & c, uint8_t const dfaState) const;
	void start(job & j, subjob & mySubjob, match_class const & mySubjobId, configuration const & c) const;
	static void on(job & j, subjob & mySubjob, match_class const & mySubjobId, uint16_t const requestedRecognizerIndex, configuration const & c, uint8_t const nextDfaState, leaf const * leaf);
	static void accept(job & j, subjob & mySubjob, match_class const & mySubjobId, configuration const & c);
	static automaton reorder(automaton const & dfa);

public:
	bool is_terminal() const override;
	uint8_t get_start_state() const;
	filter_function get_filter() const;
	associativity get_assoc() const;
};

} // namespace detail
} // namespace parlex

#endif //CORRELATED_STATE_MACHINE_HPP
