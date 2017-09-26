// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DO_HPP
#define INCLUDED_DO_HPP

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

struct DO {
	std::vector<erased<IC>> field_1;
	erased<EXPRESSION> expression;
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		std::variant<
			literal_while_t,
			literal_until_t
		>,
		std::vector<erased<IC>>,
		erased<PARENTHETICAL>
	>> field_2;


	DO(
		std::vector<erased<IC>> const & field_1,
		erased<EXPRESSION> const & expression,
		std::optional<std::tuple<
			std::vector<erased<IC>>,
			std::variant<
				literal_while_t,
				literal_until_t
			>,
			std::vector<erased<IC>>,
			erased<PARENTHETICAL>
		>> const & field_2
	) : field_1(field_1), expression(expression), field_2(field_2) {}

	static std::optional<DO> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_DO_HPP
