// This file was generated using Parlex's cpp_generator

#include "BINARY_COLLECTION_OP.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "BIJECTION.hpp"
#include "INTERSECTION.hpp"
#include "SYMMETRIC_DIFFERENCE.hpp"
#include "UNION.hpp"

#include "BINARY_COLLECTION_OP.hpp"

namespace plc {

BINARY_COLLECTION_OP BINARY_COLLECTION_OP::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().BINARY_COLLECTION_OP.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return BINARY_COLLECTION_OP(parlex::details::document::element<BINARY_COLLECTION_OP_base>::build(b, w));
}

} // namespace plc

parlex::details::recognizer const & plc::BINARY_COLLECTION_OP::recognizer() {
	return plange_grammar::get().BINARY_COLLECTION_OP.get_recognizer();
}
