// This file was generated using Parlex's cpp_generator

#include "DIMENSIONAL_NUMBER.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "DIMENSION.hpp"
#include "NON_NEG_NUMBER.hpp"

plc::DIMENSIONAL_NUMBER plc::DIMENSIONAL_NUMBER::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().DIMENSIONAL_NUMBER.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<erased<NON_NEG_NUMBER>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<erased<DIMENSION>>::build(&*children[1], w);
	return DIMENSIONAL_NUMBER(std::move(v_0), std::move(v_1));
}


parlex::detail::recognizer const & plc::DIMENSIONAL_NUMBER::recognizer() {
	return plange_grammar::get().DIMENSIONAL_NUMBER.get_recognizer();
}
