// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_UNARY_LOGICAL_OP_HPP
#define INCLUDED_UNARY_LOGICAL_OP_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ALL;
struct EXISTS;
struct EXISTS_ONE;
struct NOT;

typedef std::variant<
	erased<ALL>,
	erased<EXISTS>,
	erased<EXISTS_ONE>,
	erased<NOT>
> UNARY_LOGICAL_OP_base;

struct UNARY_LOGICAL_OP: UNARY_LOGICAL_OP_base {
	static UNARY_LOGICAL_OP build(parlex::details::ast_node const & n);
	explicit UNARY_LOGICAL_OP(UNARY_LOGICAL_OP_base const & value) : UNARY_LOGICAL_OP_base(value) {}
	static parlex::details::recognizer const & recognizer();
};
} // namespace plc



#endif //INCLUDED_UNARY_LOGICAL_OP_HPP
