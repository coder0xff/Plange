#ifndef RAW_GRAMMAR_HPP
#define RAW_GRAMMAR_HPP

#include "parlex/details/raw_grammar.hpp"

#include <map>
#include <memory>
#include <set>

#include "parlex/details/grammar_base.hpp"
#include "parlex/details/raw_state_machine.hpp"
#include "parlex/details/string_terminal.hpp"

namespace parlex {
namespace details {

class behavior_node;
class builtins_t;

class raw_grammar : public grammar_base {
public:
	raw_grammar(std::string const & nameOfMain);
	raw_grammar(raw_grammar const & other);
	virtual ~raw_grammar() = default;

	state_machine_base const& get_main_state_machine() const override;
	raw_grammar& operator=(raw_grammar const &) = delete;
	void generate_hpp(std::string grammarName, std::ostream & hpp, std::string namespace_, std::string upperCaseGrammarName) const;
	//void generate_representation(std::ostream & cpp);
	void generate_cplusplus_code(std::string grammarName, std::string nameOfMain, std::ostream & cpp, std::ostream & hpp, std::string namespace_, std::string headerPathPrefix = "") const;
	std::map<std::string, state_machine_base const *> get_state_machines() const override;
	state_machine_base const& get_state_machine(std::string const & id) const override;
	string_terminal const& get_literal(std::string const & id) const override;
	raw_state_machine& add_production(std::string id, size_t startState, size_t acceptStateCount, associativity assoc = associativity::none);
	raw_state_machine& add_production(std::string id, size_t startState, size_t acceptStateCount, filter_function filter, associativity assoc = associativity::none);
	string_terminal const& get_add_literal(std::u32string contents);
	//std::string hierarchy_dot() const;
	bool test_precedence(state_machine_base const & productionA, state_machine_base const & productionB) const override;
	precedence_collection get_precedences() const override;
	std::map<raw_state_machine const *, std::set<raw_state_machine const *>> precedences;
	string_terminal& get_or_add_literal(std::u32string const & contents);

private:
	std::string main_production_name;
	std::map<std::string, raw_state_machine> productions;
	std::map<std::u32string, string_terminal> literals;
};


} // namespace details
} // namespace parlex

#endif //RAW_GRAMMAR_HPP
