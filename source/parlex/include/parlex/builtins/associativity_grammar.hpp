#ifndef associativity_GRAMMAR_HPP
#define associativity_GRAMMAR_HPP

#include <map>
#include <string>

#include "parlex/grammar.hpp"
#include "parlex/associativity.hpp"

namespace parlex {
namespace builtins {

parlex::grammar const & get_associativity_grammar();

}

std::map<std::string, parlex::associativity> load_associativities(std::u32string document);

}

#endif
