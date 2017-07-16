// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DIMENSIONAL_ANALYSIS_OP_HPP
#define INCLUDED_DIMENSIONAL_ANALYSIS_OP_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct UNIT_DIVISION;
struct UNIT_EXPONENTIATION;
struct UNIT_MULTIPLICATION;

typedef std::variant<
	erased<UNIT_DIVISION>,
	erased<UNIT_EXPONENTIATION>,
	erased<UNIT_MULTIPLICATION>
> DIMENSIONAL_ANALYSIS_OP;

#endif //INCLUDED_DIMENSIONAL_ANALYSIS_OP_HPP
