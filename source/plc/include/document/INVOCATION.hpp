// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_INVOCATION_HPP
#define INCLUDED_INVOCATION_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct ARRAY_INVOCATION;
struct PARENTHETICAL_INVOCATION;
struct TYPE_INVOCATION;

typedef std::variant<
	erased<PARENTHETICAL_INVOCATION>,
	erased<ARRAY_INVOCATION>,
	erased<TYPE_INVOCATION>
> INVOCATION;

#endif //INCLUDED_INVOCATION_HPP
