// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_GREATER_CHAIN_LOOP_HPP
#define INCLUDED_GREATER_CHAIN_LOOP_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EXPRESSION;
struct GREATER_CHAIN_LOOP;
struct IC;

struct GREATER_CHAIN_LOOP {
	std::variant<
		literal_0x3D_t,
		literal_0x3E_t,
		literal_0x3D0x3E_t,
		literal_0xE20x890xA5_t
	> field_1;
	std::vector<erased<IC>> field_2;
	erased<EXPRESSION> expression;
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		erased<GREATER_CHAIN_LOOP>
	>> field_3;


	GREATER_CHAIN_LOOP(
		std::variant<
			literal_0x3D_t,
			literal_0x3E_t,
			literal_0x3D0x3E_t,
			literal_0xE20x890xA5_t
		> const & field_1,
		std::vector<erased<IC>> const & field_2,
		erased<EXPRESSION> const & expression,
		std::optional<std::tuple<
			std::vector<erased<IC>>,
			erased<GREATER_CHAIN_LOOP>
		>> const & field_3
	) : field_1(field_1), field_2(field_2), expression(expression), field_3(field_3) {}

	static std::optional<GREATER_CHAIN_LOOP> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_GREATER_CHAIN_LOOP_HPP
