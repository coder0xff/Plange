// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DEFINITION_HPP
#define INCLUDED_DEFINITION_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct EXPRESSION;
struct IC;
struct IDENTIFIER;
struct XML_DOC_STRING;

struct DEFINITION {
	std::optional<std::tuple<
		erased<XML_DOC_STRING>,
		std::vector<erased<IC>>
	>> field_1;
	erased<IDENTIFIER> IDENTIFIER;
	std::vector<erased<IC>> field_2;
	std::vector<erased<IC>> field_3;
	erased<EXPRESSION> EXPRESSION;

	DEFINITION(
		std::optional<std::tuple<
			erased<XML_DOC_STRING>,
			std::vector<erased<IC>>
		>> const & field_1,
		erased<IDENTIFIER> const & IDENTIFIER,
		std::vector<erased<IC>> const & field_2,
		std::vector<erased<IC>> const & field_3,
		erased<EXPRESSION> const & EXPRESSION
	) : field_1(field_1), IDENTIFIER(IDENTIFIER), field_2(field_2), field_3(field_3), EXPRESSION(EXPRESSION) {}
};



#endif //INCLUDED_DEFINITION_HPP
