// This file was generated using Parlex's cpp_generator

#include "ASM_PTR_ARITHMETIC_ATT.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "ASM_IDENTIFIER.hpp"
#include "ASM_PTR_ARITHMETIC_ATT_REG.hpp"
#include "NON_FRACTIONAL.hpp"

#include "ASM_PTR_ARITHMETIC_ATT.hpp"

namespace plc {

ASM_PTR_ARITHMETIC_ATT ASM_PTR_ARITHMETIC_ATT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return ASM_PTR_ARITHMETIC_ATT(parlex::detail::document::element<ASM_PTR_ARITHMETIC_ATT_base>::build(b, w));
}

} // namespace plc
plc::ASM_PTR_ARITHMETIC_ATT_1_t plc::ASM_PTR_ARITHMETIC_ATT_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<erased<ASM_IDENTIFIER>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3A_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<erased<NON_FRACTIONAL>>::build(&*children[2], w);
	return ASM_PTR_ARITHMETIC_ATT_1_t(std::move(v0), std::move(v1), std::move(v2));
}

plc::ASM_PTR_ARITHMETIC_ATT_2_t plc::ASM_PTR_ARITHMETIC_ATT_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<erased<ASM_IDENTIFIER>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3A_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<erased<NON_FRACTIONAL>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<erased<ASM_PTR_ARITHMETIC_ATT_REG>>::build(&*children[3], w);
	return ASM_PTR_ARITHMETIC_ATT_2_t(std::move(v0), std::move(v1), std::move(v2), std::move(v3));
}

plc::ASM_PTR_ARITHMETIC_ATT_3_t plc::ASM_PTR_ARITHMETIC_ATT_3_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<erased<NON_FRACTIONAL>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<erased<ASM_PTR_ARITHMETIC_ATT_REG>>::build(&*children[1], w);
	return ASM_PTR_ARITHMETIC_ATT_3_t(std::move(v0), std::move(v1));
}


parlex::detail::acceptor const & plc::ASM_PTR_ARITHMETIC_ATT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ASM_PTR_ARITHMETIC_ATT));
	return result;
}
