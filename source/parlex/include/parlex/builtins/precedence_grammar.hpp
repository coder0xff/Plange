#ifndef PRECEDENCE_GRAMMAR_HPP
#define PRECEDENCE_GRAMMAR_HPP

#include "parlex/grammar.hpp"
#include "parlex/builtins.hpp"
#include "parlex/precedence_collection.hpp"

namespace parlex {
namespace builtins {

parlex::grammar const & get_precedence_grammar();

}

void load_precedence(grammar & g, std::u32string const & document);

}
#endif
