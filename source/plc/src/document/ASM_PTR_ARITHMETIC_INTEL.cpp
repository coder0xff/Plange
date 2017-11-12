// This file was generated using Parlex's cpp_generator

#include "ASM_PTR_ARITHMETIC_INTEL.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "ASM_IDENTIFIER.hpp"
#include "NON_NEG_INTEGER.hpp"
#include "NON_NEG_NON_FRACTIONAL.hpp"

plc::ASM_PTR_ARITHMETIC_INTEL::field_1_t_1_t plc::ASM_PTR_ARITHMETIC_INTEL::field_1_t_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<std::variant<
		parlex::details::document::text<literal_BYTE_t>,
		parlex::details::document::text<literal_WORD_t>,
		parlex::details::document::text<literal_DWORD_t>,
		parlex::details::document::text<literal_QWORD_t>
	>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<parlex::details::document::text<literal_0x20PTR_t>>::build(&*children[1], w);
	return field_1_t_1_t(std::move(v_0), std::move(v_1));
}

plc::ASM_PTR_ARITHMETIC_INTEL::field_2_t_1_t plc::ASM_PTR_ARITHMETIC_INTEL::field_2_t_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<erased<ASM_IDENTIFIER>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<parlex::details::document::text<literal_0x3A_t>>::build(&*children[1], w);
	return field_2_t_1_t(std::move(v_0), std::move(v_1));
}

plc::ASM_PTR_ARITHMETIC_INTEL::field_4_t_1_t::field_2_t_1_t plc::ASM_PTR_ARITHMETIC_INTEL::field_4_t_1_t::field_2_t_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<parlex::details::document::text<literal_0x2A_t>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<erased<NON_NEG_NON_FRACTIONAL>>::build(&*children[1], w);
	return field_2_t_1_t(std::move(v_0), std::move(v_1));
}

plc::ASM_PTR_ARITHMETIC_INTEL::field_4_t_1_t plc::ASM_PTR_ARITHMETIC_INTEL::field_4_t_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<parlex::details::document::text<literal_0x2B_t>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<erased<ASM_IDENTIFIER>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<std::optional<field_2_t_1_t>>::build(&*children[2], w);
	return field_4_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2));
}

plc::ASM_PTR_ARITHMETIC_INTEL::field_5_t_1_t plc::ASM_PTR_ARITHMETIC_INTEL::field_5_t_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<std::variant<
		parlex::details::document::text<literal_0x2B_t>,
		parlex::details::document::text<literal_0x2D_t>
	>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<erased<NON_NEG_INTEGER>>::build(&*children[1], w);
	return field_5_t_1_t(std::move(v_0), std::move(v_1));
}

plc::ASM_PTR_ARITHMETIC_INTEL plc::ASM_PTR_ARITHMETIC_INTEL::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().ASM_PTR_ARITHMETIC_INTEL.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<std::optional<field_1_t_1_t>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<parlex::details::document::text<literal_0x5B_t>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<std::optional<field_2_t_1_t>>::build(&*children[2], w);
	auto v_3 = parlex::details::document::element<erased<ASM_IDENTIFIER>>::build(&*children[3], w);
	auto v_4 = parlex::details::document::element<std::optional<field_4_t_1_t>>::build(&*children[4], w);
	auto v_5 = parlex::details::document::element<std::optional<field_5_t_1_t>>::build(&*children[5], w);
	auto v_6 = parlex::details::document::element<parlex::details::document::text<literal_0x5D_t>>::build(&*children[6], w);
	return ASM_PTR_ARITHMETIC_INTEL(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4), std::move(v_5), std::move(v_6));
}


parlex::details::recognizer const & plc::ASM_PTR_ARITHMETIC_INTEL::recognizer() {
	return plange_grammar::get().ASM_PTR_ARITHMETIC_INTEL.get_recognizer();
}
