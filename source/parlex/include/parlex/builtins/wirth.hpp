#ifndef WIRTH_HPP
#define WIRTH_HPP

#include "parlex/grammar.hpp"
#include "parlex/state_machine.hpp"
#include "parlex/details/behavior.hpp"
#include "parlex/builtins/string_terminal.hpp"

namespace parlex {

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

struct wirth_production_def {
	std::u32string definition;
	associativity assoc;
	std::set<std::string> precedences;
	filter_function const * filter;
};

class wirth_t : public grammar {
public:

	wirth_t();
	grammar load_grammar(std::string const & nameOfMain, std::u32string const & document, std::map<std::string, associativity> const & associativities, std::set<std::string> const & longestNames);
	grammar load_grammar(std::string const & nameOfMain, std::map<std::string, wirth_production_def> const & productions);
private:
	static std::shared_ptr<behavior_node> get_or_add_production(std::map<std::string, std::shared_ptr<production>> & productionNodes, std::string name);
	static std::shared_ptr<behavior_node> get_or_add_literal(std::map<std::u32string, std::shared_ptr<literal>> & literalNodes, std::u32string temp);

	builtins::string_terminal & newline = add_literal(U"\n");
	builtins::string_terminal & hash = add_literal(U"#");
	builtins::string_terminal & period = add_literal(U".");
	builtins::string_terminal & equals = add_literal(U"=");
	builtins::string_terminal & quote = add_literal(U"\"");
	builtins::string_terminal & pipe = add_literal(U"|");
	builtins::string_terminal & openSquare = add_literal(U"[");
	builtins::string_terminal & closeSquare = add_literal(U"]");
	builtins::string_terminal & openParen = add_literal(U"(");
	builtins::string_terminal & closeParen = add_literal(U")");
	builtins::string_terminal & openCurly = add_literal(U"{");
	builtins::string_terminal & closeCurly = add_literal(U"}");
	builtins::string_terminal & underscore = add_literal(U"_");
	builtins::string_terminal & dollarSign = add_literal(U"$");
	builtins::string_terminal & percentageSign = add_literal(U"%");

	state_machine & whiteSpaceDfa = add_production("whiteSpace", 0, 1, &builtins::longest);
	state_machine & commentDfa = add_production("comment", 0, 1);
	state_machine & productionDfa = add_production("production", 0, 1);
	state_machine & expressionDfa = add_production("expression", 0, 1);
	state_machine & termDfa = add_production("term", 0, 1);
	state_machine & parentheticalDfa = add_production("parenthetical", 0, 1);
	state_machine & tagDfa = add_production("tag", 0, 1);
	state_machine & factorDfa = add_production("factor", 0, 1);
	state_machine & identifierDfa = add_production("identifier", 0, 1, &builtins::longest);
	state_machine & root = add_production("root", 0, 1);

	std::shared_ptr<behavior_node> process_factor(std::u32string document, match const & factor, abstract_syntax_graph const & asg, std::map<std::u32string, std::shared_ptr<literal>> & literalNodes, std::map<std::string, std::shared_ptr<production>> & productionNodes);

	std::shared_ptr<behavior_node> process_term(std::u32string document, match const & term, abstract_syntax_graph const & asg, std::map<std::u32string, std::shared_ptr<literal>> & literalNodes, std::map<std::string, std::shared_ptr<production>> & productionNodes);

	std::shared_ptr<behavior_node> process_expression(std::u32string document, match const & expression, abstract_syntax_graph const & asg, std::map<std::u32string, std::shared_ptr<literal>> & literalNodes, std::map<std::string, std::shared_ptr<production>> & productionNodes);

	std::shared_ptr<behavior_node> process_production(std::u32string document, match const & production, abstract_syntax_graph const & asg);

};

} //namespace details

namespace builtins {

extern details::wirth_t wirth;

} //namespace builtins

} //namespace parlex

#endif
