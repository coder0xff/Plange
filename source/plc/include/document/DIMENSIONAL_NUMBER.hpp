// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DIMENSIONAL_NUMBER_HPP
#define INCLUDED_DIMENSIONAL_NUMBER_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct DIMENSION;
struct NON_NEG_NUMBER;

struct DIMENSIONAL_NUMBER {
	erased<NON_NEG_NUMBER> field_1;
	erased<DIMENSION> field_2;

	DIMENSIONAL_NUMBER(
		erased<NON_NEG_NUMBER> const & field_1,
		erased<DIMENSION> const & field_2
	) : field_1(field_1), field_2(field_2) {}
};



#endif //INCLUDED_DIMENSIONAL_NUMBER_HPP
