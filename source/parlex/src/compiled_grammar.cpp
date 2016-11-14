

#include "parlex/compiled_grammar.hpp"

namespace parlex {

std::map<std::string, state_machine_base const *> transform_productions(std::vector<std::reference_wrapper<state_machine_base const>> productions) {
	std::map<std::string, state_machine_base const *> results;
	for (auto const & i : productions) {
		results[i.get().id] = &i.get();
	}
	return results;
}

compiled_grammar::compiled_grammar(
		state_machine_base const & main,
		std::vector<std::reference_wrapper<state_machine_base const>> productions,
		std::vector<std::pair<std::reference_wrapper<state_machine_base const>,
		std::reference_wrapper<state_machine_base const>>> precedences
) : 
		main(&main),
		productions(transform_productions(productions))
{
	for (auto const & i : precedences) {
		add_precedence(i.first, i.second);
	}
}

state_machine_base const & compiled_grammar::get_main_production() const
{
	return *main;
}

std::map<std::string, state_machine_base const *> compiled_grammar::get_productions() const
{
	return productions;
}

}