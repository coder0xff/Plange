// This file was generated using Parlex's cpp_generator

#include "PAYLOAD.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "PAYLOAD.hpp"

namespace plc {

PAYLOAD PAYLOAD::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().PAYLOAD.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return PAYLOAD(parlex::details::document::element<PAYLOAD_base>::build(document, b, w));
}

} // namespace plc
