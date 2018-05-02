// This file was generated using Parlex's cpp_generator

#include "EXPRESSION.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "ARRAY.hpp"
#include "ASM_FUNCTION.hpp"
#include "BINARY_OP.hpp"
#include "BOOL.hpp"
#include "CAST.hpp"
#include "CEILING.hpp"
#include "COMPLEMENT.hpp"
#include "CONDITIONAL.hpp"
#include "DATE.hpp"
#include "DATE_TIME.hpp"
#include "DELTA.hpp"
#include "DIMENSIONAL_NUMBER.hpp"
#include "EMBEDDED_STRING.hpp"
#include "ENUM.hpp"
#include "EQUALITY_CHAIN.hpp"
#include "FLOOR.hpp"
#include "FUNCTION.hpp"
#include "GREATER_CHAIN.hpp"
#include "IDENTIFIER.hpp"
#include "IF.hpp"
#include "INVOCATION.hpp"
#include "LESSER_CHAIN.hpp"
#include "LIST.hpp"
#include "MAGNITUDE.hpp"
#include "MAP.hpp"
#include "MEMBER_ACCESS.hpp"
#include "NEAREST_INTEGER.hpp"
#include "NON_NEG_NUMBER.hpp"
#include "OBJECT.hpp"
#include "PARENTHETICAL.hpp"
#include "RANGE.hpp"
#include "REGEX.hpp"
#include "SET.hpp"
#include "SET_COMPREHENSION.hpp"
#include "SUBSET_CHAIN.hpp"
#include "SUPERSET_CHAIN.hpp"
#include "SWIZZLE.hpp"
#include "THIS.hpp"
#include "THIS_FUNC.hpp"
#include "THIS_TYPE.hpp"
#include "TIME.hpp"
#include "TUPLE.hpp"
#include "TYPE.hpp"
#include "UNARY_OP.hpp"
#include "VECTOR_NORM.hpp"

#include "EXPRESSION.hpp"

namespace plc {

EXPRESSION EXPRESSION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return EXPRESSION(parlex::detail::document::element<EXPRESSION_base>::build(b, w));
}

} // namespace plc

parlex::detail::acceptor const & plc::EXPRESSION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().EXPRESSION));
	return result;
}
