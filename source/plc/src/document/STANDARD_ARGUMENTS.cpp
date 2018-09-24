// This file was generated using Parlex's cpp_generator

#include "STANDARD_ARGUMENTS.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "ARGUMENT_PACK.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"

plc::STANDARD_ARGUMENTS::tail_t::field_1_t plc::STANDARD_ARGUMENTS::tail_t::field_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::variant<
		val<EXPRESSION>,
		val<ARGUMENT_PACK>
	>>::build(&*children[1], w);
	return field_1_t(std::move(v0), std::move(v1));
}

plc::STANDARD_ARGUMENTS::tail_t plc::STANDARD_ARGUMENTS::tail_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2C_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<field_1_t>>::build(&*children[2], w);
	return tail_t(std::move(v0), std::move(v1), std::move(v2));
}

plc::STANDARD_ARGUMENTS plc::STANDARD_ARGUMENTS::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::optional<std::variant<
		val<EXPRESSION>,
		val<ARGUMENT_PACK>
	>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<tail_t>>::build(&*children[1], w);
	return STANDARD_ARGUMENTS(n.document_position, n.consumed_character_count, std::move(v0), std::move(v1));
}


parlex::detail::acceptor const & plc::STANDARD_ARGUMENTS::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().STANDARD_ARGUMENTS));
	return result;
}
