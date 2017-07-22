// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TIME_HPP
#define INCLUDED_TIME_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct TIME {
	bool field_1;
	std::optional<std::tuple<
		int
	>> field_8;
	std::optional<std::variant<
		std::integral_constant<int, 0>,
		std::tuple<
			std::variant<
				std::integral_constant<int, 0>,
				std::integral_constant<int, 1>
			>,
			bool
		>
	>> field_9;

	TIME(
		bool const & field_1,
		std::optional<std::tuple<
			int
		>> const & field_8,
		std::optional<std::variant<
			std::integral_constant<int, 0>,
			std::tuple<
				std::variant<
					std::integral_constant<int, 0>,
					std::integral_constant<int, 1>
				>,
				bool
			>
		>> const & field_9
	) : field_1(field_1), field_8(field_8), field_9(field_9) {}
};



#endif //INCLUDED_TIME_HPP
