// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DIMENSION_HPP
#define INCLUDED_DIMENSION_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct DIMENSIONAL_ANALYSIS_OP;
struct IDENTIFIER;

typedef std::variant<
	erased<IDENTIFIER>,
	erased<DIMENSIONAL_ANALYSIS_OP>
> DIMENSION;

#endif //INCLUDED_DIMENSION_HPP
