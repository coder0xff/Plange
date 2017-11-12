// This file was generated using Parlex's cpp_generator

#include "EMBEDDED_STRING_INTERIOR.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EMBEDDED_STRING_INTERIOR.hpp"

#include "EMBEDDED_STRING_INTERIOR.hpp"

namespace plc {

EMBEDDED_STRING_INTERIOR EMBEDDED_STRING_INTERIOR::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().EMBEDDED_STRING_INTERIOR.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return EMBEDDED_STRING_INTERIOR(parlex::details::document::element<EMBEDDED_STRING_INTERIOR_base>::build(b, w));
}

} // namespace plc
plc::EMBEDDED_STRING_INTERIOR_1_t plc::EMBEDDED_STRING_INTERIOR_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<parlex::details::document::text<literal_0x22_t>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<erased<EMBEDDED_STRING_INTERIOR>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<parlex::details::document::text<literal_0x22_t>>::build(&*children[2], w);
	return EMBEDDED_STRING_INTERIOR_1_t(std::move(v_0), std::move(v_1), std::move(v_2));
}


parlex::details::recognizer const & plc::EMBEDDED_STRING_INTERIOR::recognizer() {
	return plange_grammar::get().EMBEDDED_STRING_INTERIOR.get_recognizer();
}
