#ifndef GRAMMAR_HPP
#define GRAMMAR_HPP

#include <map>
#include <set>

#include "parlex/state_machine.hpp"
#include "parlex/builtins/string_terminal.hpp"
#include "parlex/precedence_collection.hpp"

namespace parlex {

namespace details {

class behavior_node;

}

struct production_def {
	std::shared_ptr<details::behavior_node> tree;
	parlex::associativity assoc;
	std::set<std::string> precedences;
	filter_function const * filter;
};

class grammar {
public:
	grammar(std::string const & nameOfMain);
    grammar(std::string const & nameOfMain, std::map<std::string, std::shared_ptr<details::behavior_node>> const & trees, std::map<std::string, parlex::associativity> const & associativities, std::set<std::string> const & greedyNames);
    grammar(std::string const & nameOfMain, std::map<std::string, production_def> const & productions);
    grammar(grammar const & other);
	state_machine const & get_main_production() const;
	grammar& operator=(grammar const &) = delete;
	void generate_cpp(std::string grammarName, std::string nameOfMain, std::ostream & cpp, std::ostream & hpp, std::string headerPath = "") const;
	std::map<std::string, state_machine> const & get_productions() const;
	state_machine & add_production(std::string id, size_t startState, size_t acceptStateCount, associativity assoc = associativity::none);
	state_machine & add_production(std::string id, size_t startState, size_t acceptStateCount, filter_function const * filter, associativity assoc = associativity::none);
	builtins::string_terminal & add_literal(std::u32string contents);
	void add_precedence(state_machine const & productionA, state_machine const & productionB);
	bool test_precedence(state_machine const & productionA, state_machine const & productionB) const;
	precedence_collection const & get_precedences() const;
	std::map<std::u32string, builtins::string_terminal> const & get_literals() const;
private:
	std::string main_production_name;
	std::map<std::string, state_machine> productions;
	std::map<std::u32string, builtins::string_terminal> literals;
	precedence_collection precedences;
};

}

#endif
