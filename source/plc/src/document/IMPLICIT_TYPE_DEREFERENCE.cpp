// This file was generated using Parlex's cpp_generator

#include "IMPLICIT_TYPE_DEREFERENCE.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "IC.hpp"

plc::IMPLICIT_TYPE_DEREFERENCE plc::IMPLICIT_TYPE_DEREFERENCE::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().IMPLICIT_TYPE_DEREFERENCE.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<parlex::details::document::text<literal_0x3C_t>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<parlex::details::document::text<literal_0x3E_t>>::build(&*children[2], w);
	return IMPLICIT_TYPE_DEREFERENCE(std::move(v_0), std::move(v_1), std::move(v_2));
}


parlex::details::recognizer const & plc::IMPLICIT_TYPE_DEREFERENCE::recognizer() {
	return plange_grammar::get().IMPLICIT_TYPE_DEREFERENCE.get_recognizer();
}
