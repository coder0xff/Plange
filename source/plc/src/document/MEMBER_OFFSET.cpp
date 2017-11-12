// This file was generated using Parlex's cpp_generator

#include "MEMBER_OFFSET.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "IC.hpp"
#include "WHOLE_NUMBER.hpp"

plc::MEMBER_OFFSET plc::MEMBER_OFFSET::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().MEMBER_OFFSET.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<parlex::details::document::text<literal_0x40_t>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<erased<WHOLE_NUMBER>>::build(&*children[2], w);
	return MEMBER_OFFSET(std::move(v_0), std::move(v_1), std::move(v_2));
}


parlex::details::recognizer const & plc::MEMBER_OFFSET::recognizer() {
	return plange_grammar::get().MEMBER_OFFSET.get_recognizer();
}
