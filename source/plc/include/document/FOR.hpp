// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FOR_HPP
#define INCLUDED_FOR_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct ASSIGNMENT_CHAIN;
struct EXPRESSION;
struct IC;
struct STATEMENT_SCOPE;

struct FOR {
	std::vector<erased<IC>> field_1;
	std::vector<erased<IC>> field_2;
	std::optional<std::tuple<
		erased<STATEMENT_SCOPE>,
		std::vector<erased<IC>>
	>> initializer;
	erased<EXPRESSION> condition;
	std::vector<erased<IC>> field_3;
	std::vector<erased<IC>> field_4;
	std::optional<std::tuple<
		erased<ASSIGNMENT_CHAIN>,
		std::vector<std::tuple<
			std::vector<erased<IC>>,
			std::vector<erased<IC>>,
			erased<ASSIGNMENT_CHAIN>
		>>,
		std::vector<erased<IC>>
	>> step;
	std::vector<erased<IC>> field_5;
	erased<EXPRESSION> field_6;

	FOR(
		std::vector<erased<IC>> const & field_1,
		std::vector<erased<IC>> const & field_2,
		std::optional<std::tuple<
			erased<STATEMENT_SCOPE>,
			std::vector<erased<IC>>
		>> const & initializer,
		erased<EXPRESSION> const & condition,
		std::vector<erased<IC>> const & field_3,
		std::vector<erased<IC>> const & field_4,
		std::optional<std::tuple<
			erased<ASSIGNMENT_CHAIN>,
			std::vector<std::tuple<
				std::vector<erased<IC>>,
				std::vector<erased<IC>>,
				erased<ASSIGNMENT_CHAIN>
			>>,
			std::vector<erased<IC>>
		>> const & step,
		std::vector<erased<IC>> const & field_5,
		erased<EXPRESSION> const & field_6
	) : field_1(field_1), field_2(field_2), initializer(initializer), condition(condition), field_3(field_3), field_4(field_4), step(step), field_5(field_5), field_6(field_6) {}
};



#endif //INCLUDED_FOR_HPP
