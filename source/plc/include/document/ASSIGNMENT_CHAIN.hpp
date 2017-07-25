// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASSIGNMENT_CHAIN_HPP
#define INCLUDED_ASSIGNMENT_CHAIN_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct ASSIGNMENT_CHAIN;
struct EXPRESSION;
struct IC;
struct IDENTIFIER;
struct XML_DOC_STRING;

struct ASSIGNMENT_CHAIN {
	std::optional<std::tuple<
		erased<XML_DOC_STRING>,
		std::vector<erased<IC>>
	>> field_1;
	erased<IDENTIFIER> IDENTIFIER;
	std::vector<erased<IC>> field_2;
	std::variant<
		std::integral_constant<int, 0>,
		std::integral_constant<int, 1>
	> field_3;
	std::vector<erased<IC>> field_4;
	std::variant<
		erased<EXPRESSION>,
		erased<ASSIGNMENT_CHAIN>
	> field_5;

	ASSIGNMENT_CHAIN(
		std::optional<std::tuple<
			erased<XML_DOC_STRING>,
			std::vector<erased<IC>>
		>> const & field_1,
		erased<IDENTIFIER> const & IDENTIFIER,
		std::vector<erased<IC>> const & field_2,
		std::variant<
			std::integral_constant<int, 0>,
			std::integral_constant<int, 1>
		> const & field_3,
		std::vector<erased<IC>> const & field_4,
		std::variant<
			erased<EXPRESSION>,
			erased<ASSIGNMENT_CHAIN>
		> const & field_5
	) : field_1(field_1), IDENTIFIER(IDENTIFIER), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}
};



#endif //INCLUDED_ASSIGNMENT_CHAIN_HPP
