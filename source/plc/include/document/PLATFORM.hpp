// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_PLATFORM_HPP
#define INCLUDED_PLATFORM_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct PLATFORM {
	std::variant<
		std::integral_constant<int, 0>,
		std::integral_constant<int, 1>
	> field_1;
	std::vector<std::variant<
		std::integral_constant<int, 0>,
		std::integral_constant<int, 1>,
		literal___t
	>> field_2;


	PLATFORM(
		std::variant<
			std::integral_constant<int, 0>,
			std::integral_constant<int, 1>
		> const & field_1,
		std::vector<std::variant<
			std::integral_constant<int, 0>,
			std::integral_constant<int, 1>,
			literal___t
		>> const & field_2
	) : field_1(field_1), field_2(field_2) {}

	static std::optional<PLATFORM> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_PLATFORM_HPP
