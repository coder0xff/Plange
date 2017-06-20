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

	explicit wirth_t(parser & p);

	builder::grammar load_grammar(std::string const & rootId, std::map<std::string, production> const & definitions);
	builder::grammar load_grammar(std::string const & rootId, std::u32string const & document, std::map<std::string, associativity> const & associativities, std::set<std::string> const & longestNames);

private:
	parser & p;

	string_terminal const & openSquare;
	string_terminal const & openParen;
	string_terminal const & openCurly;
	string_terminal const & dollarSign;

	state_machine_base const & productionDfa;
	state_machine_base const & expressionDfa;
	state_machine_base const & termDfa;
	state_machine_base const & parentheticalDfa;
	state_machine_base const & tagDfa;
	state_machine_base const & factorDfa;
	state_machine_base const & identifierDfa;

	erased<builder::node> process_factor2(std::u32string const & document, match const & factor, abstract_syntax_graph const & asg);
	erased<builder::node> process_term2(std::u32string const & document, match const & term, abstract_syntax_graph const & asg);
	erased<builder::node> process_expression2(std::u32string const & document, match const & expression, abstract_syntax_graph const & asg);
	erased<builder::node> process_production2(std::u32string const & document, match const & expression, abstract_syntax_graph const & asg);
	erased<builder::node> compile_source(std::u32string const & source);

};

} //namespace details
} //namespace parlex

#endif //WIRTH_HPP
