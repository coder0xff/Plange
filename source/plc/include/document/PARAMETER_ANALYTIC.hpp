// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_PARAMETER_ANALYTIC_HPP
#define INCLUDED_PARAMETER_ANALYTIC_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct EXPRESSION;
struct IC;

struct PARAMETER_ANALYTIC {
	erased<EXPRESSION> field_1;
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		std::vector<erased<IC>>,
		erased<EXPRESSION>
	>> field_2;

	PARAMETER_ANALYTIC(
		erased<EXPRESSION> const & field_1,
		std::optional<std::tuple<
			std::vector<erased<IC>>,
			std::vector<erased<IC>>,
			erased<EXPRESSION>
		>> const & field_2
	) : field_1(field_1), field_2(field_2) {}
};



#endif //INCLUDED_PARAMETER_ANALYTIC_HPP
