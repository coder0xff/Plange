// This file was generated using Parlex's cpp_generator

#include "FUNCTION.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "BLOCK.hpp"
#include "FUNCTION_MODIFIER_0.hpp"
#include "IC.hpp"
#include "PARAMETER.hpp"

plc::FUNCTION::field_1_t_1_t::field_2_t_1_t::field_1_t_1_t plc::FUNCTION::field_1_t_1_t::field_2_t_1_t::field_1_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2C_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<erased<PARAMETER>>::build(&*children[3], w);
	return field_1_t_1_t(std::move(v0), std::move(v1), std::move(v2), std::move(v3));
}

plc::FUNCTION::field_1_t_1_t::field_2_t_1_t plc::FUNCTION::field_1_t_1_t::field_2_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<erased<PARAMETER>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<field_1_t_1_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[2], w);
	return field_2_t_1_t(std::move(v0), std::move(v1), std::move(v2));
}

plc::FUNCTION::field_1_t_1_t plc::FUNCTION::field_1_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x28_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<field_2_t_1_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<parlex::detail::document::text<literal_0x29_t>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[4], w);
	return field_1_t_1_t(std::move(v0), std::move(v1), std::move(v2), std::move(v3), std::move(v4));
}

plc::FUNCTION::field_2_t_1_t plc::FUNCTION::field_2_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<erased<FUNCTION_MODIFIER_0>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	return field_2_t_1_t(std::move(v0), std::move(v1));
}

plc::FUNCTION plc::FUNCTION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::optional<field_1_t_1_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::optional<field_2_t_1_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<erased<BLOCK>>::build(&*children[2], w);
	return FUNCTION(std::move(v0), std::move(v1), std::move(v2));
}


parlex::detail::acceptor const & plc::FUNCTION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().FUNCTION));
	return result;
}
