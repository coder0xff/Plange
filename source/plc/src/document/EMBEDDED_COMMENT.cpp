// This file was generated using Parlex's cpp_generator

#include "EMBEDDED_COMMENT.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "EMBEDDED_COMMENT_INTERIOR.hpp"

plc::EMBEDDED_COMMENT plc::EMBEDDED_COMMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().EMBEDDED_COMMENT.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2F0x2A0x2A0x2A_t>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<erased<EMBEDDED_COMMENT_INTERIOR>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2A0x2A0x2A0x2F_t>>::build(&*children[2], w);
	return EMBEDDED_COMMENT(std::move(v_0), std::move(v_1), std::move(v_2));
}


parlex::detail::recognizer const & plc::EMBEDDED_COMMENT::recognizer() {
	return plange_grammar::get().EMBEDDED_COMMENT.get_recognizer();
}
