// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_IDENTIFIER_HPP
#define INCLUDED_IDENTIFIER_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct IDENTIFIER {
	std::variant<
		std::integral_constant<int, 0>,
		literal___t
	> field_1;
	std::vector<std::variant<
		std::integral_constant<int, 0>,
		std::integral_constant<int, 1>,
		literal___t
	>> field_2;


	IDENTIFIER(
		std::variant<
			std::integral_constant<int, 0>,
			literal___t
		> const & field_1,
		std::vector<std::variant<
			std::integral_constant<int, 0>,
			std::integral_constant<int, 1>,
			literal___t
		>> const & field_2
	) : field_1(field_1), field_2(field_2) {}

	static std::optional<IDENTIFIER> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_IDENTIFIER_HPP
