// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_IF_HPP
#define INCLUDED_IF_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EXPRESSION;
struct IC;
struct PARENTHETICAL;

struct IF {
	std::vector<erased<IC>> field_1;
	erased<PARENTHETICAL> condition;
	std::vector<erased<IC>> field_2;
	erased<EXPRESSION> invoke;
	std::vector<std::tuple<
		std::vector<erased<IC>>,
		std::vector<erased<IC>>,
		erased<PARENTHETICAL>,
		std::vector<erased<IC>>,
		erased<EXPRESSION>
	>> field_3;
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		std::vector<erased<IC>>,
		erased<EXPRESSION>
	>> field_4;


	IF(
		std::vector<erased<IC>> const & field_1,
		erased<PARENTHETICAL> const & condition,
		std::vector<erased<IC>> const & field_2,
		erased<EXPRESSION> const & invoke,
		std::vector<std::tuple<
			std::vector<erased<IC>>,
			std::vector<erased<IC>>,
			erased<PARENTHETICAL>,
			std::vector<erased<IC>>,
			erased<EXPRESSION>
		>> const & field_3,
		std::optional<std::tuple<
			std::vector<erased<IC>>,
			std::vector<erased<IC>>,
			erased<EXPRESSION>
		>> const & field_4
	) : field_1(field_1), condition(condition), field_2(field_2), invoke(invoke), field_3(field_3), field_4(field_4) {}

	static std::optional<IF> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_IF_HPP
