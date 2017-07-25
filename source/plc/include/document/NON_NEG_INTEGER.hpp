// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_NON_NEG_INTEGER_HPP
#define INCLUDED_NON_NEG_INTEGER_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct NON_ZERO_DECIMAL_DIGIT;

typedef std::variant<
	std::tuple<
		erased<NON_ZERO_DECIMAL_DIGIT>,
		int
	>,
	std::integral_constant<int, 1>
> NON_NEG_INTEGER;

#endif //INCLUDED_NON_NEG_INTEGER_HPP
