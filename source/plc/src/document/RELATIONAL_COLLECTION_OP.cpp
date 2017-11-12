// This file was generated using Parlex's cpp_generator

#include "RELATIONAL_COLLECTION_OP.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "HAS.hpp"
#include "IN.hpp"
#include "NOT_HAS.hpp"
#include "NOT_IN.hpp"

#include "RELATIONAL_COLLECTION_OP.hpp"

namespace plc {

RELATIONAL_COLLECTION_OP RELATIONAL_COLLECTION_OP::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().RELATIONAL_COLLECTION_OP.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return RELATIONAL_COLLECTION_OP(parlex::details::document::element<RELATIONAL_COLLECTION_OP_base>::build(b, w));
}

} // namespace plc

parlex::details::recognizer const & plc::RELATIONAL_COLLECTION_OP::recognizer() {
	return plange_grammar::get().RELATIONAL_COLLECTION_OP.get_recognizer();
}
