// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_PARENTHETICAL_INVOCATION_HPP
#define INCLUDED_PARENTHETICAL_INVOCATION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct ARGUMENT;
struct ARGUMENT_PACK;
struct EXPRESSION;
struct IC;

struct PARENTHETICAL_INVOCATION {
	erased<EXPRESSION> field_1;
	std::vector<erased<IC>> field_2;
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		std::variant<
			erased<ARGUMENT>,
			erased<ARGUMENT_PACK>
		>
	>> field_3;
	std::vector<std::tuple<
		std::vector<erased<IC>>,
		std::optional<std::tuple<
			std::vector<erased<IC>>,
			std::variant<
				erased<ARGUMENT>,
				erased<ARGUMENT_PACK>
			>
		>>
	>> field_4;
	std::vector<erased<IC>> field_5;


	PARENTHETICAL_INVOCATION(
		erased<EXPRESSION> const & field_1,
		std::vector<erased<IC>> const & field_2,
		std::optional<std::tuple<
			std::vector<erased<IC>>,
			std::variant<
				erased<ARGUMENT>,
				erased<ARGUMENT_PACK>
			>
		>> const & field_3,
		std::vector<std::tuple<
			std::vector<erased<IC>>,
			std::optional<std::tuple<
				std::vector<erased<IC>>,
				std::variant<
					erased<ARGUMENT>,
					erased<ARGUMENT_PACK>
				>
			>>
		>> const & field_4,
		std::vector<erased<IC>> const & field_5
	) : field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	static std::optional<PARENTHETICAL_INVOCATION> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_PARENTHETICAL_INVOCATION_HPP
