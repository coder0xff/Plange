// This file was generated using Parlex's cpp_generator

#include "DELTA.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "EXPRESSION.hpp"
#include "WHOLE_NUMBER.hpp"

plc::DELTA::field_2_t plc::DELTA::field_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5E_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<WHOLE_NUMBER>>::build(&*children[1], w);
	return field_2_t(v0, v1);
}

plc::DELTA plc::DELTA::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xCE0x94_t>,
		parlex::detail::document::text<literal__delta__t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::optional<field_2_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	return DELTA(n.document_position, n.consumed_character_count, v0, v1, v2);
}


parlex::detail::acceptor const & plc::DELTA::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().DELTA));
	return result;
}
