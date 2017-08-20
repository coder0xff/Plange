// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_MODIFIER_ATOMIC_HPP
#define INCLUDED_FUNCTION_MODIFIER_ATOMIC_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct FUNCTION_MODIFIER_3;
struct ICR;

struct FUNCTION_MODIFIER_ATOMIC {
	std::optional<std::tuple<
		erased<ICR>,
		erased<FUNCTION_MODIFIER_3>
	>> field_1;

	FUNCTION_MODIFIER_ATOMIC(
		std::optional<std::tuple<
			erased<ICR>,
			erased<FUNCTION_MODIFIER_3>
		>> const & field_1
	) : field_1(field_1) {}
};



#endif //INCLUDED_FUNCTION_MODIFIER_ATOMIC_HPP