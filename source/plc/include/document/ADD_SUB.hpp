// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ADD_SUB_HPP
#define INCLUDED_ADD_SUB_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct ADD_SUB {
	erased<EXPRESSION> field_1;
	std::vector<erased<IC>> field_2;
	std::variant<
		literal_0xC20xB1_t const *,
		literal_0x2B0x2D_t const *
	> field_3;
	std::vector<erased<IC>> field_4;
	erased<EXPRESSION> field_5;


	ADD_SUB(
		erased<EXPRESSION> const & field_1,
		std::vector<erased<IC>> const & field_2,
		std::variant<
			literal_0xC20xB1_t const *,
			literal_0x2B0x2D_t const *
		> const & field_3,
		std::vector<erased<IC>> const & field_4,
		erased<EXPRESSION> const & field_5
	) : field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	static ADD_SUB build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_ADD_SUB_HPP
