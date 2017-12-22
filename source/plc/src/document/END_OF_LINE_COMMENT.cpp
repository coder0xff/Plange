// This file was generated using Parlex's cpp_generator

#include "END_OF_LINE_COMMENT.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

plc::END_OF_LINE_COMMENT plc::END_OF_LINE_COMMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().END_OF_LINE_COMMENT.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2F0x2F_t>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<std::vector<parlex::detail::document::text<parlex::detail::not_newline_t>>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x0A_t>>::build(&*children[2], w);
	return END_OF_LINE_COMMENT(std::move(v_0), std::move(v_1), std::move(v_2));
}


parlex::detail::recognizer const & plc::END_OF_LINE_COMMENT::recognizer() {
	return plange_grammar::get().END_OF_LINE_COMMENT.get_recognizer();
}
