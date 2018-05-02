// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASM_EXPRESSION_HPP
#define INCLUDED_ASM_EXPRESSION_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

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
	static ASM_EXPRESSION build(parlex::detail::ast_node const & n);
	explicit ASM_EXPRESSION(ASM_EXPRESSION_base const & value) : ASM_EXPRESSION_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
} // namespace plc



#endif //INCLUDED_ASM_EXPRESSION_HPP
