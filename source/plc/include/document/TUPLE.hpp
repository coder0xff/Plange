// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TUPLE_HPP
#define INCLUDED_TUPLE_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct TUPLE {
	std::vector<erased<IC>> field_1;
	erased<EXPRESSION> field_2;
	std::vector<std::tuple<
		std::vector<erased<IC>>,
		std::vector<erased<IC>>,
		erased<EXPRESSION>
	>> field_3;
	std::vector<erased<IC>> field_4;


	TUPLE(
		std::vector<erased<IC>> const & field_1,
		erased<EXPRESSION> const & field_2,
		std::vector<std::tuple<
			std::vector<erased<IC>>,
			std::vector<erased<IC>>,
			erased<EXPRESSION>
		>> const & field_3,
		std::vector<erased<IC>> const & field_4
	) : field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4) {}

	static std::optional<TUPLE> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_TUPLE_HPP
