#ifndef WIRTH_HPP
#define WIRTH_HPP

#include "parlex/grammar.hpp"
#include "parlex/state_machine.hpp"
#include "parlex/details/behavior.hpp"
#include "parlex/filter_function.hpp"

namespace parlex {
struct abstract_syntax_graph;

class builtins_t;

namespace details {

/* similar to https://en.wikipedia.org/wiki/Wirth_syntax_notation but with tagging (TWSN)

SYNTAX        = { PRODUCTION } .

PRODUCTION    = IDENTIFIER "=" EXPRESSION "." .

EXPRESSION    = TERM { "|" TERM } .

TERM          = FACTOR { FACTOR } .

PARENTHETICAL = "[" EXPRESSION "]"
			  | "(" EXPRESSION ")"
			  | "{" EXPRESSION "}" .

TAG           = "%" IDENTIFIER

FACTOR        = ["$"] IDENTIFIER
			  | ["$"] LITERAL
			  | [TAG] PARENTHETICAL

*/

class wirth_t final : public grammar_base {
public:
	struct production_def {
		std::u32string definition;
		associativity assoc;
		std::set<std::string> precedences;
		filter_function filter;
	};

	wirth_t(parser const & p);
	state_machine_base const & get_main_production() const override;
	std::map<std::string, state_machine_base const *> get_productions() const override;

	grammar load_grammar(std::string const & nameOfMain, std::u32string const & document, std::map<std::string, associativity> const & associativities, std::set<std::string> const & longestNames);
	grammar load_grammar(std::string const & nameOfMain, std::map<std::string, production_def> const & productions);
private:
	static std::shared_ptr<behavior_node> get_or_add_production(std::map<std::string, std::shared_ptr<production>> & productionNodes, std::string name);
	static std::shared_ptr<behavior_node> get_or_add_literal(std::map<std::u32string, std::shared_ptr<literal>> & literalNodes, std::u32string temp);

	parser const & p;
	grammar g;

	string_terminal & newline;
	string_terminal & hash;
	string_terminal & period;
	string_terminal & equals;
	string_terminal & quote;
	string_terminal & pipe;
	string_terminal & openSquare;
	string_terminal & closeSquare;
	string_terminal & openParen;
	string_terminal & closeParen;
	string_terminal & openCurly;
	string_terminal & closeCurly;
	string_terminal & underscore;
	string_terminal & dollarSign;
	string_terminal & percentageSign;

	state_machine & whiteSpaceDfa;
	state_machine & commentDfa;
	state_machine & productionDfa;
	state_machine & expressionDfa;
	state_machine & termDfa;
	state_machine & parentheticalDfa;
	state_machine & tagDfa;
	state_machine & factorDfa;
	state_machine & identifierDfa;
	state_machine & root;

	std::shared_ptr<behavior_node> process_factor(std::u32string document, match const & factor, abstract_syntax_graph const & asg, std::map<std::u32string, std::shared_ptr<literal>> & literalNodes, std::map<std::string, std::shared_ptr<production>> & productionNodes);

	std::shared_ptr<behavior_node> process_term(std::u32string document, match const & term, abstract_syntax_graph const & asg, std::map<std::u32string, std::shared_ptr<literal>> & literalNodes, std::map<std::string, std::shared_ptr<production>> & productionNodes);

	std::shared_ptr<behavior_node> process_expression(std::u32string document, match const & expression, abstract_syntax_graph const & asg, std::map<std::u32string, std::shared_ptr<literal>> & literalNodes, std::map<std::string, std::shared_ptr<production>> & productionNodes);

	std::shared_ptr<behavior_node> process_production(std::u32string document, match const & production, abstract_syntax_graph const & asg);

};

} //namespace details

} //namespace parlex

#endif
