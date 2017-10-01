// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_NOT_HAS_HPP
#define INCLUDED_NOT_HAS_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct NOT_HAS {
	erased<EXPRESSION> field_1;
	std::vector<erased<IC>> field_2;
	std::variant<
		literal_0xE20x880x8C_t,
		literal_0x2Fhas_t
	> field_3;
	std::vector<erased<IC>> field_4;
	erased<EXPRESSION> field_5;


	NOT_HAS(
		erased<EXPRESSION> const & field_1,
		std::vector<erased<IC>> const & field_2,
		std::variant<
			literal_0xE20x880x8C_t,
			literal_0x2Fhas_t
		> const & field_3,
		std::vector<erased<IC>> const & field_4,
		erased<EXPRESSION> const & field_5
	) : field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	static NOT_HAS build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_NOT_HAS_HPP
