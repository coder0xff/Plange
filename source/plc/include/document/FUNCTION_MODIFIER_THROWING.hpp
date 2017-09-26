// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_MODIFIER_THROWING_HPP
#define INCLUDED_FUNCTION_MODIFIER_THROWING_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct ARRAY;
struct FUNCTION_MODIFIER_2;
struct IC;
struct ICR;

struct FUNCTION_MODIFIER_THROWING {
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		erased<ARRAY>
	>> field_1;
	std::optional<std::tuple<
		erased<ICR>,
		erased<FUNCTION_MODIFIER_2>
	>> field_2;


	FUNCTION_MODIFIER_THROWING(
		std::optional<std::tuple<
			std::vector<erased<IC>>,
			erased<ARRAY>
		>> const & field_1,
		std::optional<std::tuple<
			erased<ICR>,
			erased<FUNCTION_MODIFIER_2>
		>> const & field_2
	) : field_1(field_1), field_2(field_2) {}

	static std::optional<FUNCTION_MODIFIER_THROWING> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_FUNCTION_MODIFIER_THROWING_HPP
