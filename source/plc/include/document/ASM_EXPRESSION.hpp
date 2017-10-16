// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASM_EXPRESSION_HPP
#define INCLUDED_ASM_EXPRESSION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ASM_IDENTIFIER;
struct ASM_PTR_ARITHMETIC_ATT;
struct ASM_PTR_ARITHMETIC_INTEL;
struct NON_FRACTIONAL;

typedef std::variant<
	erased<ASM_IDENTIFIER>,
	erased<ASM_PTR_ARITHMETIC_ATT>,
	erased<ASM_PTR_ARITHMETIC_INTEL>,
	erased<NON_FRACTIONAL>
> ASM_EXPRESSION_base;

struct ASM_EXPRESSION: ASM_EXPRESSION_base {
	static ASM_EXPRESSION build(std::u32string const & document, parlex::details::ast_node const & n);
	explicit ASM_EXPRESSION(ASM_EXPRESSION_base const & value) : ASM_EXPRESSION_base(value) {}
};
} // namespace plc



#endif //INCLUDED_ASM_EXPRESSION_HPP
