#ifndef GRAMMAR2_HPP
#define GRAMMAR2_HPP

#include <map>
#include <set>

#include "parlex/details/string_terminal.hpp"
#include "parlex/behavior2.hpp"
#include "parlex/state_machine2.hpp"
#include "parlex/precedence_collection.hpp"
#include "parlex/grammar_base.hpp"

namespace parlex {
class builtins_t;
class grammar2;

// you must first create all the productions objects
// then create the behaviors
// then call set_behavior on each production
class grammar2 : public grammar_base {
public:
	struct production {
		production(state_machine2_info const & info);
	private:
		friend class grammar2;
		state_machine2 state_machine;
		std::unique_ptr<behavior2::node> behavior;
		void set_behavior(erased<behavior2::node> const & behavior);
	};

	grammar2(builtins_t const & builtins, std::string const & rootName, std::vector<state_machine2_info> const & infos, std::function<erased<behavior2::node> (std::string const &, grammar2 & g)> behavior_function);
	virtual ~grammar2() = default;

	std::string const root_name;
	std::map<std::u32string, details::string_terminal> literals;
	std::map<state_machine2 const *, std::set<state_machine2 const *>> precedences;

	details::string_terminal& get_or_add_literal(std::u32string const & contents);
	state_machine2 const& get_state_machine(std::string const & id) const;

	state_machine_base2 const& get_main_production() const override;
	std::map<std::string, state_machine_base2 const *> get_productions() const override;
	bool test_precedence(state_machine_base2 const & productionA, state_machine_base2 const & productionB) const override;
	precedence_collection get_precedences() const override;
private:
	std::map<std::string, production> productions;
};

} //namespace parlex

#endif //GRAMMAR2_HPP
