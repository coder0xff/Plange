#ifndef CORRELATED_GRAMMAR_HPP
#define CORRELATED_GRAMMAR_HPP

#include <map>
#include <set>

#include "parlex/details/string_terminal.hpp"
#include "parlex/behavior.hpp"
#include "parlex/correlated_state_machine.hpp"
#include "parlex/precedence_collection.hpp"
#include "parlex/grammar_base.hpp"

namespace parlex {
class builtins_t;
class correlated_grammar;

// you must first create all the productions objects
// then create the behaviors
// then call set_behavior on each production
class correlated_grammar : public grammar_base {
public:
	struct production {
		production(correlated_state_machine_info const & info);
	private:
		friend class correlated_grammar;
		correlated_state_machine state_machine;
		std::unique_ptr<behavior::node> behavior;
		void set_behavior(erased<behavior::node> const & behavior);
	};

	correlated_grammar(builtins_t const & builtins, std::string const & rootName, std::vector<correlated_state_machine_info> const & infos, std::function<erased<behavior::node> (std::string const &, correlated_grammar & g)> behavior_function);
	virtual ~correlated_grammar() = default;

	std::string const root_name;
	std::map<std::u32string, details::string_terminal> literals;
	std::map<correlated_state_machine const *, std::set<correlated_state_machine const *>> precedences;

	details::string_terminal& get_or_add_literal(std::u32string const & contents);
	correlated_state_machine const& get_state_machine(std::string const & id) const;

	state_machine_base const& get_main_production() const override;
	std::map<std::string, state_machine_base const *> get_productions() const override;
	bool test_precedence(state_machine_base const & productionA, state_machine_base const & productionB) const override;
	precedence_collection get_precedences() const override;
private:
	std::map<std::string, production> productions;
};

} //namespace parlex

#endif //CORRELATED_GRAMMAR_HPP
