#ifndef COMPILED_GRAMMAR_HPP
#define COMPILED_GRAMMAR_HPP

#include "parlex/grammar_base.hpp"

namespace parlex {
	
class compiled_grammar : public grammar_base {
	
public:
	compiled_grammar::compiled_grammar(
		state_machine_base const & main,
		std::vector<std::reference_wrapper<state_machine_base const>> productions,
		std::vector<std::pair<std::reference_wrapper<state_machine_base const>, std::reference_wrapper<state_machine_base const>>> precedences
	);
	state_machine_base const & get_main_production() const override final;
	std::map<std::string, state_machine_base const *> get_productions() const override final;
private:
	state_machine_base const * const main;
	std::map<std::string, state_machine_base const *> const productions;
};

}

#endif