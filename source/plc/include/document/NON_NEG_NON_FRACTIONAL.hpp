// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_NON_NEG_NON_FRACTIONAL_HPP
#define INCLUDED_NON_NEG_NON_FRACTIONAL_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct HEX;
struct NON_NEG_INTEGER;
struct OCTAL;

typedef std::variant<
	erased<NON_NEG_INTEGER>,
	erased<HEX>,
	erased<OCTAL>
> NON_NEG_NON_FRACTIONAL;

#endif //INCLUDED_NON_NEG_NON_FRACTIONAL_HPP
