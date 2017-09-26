// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_MAPS_TO_HPP
#define INCLUDED_MAPS_TO_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct MAPS_TO {
	erased<EXPRESSION> field_1;
	std::vector<erased<IC>> field_2;
	std::variant<
		literal_0xE20x860x92_t,
		literal_0x2D0x3E_t
	> field_3;
	std::vector<erased<IC>> field_4;
	erased<EXPRESSION> field_5;


	MAPS_TO(
		erased<EXPRESSION> const & field_1,
		std::vector<erased<IC>> const & field_2,
		std::variant<
			literal_0xE20x860x92_t,
			literal_0x2D0x3E_t
		> const & field_3,
		std::vector<erased<IC>> const & field_4,
		erased<EXPRESSION> const & field_5
	) : field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	static std::optional<MAPS_TO> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_MAPS_TO_HPP
