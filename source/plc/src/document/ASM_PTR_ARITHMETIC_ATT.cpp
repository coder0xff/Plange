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

ASM_PTR_ARITHMETIC_ATT ASM_PTR_ARITHMETIC_ATT::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	return ASM_PTR_ARITHMETIC_ATT(parlex::details::document::element<ASM_PTR_ARITHMETIC_ATT_base>::build(b, n));
}

} // namespace plc
plc::ASM_PTR_ARITHMETIC_ATT_1_t plc::ASM_PTR_ARITHMETIC_ATT_1_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return ASM_PTR_ARITHMETIC_ATT_1_t(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0])
);
}

plc::ASM_PTR_ARITHMETIC_ATT_2_t plc::ASM_PTR_ARITHMETIC_ATT_2_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return ASM_PTR_ARITHMETIC_ATT_2_t(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_3)>::build(*children[0], n.children[0])
);
}

plc::ASM_PTR_ARITHMETIC_ATT_3_t plc::ASM_PTR_ARITHMETIC_ATT_3_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return ASM_PTR_ARITHMETIC_ATT_3_t(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0])
);
}

