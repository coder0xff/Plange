// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_PLATFORM_HPP
#define INCLUDED_PLATFORM_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct PLATFORM {
	std::variant<
		std::integral_constant<int, 0>,
		std::integral_constant<int, 1>
	> field_1;
	std::vector<std::variant<
		std::integral_constant<int, 0>,
		std::integral_constant<int, 1>,
		std::integral_constant<int, 2>
	>> field_2;

	PLATFORM(
		std::variant<
			std::integral_constant<int, 0>,
			std::integral_constant<int, 1>
		> const & field_1,
		std::vector<std::variant<
			std::integral_constant<int, 0>,
			std::integral_constant<int, 1>,
			std::integral_constant<int, 2>
		>> const & field_2
	) : field_1(field_1), field_2(field_2) {}
};



#endif //INCLUDED_PLATFORM_HPP
