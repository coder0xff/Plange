// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EMBEDDED_COMMENT_INTERIOR_HPP
#define INCLUDED_EMBEDDED_COMMENT_INTERIOR_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct EMBEDDED_COMMENT_INTERIOR;
struct PAYLOAD;

typedef std::variant<
	erased<PAYLOAD>,
	std::tuple<
		erased<EMBEDDED_COMMENT_INTERIOR>
	>
> EMBEDDED_COMMENT_INTERIOR;

#endif //INCLUDED_EMBEDDED_COMMENT_INTERIOR_HPP
