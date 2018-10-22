// This file was generated using Parlex's cpp_generator

#include "GREATER_NODE.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "EXPRESSION.hpp"
#include "GREATER_NODE.hpp"
#include "IC.hpp"

plc::GREATER_NODE::field_3_t plc::GREATER_NODE::field_3_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<GREATER_NODE>>::build(&*children[1], w);
	return field_3_t(v0, v1);
}

plc::GREATER_NODE plc::GREATER_NODE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3D_t>,
		parlex::detail::document::text<literal_0x3E_t>,
		parlex::detail::document::text<literal_0x3D0x3E_t>,
		parlex::detail::document::text<literal_0xE20x890xA5_t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::optional<field_3_t>>::build(&*children[3], w);
	return GREATER_NODE(n.document_position, n.consumed_character_count, v0, v1, v2, v3);
}


parlex::detail::acceptor const & plc::GREATER_NODE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().GREATER_NODE));
	return result;
}
