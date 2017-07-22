// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_NON_FRACTIONAL_HPP
#define INCLUDED_NON_FRACTIONAL_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct NON_NEG_NON_FRACTIONAL;

struct NON_FRACTIONAL {
	bool field_1;
	erased<NON_NEG_NON_FRACTIONAL> field_2;

	NON_FRACTIONAL(
		bool const & field_1,
		erased<NON_NEG_NON_FRACTIONAL> const & field_2
	) : field_1(field_1), field_2(field_2) {}
};



#endif //INCLUDED_NON_FRACTIONAL_HPP
