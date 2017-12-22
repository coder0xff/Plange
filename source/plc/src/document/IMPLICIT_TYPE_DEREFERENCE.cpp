// This file was generated using Parlex's cpp_generator

#include "IMPLICIT_TYPE_DEREFERENCE.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "IC.hpp"

plc::IMPLICIT_TYPE_DEREFERENCE plc::IMPLICIT_TYPE_DEREFERENCE::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().IMPLICIT_TYPE_DEREFERENCE.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3C_t>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3E_t>>::build(&*children[2], w);
	return IMPLICIT_TYPE_DEREFERENCE(std::move(v_0), std::move(v_1), std::move(v_2));
}


parlex::detail::recognizer const & plc::IMPLICIT_TYPE_DEREFERENCE::recognizer() {
	return plange_grammar::get().IMPLICIT_TYPE_DEREFERENCE.get_recognizer();
}
