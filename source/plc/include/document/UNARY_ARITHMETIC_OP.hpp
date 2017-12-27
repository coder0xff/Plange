// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_UNARY_ARITHMETIC_OP_HPP
#define INCLUDED_UNARY_ARITHMETIC_OP_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct FACTORIAL;
struct NEGATION;
struct POST_DEC;
struct POST_INC;
struct PRE_DEC;
struct PRE_INC;
struct RADICAL;

typedef std::variant<
	erased<FACTORIAL>,
	erased<NEGATION>,
	erased<POST_DEC>,
	erased<POST_INC>,
	erased<PRE_DEC>,
	erased<PRE_INC>,
	erased<RADICAL>
> UNARY_ARITHMETIC_OP_base;

struct UNARY_ARITHMETIC_OP: UNARY_ARITHMETIC_OP_base {
	static UNARY_ARITHMETIC_OP build(parlex::detail::ast_node const & n);
	explicit UNARY_ARITHMETIC_OP(UNARY_ARITHMETIC_OP_base const & value) : UNARY_ARITHMETIC_OP_base(value) {}
	static parlex::detail::state_machine const & state_machine();
};
} // namespace plc



#endif //INCLUDED_UNARY_ARITHMETIC_OP_HPP
