// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_INHERITANCE_LIST_HPP
#define INCLUDED_INHERITANCE_LIST_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct EXPRESSION;
struct IC;
struct INHERITANCE_ITEM_PREFIX;

struct INHERITANCE_LIST {
	std::optional<erased<INHERITANCE_ITEM_PREFIX>> field_1;
	erased<EXPRESSION> EXPRESSION;
	std::vector<std::tuple<
		std::vector<erased<IC>>,
		std::vector<erased<IC>>,
		std::optional<erased<INHERITANCE_ITEM_PREFIX>>,
		erased<EXPRESSION>
	>> field_2;

	INHERITANCE_LIST(
		std::optional<erased<INHERITANCE_ITEM_PREFIX>> const & field_1,
		erased<EXPRESSION> const & EXPRESSION,
		std::vector<std::tuple<
			std::vector<erased<IC>>,
			std::vector<erased<IC>>,
			std::optional<erased<INHERITANCE_ITEM_PREFIX>>,
			erased<EXPRESSION>
		>> const & field_2
	) : field_1(field_1), EXPRESSION(EXPRESSION), field_2(field_2) {}
};



#endif //INCLUDED_INHERITANCE_LIST_HPP
