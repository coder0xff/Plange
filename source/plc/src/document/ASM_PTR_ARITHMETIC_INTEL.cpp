// This file was generated using Parlex's cpp_generator

#include "ASM_PTR_ARITHMETIC_INTEL.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "ASM_IDENTIFIER.hpp"
#include "NON_NEG_INTEGER.hpp"
#include "NON_NEG_NON_FRACTIONAL.hpp"

plc::ASM_PTR_ARITHMETIC_INTEL::field_1_t_1_t plc::ASM_PTR_ARITHMETIC_INTEL::field_1_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<std::variant<
		literal_BYTE_t,
		literal_WORD_t,
		literal_DWORD_t,
		literal_QWORD_t
	>>::build(document, *children[0], w);
	assert(w.pos != w.end); ++w.pos; // PTR 
	return field_1_t_1_t(std::move(v_0));
}

plc::ASM_PTR_ARITHMETIC_INTEL::field_2_t_1_t plc::ASM_PTR_ARITHMETIC_INTEL::field_2_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<erased<ASM_IDENTIFIER>>::build(document, *children[0], w);
	assert(w.pos != w.end); ++w.pos; //: 
	return field_2_t_1_t(std::move(v_0));
}

plc::ASM_PTR_ARITHMETIC_INTEL::field_4_t_1_t::field_2_t_1_t plc::ASM_PTR_ARITHMETIC_INTEL::field_4_t_1_t::field_2_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	assert(w.pos != w.end); ++w.pos; //* 
	auto v_0 = parlex::details::document::element<erased<NON_NEG_NON_FRACTIONAL>>::build(document, *children[1], w);
	return field_2_t_1_t(std::move(v_0));
}

plc::ASM_PTR_ARITHMETIC_INTEL::field_4_t_1_t plc::ASM_PTR_ARITHMETIC_INTEL::field_4_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	assert(w.pos != w.end); ++w.pos; //+ 
	auto v_0 = parlex::details::document::element<erased<ASM_IDENTIFIER>>::build(document, *children[1], w);
	auto v_1 = parlex::details::document::element<std::optional<field_2_t_1_t>>::build(document, *children[2], w);
	return field_4_t_1_t(std::move(v_0), std::move(v_1));
}

plc::ASM_PTR_ARITHMETIC_INTEL::field_5_t_1_t plc::ASM_PTR_ARITHMETIC_INTEL::field_5_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<std::variant<
		literal_0x2B_t,
		literal_0x2D_t
	>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<erased<NON_NEG_INTEGER>>::build(document, *children[1], w);
	return field_5_t_1_t(std::move(v_0), std::move(v_1));
}

plc::ASM_PTR_ARITHMETIC_INTEL plc::ASM_PTR_ARITHMETIC_INTEL::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().ASM_PTR_ARITHMETIC_INTEL.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<std::optional<field_1_t_1_t>>::build(document, *children[0], w);
	assert(w.pos != w.end); ++w.pos; //[ 
	auto v_1 = parlex::details::document::element<std::optional<field_2_t_1_t>>::build(document, *children[2], w);
	auto v_2 = parlex::details::document::element<erased<ASM_IDENTIFIER>>::build(document, *children[3], w);
	auto v_3 = parlex::details::document::element<std::optional<field_4_t_1_t>>::build(document, *children[4], w);
	auto v_4 = parlex::details::document::element<std::optional<field_5_t_1_t>>::build(document, *children[5], w);
	assert(w.pos != w.end); ++w.pos; //] 
	return ASM_PTR_ARITHMETIC_INTEL(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4));
}

