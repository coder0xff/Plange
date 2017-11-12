// This file was generated using Parlex's cpp_generator

#include "NON_FRACTIONAL.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "NON_NEG_NON_FRACTIONAL.hpp"

plc::NON_FRACTIONAL plc::NON_FRACTIONAL::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().NON_FRACTIONAL.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<std::optional<parlex::details::document::text<literal_0x2D_t>>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<erased<NON_NEG_NON_FRACTIONAL>>::build(&*children[1], w);
	return NON_FRACTIONAL(std::move(v_0), std::move(v_1));
}


parlex::details::recognizer const & plc::NON_FRACTIONAL::recognizer() {
	return plange_grammar::get().NON_FRACTIONAL.get_recognizer();
}
