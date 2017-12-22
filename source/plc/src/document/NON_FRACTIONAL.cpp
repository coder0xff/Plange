// This file was generated using Parlex's cpp_generator

#include "NON_FRACTIONAL.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "NON_NEG_NON_FRACTIONAL.hpp"

plc::NON_FRACTIONAL plc::NON_FRACTIONAL::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().NON_FRACTIONAL.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<std::optional<parlex::detail::document::text<literal_0x2D_t>>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<erased<NON_NEG_NON_FRACTIONAL>>::build(&*children[1], w);
	return NON_FRACTIONAL(std::move(v_0), std::move(v_1));
}


parlex::detail::recognizer const & plc::NON_FRACTIONAL::recognizer() {
	return plange_grammar::get().NON_FRACTIONAL.get_recognizer();
}
