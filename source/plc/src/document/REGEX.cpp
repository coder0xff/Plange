// This file was generated using Parlex's cpp_generator

#include "REGEX.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

plc::REGEX plc::REGEX::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().REGEX.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<parlex::detail::document::text<literal_R_t>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<parlex::detail::document::text<void>>::build(&*children[1], w);
	return REGEX(std::move(v_0), std::move(v_1));
}


parlex::detail::recognizer const & plc::REGEX::recognizer() {
	return plange_grammar::get().REGEX.get_recognizer();
}
