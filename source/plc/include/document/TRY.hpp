// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TRY_HPP
#define INCLUDED_TRY_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct EXPRESSION;
struct IC;

struct TRY {
	std::vector<erased<IC>> field_1;
	erased<EXPRESSION> field_2;
	std::vector<erased<IC>> field_3;
	std::vector<erased<IC>> field_4;
	erased<EXPRESSION> field_5;
	std::vector<std::tuple<
		std::vector<erased<IC>>,
		erased<EXPRESSION>
	>> field_6;
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		std::vector<erased<IC>>,
		erased<EXPRESSION>
	>> field_7;

	TRY(
		std::vector<erased<IC>> const & field_1,
		erased<EXPRESSION> const & field_2,
		std::vector<erased<IC>> const & field_3,
		std::vector<erased<IC>> const & field_4,
		erased<EXPRESSION> const & field_5,
		std::vector<std::tuple<
			std::vector<erased<IC>>,
			erased<EXPRESSION>
		>> const & field_6,
		std::optional<std::tuple<
			std::vector<erased<IC>>,
			std::vector<erased<IC>>,
			erased<EXPRESSION>
		>> const & field_7
	) : field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5), field_6(field_6), field_7(field_7) {}
};



#endif //INCLUDED_TRY_HPP
