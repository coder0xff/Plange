// This file was generated using Parlex's cpp_generator

#include "FUNCTION_MODIFIER_THROWING.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "ARRAY.hpp"
#include "FUNCTION_MODIFIER_2.hpp"
#include "IC.hpp"

plc::FUNCTION_MODIFIER_THROWING::field_1_t_1_t plc::FUNCTION_MODIFIER_THROWING::field_1_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<erased<ARRAY>>::build(&*children[1], w);
	return field_1_t_1_t(std::move(v0), std::move(v1));
}

plc::FUNCTION_MODIFIER_THROWING::field_2_t_1_t plc::FUNCTION_MODIFIER_THROWING::field_2_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<erased<IC>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<erased<FUNCTION_MODIFIER_2>>::build(&*children[2], w);
	return field_2_t_1_t(std::move(v0), std::move(v1), std::move(v2));
}

plc::FUNCTION_MODIFIER_THROWING plc::FUNCTION_MODIFIER_THROWING::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_throwing_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::optional<field_1_t_1_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<field_2_t_1_t>>::build(&*children[2], w);
	return FUNCTION_MODIFIER_THROWING(std::move(v0), std::move(v1), std::move(v2));
}


parlex::detail::acceptor const & plc::FUNCTION_MODIFIER_THROWING::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().FUNCTION_MODIFIER_THROWING));
	return result;
}
