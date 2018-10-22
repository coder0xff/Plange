// This file was generated using Parlex's cpp_generator

#include "TYPE_SCOPE.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "IC.hpp"
#include "TYPE_STATEMENT.hpp"

plc::TYPE_SCOPE::field_2_t plc::TYPE_SCOPE::field_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<TYPE_STATEMENT>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	return field_2_t(v0, v1);
}

plc::TYPE_SCOPE plc::TYPE_SCOPE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<field_2_t>>::build(&*children[1], w);
	return TYPE_SCOPE(n.document_position, n.consumed_character_count, v0, v1);
}


parlex::detail::acceptor const & plc::TYPE_SCOPE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().TYPE_SCOPE));
	return result;
}
