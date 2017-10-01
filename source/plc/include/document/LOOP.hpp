// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_LOOP_HPP
#define INCLUDED_LOOP_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EXPRESSION;
struct IC;
struct PARENTHETICAL;

struct LOOP {
	std::variant<
		literal_while_t,
		literal_until_t
	> field_1;
	std::vector<erased<IC>> field_2;
	erased<PARENTHETICAL> field_3;
	std::vector<erased<IC>> field_4;
	erased<EXPRESSION> field_5;


	LOOP(
		std::variant<
			literal_while_t,
			literal_until_t
		> const & field_1,
		std::vector<erased<IC>> const & field_2,
		erased<PARENTHETICAL> const & field_3,
		std::vector<erased<IC>> const & field_4,
		erased<EXPRESSION> const & field_5
	) : field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	static LOOP build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_LOOP_HPP
