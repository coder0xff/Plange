// This file was generated using Parlex's cpp_generator

#include "FOR_STEP_LIST.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "FOR_STEP.hpp"
#include "IC.hpp"

plc::FOR_STEP_LIST::tail_t plc::FOR_STEP_LIST::tail_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2C_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<val<FOR_STEP>>::build(&*children[3], w);
	return tail_t(std::move(v0), std::move(v1), std::move(v2), std::move(v3));
}

plc::FOR_STEP_LIST plc::FOR_STEP_LIST::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<FOR_STEP>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<tail_t>>::build(&*children[1], w);
	return FOR_STEP_LIST(n.document_position, n.consumed_character_count, std::move(v0), std::move(v1));
}


parlex::detail::acceptor const & plc::FOR_STEP_LIST::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().FOR_STEP_LIST));
	return result;
}
