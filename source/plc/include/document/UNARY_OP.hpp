// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_UNARY_OP_HPP
#define INCLUDED_UNARY_OP_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ALLOCATION;
struct CARDINALITY;
struct KLEENE_STAR;
struct UNARY_ARITHMETIC_OP;
struct UNARY_LOGICAL_OP;

typedef std::variant<
	erased<ALLOCATION>,
	erased<CARDINALITY>,
	erased<KLEENE_STAR>,
	erased<UNARY_ARITHMETIC_OP>,
	erased<UNARY_LOGICAL_OP>
> UNARY_OP_base;

struct UNARY_OP: UNARY_OP_base {
	static UNARY_OP build(parlex::detail::ast_node const & n);
	explicit UNARY_OP(UNARY_OP_base const & value) : UNARY_OP_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
} // namespace plc



#endif //INCLUDED_UNARY_OP_HPP
