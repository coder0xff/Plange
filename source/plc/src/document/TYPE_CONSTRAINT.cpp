// This file was generated using Parlex's cpp_generator

#include "TYPE_CONSTRAINT.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "IC.hpp"
#include "TYPE_CONSTRAINT_CHAIN.hpp"
#include "TYPE_CONSTRAINT_HEAD.hpp"

plc::TYPE_CONSTRAINT plc::TYPE_CONSTRAINT::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().TYPE_CONSTRAINT.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<erased<TYPE_CONSTRAINT_HEAD>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<erased<TYPE_CONSTRAINT_CHAIN>>::build(&*children[2], w);
	return TYPE_CONSTRAINT(std::move(v_0), std::move(v_1), std::move(v_2));
}


parlex::details::recognizer const & plc::TYPE_CONSTRAINT::recognizer() {
	return plange_grammar::get().TYPE_CONSTRAINT.get_recognizer();
}
