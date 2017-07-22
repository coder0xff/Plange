// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_WHOLE_NUMBER_HPP
#define INCLUDED_WHOLE_NUMBER_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct WHOLE_NUMBER {
	std::variant<
		std::integral_constant<int, 0>,
		std::integral_constant<int, 1>,
		std::integral_constant<int, 2>,
		std::integral_constant<int, 3>,
		std::integral_constant<int, 4>,
		std::integral_constant<int, 5>,
		std::integral_constant<int, 6>,
		std::integral_constant<int, 7>,
		std::integral_constant<int, 8>
	> field_1;
	std::vector<std::variant<
		std::integral_constant<int, 0>,
		std::integral_constant<int, 1>,
		std::integral_constant<int, 2>,
		std::integral_constant<int, 3>,
		std::integral_constant<int, 4>,
		std::integral_constant<int, 5>,
		std::integral_constant<int, 6>,
		std::integral_constant<int, 7>,
		std::integral_constant<int, 8>,
		std::integral_constant<int, 9>
	>> field_2;

	WHOLE_NUMBER(
		std::variant<
			std::integral_constant<int, 0>,
			std::integral_constant<int, 1>,
			std::integral_constant<int, 2>,
			std::integral_constant<int, 3>,
			std::integral_constant<int, 4>,
			std::integral_constant<int, 5>,
			std::integral_constant<int, 6>,
			std::integral_constant<int, 7>,
			std::integral_constant<int, 8>
		> const & field_1,
		std::vector<std::variant<
			std::integral_constant<int, 0>,
			std::integral_constant<int, 1>,
			std::integral_constant<int, 2>,
			std::integral_constant<int, 3>,
			std::integral_constant<int, 4>,
			std::integral_constant<int, 5>,
			std::integral_constant<int, 6>,
			std::integral_constant<int, 7>,
			std::integral_constant<int, 8>,
			std::integral_constant<int, 9>
		>> const & field_2
	) : field_1(field_1), field_2(field_2) {}
};



#endif //INCLUDED_WHOLE_NUMBER_HPP
