// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_BINARY_ARITHMETIC_OP_HPP
#define INCLUDED_BINARY_ARITHMETIC_OP_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ADDITION;
struct ADD_SUB;
struct DIVISION;
struct EXPONENTIATION;
struct INTEGER_DIVISION;
struct MODULATION;
struct MULTIPLICATIVE_OP;
struct SHIFTL;
struct SHIFTR;
struct SUBTRACTION;

typedef std::variant<
	erased<ADD_SUB>,
	erased<ADDITION>,
	erased<DIVISION>,
	erased<EXPONENTIATION>,
	erased<INTEGER_DIVISION>,
	erased<MODULATION>,
	erased<MULTIPLICATIVE_OP>,
	erased<SHIFTL>,
	erased<SHIFTR>,
	erased<SUBTRACTION>
> BINARY_ARITHMETIC_OP_base;

struct BINARY_ARITHMETIC_OP: BINARY_ARITHMETIC_OP_base {
	static BINARY_ARITHMETIC_OP build(parlex::detail::ast_node const & n);
	explicit BINARY_ARITHMETIC_OP(BINARY_ARITHMETIC_OP_base const & value) : BINARY_ARITHMETIC_OP_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
} // namespace plc



#endif //INCLUDED_BINARY_ARITHMETIC_OP_HPP
