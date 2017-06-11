#ifndef BUILDER_HPP
#define BUILDER_HPP

#include "parlex/state_machine_base.hpp"
#include "parlex/details/string_terminal.hpp"
#include "parlex/builtins.hpp"

#define DECLARE_DFA(name) \
	class name##_t : public parlex::state_machine_base { \
	public: \
		name##_t(parlex::builtins_t const & builtins); \
		void process(parlex::details::context_ref const & c, size_t dfaState) const override; \
		parlex::builtins_t const & builtins; \
		int get_start_state() const final; \
		parlex::filter_function get_filter() const final; \
		parlex::associativity get_assoc() const final; \
	}

#define DEFINE_TERMINAL(name, U32content) static parlex::details::string_terminal name(U32content)

#define DEFINE_DFA(name, cases, startStates) \
	name##_t::name##_t(parlex::builtins_t const & builtins) : state_machine_base(#name), builtins(builtins) {} \
	void name##_t::process(parlex::details::context_ref const & c, size_t dfaState) const { \
		switch (dfaState) { \
		cases \
		default: \
			throw std::logic_error("invalid state: " + std::to_string(dfaState)); \
		} \
	} \
	name##_t name

#define DFA_STATE case
#define DFA_ACCEPT accept(c)
#define DFA_EDGE(recognizer, out_neighbor) on(c, recognizer, out_neighbor)

#define DEFINE_GRAMMAR(builtins, name, main, productions, precedences) \
	parlex::compiled_grammar name(builtins, main, std::vector<std::reference_wrapper<parlex::state_machine_base const>>productions, std::vector<std::pair<std::reference_wrapper<parlex::state_machine_base const>, std::reference_wrapper<parlex::state_machine_base const>>>precedences)

#define GRAMMAR_PRECEDENCE(a, b) (std::pair<std::reference_wrapper<parlex::state_machine_base const>, std::reference_wrapper<parlex::state_machine_base const>>(a, b))

#endif //BUILDER_HPP
