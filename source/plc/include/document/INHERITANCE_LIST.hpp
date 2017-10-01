// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_INHERITANCE_LIST_HPP
#define INCLUDED_INHERITANCE_LIST_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EXPRESSION;
struct IC;
struct INHERITANCE_ITEM_PREFIX;

struct INHERITANCE_LIST {
	std::optional<erased<INHERITANCE_ITEM_PREFIX>> field_1;
	erased<EXPRESSION> expression;
	std::vector<std::tuple<
		std::vector<erased<IC>>,
		std::vector<erased<IC>>,
		std::optional<erased<INHERITANCE_ITEM_PREFIX>>,
		erased<EXPRESSION>
	>> field_2;


	INHERITANCE_LIST(
		std::optional<erased<INHERITANCE_ITEM_PREFIX>> const & field_1,
		erased<EXPRESSION> const & expression,
		std::vector<std::tuple<
			std::vector<erased<IC>>,
			std::vector<erased<IC>>,
			std::optional<erased<INHERITANCE_ITEM_PREFIX>>,
			erased<EXPRESSION>
		>> const & field_2
	) : field_1(field_1), expression(expression), field_2(field_2) {}

	static INHERITANCE_LIST build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_INHERITANCE_LIST_HPP
