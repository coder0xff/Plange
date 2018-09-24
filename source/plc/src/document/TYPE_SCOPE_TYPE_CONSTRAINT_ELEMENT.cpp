// This file was generated using Parlex's cpp_generator

#include "TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "DEFINITION.hpp"
#include "TYPE_SCOPE_ASSIGNMENT.hpp"
#include "TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION.hpp"

#include "TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT.hpp"

namespace plc {

TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT(parlex::detail::document::element<TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT_base>::build(b, w));
}

} // namespace plc

parlex::detail::acceptor const & plc::TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT));
	return result;
}
