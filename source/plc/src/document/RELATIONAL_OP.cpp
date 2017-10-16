// This file was generated using Parlex's cpp_generator

#include "RELATIONAL_OP.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "CASTS.hpp"
#include "DOWNCASTS.hpp"
#include "EXACTLY.hpp"
#include "IMPLEMENTS.hpp"
#include "INEQUALITY.hpp"
#include "INHERITS.hpp"
#include "IS.hpp"
#include "RELATIONAL_COLLECTION_OP.hpp"
#include "UPCASTS.hpp"

#include "RELATIONAL_OP.hpp"

namespace plc {

RELATIONAL_OP RELATIONAL_OP::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().RELATIONAL_OP.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return RELATIONAL_OP(parlex::details::document::element<RELATIONAL_OP_base>::build(document, b, w));
}

} // namespace plc
