// This file was generated using Parlex's cpp_generator

#include "ASM_PTR_ARITHMETIC_ATT.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "ASM_IDENTIFIER.hpp"
#include "ASM_PTR_ARITHMETIC_ATT_REG.hpp"
#include "NON_FRACTIONAL.hpp"

#include "ASM_PTR_ARITHMETIC_ATT.hpp"

namespace plc {

ASM_PTR_ARITHMETIC_ATT ASM_PTR_ARITHMETIC_ATT::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().ASM_PTR_ARITHMETIC_ATT.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return ASM_PTR_ARITHMETIC_ATT(parlex::details::document::element<ASM_PTR_ARITHMETIC_ATT_base>::build(b, w));
}

} // namespace plc
plc::ASM_PTR_ARITHMETIC_ATT_1_t plc::ASM_PTR_ARITHMETIC_ATT_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<erased<ASM_IDENTIFIER>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<parlex::details::document::text<literal_0x3A_t>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<erased<NON_FRACTIONAL>>::build(&*children[2], w);
	return ASM_PTR_ARITHMETIC_ATT_1_t(std::move(v_0), std::move(v_1), std::move(v_2));
}

plc::ASM_PTR_ARITHMETIC_ATT_2_t plc::ASM_PTR_ARITHMETIC_ATT_2_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<erased<ASM_IDENTIFIER>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<parlex::details::document::text<literal_0x3A_t>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<erased<NON_FRACTIONAL>>::build(&*children[2], w);
	auto v_3 = parlex::details::document::element<erased<ASM_PTR_ARITHMETIC_ATT_REG>>::build(&*children[3], w);
	return ASM_PTR_ARITHMETIC_ATT_2_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3));
}

plc::ASM_PTR_ARITHMETIC_ATT_3_t plc::ASM_PTR_ARITHMETIC_ATT_3_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<erased<NON_FRACTIONAL>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<erased<ASM_PTR_ARITHMETIC_ATT_REG>>::build(&*children[1], w);
	return ASM_PTR_ARITHMETIC_ATT_3_t(std::move(v_0), std::move(v_1));
}


parlex::details::recognizer const & plc::ASM_PTR_ARITHMETIC_ATT::recognizer() {
	return plange_grammar::get().ASM_PTR_ARITHMETIC_ATT.get_recognizer();
}
