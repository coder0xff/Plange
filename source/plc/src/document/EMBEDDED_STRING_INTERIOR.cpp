// This file was generated using Parlex's cpp_generator

#include "EMBEDDED_STRING_INTERIOR.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EMBEDDED_STRING_INTERIOR.hpp"
#include "PAYLOAD.hpp"

#include "EMBEDDED_STRING_INTERIOR.hpp"

namespace plc {

EMBEDDED_STRING_INTERIOR EMBEDDED_STRING_INTERIOR::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().EMBEDDED_STRING_INTERIOR.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return EMBEDDED_STRING_INTERIOR(parlex::details::document::element<EMBEDDED_STRING_INTERIOR_base>::build(document, b, w));
}

} // namespace plc
plc::EMBEDDED_STRING_INTERIOR_2_t plc::EMBEDDED_STRING_INTERIOR_2_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	assert(w.pos != w.end); ++w.pos; //" 
	auto v_0 = parlex::details::document::element<erased<EMBEDDED_STRING_INTERIOR>>::build(document, *children[1], w);
	assert(w.pos != w.end); ++w.pos; //" 
	return EMBEDDED_STRING_INTERIOR_2_t(std::move(v_0));
}

