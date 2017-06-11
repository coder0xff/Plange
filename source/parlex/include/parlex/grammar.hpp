#ifndef GRAMMAR_HPP
#define GRAMMAR_HPP

#include <map>
#include <memory>
#include <set>

#include "parlex/state_machine.hpp"
#include "parlex/details/string_terminal.hpp"
#include "parlex/grammar_base.hpp"

namespace parlex {

namespace details {

class behavior_node;

} // namespace details

class builtins_t;

class grammar : public grammar_base {
public:
	grammar(builtins_t const & builtins, std::string const & nameOfMain);
	grammar(grammar const & other);
	virtual ~grammar() = default;

	state_machine_base const& get_main_production() const override;
	grammar& operator=(grammar const &) = delete;
	void generate_hpp(std::string grammarName, std::ostream & hpp, std::string namespace_, std::string upperCaseGrammarName) const;
	//void generate_representation(std::ostream & cpp);
	void generate_cplusplus_code(builtins_t const & builtins, std::string grammarName, std::string nameOfMain, std::ostream & cpp, std::ostream & hpp, std::string namespace_, std::string headerPathPrefix = "") const;
	std::map<std::string, state_machine_base const *> get_productions() const override;
	state_machine& add_production(std::string id, size_t startState, size_t acceptStateCount, associativity assoc = associativity::none);
	state_machine& add_production(std::string id, size_t startState, size_t acceptStateCount, filter_function filter, associativity assoc = associativity::none);
	details::string_terminal const& get_add_literal(std::u32string contents);
	std::map<std::u32string, details::string_terminal> const& get_literals() const;
	//std::string hierarchy_dot() const;
	bool test_precedence(state_machine_base const & productionA, state_machine_base const & productionB) const override;
	precedence_collection get_precedences() const override;
	std::map<state_machine const *, std::set<state_machine const *>> precedences;
	details::string_terminal& get_or_add_literal(std::u32string const & contents);
private:
	std::string main_production_name;
	std::map<std::string, state_machine> productions;
	std::map<std::u32string, details::string_terminal> literals;
};

} // namespace parlex

#endif //GRAMMAR_HPP
