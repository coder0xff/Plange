#ifndef WIRTH_HPP
#define WIRTH_HPP

#include "parlex/associativity.hpp"
#include "parlex/builder.hpp"
#include "parlex/filter_function.hpp"

#include "parlex/details/grammar.hpp"

#include "erased.hpp"

namespace parlex {
namespace details {

struct abstract_syntax_semilattice;
struct node;

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

class wirth_t final : public grammar {
public:
	struct production {
		production(std::u32string const & source, associativity assoc, filter_function filter, std::set<std::string> const & precedences);
		std::u32string const source;
		associativity const assoc;
		filter_function const filter;
		std::set<std::string> const precedences;
	};

	explicit wirth_t();

	builder load_grammar(std::string const & rootId, std::map<std::string, production> const & definitions) const;
	builder load_grammar(std::string const & rootId, std::u32string const & document, std::map<std::string, associativity> const & associativities, std::set<std::string> const & longestNames) const;

	erased<node> compile_expression(std::u32string const & source) const;

private:
	string_terminal const & openSquare;
	string_terminal const & openParen;
	string_terminal const & openCurly;
	string_terminal const & dollarSign;

	state_machine const & productionDfa;
	state_machine const & expressionDfa;
	state_machine const & termDfa;
	state_machine const & parentheticalDfa;
	state_machine const & tagDfa;
	state_machine const & factorDfa;
	state_machine const & identifierDfa;

	erased<node> process_factor(std::u32string const & document, match const & factor, abstract_syntax_semilattice const & asg) const;
	erased<node> process_term(std::u32string const & document, match const & term, abstract_syntax_semilattice const & asg) const;
	erased<node> process_expression(std::u32string const & document, match const & expression, abstract_syntax_semilattice const & asg) const;
	erased<node> process_production(std::u32string const & document, match const & expression, abstract_syntax_semilattice const & asg) const;

};

} //namespace details

details::wirth_t const& wirth();

} //namespace parlex

#endif //WIRTH_HPP
