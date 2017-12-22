// This file was generated using Parlex's cpp_generator

#include "EMBEDDED_NEWLINE_STRING.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "EMBEDDED_NEWLINE_STRING_INTERIOR.hpp"

plc::EMBEDDED_NEWLINE_STRING plc::EMBEDDED_NEWLINE_STRING::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().EMBEDDED_NEWLINE_STRING.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x220x220x22_t>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<erased<EMBEDDED_NEWLINE_STRING_INTERIOR>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x220x220x22_t>>::build(&*children[2], w);
	return EMBEDDED_NEWLINE_STRING(std::move(v_0), std::move(v_1), std::move(v_2));
}


parlex::detail::recognizer const & plc::EMBEDDED_NEWLINE_STRING::recognizer() {
	return plange_grammar::get().EMBEDDED_NEWLINE_STRING.get_recognizer();
}
