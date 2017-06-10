#ifndef GRAMMAR2_HPP
#define GRAMMAR2_HPP

#include <map>
#include <set>

#include "parlex/details/string_terminal.hpp"
#include "parlex/details/behavior2.hpp"
#include "state_machine2.hpp"

namespace parlex {
class builtins_t;

class grammar2 {
public:
	typedef std::map<recognizer const *, std::set<recognizer const *>> precedence_collection;

	struct production {
		production(std::string const & id, erased<behavior2::node> const & behavior, filter_function const & filter, associativity assoc = associativity::none);
		production(std::string const & id, erased<behavior2::node> const & behavior, associativity assoc = associativity::none);
		erased<behavior2::node> const behavior;
		state_machine2 const state_machine;
	};

	grammar2(builtins_t const & builtins, std::string const & mainProductionName);

	builtins_t const & builtins;
	std::string const main_production_name;
	std::map<std::string, production> productions;
	std::map<std::u32string, details::string_terminal> literals;
	precedence_collection precedences;

	state_machine_base2 const & get_main_production() const;
	details::string_terminal & get_or_add_literal(std::u32string const & contents);
};

}

#endif
