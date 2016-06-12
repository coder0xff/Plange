#ifndef BUILTINS_HPP
#define BUILTINS_HPP

// Terminals
#include "parlex/builtins/any_character.hpp"
#include "parlex/builtins/set_terminal.hpp"
#include "parlex/builtins/string_terminal.hpp"
#include "parlex/builtins/unicode.hpp"
#include "parlex/builtins/not_double_quote.hpp"
#include "parlex/builtins/not_newline.hpp"

// Filters
#include "parlex/builtins/greedy.hpp"

// State Machines
#include "parlex/builtins/c_string.hpp"

// Grammars
#include "parlex/builtins/wirth.hpp"
#include "parlex/builtins/precedence_grammar.hpp"
#include "parlex/builtins/associativity_grammar.hpp"

// Misc
#include "parlex/builtins/progress_bar.hpp"

namespace parlex {
namespace builtins {

std::map<std::string, recognizer *> const & get_builtins_table();
bool resolve_builtin(std::string const & name, parlex::recognizer const *& ptr);

}
}

#endif
