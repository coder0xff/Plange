// This file was generated using Parlex's cpp_generator

#include "ARRAY_INVOCATION.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "ARRAY_INDEXER.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"

plc::ARRAY_INVOCATION::argsTail_t_1_t plc::ARRAY_INVOCATION::argsTail_t_1_t::build(parlex::detail::behavior::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2C_t>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<std::optional<erased<ARRAY_INDEXER>>>::build(&*children[2], w);
	return argsTail_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2));
}

plc::ARRAY_INVOCATION plc::ARRAY_INVOCATION::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().ARRAY_INVOCATION.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5B_t>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<std::optional<erased<ARRAY_INDEXER>>>::build(&*children[2], w);
	auto v_3 = parlex::detail::document::element<std::vector<argsTail_t_1_t>>::build(&*children[3], w);
	auto v_4 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[4], w);
	auto v_5 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5D_t>>::build(&*children[5], w);
	return ARRAY_INVOCATION(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4), std::move(v_5));
}


parlex::detail::recognizer const & plc::ARRAY_INVOCATION::recognizer() {
	return plange_grammar::get().ARRAY_INVOCATION.get_recognizer();
}
