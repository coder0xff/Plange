// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_UNIT_EXPONENTIATION_HPP
#define INCLUDED_UNIT_EXPONENTIATION_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct DIMENSION;
struct NON_FRACTIONAL;

struct UNIT_EXPONENTIATION {
	erased<DIMENSION> field_1;
	erased<NON_FRACTIONAL> field_2;

	UNIT_EXPONENTIATION(
		erased<DIMENSION> const & field_1,
		erased<NON_FRACTIONAL> const & field_2
	) : field_1(field_1), field_2(field_2) {}
};



#endif //INCLUDED_UNIT_EXPONENTIATION_HPP
