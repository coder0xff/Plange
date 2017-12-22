// This file was generated using Parlex's cpp_generator

#include "READ_LOCK.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "PARENTHETICAL.hpp"

plc::READ_LOCK plc::READ_LOCK::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().READ_LOCK.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<parlex::detail::document::text<literal_read_lock_t>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<erased<PARENTHETICAL>>::build(&*children[2], w);
	auto v_3 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	auto v_4 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[4], w);
	return READ_LOCK(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4));
}


parlex::detail::recognizer const & plc::READ_LOCK::recognizer() {
	return plange_grammar::get().READ_LOCK.get_recognizer();
}
