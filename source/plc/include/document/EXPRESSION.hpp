// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EXPRESSION_HPP
#define INCLUDED_EXPRESSION_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ARRAY;
struct ASM_FUNCTION;
struct BINARY_OP;
struct BOOL;
struct CAST;
struct CEILING;
struct COMPLEMENT;
struct CONDITIONAL;
struct DATE;
struct DATE_TIME;
struct DELTA;
struct DIMENSIONAL_NUMBER;
struct EMBEDDED_STRING;
struct ENUM;
struct EQUALITY;
struct FLOOR;
struct FUNCTION;
struct GREATER;
struct IDENTIFIER;
struct IF;
struct INVOCATION;
struct LESSER;
struct LIST;
struct MAGNITUDE;
struct MAP;
struct MEMBER_ACCESS;
struct NEAREST_INTEGER;
struct NON_NEG_NUMBER;
struct OBJECT;
struct PARENTHETICAL;
struct RANGE;
struct REGEX;
struct SET;
struct SET_COMPREHENSION;
struct SUBSET;
struct SUPERSET;
struct SWIZZLE;
struct THIS;
struct THIS_FUNC;
struct THIS_TYPE;
struct TIME;
struct TUPLE;
struct TYPE;
struct UNARY_OP;
struct VECTOR_NORM;

typedef std::variant<
	val<ARRAY>,
	val<ASM_FUNCTION>,
	val<BINARY_OP>,
	val<BOOL>,
	val<CAST>,
	val<CEILING>,
	val<COMPLEMENT>,
	val<CONDITIONAL>,
	val<DATE>,
	val<DATE_TIME>,
	val<DELTA>,
	val<DIMENSIONAL_NUMBER>,
	val<EMBEDDED_STRING>,
	val<ENUM>,
	val<EQUALITY>,
	val<FLOOR>,
	val<FUNCTION>,
	val<GREATER>,
	val<IDENTIFIER>,
	val<IF>,
	val<INVOCATION>,
	val<LESSER>,
	val<LIST>,
	val<MAGNITUDE>,
	val<MAP>,
	val<MEMBER_ACCESS>,
	val<NEAREST_INTEGER>,
	val<NON_NEG_NUMBER>,
	val<OBJECT>,
	val<PARENTHETICAL>,
	val<RANGE>,
	val<REGEX>,
	val<SET>,
	val<SET_COMPREHENSION>,
	val<SUBSET>,
	val<SUPERSET>,
	val<SWIZZLE>,
	val<THIS>,
	val<THIS_FUNC>,
	val<THIS_TYPE>,
	val<TIME>,
	val<TUPLE>,
	val<TYPE>,
	val<UNARY_OP>,
	val<VECTOR_NORM>,
	parlex::detail::document::text<literal_context_t>,
	parlex::detail::document::text<literal_null_t>,
	parlex::detail::document::text<void>
> EXPRESSION_base;

struct EXPRESSION: EXPRESSION_base {
	static EXPRESSION build(parlex::detail::ast_node const & n);
	explicit EXPRESSION(EXPRESSION_base const & value) : EXPRESSION_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
} // namespace plc



#endif //INCLUDED_EXPRESSION_HPP
