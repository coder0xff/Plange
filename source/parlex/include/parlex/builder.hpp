#ifndef BUILDER_HPP
#define BUILDER_HPP

#include "parlex/state_machine_base.hpp"
#include "parlex/compiled_grammar.hpp"
#include "parlex/details/string_terminal.hpp"

#define DECLARE_DFA(name) \
	class name##_t : public parlex::state_machine_base { \
	public: \
		name##_t(builtins_t const & builtins); \
		void process(parlex::details::context_ref const & c, size_t dfaState) const override; \
		builtins const & builtins; \
	} name##_t name

#define DEFINE_TERMINAL(name, U32content) static parlex::details::string_terminal name(U32content)

#define DEFINE_DFA(name, cases, ...) \
	name##_t::name##_t() : state_machine_base(#name, __VA_ARGS__) {} \
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