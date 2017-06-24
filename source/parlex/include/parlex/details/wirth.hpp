#ifndef WIRTH_HPP
#define WIRTH_HPP

#include "parlex/correlated_grammar.hpp"
#include "parlex/filter_function.hpp"

#include "erased.hpp"

namespace parlex {
struct abstract_syntax_graph;
class builtins_t;

namespace builder {
struct grammar;
struct node;
}

namespace details {

/* similar to https://en.wikipedia.org/wiki/Wirth_syntax_notation but with tagging

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

class wirth_t final : public correlated_grammar {
public:
	struct production {
		production(std::u32string const & source, associativity assoc, filter_function filter, std::set<std::string> const & precedences);
		std::u32string const source;
		associativity const assoc;
		filter_function const filter;
		std::set<std::string> const precedences;
	};

	explicit wirth_t();

	builder::grammar load_grammar(std::string const & rootId, std::map<std::string, production> const & definitions) const;
	builder::grammar load_grammar(std::string const & rootId, std::u32string const & document, std::map<std::string, associativity> const & associativities, std::set<std::string> const & longestNames) const;

	erased<builder::node> compile_expression(std::u32string const & source) const;

private:
	string_terminal const & openSquare;
	string_terminal const & openParen;
	string_terminal const & openCurly;
	string_terminal const & dollarSign;

	correlated_state_machine const & productionDfa;
	correlated_state_machine const & expressionDfa;
	correlated_state_machine const & termDfa;
	correlated_state_machine const & parentheticalDfa;
	correlated_state_machine const & tagDfa;
	correlated_state_machine const & factorDfa;
	correlated_state_machine const & identifierDfa;

	erased<builder::node> process_factor(std::u32string const & document, match const & factor, abstract_syntax_graph const & asg) const;
	erased<builder::node> process_term(std::u32string const & document, match const & term, abstract_syntax_graph const & asg) const;
	erased<builder::node> process_expression(std::u32string const & document, match const & expression, abstract_syntax_graph const & asg) const;
	erased<builder::node> process_production(std::u32string const & document, match const & expression, abstract_syntax_graph const & asg) const;

};

} //namespace details

details::wirth_t const& wirth();

} //namespace parlex

#endif //WIRTH_HPP
