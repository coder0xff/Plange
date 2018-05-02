// This file was generated using Parlex's cpp_generator

#include "ASM_PTR_ARITHMETIC_ATT_REG.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "ASM_IDENTIFIER.hpp"
#include "NON_NEG_NON_FRACTIONAL.hpp"

plc::ASM_PTR_ARITHMETIC_ATT_REG::field_2_t_1_t::field_1_t_1_t plc::ASM_PTR_ARITHMETIC_ATT_REG::field_2_t_1_t::field_1_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2C_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<erased<NON_NEG_NON_FRACTIONAL>>::build(&*children[1], w);
	return field_1_t_1_t(std::move(v0), std::move(v1));
}

plc::ASM_PTR_ARITHMETIC_ATT_REG::field_2_t_1_t plc::ASM_PTR_ARITHMETIC_ATT_REG::field_2_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2C_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<erased<ASM_IDENTIFIER>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<field_1_t_1_t>>::build(&*children[2], w);
	return field_2_t_1_t(std::move(v0), std::move(v1), std::move(v2));
}

plc::ASM_PTR_ARITHMETIC_ATT_REG plc::ASM_PTR_ARITHMETIC_ATT_REG::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x28_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::optional<erased<ASM_IDENTIFIER>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<field_2_t_1_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<parlex::detail::document::text<literal_0x29_t>>::build(&*children[3], w);
	return ASM_PTR_ARITHMETIC_ATT_REG(std::move(v0), std::move(v1), std::move(v2), std::move(v3));
}


parlex::detail::acceptor const & plc::ASM_PTR_ARITHMETIC_ATT_REG::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ASM_PTR_ARITHMETIC_ATT_REG));
	return result;
}
