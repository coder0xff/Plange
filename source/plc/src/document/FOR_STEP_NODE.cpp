// This file was generated using Parlex's cpp_generator

#include "FOR_STEP_NODE.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "EXPRESSION.hpp"
#include "FOR_STEP_NODE.hpp"
#include "IC.hpp"
#include "IDENTIFIER.hpp"

plc::FOR_STEP_NODE::value_t plc::FOR_STEP_NODE::value_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<IDENTIFIER>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<FOR_STEP_NODE>>::build(&*children[2], w);
	return value_t(std::move(v0), std::move(v1), std::move(v2));
}

plc::FOR_STEP_NODE plc::FOR_STEP_NODE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x860x90_t>,
		parlex::detail::document::text<literal_0x3C0x2D_t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		val<EXPRESSION>,
		value_t
	>>::build(&*children[2], w);
	return FOR_STEP_NODE(n.document_position, n.consumed_character_count, std::move(v0), std::move(v1), std::move(v2));
}


parlex::detail::acceptor const & plc::FOR_STEP_NODE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().FOR_STEP_NODE));
	return result;
}
