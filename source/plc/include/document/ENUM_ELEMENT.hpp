// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ENUM_ELEMENT_HPP
#define INCLUDED_ENUM_ELEMENT_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct EXPRESSION;
struct IC;
struct IDENTIFIER;

struct ENUM_ELEMENT {
	erased<IDENTIFIER> IDENTIFIER;
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		std::vector<erased<IC>>,
		erased<EXPRESSION>
	>> field_1;

	ENUM_ELEMENT(
		erased<IDENTIFIER> const & IDENTIFIER,
		std::optional<std::tuple<
			std::vector<erased<IC>>,
			std::vector<erased<IC>>,
			erased<EXPRESSION>
		>> const & field_1
	) : IDENTIFIER(IDENTIFIER), field_1(field_1) {}
};



#endif //INCLUDED_ENUM_ELEMENT_HPP
