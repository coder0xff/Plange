#ifndef GRAMMAR_HPP
#define GRAMMAR_HPP

#include <map>
#include <string>
#include <set>

#include "parlex/state_machine.hpp"
#include "parlex/builtins/string_terminal.hpp"

namespace parlex {

namespace details {

class behavior_node;

}

class grammar {
public:
	grammar(std::string nameOfMain);
    grammar(std::string nameOfMain, std::map<std::string, std::shared_ptr<details::behavior_node>> const & trees, std::set<std::string> greedyNames);
    grammar(grammar const & other);
	state_machine const & get_main_production() const;
	grammar& operator=(grammar const &) = delete;
	void generate_cpp(std::string grammarName, std::string nameOfMain, std::ostream & cpp, std::ostream & hpp) const;
	std::map<std::string, state_machine> const & get_productions() const;
	state_machine & add_production(std::string id, size_t startState, size_t acceptStateCount, associativity assoc = associativity::none);
	state_machine & add_production(std::string id, size_t startState, size_t acceptStateCount, filter_function const & filter, associativity assoc = associativity::none);
	builtins::string_terminal & add_literal(std::u32string contents);
	void add_precedence(state_machine const & productionA, state_machine const & productionB);
private:
	std::string main_production_name;
	std::map<std::string, state_machine> productions;
	std::list<builtins::string_terminal> literals;
	std::map<state_machine const *, std::set<state_machine const *>> precedence;
};

}

#endif
