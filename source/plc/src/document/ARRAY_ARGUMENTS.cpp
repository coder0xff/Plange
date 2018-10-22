// This file was generated using Parlex's cpp_generator

#include "ARRAY_ARGUMENTS.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "ARRAY_INDEXER.hpp"
#include "IC.hpp"

plc::ARRAY_ARGUMENTS::tail_t::field_1_t plc::ARRAY_ARGUMENTS::tail_t::field_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<ARRAY_INDEXER>>::build(&*children[1], w);
	return field_1_t(v0, v1);
}

plc::ARRAY_ARGUMENTS::tail_t plc::ARRAY_ARGUMENTS::tail_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2C_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<field_1_t>>::build(&*children[2], w);
	return tail_t(v0, v1, v2);
}

plc::ARRAY_ARGUMENTS plc::ARRAY_ARGUMENTS::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::optional<val<ARRAY_INDEXER>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<tail_t>>::build(&*children[1], w);
	return ARRAY_ARGUMENTS(n.document_position, n.consumed_character_count, v0, v1);
}


parlex::detail::acceptor const & plc::ARRAY_ARGUMENTS::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ARRAY_ARGUMENTS));
	return result;
}
