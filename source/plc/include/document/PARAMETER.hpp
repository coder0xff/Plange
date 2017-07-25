// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_PARAMETER_HPP
#define INCLUDED_PARAMETER_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct PARAMETER_ANALYTIC;
struct PARAMETER_NATURAL;

typedef std::variant<
	erased<PARAMETER_NATURAL>,
	erased<PARAMETER_ANALYTIC>
> PARAMETER;

#endif //INCLUDED_PARAMETER_HPP
