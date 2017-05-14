#ifndef WIRTH_HPP
#define WIRTH_HPP

#include "parlex/grammar.hpp"
#include "parlex/state_machine.hpp"

namespace parlex {
namespace builtins {

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

extern grammar wirth;

}

struct wirth_production_def {
	std::u32string definition;
	associativity assoc;
	std::set<std::string> precedences;
	filter_function const * filter;
};

grammar load_grammar(std::string const & nameOfMain, std::u32string const & document, std::map<std::string, associativity> const & associativities, std::set<std::string> const & longestNames);
grammar load_grammar(std::string const & nameOfMain, std::map<std::string, wirth_production_def> const & productions);

}

#endif
