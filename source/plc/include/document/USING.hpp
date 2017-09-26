// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_USING_HPP
#define INCLUDED_USING_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct BLOCK;
struct EXPRESSION;
struct IC;

struct USING {
	std::vector<erased<IC>> field_1;
	std::vector<erased<IC>> field_2;
	erased<EXPRESSION> field_3;
	std::vector<erased<IC>> field_4;
	std::vector<erased<IC>> field_5;
	erased<BLOCK> field_6;


	USING(
		std::vector<erased<IC>> const & field_1,
		std::vector<erased<IC>> const & field_2,
		erased<EXPRESSION> const & field_3,
		std::vector<erased<IC>> const & field_4,
		std::vector<erased<IC>> const & field_5,
		erased<BLOCK> const & field_6
	) : field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5), field_6(field_6) {}

	static std::optional<USING> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_USING_HPP
