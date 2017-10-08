// This file was generated using Parlex's cpp_generator

#include "ASM_PTR_ARITHMETIC_INTEL.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "ASM_IDENTIFIER.hpp"
#include "NON_NEG_INTEGER.hpp"
#include "NON_NEG_NON_FRACTIONAL.hpp"
plc::ASM_PTR_ARITHMETIC_INTEL::field_1_t_1_t plc::ASM_PTR_ARITHMETIC_INTEL::field_1_t_1_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return field_1_t_1_t(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0])
);
}

plc::ASM_PTR_ARITHMETIC_INTEL::field_2_t_1_t plc::ASM_PTR_ARITHMETIC_INTEL::field_2_t_1_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return field_2_t_1_t(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0])
);
}

plc::ASM_PTR_ARITHMETIC_INTEL::field_4_t_1_t::field_2_t_1_t plc::ASM_PTR_ARITHMETIC_INTEL::field_4_t_1_t::field_2_t_1_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return field_2_t_1_t(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0])
);
}

plc::ASM_PTR_ARITHMETIC_INTEL::field_4_t_1_t plc::ASM_PTR_ARITHMETIC_INTEL::field_4_t_1_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return field_4_t_1_t(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0])
);
}

plc::ASM_PTR_ARITHMETIC_INTEL::field_5_t_1_t plc::ASM_PTR_ARITHMETIC_INTEL::field_5_t_1_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return field_5_t_1_t(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0])
);
}

plc::ASM_PTR_ARITHMETIC_INTEL plc::ASM_PTR_ARITHMETIC_INTEL::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return ASM_PTR_ARITHMETIC_INTEL(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_3)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_4)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_5)>::build(*children[0], n.children[0])
);
}

