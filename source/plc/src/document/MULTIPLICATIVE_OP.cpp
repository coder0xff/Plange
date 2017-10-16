// This file was generated using Parlex's cpp_generator

#include "MULTIPLICATIVE_OP.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "CROSS_PRODUCT.hpp"
#include "DOT_PRODUCT.hpp"
#include "MULTIPLICATION.hpp"

#include "MULTIPLICATIVE_OP.hpp"

namespace plc {

MULTIPLICATIVE_OP MULTIPLICATIVE_OP::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().MULTIPLICATIVE_OP.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return MULTIPLICATIVE_OP(parlex::details::document::element<MULTIPLICATIVE_OP_base>::build(document, b, w));
}

} // namespace plc
