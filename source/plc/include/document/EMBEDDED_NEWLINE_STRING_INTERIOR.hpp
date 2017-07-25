// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EMBEDDED_NEWLINE_STRING_INTERIOR_HPP
#define INCLUDED_EMBEDDED_NEWLINE_STRING_INTERIOR_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct EMBEDDED_NEWLINE_STRING_INTERIOR;
struct PAYLOAD;

typedef std::variant<
	std::tuple<
		erased<PAYLOAD>
	>,
	std::tuple<
		erased<EMBEDDED_NEWLINE_STRING_INTERIOR>
	>
> EMBEDDED_NEWLINE_STRING_INTERIOR;

#endif //INCLUDED_EMBEDDED_NEWLINE_STRING_INTERIOR_HPP
