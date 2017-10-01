// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASM_STATEMENT_HPP
#define INCLUDED_ASM_STATEMENT_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct ASM_EXPRESSION;
struct ASM_OP;
struct IC;
struct ICR;

struct ASM_STATEMENT {
	erased<ASM_OP> field_1;
	std::optional<std::tuple<
		erased<ICR>,
		erased<ASM_EXPRESSION>,
		std::vector<std::tuple<
			std::vector<erased<IC>>,
			std::optional<std::tuple<
				std::vector<erased<IC>>,
				erased<ASM_EXPRESSION>
			>>
		>>
	>> field_2;
	std::vector<erased<IC>> field_3;


	ASM_STATEMENT(
		erased<ASM_OP> const & field_1,
		std::optional<std::tuple<
			erased<ICR>,
			erased<ASM_EXPRESSION>,
			std::vector<std::tuple<
				std::vector<erased<IC>>,
				std::optional<std::tuple<
					std::vector<erased<IC>>,
					erased<ASM_EXPRESSION>
				>>
			>>
		>> const & field_2,
		std::vector<erased<IC>> const & field_3
	) : field_1(field_1), field_2(field_2), field_3(field_3) {}

	static ASM_STATEMENT build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_ASM_STATEMENT_HPP
