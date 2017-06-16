#ifndef WIRTH_HPP
#define WIRTH_HPP

#include "parlex/filter_function.hpp"
#include "parlex/grammar.hpp"

#include "erased.hpp"
 
namespace parlex {
struct abstract_syntax_graph;
class builtins_t;

namespace builder {
struct grammar;
struct node;
}

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

class wirth_t final : public grammar {
public:
	struct production {
		production(std::u32string const & source, associativity assoc, filter_function filter, std::set<std::string> const & precedences);
		std::u32string const source;
		associativity const assoc;
		filter_function const filter;
		std::set<std::string> const precedences;
	};

	wirth_t(parser & p);

	builder::grammar load_grammar(std::string const & rootId, std::map<std::string, production> const & definitions);
	builder::grammar load_grammar(std::string const & rootId, std::u32string const & document, std::map<std::string, associativity> const & associativities, std::set<std::string> const & longestNames);

private:
	parser & p;

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
	state_machine & rootDfa;

	erased<builder::node> process_factor2(std::u32string const & document, match const & factor, abstract_syntax_graph const & asg);
	erased<builder::node> process_term2(std::u32string const & document, match const & term, abstract_syntax_graph const & asg);
	erased<builder::node> process_expression2(std::u32string const & document, match const & expression, abstract_syntax_graph const & asg);
	erased<builder::node> process_production2(std::u32string const & document, match const & expression, abstract_syntax_graph const & asg);
	erased<builder::node> compile_source(std::u32string const & source);

};

} //namespace details
} //namespace parlex

#endif //WIRTH_HPP
