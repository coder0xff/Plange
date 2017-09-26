// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EQUALITY_CHAIN_LOOP_HPP
#define INCLUDED_EQUALITY_CHAIN_LOOP_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EQUALITY_CHAIN_LOOP;
struct EXPRESSION;
struct IC;

struct EQUALITY_CHAIN_LOOP {
	std::vector<erased<IC>> field_1;
	erased<EXPRESSION> expression;
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		erased<EQUALITY_CHAIN_LOOP>
	>> field_2;


	EQUALITY_CHAIN_LOOP(
		std::vector<erased<IC>> const & field_1,
		erased<EXPRESSION> const & expression,
		std::optional<std::tuple<
			std::vector<erased<IC>>,
			erased<EQUALITY_CHAIN_LOOP>
		>> const & field_2
	) : field_1(field_1), expression(expression), field_2(field_2) {}

	static std::optional<EQUALITY_CHAIN_LOOP> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_EQUALITY_CHAIN_LOOP_HPP
