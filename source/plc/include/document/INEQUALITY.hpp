// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_INEQUALITY_HPP
#define INCLUDED_INEQUALITY_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct INEQUALITY {
	erased<EXPRESSION> field_1;
	std::vector<erased<IC>> field_2;
	std::variant<
		literal_0xE20x890xA0_t,
		literal_0x2F0x3D_t
	> field_3;
	std::vector<erased<IC>> field_4;
	erased<EXPRESSION> field_5;


	INEQUALITY(
		erased<EXPRESSION> const & field_1,
		std::vector<erased<IC>> const & field_2,
		std::variant<
			literal_0xE20x890xA0_t,
			literal_0x2F0x3D_t
		> const & field_3,
		std::vector<erased<IC>> const & field_4,
		erased<EXPRESSION> const & field_5
	) : field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	static std::optional<INEQUALITY> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_INEQUALITY_HPP
