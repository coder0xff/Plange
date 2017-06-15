#include "parlex/grammar_base.hpp"

namespace parlex {

grammar_base::grammar_base(builtins_t const & builtins) : builtins(builtins) {
}

grammar_base::grammar_base(grammar_base const & other) : builtins(other.builtins) {
}

}
