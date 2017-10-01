// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASM_PTR_ARITHMETIC_ATT_REG_HPP
#define INCLUDED_ASM_PTR_ARITHMETIC_ATT_REG_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct ASM_IDENTIFIER;
struct NON_NEG_NON_FRACTIONAL;

struct ASM_PTR_ARITHMETIC_ATT_REG {
	std::optional<erased<ASM_IDENTIFIER>> field_1;
	std::optional<std::tuple<
		erased<ASM_IDENTIFIER>,
		std::optional<std::tuple<
			erased<NON_NEG_NON_FRACTIONAL>
		>>
	>> field_2;


	ASM_PTR_ARITHMETIC_ATT_REG(
		std::optional<erased<ASM_IDENTIFIER>> const & field_1,
		std::optional<std::tuple<
			erased<ASM_IDENTIFIER>,
			std::optional<std::tuple<
				erased<NON_NEG_NON_FRACTIONAL>
			>>
		>> const & field_2
	) : field_1(field_1), field_2(field_2) {}

	static ASM_PTR_ARITHMETIC_ATT_REG build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_ASM_PTR_ARITHMETIC_ATT_REG_HPP
