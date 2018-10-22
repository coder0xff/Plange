// This file was generated using Parlex's cpp_generator

#include "TYPE_CONSTRAINT.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "IC.hpp"
#include "TYPE_CONSTRAINT_ELEMENT.hpp"
#include "TYPE_CONSTRAINT_SPECIFICATION.hpp"

plc::TYPE_CONSTRAINT::tail_t plc::TYPE_CONSTRAINT::tail_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2C_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<val<TYPE_CONSTRAINT_ELEMENT>>::build(&*children[3], w);
	return tail_t(v0, v1, v2, v3);
}

plc::TYPE_CONSTRAINT plc::TYPE_CONSTRAINT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<TYPE_CONSTRAINT_SPECIFICATION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<TYPE_CONSTRAINT_ELEMENT>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<tail_t>>::build(&*children[3], w);
	return TYPE_CONSTRAINT(n.document_position, n.consumed_character_count, v0, v1, v2, v3);
}


parlex::detail::acceptor const & plc::TYPE_CONSTRAINT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().TYPE_CONSTRAINT));
	return result;
}
