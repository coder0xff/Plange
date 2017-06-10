#ifndef GRAMMAR_HPP
#define GRAMMAR_HPP

#include <map>
#include <memory>
#include <set>

#include "parlex/state_machine.hpp"
#include "parlex/details/string_terminal.hpp"
#include "grammar_base.hpp"
#include <list>

namespace parlex {

namespace details {

class behavior_node;

}

class builtins_t;

class grammar final: public grammar_base {
public:
	struct production_def {
		std::shared_ptr<details::behavior_node> tree;
		associativity assoc;
		std::set<std::string> precedences;
		filter_function filter;
	};

	grammar(builtins_t const & builtins, std::string const & nameOfMain);
    grammar(builtins_t const & builtins, std::string const & nameOfMain, std::map<std::string, std::shared_ptr<details::behavior_node>> const & trees, std::map<std::string, associativity> const & associativities, std::set<std::string> const & longestNames);
    grammar(builtins_t const & builtins, std::string const & nameOfMain, std::map<std::string, production_def> const & productions);
    grammar(grammar const & other);
	state_machine_base const & get_main_production() const override;
	grammar& operator=(grammar const &) = delete;
	void generate_hpp(std::string grammarName, std::ostream & hpp, std::string namespace_, std::string upperCaseGrammarName) const;
	void generate_representation(std::ostream & cpp);
	void generate_cplusplus_code(builtins_t const & builtins, std::string grammarName, std::string nameOfMain, std::ostream & cpp, std::ostream & hpp, std::string namespace_, std::string headerPathPrefix = "") const;
	std::map<std::string, state_machine_base const *> get_productions() const override;
	state_machine & add_production(std::string id, size_t startState, size_t acceptStateCount, associativity assoc = none);
	state_machine & add_production(std::string id, size_t startState, size_t acceptStateCount, filter_function filter, associativity assoc = none);
	details::string_terminal & add_literal(std::u32string contents);
	std::map<std::u32string, details::string_terminal> const & get_literals() const;
	static std::string hierarchy_dot(std::map<std::string, production_def> const & productions);
private:
	std::string main_production_name;
	std::map<std::string, production_def> definitions;
	std::map<std::string, state_machine> productions;
	std::map<std::u32string, details::string_terminal> literals;
};

}

#endif
