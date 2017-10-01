// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASM_PTR_ARITHMETIC_ATT_HPP
#define INCLUDED_ASM_PTR_ARITHMETIC_ATT_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct ASM_IDENTIFIER;
struct ASM_PTR_ARITHMETIC_ATT_REG;
struct NON_FRACTIONAL;

typedef std::variant<
	std::tuple<
		erased<ASM_IDENTIFIER>,
		erased<NON_FRACTIONAL>
	>,
	std::tuple<
		erased<ASM_IDENTIFIER>,
		erased<NON_FRACTIONAL>,
		erased<ASM_PTR_ARITHMETIC_ATT_REG>
	>,
	std::tuple<
		erased<NON_FRACTIONAL>,
		erased<ASM_PTR_ARITHMETIC_ATT_REG>
	>
> ASM_PTR_ARITHMETIC_ATT_base;

struct ASM_PTR_ARITHMETIC_ATT: ASM_PTR_ARITHMETIC_ATT_base {
	static ASM_PTR_ARITHMETIC_ATT build(parlex::details::ast_node const & n);
	explicit ASM_PTR_ARITHMETIC_ATT(ASM_PTR_ARITHMETIC_ATT_base const & value) : ASM_PTR_ARITHMETIC_ATT_base(value) {}
};
} // namespace plc



#endif //INCLUDED_ASM_PTR_ARITHMETIC_ATT_HPP
