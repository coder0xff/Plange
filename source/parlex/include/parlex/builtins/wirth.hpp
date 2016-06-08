#ifndef WIRTH_HPP
#define WIRTH_HPP

#include "parlex/grammar.hpp"
#include "parlex/state_machine.hpp"

namespace parlex {
namespace builtins {

	// https://en.wikipedia.org/wiki/Wirth_syntax_notation
extern grammar wirth;

}

grammar load_grammar(std::string const & nameOfMain, std::u32string const & document, std::map<std::string, parlex::associativity> const & associativities, std::set<std::string> const & greedyNames);

}

#endif
