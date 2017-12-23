#ifndef WIRTH_HPP
#define WIRTH_HPP

#include "parlex/associativity.hpp"
#include "parlex/builder.hpp"
#include "parlex/filter_function.hpp"

#include "parlex/detail/grammar.hpp"

#include "erased.hpp"

namespace parlex {
namespace detail {

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

TAG           = "%" IDENTIFIER .

FACTOR        = ["$"] IDENTIFIER
			  | ["$"] LITERAL
			  | [TAG] PARENTHETICAL .

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
	string_terminal const & open_square;
	string_terminal const & open_paren;
	string_terminal const & open_curly;
	string_terminal const & dollar_sign;

	state_machine const & production_dfa;
	state_machine const & expression_dfa;
	state_machine const & term_dfa;
	state_machine const & parenthetical_dfa;
	state_machine const & tag_dfa;
	state_machine const & factor_dfa;
	state_machine const & identifier_dfa;

	erased<node> process_factor(std::u32string const & document, ast_node const & factor) const;
	erased<node> process_term(std::u32string const & document, ast_node const & term) const;
	erased<node> process_expression(std::u32string const & document, ast_node const & expression) const;
	erased<node> process_production(std::u32string const & document, ast_node const & production) const;

};

} //namespace detail

detail::wirth_t const& wirth();

} //namespace parlex

#endif //WIRTH_HPP
