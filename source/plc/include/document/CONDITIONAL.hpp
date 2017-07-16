// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_CONDITIONAL_HPP
#define INCLUDED_CONDITIONAL_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"
#include "parlex/builder.hpp"

struct EXPRESSION;
struct IC;

struct CONDITIONAL {
	erased<EXPRESSION> condition;
	std::vector<erased<IC>> field_1;
	std::vector<erased<IC>> field_2;
	erased<EXPRESSION> true_case;
	std::vector<erased<IC>> field_3;
	std::vector<erased<IC>> field_4;
	erased<EXPRESSION> false_case;

	CONDITIONAL(
		erased<EXPRESSION> const & condition,
		std::vector<erased<IC>> const & field_1,
		std::vector<erased<IC>> const & field_2,
		erased<EXPRESSION> const & true_case,
		std::vector<erased<IC>> const & field_3,
		std::vector<erased<IC>> const & field_4,
		erased<EXPRESSION> const & false_case
	) : condition(condition), field_1(field_1), field_2(field_2), true_case(true_case), field_3(field_3), field_4(field_4), false_case(false_case) {}

	static erased<EXPRESSION> build_condition(std::vector<parlex::details::match>::iterator & i, parlex::details::behavior::node const & behavior);
	static std::optional<CONDITIONAL> build(std::vector<parlex::match>::iterator & i, parlex::details::node const & behavior) {

	}
};



#endif //INCLUDED_CONDITIONAL_HPP
