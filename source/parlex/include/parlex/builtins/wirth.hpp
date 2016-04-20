#ifndef WIRTH_HPP
#define WIRTH_HPP

#include "parlex/grammar.hpp"
#include "parlex/state_machine.hpp"

namespace parlex {
namespace builtins {

	// https://en.wikipedia.org/wiki/Wirth_syntax_notation
extern state_machine wirth;
grammar parse_wirth(std::string nameOfMain, std::u32string const & document);

}
}

#endif
