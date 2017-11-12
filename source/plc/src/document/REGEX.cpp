// This file was generated using Parlex's cpp_generator

#include "REGEX.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

plc::REGEX plc::REGEX::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().REGEX.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<parlex::details::document::text<literal_R_t>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<parlex::details::document::text<void>>::build(&*children[1], w);
	return REGEX(std::move(v_0), std::move(v_1));
}


parlex::details::recognizer const & plc::REGEX::recognizer() {
	return plange_grammar::get().REGEX.get_recognizer();
}
