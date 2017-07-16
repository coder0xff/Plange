// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_NON_NEG_NUMBER_HPP
#define INCLUDED_NON_NEG_NUMBER_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct NON_NEG_FRACTIONAL;
struct NON_NEG_NON_FRACTIONAL;

typedef std::variant<
	erased<NON_NEG_NON_FRACTIONAL>,
	erased<NON_NEG_FRACTIONAL>
> NON_NEG_NUMBER;

#endif //INCLUDED_NON_NEG_NUMBER_HPP
