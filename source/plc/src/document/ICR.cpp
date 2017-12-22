// This file was generated using Parlex's cpp_generator

#include "ICR.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "IC.hpp"

plc::ICR plc::ICR::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().ICR.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<erased<IC>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	return ICR(std::move(v_0), std::move(v_1));
}


parlex::detail::recognizer const & plc::ICR::recognizer() {
	return plange_grammar::get().ICR.get_recognizer();
}
