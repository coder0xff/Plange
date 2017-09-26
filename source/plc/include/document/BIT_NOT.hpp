// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_BIT_NOT_HPP
#define INCLUDED_BIT_NOT_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct BIT_NOT {
	std::vector<erased<IC>> field_1;
	erased<EXPRESSION> field_2;


	BIT_NOT(
		std::vector<erased<IC>> const & field_1,
		erased<EXPRESSION> const & field_2
	) : field_1(field_1), field_2(field_2) {}

	static std::optional<BIT_NOT> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_BIT_NOT_HPP
