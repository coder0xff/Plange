// This file was generated using Parlex's cpp_generator

#include "grammar.hpp"

#include "parlex/detail/document.hpp"
namespace plc {

ADDITION ADDITION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2B_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return ADDITION(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::ADDITION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ADDITION));
	return result;
}

ADDITION_ASSIGNMENT ADDITION_ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x2B0x3C0x2D_t>,
		parlex::detail::document::text<literal_0x2B0xE20x860x90_t>,
		parlex::detail::document::text<literal_0xE20xA50x86_t>
	>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return ADDITION_ASSIGNMENT(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::ADDITION_ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ADDITION_ASSIGNMENT));
	return result;
}

ADD_SUB ADD_SUB::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xC20xB1_t>,
		parlex::detail::document::text<literal_0x2B0x2D_t>
	>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return ADD_SUB(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::ADD_SUB::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ADD_SUB));
	return result;
}

ADD_SUB_ASSIGNMENT ADD_SUB_ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xC20xB1_t>,
		parlex::detail::document::text<literal_0x2B0x2D_t>
	>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[5], w);
	return ADD_SUB_ASSIGNMENT(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5);
}

parlex::detail::acceptor const & plc::ADD_SUB_ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ADD_SUB_ASSIGNMENT));
	return result;
}

ALL ALL::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x880x80_t>,
		parlex::detail::document::text<literal_all_t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	return ALL(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::ALL::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ALL));
	return result;
}

ALLOCATION ALLOCATION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_alloc_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<PARENTHETICAL_INVOCATION>>::build(&*children[2], w);
	return ALLOCATION(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::ALLOCATION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ALLOCATION));
	return result;
}

AND AND::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x880xA7_t>,
		parlex::detail::document::text<literal_and_t>
	>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return AND(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::AND::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().AND));
	return result;
}

AND_ASSIGNMENT AND_ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x880xA7_t>,
		parlex::detail::document::text<literal_and_t>
	>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[5], w);
	return AND_ASSIGNMENT(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5);
}

parlex::detail::acceptor const & plc::AND_ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().AND_ASSIGNMENT));
	return result;
}

ARGUMENT_PACK ARGUMENT_PACK::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2E0x2E0x2E_t>>::build(&*children[2], w);
	return ARGUMENT_PACK(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::ARGUMENT_PACK::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ARGUMENT_PACK));
	return result;
}

ARRAY::field_2_t::field_1_t ARRAY::field_2_t::field_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2C_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[3], w);
	return field_1_t(v0, v1, v2, v3);
}

ARRAY::field_2_t ARRAY::field_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<field_1_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	return field_2_t(v0, v1, v2);
}

ARRAY ARRAY::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5B_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<field_2_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5D_t>>::build(&*children[3], w);
	return ARRAY(n.document_position, n.consumed_character_count, v0, v1, v2, v3);
}

parlex::detail::acceptor const & plc::ARRAY::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ARRAY));
	return result;
}

ARRAY_ARGUMENTS::tail_t::field_1_t ARRAY_ARGUMENTS::tail_t::field_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<ARRAY_INDEXER>>::build(&*children[1], w);
	return field_1_t(v0, v1);
}

ARRAY_ARGUMENTS::tail_t ARRAY_ARGUMENTS::tail_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2C_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<field_1_t>>::build(&*children[2], w);
	return tail_t(v0, v1, v2);
}

ARRAY_ARGUMENTS ARRAY_ARGUMENTS::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::optional<val<ARRAY_INDEXER>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<tail_t>>::build(&*children[1], w);
	return ARRAY_ARGUMENTS(n.document_position, n.consumed_character_count, v0, v1);
}

parlex::detail::acceptor const & plc::ARRAY_ARGUMENTS::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ARRAY_ARGUMENTS));
	return result;
}


ARRAY_INDEXER ARRAY_INDEXER::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return ARRAY_INDEXER(parlex::detail::document::element<ARRAY_INDEXER_base>::build(b, w));
}

parlex::detail::acceptor const & plc::ARRAY_INDEXER::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ARRAY_INDEXER));
	return result;
}

ARRAY_INVOCATION::arguments_t ARRAY_INVOCATION::arguments_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<ARRAY_ARGUMENTS>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	return arguments_t(v0, v1);
}

ARRAY_INVOCATION ARRAY_INVOCATION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5B_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<arguments_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5D_t>>::build(&*children[3], w);
	return ARRAY_INVOCATION(n.document_position, n.consumed_character_count, v0, v1, v2, v3);
}

parlex::detail::acceptor const & plc::ARRAY_INVOCATION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ARRAY_INVOCATION));
	return result;
}


ASM_EXPRESSION ASM_EXPRESSION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return ASM_EXPRESSION(parlex::detail::document::element<ASM_EXPRESSION_base>::build(b, w));
}

parlex::detail::acceptor const & plc::ASM_EXPRESSION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ASM_EXPRESSION));
	return result;
}

ASM_FUNCTION::field_1_t::field_2_t::field_1_t ASM_FUNCTION::field_1_t::field_2_t::field_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2C_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<val<PARAMETER>>::build(&*children[3], w);
	return field_1_t(v0, v1, v2, v3);
}

ASM_FUNCTION::field_1_t::field_2_t ASM_FUNCTION::field_1_t::field_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<PARAMETER>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<field_1_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	return field_2_t(v0, v1, v2);
}

ASM_FUNCTION::field_1_t ASM_FUNCTION::field_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x28_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<field_2_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<parlex::detail::document::text<literal_0x29_t>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	return field_1_t(v0, v1, v2, v3, v4);
}

ASM_FUNCTION ASM_FUNCTION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::optional<field_1_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::optional<val<FUNCTION_MODIFIER_0>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_asm_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7B_t>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<val<ASM_SCOPE>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7D_t>>::build(&*children[6], w);
	return ASM_FUNCTION(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5, v6);
}

parlex::detail::acceptor const & plc::ASM_FUNCTION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ASM_FUNCTION));
	return result;
}

ASM_IDENTIFIER ASM_IDENTIFIER::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::optional<parlex::detail::document::text<literal_0x25_t>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<IDENTIFIER>>::build(&*children[1], w);
	return ASM_IDENTIFIER(n.document_position, n.consumed_character_count, v0, v1);
}

parlex::detail::acceptor const & plc::ASM_IDENTIFIER::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ASM_IDENTIFIER));
	return result;
}

ASM_OP ASM_OP::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::lowercase_letter_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<parlex::detail::document::text<parlex::detail::lowercase_letter_t>>>::build(&*children[1], w);
	return ASM_OP(n.document_position, n.consumed_character_count, v0, v1);
}

parlex::detail::acceptor const & plc::ASM_OP::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ASM_OP));
	return result;
}


ASM_PTR_ARITHMETIC_ATT ASM_PTR_ARITHMETIC_ATT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return ASM_PTR_ARITHMETIC_ATT(parlex::detail::document::element<ASM_PTR_ARITHMETIC_ATT_base>::build(b, w));
}

ASM_PTR_ARITHMETIC_ATT1_t ASM_PTR_ARITHMETIC_ATT1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<ASM_IDENTIFIER>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3A_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<NON_FRACTIONAL>>::build(&*children[2], w);
	return ASM_PTR_ARITHMETIC_ATT1_t(v0, v1, v2);
}

ASM_PTR_ARITHMETIC_ATT2_t ASM_PTR_ARITHMETIC_ATT2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<ASM_IDENTIFIER>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3A_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<NON_FRACTIONAL>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<val<ASM_PTR_ARITHMETIC_ATT_REG>>::build(&*children[3], w);
	return ASM_PTR_ARITHMETIC_ATT2_t(v0, v1, v2, v3);
}

ASM_PTR_ARITHMETIC_ATT3_t ASM_PTR_ARITHMETIC_ATT3_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<NON_FRACTIONAL>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<ASM_PTR_ARITHMETIC_ATT_REG>>::build(&*children[1], w);
	return ASM_PTR_ARITHMETIC_ATT3_t(v0, v1);
}

parlex::detail::acceptor const & plc::ASM_PTR_ARITHMETIC_ATT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ASM_PTR_ARITHMETIC_ATT));
	return result;
}

ASM_PTR_ARITHMETIC_ATT_REG::field_2_t::field_1_t ASM_PTR_ARITHMETIC_ATT_REG::field_2_t::field_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2C_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<NON_NEG_NON_FRACTIONAL>>::build(&*children[1], w);
	return field_1_t(v0, v1);
}

ASM_PTR_ARITHMETIC_ATT_REG::field_2_t ASM_PTR_ARITHMETIC_ATT_REG::field_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2C_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<ASM_IDENTIFIER>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<field_1_t>>::build(&*children[2], w);
	return field_2_t(v0, v1, v2);
}

ASM_PTR_ARITHMETIC_ATT_REG ASM_PTR_ARITHMETIC_ATT_REG::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x28_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::optional<val<ASM_IDENTIFIER>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<field_2_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<parlex::detail::document::text<literal_0x29_t>>::build(&*children[3], w);
	return ASM_PTR_ARITHMETIC_ATT_REG(n.document_position, n.consumed_character_count, v0, v1, v2, v3);
}

parlex::detail::acceptor const & plc::ASM_PTR_ARITHMETIC_ATT_REG::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ASM_PTR_ARITHMETIC_ATT_REG));
	return result;
}

ASM_PTR_ARITHMETIC_INTEL::field_1_t ASM_PTR_ARITHMETIC_INTEL::field_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_BYTE_t>,
		parlex::detail::document::text<literal_WORD_t>,
		parlex::detail::document::text<literal_DWORD_t>,
		parlex::detail::document::text<literal_QWORD_t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x20PTR_t>>::build(&*children[1], w);
	return field_1_t(v0, v1);
}

ASM_PTR_ARITHMETIC_INTEL::field_2_t ASM_PTR_ARITHMETIC_INTEL::field_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<ASM_IDENTIFIER>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3A_t>>::build(&*children[1], w);
	return field_2_t(v0, v1);
}

ASM_PTR_ARITHMETIC_INTEL::field_4_t::field_2_t ASM_PTR_ARITHMETIC_INTEL::field_4_t::field_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2A_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<NON_NEG_NON_FRACTIONAL>>::build(&*children[1], w);
	return field_2_t(v0, v1);
}

ASM_PTR_ARITHMETIC_INTEL::field_4_t ASM_PTR_ARITHMETIC_INTEL::field_4_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2B_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<ASM_IDENTIFIER>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<field_2_t>>::build(&*children[2], w);
	return field_4_t(v0, v1, v2);
}

ASM_PTR_ARITHMETIC_INTEL::field_5_t ASM_PTR_ARITHMETIC_INTEL::field_5_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x2B_t>,
		parlex::detail::document::text<literal_0x2D_t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<NON_NEG_INTEGER>>::build(&*children[1], w);
	return field_5_t(v0, v1);
}

ASM_PTR_ARITHMETIC_INTEL ASM_PTR_ARITHMETIC_INTEL::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::optional<field_1_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5B_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<field_2_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<val<ASM_IDENTIFIER>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::optional<field_4_t>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<std::optional<field_5_t>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5D_t>>::build(&*children[6], w);
	return ASM_PTR_ARITHMETIC_INTEL(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5, v6);
}

parlex::detail::acceptor const & plc::ASM_PTR_ARITHMETIC_INTEL::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ASM_PTR_ARITHMETIC_INTEL));
	return result;
}


ASM_SCOPE ASM_SCOPE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return ASM_SCOPE(parlex::detail::document::element<ASM_SCOPE_base>::build(b, w));
}

parlex::detail::acceptor const & plc::ASM_SCOPE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ASM_SCOPE));
	return result;
}

ASM_STATEMENT::field_2_t::field_3_t::field_2_t ASM_STATEMENT::field_2_t::field_3_t::field_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<ASM_EXPRESSION>>::build(&*children[1], w);
	return field_2_t(v0, v1);
}

ASM_STATEMENT::field_2_t::field_3_t ASM_STATEMENT::field_2_t::field_3_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2C_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<field_2_t>>::build(&*children[2], w);
	return field_3_t(v0, v1, v2);
}

ASM_STATEMENT::field_2_t ASM_STATEMENT::field_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<ASM_EXPRESSION>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<field_3_t>>::build(&*children[2], w);
	return field_2_t(v0, v1, v2);
}

ASM_STATEMENT ASM_STATEMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<ASM_OP>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::optional<field_2_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<parlex::detail::document::text<literal_0x0A_t>>::build(&*children[3], w);
	return ASM_STATEMENT(n.document_position, n.consumed_character_count, v0, v1, v2, v3);
}

parlex::detail::acceptor const & plc::ASM_STATEMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ASM_STATEMENT));
	return result;
}

ASSIGNMENT ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<IDENTIFIER_SPECIFICATION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<ASSIGNMENT_NODE>>::build(&*children[2], w);
	return ASSIGNMENT(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ASSIGNMENT));
	return result;
}

ASSIGNMENT_NODE::value_t ASSIGNMENT_NODE::value_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<IDENTIFIER_SPECIFICATION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<ASSIGNMENT_NODE>>::build(&*children[2], w);
	return value_t(v0, v1, v2);
}

ASSIGNMENT_NODE ASSIGNMENT_NODE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x860x90_t>,
		parlex::detail::document::text<literal_0x3C0x2D_t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		val<EXPRESSION>,
		value_t
	>>::build(&*children[2], w);
	return ASSIGNMENT_NODE(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::ASSIGNMENT_NODE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ASSIGNMENT_NODE));
	return result;
}

ATTRIBUTE ATTRIBUTE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x40_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<parlex::detail::document::text<literal_0x40_t>>::build(&*children[4], w);
	return ATTRIBUTE(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::ATTRIBUTE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ATTRIBUTE));
	return result;
}

BIJECTION BIJECTION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x860x94_t>,
		parlex::detail::document::text<literal_0x3C0x2D0x3E_t>
	>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return BIJECTION(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::BIJECTION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().BIJECTION));
	return result;
}


BINARY_ARITHMETIC_OP BINARY_ARITHMETIC_OP::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return BINARY_ARITHMETIC_OP(parlex::detail::document::element<BINARY_ARITHMETIC_OP_base>::build(b, w));
}

parlex::detail::acceptor const & plc::BINARY_ARITHMETIC_OP::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().BINARY_ARITHMETIC_OP));
	return result;
}


BINARY_COLLECTION_OP BINARY_COLLECTION_OP::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return BINARY_COLLECTION_OP(parlex::detail::document::element<BINARY_COLLECTION_OP_base>::build(b, w));
}

parlex::detail::acceptor const & plc::BINARY_COLLECTION_OP::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().BINARY_COLLECTION_OP));
	return result;
}


BINARY_LOGICAL_OP BINARY_LOGICAL_OP::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return BINARY_LOGICAL_OP(parlex::detail::document::element<BINARY_LOGICAL_OP_base>::build(b, w));
}

parlex::detail::acceptor const & plc::BINARY_LOGICAL_OP::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().BINARY_LOGICAL_OP));
	return result;
}


BINARY_OP BINARY_OP::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return BINARY_OP(parlex::detail::document::element<BINARY_OP_base>::build(b, w));
}

parlex::detail::acceptor const & plc::BINARY_OP::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().BINARY_OP));
	return result;
}


BITWISE_OP BITWISE_OP::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return BITWISE_OP(parlex::detail::document::element<BITWISE_OP_base>::build(b, w));
}

parlex::detail::acceptor const & plc::BITWISE_OP::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().BITWISE_OP));
	return result;
}

BIT_AND BIT_AND::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x260x26_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return BIT_AND(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::BIT_AND::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().BIT_AND));
	return result;
}

BIT_AND_ASSIGNMENT BIT_AND_ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x260x26_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[5], w);
	return BIT_AND_ASSIGNMENT(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5);
}

parlex::detail::acceptor const & plc::BIT_AND_ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().BIT_AND_ASSIGNMENT));
	return result;
}

BIT_NOT BIT_NOT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7E0x7E_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	return BIT_NOT(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::BIT_NOT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().BIT_NOT));
	return result;
}

BIT_NOT_ASSIGNMENT BIT_NOT_ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7E0x7E_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	>>::build(&*children[3], w);
	return BIT_NOT_ASSIGNMENT(n.document_position, n.consumed_character_count, v0, v1, v2, v3);
}

parlex::detail::acceptor const & plc::BIT_NOT_ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().BIT_NOT_ASSIGNMENT));
	return result;
}

BIT_OR BIT_OR::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7C0x7C_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return BIT_OR(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::BIT_OR::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().BIT_OR));
	return result;
}

BIT_OR_ASSIGNMENT BIT_OR_ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7C0x7C_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[5], w);
	return BIT_OR_ASSIGNMENT(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5);
}

parlex::detail::acceptor const & plc::BIT_OR_ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().BIT_OR_ASSIGNMENT));
	return result;
}

BIT_XOR BIT_XOR::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5E0x5E_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return BIT_XOR(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::BIT_XOR::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().BIT_XOR));
	return result;
}

BIT_XOR_ASSIGNMENT BIT_XOR_ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5E0x5E_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[5], w);
	return BIT_XOR_ASSIGNMENT(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5);
}

parlex::detail::acceptor const & plc::BIT_XOR_ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().BIT_XOR_ASSIGNMENT));
	return result;
}

BLOCK BLOCK::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7B_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<STATEMENT_SCOPE>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7D_t>>::build(&*children[2], w);
	return BLOCK(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::BLOCK::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().BLOCK));
	return result;
}


BOOL BOOL::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return BOOL(parlex::detail::document::element<BOOL_base>::build(b, w));
}

parlex::detail::acceptor const & plc::BOOL::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().BOOL));
	return result;
}

BREAK::field_1_t1 BREAK::field_1_t1::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5B_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5D_t>>::build(&*children[5], w);
	return field_1_t1(v0, v1, v2, v3, v4, v5);
}

BREAK::field_1_t2 BREAK::field_1_t2::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<IC>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<IDENTIFIER>>::build(&*children[2], w);
	return field_1_t2(v0, v1, v2);
}

BREAK BREAK::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_break_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::optional<std::variant<
		field_1_t1,
		field_1_t2
	>>>::build(&*children[1], w);
	return BREAK(n.document_position, n.consumed_character_count, v0, v1);
}

parlex::detail::acceptor const & plc::BREAK::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().BREAK));
	return result;
}

CARDINALITY CARDINALITY::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x23_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	return CARDINALITY(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::CARDINALITY::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().CARDINALITY));
	return result;
}

CAST CAST::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<PARENTHETICAL>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	return CAST(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::CAST::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().CAST));
	return result;
}

CASTS CASTS::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_casts_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return CASTS(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::CASTS::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().CASTS));
	return result;
}


CEILING CEILING::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return CEILING(parlex::detail::document::element<CEILING_base>::build(b, w));
}

CEILING1_t CEILING1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0xE20x8C0x88_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<parlex::detail::document::text<literal_0xE20x8C0x89_t>>::build(&*children[4], w);
	return CEILING1_t(v0, v1, v2, v3, v4);
}

CEILING2_t CEILING2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7C0x27_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<parlex::detail::document::text<literal_0x270x7C_t>>::build(&*children[4], w);
	return CEILING2_t(v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::CEILING::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().CEILING));
	return result;
}

COMMENT COMMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2F0x2A_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<parlex::detail::document::text<parlex::detail::all_t>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2A0x2F_t>>::build(&*children[2], w);
	return COMMENT(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::COMMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().COMMENT));
	return result;
}

COMPLEMENT COMPLEMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0xE10xB60x9C_t>>::build(&*children[2], w);
	return COMPLEMENT(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::COMPLEMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().COMPLEMENT));
	return result;
}

COMPOSITION COMPOSITION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x880x98_t>,
		parlex::detail::document::text<literal__o__t>
	>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return COMPOSITION(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::COMPOSITION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().COMPOSITION));
	return result;
}

COMPOSITION_ASSIGNMENT COMPOSITION_ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x880x98_t>,
		parlex::detail::document::text<literal__o__t>
	>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[5], w);
	return COMPOSITION_ASSIGNMENT(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5);
}

parlex::detail::acceptor const & plc::COMPOSITION_ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().COMPOSITION_ASSIGNMENT));
	return result;
}

COMPOUND COMPOUND::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7C_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return COMPOUND(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::COMPOUND::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().COMPOUND));
	return result;
}

COMPOUND_ASSIGNMENT COMPOUND_ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7C_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[5], w);
	return COMPOUND_ASSIGNMENT(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5);
}

parlex::detail::acceptor const & plc::COMPOUND_ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().COMPOUND_ASSIGNMENT));
	return result;
}

CONDITIONAL CONDITIONAL::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3F_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3A_t>>::build(&*children[6], w);
	auto v7 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[7], w);
	auto v8 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[8], w);
	return CONDITIONAL(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5, v6, v7, v8);
}

parlex::detail::acceptor const & plc::CONDITIONAL::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().CONDITIONAL));
	return result;
}


CONSTRUCTIVE_OP CONSTRUCTIVE_OP::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return CONSTRUCTIVE_OP(parlex::detail::document::element<CONSTRUCTIVE_OP_base>::build(b, w));
}

parlex::detail::acceptor const & plc::CONSTRUCTIVE_OP::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().CONSTRUCTIVE_OP));
	return result;
}

CONTINUE::field_1_t1 CONTINUE::field_1_t1::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5B_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5D_t>>::build(&*children[5], w);
	return field_1_t1(v0, v1, v2, v3, v4, v5);
}

CONTINUE::field_1_t2 CONTINUE::field_1_t2::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<IC>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<IDENTIFIER>>::build(&*children[2], w);
	return field_1_t2(v0, v1, v2);
}

CONTINUE CONTINUE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_continue_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::optional<std::variant<
		field_1_t1,
		field_1_t2
	>>>::build(&*children[1], w);
	return CONTINUE(n.document_position, n.consumed_character_count, v0, v1);
}

parlex::detail::acceptor const & plc::CONTINUE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().CONTINUE));
	return result;
}

CROSS_PRODUCT CROSS_PRODUCT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xC30x97_t>,
		parlex::detail::document::text<literal__x__t>
	>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return CROSS_PRODUCT(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::CROSS_PRODUCT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().CROSS_PRODUCT));
	return result;
}

CROSS_PRODUCT_ASSIGNMENT CROSS_PRODUCT_ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xC30x97_t>,
		parlex::detail::document::text<literal__x__t>
	>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[5], w);
	return CROSS_PRODUCT_ASSIGNMENT(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5);
}

parlex::detail::acceptor const & plc::CROSS_PRODUCT_ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().CROSS_PRODUCT_ASSIGNMENT));
	return result;
}


DATE DATE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return DATE(parlex::detail::document::element<DATE_base>::build(b, w));
}

parlex::detail::acceptor const & plc::DATE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().DATE));
	return result;
}

DATE_TIME DATE_TIME::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<DATE>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_T_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<TIME>>::build(&*children[2], w);
	return DATE_TIME(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::DATE_TIME::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().DATE_TIME));
	return result;
}

DATE_YEAR_DAY DATE_YEAR_DAY::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2D_t>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[6], w);
	auto v7 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[7], w);
	return DATE_YEAR_DAY(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5, v6, v7);
}

parlex::detail::acceptor const & plc::DATE_YEAR_DAY::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().DATE_YEAR_DAY));
	return result;
}

DATE_YEAR_MONTH_DAY DATE_YEAR_MONTH_DAY::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2D_t>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[6], w);
	auto v7 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2D_t>>::build(&*children[7], w);
	auto v8 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[8], w);
	auto v9 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[9], w);
	return DATE_YEAR_MONTH_DAY(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9);
}

parlex::detail::acceptor const & plc::DATE_YEAR_MONTH_DAY::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().DATE_YEAR_MONTH_DAY));
	return result;
}

DEFINITION DEFINITION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<IDENTIFIER_SPECIFICATION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3A0x3D_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return DEFINITION(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::DEFINITION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().DEFINITION));
	return result;
}

DELTA::field_2_t DELTA::field_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5E_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<WHOLE_NUMBER>>::build(&*children[1], w);
	return field_2_t(v0, v1);
}

DELTA DELTA::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xCE0x94_t>,
		parlex::detail::document::text<literal__delta__t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::optional<field_2_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	return DELTA(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::DELTA::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().DELTA));
	return result;
}


DIMENSION DIMENSION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return DIMENSION(parlex::detail::document::element<DIMENSION_base>::build(b, w));
}

parlex::detail::acceptor const & plc::DIMENSION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().DIMENSION));
	return result;
}


DIMENSIONAL_ANALYSIS_OP DIMENSIONAL_ANALYSIS_OP::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return DIMENSIONAL_ANALYSIS_OP(parlex::detail::document::element<DIMENSIONAL_ANALYSIS_OP_base>::build(b, w));
}

parlex::detail::acceptor const & plc::DIMENSIONAL_ANALYSIS_OP::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().DIMENSIONAL_ANALYSIS_OP));
	return result;
}

DIMENSIONAL_NUMBER DIMENSIONAL_NUMBER::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<NON_NEG_NUMBER>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<DIMENSION>>::build(&*children[1], w);
	return DIMENSIONAL_NUMBER(n.document_position, n.consumed_character_count, v0, v1);
}

parlex::detail::acceptor const & plc::DIMENSIONAL_NUMBER::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().DIMENSIONAL_NUMBER));
	return result;
}

DIVISION DIVISION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xC30xB7_t>,
		parlex::detail::document::text<literal_0x2F_t>
	>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return DIVISION(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::DIVISION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().DIVISION));
	return result;
}

DIVISION_ASSIGNMENT DIVISION_ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xC30xB7_t>,
		parlex::detail::document::text<literal_0x2F_t>
	>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[5], w);
	return DIVISION_ASSIGNMENT(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5);
}

parlex::detail::acceptor const & plc::DIVISION_ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().DIVISION_ASSIGNMENT));
	return result;
}

DO::field_2_t DO::field_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_while_t>,
		parlex::detail::document::text<literal_until_t>
	>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<val<PARENTHETICAL>>::build(&*children[3], w);
	return field_2_t(v0, v1, v2, v3);
}

DO DO::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_do_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::optional<field_2_t>>::build(&*children[3], w);
	return DO(n.document_position, n.consumed_character_count, v0, v1, v2, v3);
}

parlex::detail::acceptor const & plc::DO::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().DO));
	return result;
}

DOT_PRODUCT DOT_PRODUCT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x8B0x85_t>,
		parlex::detail::document::text<literal__dot__t>
	>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return DOT_PRODUCT(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::DOT_PRODUCT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().DOT_PRODUCT));
	return result;
}

DOWNCASTS DOWNCASTS::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_downcasts_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return DOWNCASTS(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::DOWNCASTS::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().DOWNCASTS));
	return result;
}

EMBEDDED_COMMENT EMBEDDED_COMMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2F0x2A0x2A0x2A_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<EMBEDDED_COMMENT_INTERIOR>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2A0x2A0x2A0x2F_t>>::build(&*children[2], w);
	return EMBEDDED_COMMENT(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::EMBEDDED_COMMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().EMBEDDED_COMMENT));
	return result;
}


EMBEDDED_COMMENT_INTERIOR EMBEDDED_COMMENT_INTERIOR::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return EMBEDDED_COMMENT_INTERIOR(parlex::detail::document::element<EMBEDDED_COMMENT_INTERIOR_base>::build(b, w));
}

EMBEDDED_COMMENT_INTERIOR_t EMBEDDED_COMMENT_INTERIOR_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2A_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<EMBEDDED_COMMENT_INTERIOR>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2A_t>>::build(&*children[2], w);
	return EMBEDDED_COMMENT_INTERIOR_t(v0, v1, v2);
}

parlex::detail::acceptor const & plc::EMBEDDED_COMMENT_INTERIOR::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().EMBEDDED_COMMENT_INTERIOR));
	return result;
}

EMBEDDED_NEWLINE_STRING EMBEDDED_NEWLINE_STRING::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x220x220x22_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<EMBEDDED_NEWLINE_STRING_INTERIOR>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x220x220x22_t>>::build(&*children[2], w);
	return EMBEDDED_NEWLINE_STRING(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::EMBEDDED_NEWLINE_STRING::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().EMBEDDED_NEWLINE_STRING));
	return result;
}


EMBEDDED_NEWLINE_STRING_INTERIOR EMBEDDED_NEWLINE_STRING_INTERIOR::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return EMBEDDED_NEWLINE_STRING_INTERIOR(parlex::detail::document::element<EMBEDDED_NEWLINE_STRING_INTERIOR_base>::build(b, w));
}

EMBEDDED_NEWLINE_STRING_INTERIOR1_t EMBEDDED_NEWLINE_STRING_INTERIOR1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x0A_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<PAYLOAD>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x0A_t>>::build(&*children[2], w);
	return EMBEDDED_NEWLINE_STRING_INTERIOR1_t(v0, v1, v2);
}

EMBEDDED_NEWLINE_STRING_INTERIOR2_t EMBEDDED_NEWLINE_STRING_INTERIOR2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x22_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<EMBEDDED_NEWLINE_STRING_INTERIOR>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x22_t>>::build(&*children[2], w);
	return EMBEDDED_NEWLINE_STRING_INTERIOR2_t(v0, v1, v2);
}

parlex::detail::acceptor const & plc::EMBEDDED_NEWLINE_STRING_INTERIOR::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().EMBEDDED_NEWLINE_STRING_INTERIOR));
	return result;
}

EMBEDDED_STRING EMBEDDED_STRING::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x220x220x22_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<EMBEDDED_STRING_INTERIOR>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x220x220x22_t>>::build(&*children[2], w);
	return EMBEDDED_STRING(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::EMBEDDED_STRING::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().EMBEDDED_STRING));
	return result;
}


EMBEDDED_STRING_INTERIOR EMBEDDED_STRING_INTERIOR::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return EMBEDDED_STRING_INTERIOR(parlex::detail::document::element<EMBEDDED_STRING_INTERIOR_base>::build(b, w));
}

EMBEDDED_STRING_INTERIOR_t EMBEDDED_STRING_INTERIOR_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x22_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<EMBEDDED_STRING_INTERIOR>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x22_t>>::build(&*children[2], w);
	return EMBEDDED_STRING_INTERIOR_t(v0, v1, v2);
}

parlex::detail::acceptor const & plc::EMBEDDED_STRING_INTERIOR::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().EMBEDDED_STRING_INTERIOR));
	return result;
}

END_OF_LINE_COMMENT END_OF_LINE_COMMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2F0x2F_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<parlex::detail::document::text<parlex::detail::not_newline_t>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x0A_t>>::build(&*children[2], w);
	return END_OF_LINE_COMMENT(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::END_OF_LINE_COMMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().END_OF_LINE_COMMENT));
	return result;
}

ENUM::field_2_t ENUM::field_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_inheriting_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<INHERITANCE_LIST>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	return field_2_t(v0, v1, v2, v3);
}

ENUM::field_3_t ENUM::field_3_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_implementing_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<INHERITANCE_LIST>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	return field_3_t(v0, v1, v2, v3);
}

ENUM::field_4_t::field_1_t ENUM::field_4_t::field_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3B_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<val<ENUM_ELEMENT>>::build(&*children[3], w);
	return field_1_t(v0, v1, v2, v3);
}

ENUM::field_4_t ENUM::field_4_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<ENUM_ELEMENT>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<field_1_t>>::build(&*children[1], w);
	return field_4_t(v0, v1);
}

ENUM ENUM::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_enum_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<field_2_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::optional<field_3_t>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7B_t>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<std::optional<field_4_t>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7D_t>>::build(&*children[6], w);
	return ENUM(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5, v6);
}

parlex::detail::acceptor const & plc::ENUM::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ENUM));
	return result;
}

ENUM_ELEMENT::field_1_t ENUM_ELEMENT::field_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3A0x3D_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[3], w);
	return field_1_t(v0, v1, v2, v3);
}

ENUM_ELEMENT ENUM_ELEMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::optional<val<XML_DOC_STRING>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<IDENTIFIER>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<field_1_t>>::build(&*children[2], w);
	return ENUM_ELEMENT(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::ENUM_ELEMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ENUM_ELEMENT));
	return result;
}

EQUALITY EQUALITY::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EQUALITY_NODE>>::build(&*children[2], w);
	return EQUALITY(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::EQUALITY::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().EQUALITY));
	return result;
}

EQUALITY_NODE::field_2_t EQUALITY_NODE::field_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<EQUALITY_NODE>>::build(&*children[1], w);
	return field_2_t(v0, v1);
}

EQUALITY_NODE EQUALITY_NODE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3D_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::optional<field_2_t>>::build(&*children[3], w);
	return EQUALITY_NODE(n.document_position, n.consumed_character_count, v0, v1, v2, v3);
}

parlex::detail::acceptor const & plc::EQUALITY_NODE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().EQUALITY_NODE));
	return result;
}

EXACTLY EXACTLY::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_exactly_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return EXACTLY(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::EXACTLY::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().EXACTLY));
	return result;
}

EXISTS EXISTS::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x880x83_t>,
		parlex::detail::document::text<literal_exists_t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	return EXISTS(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::EXISTS::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().EXISTS));
	return result;
}

EXISTS_ONE EXISTS_ONE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x880x830x21_t>,
		parlex::detail::document::text<literal_exists0x21_t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	return EXISTS_ONE(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::EXISTS_ONE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().EXISTS_ONE));
	return result;
}

EXPONENTIATION EXPONENTIATION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5E_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return EXPONENTIATION(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::EXPONENTIATION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().EXPONENTIATION));
	return result;
}

EXPONENTIATION_ASSIGNMENT EXPONENTIATION_ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5E_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[5], w);
	return EXPONENTIATION_ASSIGNMENT(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5);
}

parlex::detail::acceptor const & plc::EXPONENTIATION_ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().EXPONENTIATION_ASSIGNMENT));
	return result;
}


EXPRESSION EXPRESSION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return EXPRESSION(parlex::detail::document::element<EXPRESSION_base>::build(b, w));
}

parlex::detail::acceptor const & plc::EXPRESSION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().EXPRESSION));
	return result;
}

FACTORIAL FACTORIAL::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x21_t>>::build(&*children[2], w);
	return FACTORIAL(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::FACTORIAL::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().FACTORIAL));
	return result;
}

FACTORIAL_ASSIGNMENT FACTORIAL_ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x21_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	>>::build(&*children[3], w);
	return FACTORIAL_ASSIGNMENT(n.document_position, n.consumed_character_count, v0, v1, v2, v3);
}

parlex::detail::acceptor const & plc::FACTORIAL_ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().FACTORIAL_ASSIGNMENT));
	return result;
}


FLOOR FLOOR::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return FLOOR(parlex::detail::document::element<FLOOR_base>::build(b, w));
}

FLOOR1_t FLOOR1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0xE20x8C0x8A_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<parlex::detail::document::text<literal_0xE20x8C0x8B_t>>::build(&*children[4], w);
	return FLOOR1_t(v0, v1, v2, v3, v4);
}

FLOOR2_t FLOOR2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7C__t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<parlex::detail::document::text<literal__0x7C_t>>::build(&*children[4], w);
	return FLOOR2_t(v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::FLOOR::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().FLOOR));
	return result;
}

FOR::initializer_t FOR::initializer_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<STATEMENT_SCOPE>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	return initializer_t(v0, v1);
}

FOR::step_t FOR::step_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<FOR_STEP_LIST>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	return step_t(v0, v1);
}

FOR FOR::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_for_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x28_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::optional<initializer_t>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[6], w);
	auto v7 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3B_t>>::build(&*children[7], w);
	auto v8 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[8], w);
	auto v9 = parlex::detail::document::element<std::optional<step_t>>::build(&*children[9], w);
	auto v10 = parlex::detail::document::element<parlex::detail::document::text<literal_0x29_t>>::build(&*children[10], w);
	auto v11 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[11], w);
	auto v12 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[12], w);
	return FOR(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12);
}

parlex::detail::acceptor const & plc::FOR::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().FOR));
	return result;
}

FOR_COLLECTION::declaration::field_1_t FOR_COLLECTION::declaration::field_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		val<TYPE_DEREFERENCE>,
		val<IMPLICIT_TYPE_DEREFERENCE>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	return field_1_t(v0, v1);
}

FOR_COLLECTION::declaration FOR_COLLECTION::declaration::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::optional<field_1_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<IDENTIFIER>>::build(&*children[1], w);
	return declaration(v0, v1);
}

FOR_COLLECTION FOR_COLLECTION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_for_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x28_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::variant<
		declaration,
		val<EXPRESSION>
	>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_in_t>,
		parlex::detail::document::text<literal_0xE20x880x88_t>
	>>::build(&*children[6], w);
	auto v7 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[7], w);
	auto v8 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[8], w);
	auto v9 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[9], w);
	auto v10 = parlex::detail::document::element<parlex::detail::document::text<literal_0x29_t>>::build(&*children[10], w);
	auto v11 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[11], w);
	auto v12 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[12], w);
	return FOR_COLLECTION(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12);
}

parlex::detail::acceptor const & plc::FOR_COLLECTION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().FOR_COLLECTION));
	return result;
}

FOR_STEP FOR_STEP::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<IDENTIFIER>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<FOR_STEP_NODE>>::build(&*children[2], w);
	return FOR_STEP(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::FOR_STEP::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().FOR_STEP));
	return result;
}

FOR_STEP_LIST::tail_t FOR_STEP_LIST::tail_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2C_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<val<FOR_STEP>>::build(&*children[3], w);
	return tail_t(v0, v1, v2, v3);
}

FOR_STEP_LIST FOR_STEP_LIST::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<FOR_STEP>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<tail_t>>::build(&*children[1], w);
	return FOR_STEP_LIST(n.document_position, n.consumed_character_count, v0, v1);
}

parlex::detail::acceptor const & plc::FOR_STEP_LIST::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().FOR_STEP_LIST));
	return result;
}

FOR_STEP_NODE::value_t FOR_STEP_NODE::value_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<IDENTIFIER>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<FOR_STEP_NODE>>::build(&*children[2], w);
	return value_t(v0, v1, v2);
}

FOR_STEP_NODE FOR_STEP_NODE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x860x90_t>,
		parlex::detail::document::text<literal_0x3C0x2D_t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		val<EXPRESSION>,
		value_t
	>>::build(&*children[2], w);
	return FOR_STEP_NODE(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::FOR_STEP_NODE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().FOR_STEP_NODE));
	return result;
}

FREE FREE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_free_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	return FREE(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::FREE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().FREE));
	return result;
}

FUNCTION::field_1_t::field_2_t::field_1_t FUNCTION::field_1_t::field_2_t::field_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2C_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<val<PARAMETER>>::build(&*children[3], w);
	return field_1_t(v0, v1, v2, v3);
}

FUNCTION::field_1_t::field_2_t FUNCTION::field_1_t::field_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<PARAMETER>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<field_1_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	return field_2_t(v0, v1, v2);
}

FUNCTION::field_1_t FUNCTION::field_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x28_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<field_2_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<parlex::detail::document::text<literal_0x29_t>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	return field_1_t(v0, v1, v2, v3, v4);
}

FUNCTION::field_2_t FUNCTION::field_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<FUNCTION_MODIFIER_0>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	return field_2_t(v0, v1);
}

FUNCTION FUNCTION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::optional<field_1_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::optional<field_2_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<BLOCK>>::build(&*children[2], w);
	return FUNCTION(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::FUNCTION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().FUNCTION));
	return result;
}


FUNCTION_MODIFIER_0 FUNCTION_MODIFIER_0::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return FUNCTION_MODIFIER_0(parlex::detail::document::element<FUNCTION_MODIFIER_0_base>::build(b, w));
}

parlex::detail::acceptor const & plc::FUNCTION_MODIFIER_0::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().FUNCTION_MODIFIER_0));
	return result;
}


FUNCTION_MODIFIER_1 FUNCTION_MODIFIER_1::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return FUNCTION_MODIFIER_1(parlex::detail::document::element<FUNCTION_MODIFIER_1_base>::build(b, w));
}

parlex::detail::acceptor const & plc::FUNCTION_MODIFIER_1::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().FUNCTION_MODIFIER_1));
	return result;
}


FUNCTION_MODIFIER_2 FUNCTION_MODIFIER_2::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return FUNCTION_MODIFIER_2(parlex::detail::document::element<FUNCTION_MODIFIER_2_base>::build(b, w));
}

parlex::detail::acceptor const & plc::FUNCTION_MODIFIER_2::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().FUNCTION_MODIFIER_2));
	return result;
}


FUNCTION_MODIFIER_3 FUNCTION_MODIFIER_3::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return FUNCTION_MODIFIER_3(parlex::detail::document::element<FUNCTION_MODIFIER_3_base>::build(b, w));
}

parlex::detail::acceptor const & plc::FUNCTION_MODIFIER_3::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().FUNCTION_MODIFIER_3));
	return result;
}


FUNCTION_MODIFIER_4 FUNCTION_MODIFIER_4::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return FUNCTION_MODIFIER_4(parlex::detail::document::element<FUNCTION_MODIFIER_4_base>::build(b, w));
}

parlex::detail::acceptor const & plc::FUNCTION_MODIFIER_4::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().FUNCTION_MODIFIER_4));
	return result;
}

FUNCTION_MODIFIER_ATOMIC::field_1_t FUNCTION_MODIFIER_ATOMIC::field_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<IC>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<FUNCTION_MODIFIER_3>>::build(&*children[2], w);
	return field_1_t(v0, v1, v2);
}

FUNCTION_MODIFIER_ATOMIC FUNCTION_MODIFIER_ATOMIC::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_atomic_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::optional<field_1_t>>::build(&*children[1], w);
	return FUNCTION_MODIFIER_ATOMIC(n.document_position, n.consumed_character_count, v0, v1);
}

parlex::detail::acceptor const & plc::FUNCTION_MODIFIER_ATOMIC::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().FUNCTION_MODIFIER_ATOMIC));
	return result;
}


FUNCTION_MODIFIER_CALLING_CONVENTION FUNCTION_MODIFIER_CALLING_CONVENTION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return FUNCTION_MODIFIER_CALLING_CONVENTION(parlex::detail::document::element<FUNCTION_MODIFIER_CALLING_CONVENTION_base>::build(b, w));
}

parlex::detail::acceptor const & plc::FUNCTION_MODIFIER_CALLING_CONVENTION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().FUNCTION_MODIFIER_CALLING_CONVENTION));
	return result;
}

FUNCTION_MODIFIER_MODEL::field_1_t FUNCTION_MODIFIER_MODEL::field_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<IC>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<FUNCTION_MODIFIER_CALLING_CONVENTION>>::build(&*children[2], w);
	return field_1_t(v0, v1, v2);
}

FUNCTION_MODIFIER_MODEL FUNCTION_MODIFIER_MODEL::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_pure_t>,
		parlex::detail::document::text<literal_imperative_t>,
		parlex::detail::document::text<literal_opaque_t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::optional<field_1_t>>::build(&*children[1], w);
	return FUNCTION_MODIFIER_MODEL(n.document_position, n.consumed_character_count, v0, v1);
}

parlex::detail::acceptor const & plc::FUNCTION_MODIFIER_MODEL::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().FUNCTION_MODIFIER_MODEL));
	return result;
}

FUNCTION_MODIFIER_PLATFORM::field_2_t FUNCTION_MODIFIER_PLATFORM::field_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<IC>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<PLATFORM>>::build(&*children[2], w);
	return field_2_t(v0, v1, v2);
}

FUNCTION_MODIFIER_PLATFORM::field_3_t FUNCTION_MODIFIER_PLATFORM::field_3_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<IC>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<FUNCTION_MODIFIER_4>>::build(&*children[2], w);
	return field_3_t(v0, v1, v2);
}

FUNCTION_MODIFIER_PLATFORM FUNCTION_MODIFIER_PLATFORM::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<PLATFORM>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<field_2_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<field_3_t>>::build(&*children[2], w);
	return FUNCTION_MODIFIER_PLATFORM(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::FUNCTION_MODIFIER_PLATFORM::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().FUNCTION_MODIFIER_PLATFORM));
	return result;
}

FUNCTION_MODIFIER_STABILITY::field_1_t FUNCTION_MODIFIER_STABILITY::field_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<IC>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<FUNCTION_MODIFIER_1>>::build(&*children[2], w);
	return field_1_t(v0, v1, v2);
}

FUNCTION_MODIFIER_STABILITY FUNCTION_MODIFIER_STABILITY::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_stable_t>,
		parlex::detail::document::text<literal_unstable_t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::optional<field_1_t>>::build(&*children[1], w);
	return FUNCTION_MODIFIER_STABILITY(n.document_position, n.consumed_character_count, v0, v1);
}

parlex::detail::acceptor const & plc::FUNCTION_MODIFIER_STABILITY::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().FUNCTION_MODIFIER_STABILITY));
	return result;
}

FUNCTION_MODIFIER_THROWING::field_1_t FUNCTION_MODIFIER_THROWING::field_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<ARRAY>>::build(&*children[1], w);
	return field_1_t(v0, v1);
}

FUNCTION_MODIFIER_THROWING::field_2_t FUNCTION_MODIFIER_THROWING::field_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<IC>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<FUNCTION_MODIFIER_2>>::build(&*children[2], w);
	return field_2_t(v0, v1, v2);
}

FUNCTION_MODIFIER_THROWING FUNCTION_MODIFIER_THROWING::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_throwing_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::optional<field_1_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<field_2_t>>::build(&*children[2], w);
	return FUNCTION_MODIFIER_THROWING(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::FUNCTION_MODIFIER_THROWING::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().FUNCTION_MODIFIER_THROWING));
	return result;
}

GREATER GREATER::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<GREATER_NODE>>::build(&*children[2], w);
	return GREATER(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::GREATER::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().GREATER));
	return result;
}

GREATER_NODE::field_3_t GREATER_NODE::field_3_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<GREATER_NODE>>::build(&*children[1], w);
	return field_3_t(v0, v1);
}

GREATER_NODE GREATER_NODE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3D_t>,
		parlex::detail::document::text<literal_0x3E_t>,
		parlex::detail::document::text<literal_0x3D0x3E_t>,
		parlex::detail::document::text<literal_0xE20x890xA5_t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::optional<field_3_t>>::build(&*children[3], w);
	return GREATER_NODE(n.document_position, n.consumed_character_count, v0, v1, v2, v3);
}

parlex::detail::acceptor const & plc::GREATER_NODE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().GREATER_NODE));
	return result;
}

HAS HAS::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x880x8B_t>,
		parlex::detail::document::text<literal_has_t>
	>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return HAS(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::HAS::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().HAS));
	return result;
}

HEX HEX::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::hexadecimal_digit_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<parlex::detail::document::text<parlex::detail::hexadecimal_digit_t>>>::build(&*children[2], w);
	return HEX(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::HEX::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().HEX));
	return result;
}


IC IC::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return IC(parlex::detail::document::element<IC_base>::build(b, w));
}

parlex::detail::acceptor const & plc::IC::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().IC));
	return result;
}

IDENTIFIER IDENTIFIER::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<parlex::detail::letter_t>,
		parlex::detail::document::text<literal___t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<std::variant<
		parlex::detail::document::text<parlex::detail::letter_t>,
		parlex::detail::document::text<parlex::detail::number_t>,
		parlex::detail::document::text<literal___t>
	>>>::build(&*children[1], w);
	return IDENTIFIER(n.document_position, n.consumed_character_count, v0, v1);
}

parlex::detail::acceptor const & plc::IDENTIFIER::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().IDENTIFIER));
	return result;
}

IDENTIFIER_SPECIFICATION::attributes_t IDENTIFIER_SPECIFICATION::attributes_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<ATTRIBUTE>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	return attributes_t(v0, v1);
}

IDENTIFIER_SPECIFICATION::visibility_t IDENTIFIER_SPECIFICATION::visibility_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<VISIBILITY_MODIFIER>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	return visibility_t(v0, v1);
}

IDENTIFIER_SPECIFICATION::static__t IDENTIFIER_SPECIFICATION::static__t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_static_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	return static__t(v0, v1);
}

IDENTIFIER_SPECIFICATION::extern__t IDENTIFIER_SPECIFICATION::extern__t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_extern_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	return extern__t(v0, v1);
}

IDENTIFIER_SPECIFICATION IDENTIFIER_SPECIFICATION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::optional<val<XML_DOC_STRING>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<attributes_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<visibility_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::optional<static__t>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::optional<extern__t>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<val<IDENTIFIER>>::build(&*children[5], w);
	return IDENTIFIER_SPECIFICATION(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5);
}

parlex::detail::acceptor const & plc::IDENTIFIER_SPECIFICATION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().IDENTIFIER_SPECIFICATION));
	return result;
}

IF::field_3_t IF::field_3_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_elif_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<val<PARENTHETICAL>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[5], w);
	return field_3_t(v0, v1, v2, v3, v4, v5);
}

IF::field_4_t IF::field_4_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_else_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[3], w);
	return field_4_t(v0, v1, v2, v3);
}

IF IF::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_if_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<PARENTHETICAL>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<std::vector<field_3_t>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<std::optional<field_4_t>>::build(&*children[6], w);
	return IF(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5, v6);
}

parlex::detail::acceptor const & plc::IF::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().IF));
	return result;
}

IFF IFF::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x870x94_t>,
		parlex::detail::document::text<literal_0x3C0x3D0x3E_t>
	>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return IFF(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::IFF::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().IFF));
	return result;
}

IMPLEMENTS IMPLEMENTS::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_implements_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return IMPLEMENTS(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::IMPLEMENTS::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().IMPLEMENTS));
	return result;
}

IMPLICATION IMPLICATION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x870x92_t>,
		parlex::detail::document::text<literal_0x3D0x3E_t>
	>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return IMPLICATION(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::IMPLICATION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().IMPLICATION));
	return result;
}

IMPLICATION_ASSIGNMENT IMPLICATION_ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x870x92_t>,
		parlex::detail::document::text<literal_0x3D0x3E_t>
	>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[5], w);
	return IMPLICATION_ASSIGNMENT(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5);
}

parlex::detail::acceptor const & plc::IMPLICATION_ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().IMPLICATION_ASSIGNMENT));
	return result;
}

IMPLICIT_TYPE_DEREFERENCE IMPLICIT_TYPE_DEREFERENCE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3C_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3E_t>>::build(&*children[2], w);
	return IMPLICIT_TYPE_DEREFERENCE(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::IMPLICIT_TYPE_DEREFERENCE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().IMPLICIT_TYPE_DEREFERENCE));
	return result;
}

IMPORT IMPORT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_import_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	return IMPORT(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::IMPORT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().IMPORT));
	return result;
}

IN IN::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x880x88_t>,
		parlex::detail::document::text<literal_in_t>
	>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return IN(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::IN::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().IN));
	return result;
}

INEQUALITY INEQUALITY::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x890xA0_t>,
		parlex::detail::document::text<literal_0x2F0x3D_t>
	>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return INEQUALITY(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::INEQUALITY::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().INEQUALITY));
	return result;
}

INHERITANCE_ITEM_PREFIX::field_1_t2 INHERITANCE_ITEM_PREFIX::field_1_t2::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<VISIBILITY_MODIFIER>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<IC>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<parlex::detail::document::text<literal_diamond_t>>::build(&*children[3], w);
	return field_1_t2(v0, v1, v2, v3);
}

INHERITANCE_ITEM_PREFIX INHERITANCE_ITEM_PREFIX::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		val<VISIBILITY_MODIFIER>,
		field_1_t2,
		parlex::detail::document::text<literal_diamond_t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<IC>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	return INHERITANCE_ITEM_PREFIX(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::INHERITANCE_ITEM_PREFIX::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().INHERITANCE_ITEM_PREFIX));
	return result;
}

INHERITANCE_LIST::field_2_t INHERITANCE_LIST::field_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2C_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::optional<val<INHERITANCE_ITEM_PREFIX>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return field_2_t(v0, v1, v2, v3, v4);
}

INHERITANCE_LIST INHERITANCE_LIST::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::optional<val<INHERITANCE_ITEM_PREFIX>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<field_2_t>>::build(&*children[2], w);
	return INHERITANCE_LIST(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::INHERITANCE_LIST::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().INHERITANCE_LIST));
	return result;
}

INHERITS INHERITS::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_inherits_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return INHERITS(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::INHERITS::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().INHERITS));
	return result;
}

INTEGER_DIVISION INTEGER_DIVISION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5C_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return INTEGER_DIVISION(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::INTEGER_DIVISION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().INTEGER_DIVISION));
	return result;
}

INTEGER_DIVISION_ASSIGNMENT INTEGER_DIVISION_ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5C_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[5], w);
	return INTEGER_DIVISION_ASSIGNMENT(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5);
}

parlex::detail::acceptor const & plc::INTEGER_DIVISION_ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().INTEGER_DIVISION_ASSIGNMENT));
	return result;
}

INTERSECTION INTERSECTION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0xE20x880xA9_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return INTERSECTION(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::INTERSECTION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().INTERSECTION));
	return result;
}

INTERSECTION_ASSIGNMENT INTERSECTION_ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0xE20x880xA9_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[5], w);
	return INTERSECTION_ASSIGNMENT(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5);
}

parlex::detail::acceptor const & plc::INTERSECTION_ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().INTERSECTION_ASSIGNMENT));
	return result;
}

INVOCATION INVOCATION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		val<PARENTHETICAL_INVOCATION>,
		val<ARRAY_INVOCATION>,
		val<TYPE_INVOCATION>
	>>::build(&*children[2], w);
	return INVOCATION(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::INVOCATION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().INVOCATION));
	return result;
}

IS IS::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_is_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return IS(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::IS::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().IS));
	return result;
}

KLEENE_STAR KLEENE_STAR::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2A_t>>::build(&*children[2], w);
	return KLEENE_STAR(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::KLEENE_STAR::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().KLEENE_STAR));
	return result;
}

LESSER LESSER::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<LESSER_NODE>>::build(&*children[2], w);
	return LESSER(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::LESSER::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().LESSER));
	return result;
}

LESSER_NODE::field_2_t LESSER_NODE::field_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<LESSER_NODE>>::build(&*children[1], w);
	return field_2_t(v0, v1);
}

LESSER_NODE LESSER_NODE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3D_t>,
		parlex::detail::document::text<literal_0x3C_t>,
		parlex::detail::document::text<literal_0x3D0x3C_t>,
		parlex::detail::document::text<literal_0xE20x890xA4_t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::optional<field_2_t>>::build(&*children[3], w);
	return LESSER_NODE(n.document_position, n.consumed_character_count, v0, v1, v2, v3);
}

parlex::detail::acceptor const & plc::LESSER_NODE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().LESSER_NODE));
	return result;
}

LIST::elements_t::field_2_t LIST::elements_t::field_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2C0x20_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[3], w);
	return field_2_t(v0, v1, v2, v3);
}

LIST::elements_t LIST::elements_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<field_2_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	return elements_t(v0, v1, v2);
}

LIST LIST::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5B0x7C_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<elements_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7C0x5D_t>>::build(&*children[3], w);
	return LIST(n.document_position, n.consumed_character_count, v0, v1, v2, v3);
}

parlex::detail::acceptor const & plc::LIST::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().LIST));
	return result;
}

LOCK LOCK::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_lock_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<PARENTHETICAL>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<BLOCK>>::build(&*children[4], w);
	return LOCK(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::LOCK::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().LOCK));
	return result;
}

LOOP LOOP::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_while_t>,
		parlex::detail::document::text<literal_until_t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<PARENTHETICAL>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return LOOP(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::LOOP::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().LOOP));
	return result;
}

MAGNITUDE MAGNITUDE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7C_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7C_t>>::build(&*children[4], w);
	return MAGNITUDE(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::MAGNITUDE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().MAGNITUDE));
	return result;
}

MAP::field_1_t::field_6_t MAP::field_1_t::field_6_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2C_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3A_t>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[6], w);
	auto v7 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[7], w);
	return field_6_t(v0, v1, v2, v3, v4, v5, v6, v7);
}

MAP::field_1_t MAP::field_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3A_t>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<std::vector<field_6_t>>::build(&*children[6], w);
	return field_1_t(v0, v1, v2, v3, v4, v5, v6);
}

MAP MAP::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7B_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::optional<field_1_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7D_t>>::build(&*children[3], w);
	return MAP(n.document_position, n.consumed_character_count, v0, v1, v2, v3);
}

parlex::detail::acceptor const & plc::MAP::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().MAP));
	return result;
}

MAPS_TO::field_1_t MAPS_TO::field_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_volatile_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<IC>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	return field_1_t(v0, v1, v2);
}

MAPS_TO::field_2_t MAPS_TO::field_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_const_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<IC>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	return field_2_t(v0, v1, v2);
}

MAPS_TO MAPS_TO::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::optional<field_1_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::optional<field_2_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x860x92_t>,
		parlex::detail::document::text<literal_0x2D0x3E_t>
	>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[6], w);
	return MAPS_TO(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5, v6);
}

parlex::detail::acceptor const & plc::MAPS_TO::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().MAPS_TO));
	return result;
}

MEMBER_ACCESS MEMBER_ACCESS::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2E_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<IDENTIFIER>>::build(&*children[4], w);
	return MEMBER_ACCESS(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::MEMBER_ACCESS::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().MEMBER_ACCESS));
	return result;
}

MEMBER_OFFSET MEMBER_OFFSET::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x40_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<NATURAL_NUMBER>>::build(&*children[2], w);
	return MEMBER_OFFSET(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::MEMBER_OFFSET::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().MEMBER_OFFSET));
	return result;
}

MODULATION MODULATION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x25_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return MODULATION(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::MODULATION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().MODULATION));
	return result;
}

MODULATION_ASSIGNMENT MODULATION_ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x25_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[5], w);
	return MODULATION_ASSIGNMENT(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5);
}

parlex::detail::acceptor const & plc::MODULATION_ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().MODULATION_ASSIGNMENT));
	return result;
}

MULTIPLICATION MULTIPLICATION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2A_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return MULTIPLICATION(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::MULTIPLICATION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().MULTIPLICATION));
	return result;
}

MULTIPLICATION_ASSIGNMENT MULTIPLICATION_ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2A_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[5], w);
	return MULTIPLICATION_ASSIGNMENT(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5);
}

parlex::detail::acceptor const & plc::MULTIPLICATION_ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().MULTIPLICATION_ASSIGNMENT));
	return result;
}


MULTIPLICATIVE_OP MULTIPLICATIVE_OP::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return MULTIPLICATIVE_OP(parlex::detail::document::element<MULTIPLICATIVE_OP_base>::build(b, w));
}

parlex::detail::acceptor const & plc::MULTIPLICATIVE_OP::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().MULTIPLICATIVE_OP));
	return result;
}

NAND NAND::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x860x91_t>,
		parlex::detail::document::text<literal_nand_t>
	>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return NAND(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::NAND::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().NAND));
	return result;
}

NAND_ASSIGNMENT NAND_ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x860x91_t>,
		parlex::detail::document::text<literal_nand_t>
	>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[5], w);
	return NAND_ASSIGNMENT(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5);
}

parlex::detail::acceptor const & plc::NAND_ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().NAND_ASSIGNMENT));
	return result;
}

NATURAL_NUMBER NATURAL_NUMBER::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<parlex::detail::document::text<parlex::detail::decimal_digit_t>>>::build(&*children[1], w);
	return NATURAL_NUMBER(n.document_position, n.consumed_character_count, v0, v1);
}

parlex::detail::acceptor const & plc::NATURAL_NUMBER::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().NATURAL_NUMBER));
	return result;
}


NEAREST_INTEGER NEAREST_INTEGER::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return NEAREST_INTEGER(parlex::detail::document::element<NEAREST_INTEGER_base>::build(b, w));
}

NEAREST_INTEGER1_t NEAREST_INTEGER1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0xE20x8C0x8A_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<parlex::detail::document::text<literal_0xE20x8C0x89_t>>::build(&*children[4], w);
	return NEAREST_INTEGER1_t(v0, v1, v2, v3, v4);
}

NEAREST_INTEGER2_t NEAREST_INTEGER2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7C__t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<parlex::detail::document::text<literal_0x270x7C_t>>::build(&*children[4], w);
	return NEAREST_INTEGER2_t(v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::NEAREST_INTEGER::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().NEAREST_INTEGER));
	return result;
}

NEGATION NEGATION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2D_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	return NEGATION(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::NEGATION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().NEGATION));
	return result;
}

NEGATION_ASSIGNMENT NEGATION_ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2D_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	>>::build(&*children[3], w);
	return NEGATION_ASSIGNMENT(n.document_position, n.consumed_character_count, v0, v1, v2, v3);
}

parlex::detail::acceptor const & plc::NEGATION_ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().NEGATION_ASSIGNMENT));
	return result;
}

NON_FRACTIONAL NON_FRACTIONAL::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::optional<parlex::detail::document::text<literal_0x2D_t>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<NON_NEG_NON_FRACTIONAL>>::build(&*children[1], w);
	return NON_FRACTIONAL(n.document_position, n.consumed_character_count, v0, v1);
}

parlex::detail::acceptor const & plc::NON_FRACTIONAL::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().NON_FRACTIONAL));
	return result;
}


NON_NEG_FRACTIONAL NON_NEG_FRACTIONAL::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return NON_NEG_FRACTIONAL(parlex::detail::document::element<NON_NEG_FRACTIONAL_base>::build(b, w));
}

NON_NEG_FRACTIONAL1_t NON_NEG_FRACTIONAL1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<parlex::detail::document::text<parlex::detail::decimal_digit_t>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2E_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<parlex::detail::document::text<parlex::detail::decimal_digit_t>>>::build(&*children[3], w);
	return NON_NEG_FRACTIONAL1_t(v0, v1, v2, v3);
}

NON_NEG_FRACTIONAL2_t NON_NEG_FRACTIONAL2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2E_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<parlex::detail::document::text<parlex::detail::decimal_digit_t>>>::build(&*children[2], w);
	return NON_NEG_FRACTIONAL2_t(v0, v1, v2);
}

parlex::detail::acceptor const & plc::NON_NEG_FRACTIONAL::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().NON_NEG_FRACTIONAL));
	return result;
}


NON_NEG_INTEGER NON_NEG_INTEGER::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return NON_NEG_INTEGER(parlex::detail::document::element<NON_NEG_INTEGER_base>::build(b, w));
}

NON_NEG_INTEGER1_t NON_NEG_INTEGER1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<NON_ZERO_DECIMAL_DIGIT>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<parlex::detail::document::text<parlex::detail::decimal_digit_t>>>::build(&*children[1], w);
	return NON_NEG_INTEGER1_t(v0, v1);
}

parlex::detail::acceptor const & plc::NON_NEG_INTEGER::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().NON_NEG_INTEGER));
	return result;
}


NON_NEG_NON_FRACTIONAL NON_NEG_NON_FRACTIONAL::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return NON_NEG_NON_FRACTIONAL(parlex::detail::document::element<NON_NEG_NON_FRACTIONAL_base>::build(b, w));
}

parlex::detail::acceptor const & plc::NON_NEG_NON_FRACTIONAL::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().NON_NEG_NON_FRACTIONAL));
	return result;
}


NON_NEG_NUMBER NON_NEG_NUMBER::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return NON_NEG_NUMBER(parlex::detail::document::element<NON_NEG_NUMBER_base>::build(b, w));
}

parlex::detail::acceptor const & plc::NON_NEG_NUMBER::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().NON_NEG_NUMBER));
	return result;
}


NON_ZERO_DECIMAL_DIGIT NON_ZERO_DECIMAL_DIGIT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return NON_ZERO_DECIMAL_DIGIT(parlex::detail::document::element<NON_ZERO_DECIMAL_DIGIT_base>::build(b, w));
}

parlex::detail::acceptor const & plc::NON_ZERO_DECIMAL_DIGIT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().NON_ZERO_DECIMAL_DIGIT));
	return result;
}

NOR NOR::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x860x93_t>,
		parlex::detail::document::text<literal_nor_t>
	>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return NOR(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::NOR::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().NOR));
	return result;
}

NOR_ASSIGNMENT NOR_ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x860x93_t>,
		parlex::detail::document::text<literal_nor_t>
	>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[5], w);
	return NOR_ASSIGNMENT(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5);
}

parlex::detail::acceptor const & plc::NOR_ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().NOR_ASSIGNMENT));
	return result;
}

NOT NOT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xC20xAC_t>,
		parlex::detail::document::text<literal_0x7E_t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	return NOT(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::NOT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().NOT));
	return result;
}

NOT_ASSIGNMENT NOT_ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xC20xAC_t>,
		parlex::detail::document::text<literal_0x7E_t>
	>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	>>::build(&*children[3], w);
	return NOT_ASSIGNMENT(n.document_position, n.consumed_character_count, v0, v1, v2, v3);
}

parlex::detail::acceptor const & plc::NOT_ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().NOT_ASSIGNMENT));
	return result;
}

NOT_HAS NOT_HAS::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x880x8C_t>,
		parlex::detail::document::text<literal_0x2Fhas_t>
	>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return NOT_HAS(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::NOT_HAS::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().NOT_HAS));
	return result;
}

NOT_IN NOT_IN::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x880x89_t>,
		parlex::detail::document::text<literal_0x2Fin_t>
	>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return NOT_IN(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::NOT_IN::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().NOT_IN));
	return result;
}

NULL_COALESCE NULL_COALESCE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3F0x3F_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return NULL_COALESCE(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::NULL_COALESCE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().NULL_COALESCE));
	return result;
}

NULL_COALESCE_ASSIGNMENT NULL_COALESCE_ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3F0x3F_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[5], w);
	return NULL_COALESCE_ASSIGNMENT(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5);
}

parlex::detail::acceptor const & plc::NULL_COALESCE_ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().NULL_COALESCE_ASSIGNMENT));
	return result;
}

OBJECT::field_2_t OBJECT::field_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_inheriting_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<INHERITANCE_LIST>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	return field_2_t(v0, v1, v2, v3);
}

OBJECT::field_3_t OBJECT::field_3_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_implementing_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<INHERITANCE_LIST>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	return field_3_t(v0, v1, v2, v3);
}

OBJECT OBJECT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_object_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<field_2_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::optional<field_3_t>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7B_t>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<val<TYPE_SCOPE>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7D_t>>::build(&*children[6], w);
	return OBJECT(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5, v6);
}

parlex::detail::acceptor const & plc::OBJECT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().OBJECT));
	return result;
}

OCTAL OCTAL::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::octal_digit_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<parlex::detail::document::text<parlex::detail::octal_digit_t>>>::build(&*children[2], w);
	return OCTAL(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::OCTAL::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().OCTAL));
	return result;
}


OP_ASSIGNMENT OP_ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return OP_ASSIGNMENT(parlex::detail::document::element<OP_ASSIGNMENT_base>::build(b, w));
}

parlex::detail::acceptor const & plc::OP_ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().OP_ASSIGNMENT));
	return result;
}

OR OR::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x880xA8_t>,
		parlex::detail::document::text<literal_or_t>
	>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return OR(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::OR::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().OR));
	return result;
}

OR_ASSIGNMENT OR_ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x880xA8_t>,
		parlex::detail::document::text<literal_or_t>
	>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[5], w);
	return OR_ASSIGNMENT(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5);
}

parlex::detail::acceptor const & plc::OR_ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().OR_ASSIGNMENT));
	return result;
}


PARAMETER PARAMETER::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return PARAMETER(parlex::detail::document::element<PARAMETER_base>::build(b, w));
}

parlex::detail::acceptor const & plc::PARAMETER::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().PARAMETER));
	return result;
}

PARAMETER_ANALYTIC::field_2_t PARAMETER_ANALYTIC::field_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3D_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[3], w);
	return field_2_t(v0, v1, v2, v3);
}

PARAMETER_ANALYTIC PARAMETER_ANALYTIC::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::optional<field_2_t>>::build(&*children[1], w);
	return PARAMETER_ANALYTIC(n.document_position, n.consumed_character_count, v0, v1);
}

parlex::detail::acceptor const & plc::PARAMETER_ANALYTIC::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().PARAMETER_ANALYTIC));
	return result;
}


PARAMETER_NATURAL PARAMETER_NATURAL::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return PARAMETER_NATURAL(parlex::detail::document::element<PARAMETER_NATURAL_base>::build(b, w));
}

PARAMETER_NATURAL1_t::field_1_t PARAMETER_NATURAL1_t::field_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<TYPE_DEREFERENCE>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	return field_1_t(v0, v1);
}

PARAMETER_NATURAL1_t PARAMETER_NATURAL1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::optional<field_1_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<IDENTIFIER>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<parlex::detail::document::text<literal_0x2E0x2E0x2E_t>>>::build(&*children[2], w);
	return PARAMETER_NATURAL1_t(v0, v1, v2);
}

PARAMETER_NATURAL2_t::field_1_t PARAMETER_NATURAL2_t::field_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		val<TYPE_DEREFERENCE>,
		val<IMPLICIT_TYPE_DEREFERENCE>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	return field_1_t(v0, v1);
}

PARAMETER_NATURAL2_t PARAMETER_NATURAL2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::optional<field_1_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<IDENTIFIER>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<parlex::detail::document::text<literal_0x2E0x2E0x2E_t>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3D_t>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[6], w);
	auto v7 = parlex::detail::document::element<std::optional<parlex::detail::document::text<literal_0x2E0x2E0x2E_t>>>::build(&*children[7], w);
	return PARAMETER_NATURAL2_t(v0, v1, v2, v3, v4, v5, v6, v7);
}

parlex::detail::acceptor const & plc::PARAMETER_NATURAL::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().PARAMETER_NATURAL));
	return result;
}

PARENTHETICAL PARENTHETICAL::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x28_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<parlex::detail::document::text<literal_0x29_t>>::build(&*children[4], w);
	return PARENTHETICAL(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::PARENTHETICAL::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().PARENTHETICAL));
	return result;
}

PARENTHETICAL_INVOCATION::arguments_t PARENTHETICAL_INVOCATION::arguments_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<STANDARD_ARGUMENTS>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	return arguments_t(v0, v1);
}

PARENTHETICAL_INVOCATION PARENTHETICAL_INVOCATION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x28_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<arguments_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<parlex::detail::document::text<literal_0x29_t>>::build(&*children[3], w);
	return PARENTHETICAL_INVOCATION(n.document_position, n.consumed_character_count, v0, v1, v2, v3);
}

parlex::detail::acceptor const & plc::PARENTHETICAL_INVOCATION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().PARENTHETICAL_INVOCATION));
	return result;
}

PAYLOAD PAYLOAD::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::all_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<parlex::detail::document::text<parlex::detail::all_t>>>::build(&*children[1], w);
	return PAYLOAD(n.document_position, n.consumed_character_count, v0, v1);
}

parlex::detail::acceptor const & plc::PAYLOAD::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().PAYLOAD));
	return result;
}

PLATFORM PLATFORM::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal___t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<parlex::detail::letter_t>,
		parlex::detail::document::text<parlex::detail::number_t>
	>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<std::variant<
		parlex::detail::document::text<parlex::detail::letter_t>,
		parlex::detail::document::text<parlex::detail::number_t>,
		parlex::detail::document::text<literal___t>
	>>>::build(&*children[2], w);
	return PLATFORM(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::PLATFORM::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().PLATFORM));
	return result;
}

POST_DEC POST_DEC::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2D0x2D_t>>::build(&*children[2], w);
	return POST_DEC(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::POST_DEC::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().POST_DEC));
	return result;
}

POST_INC POST_INC::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2B0x2B_t>>::build(&*children[2], w);
	return POST_INC(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::POST_INC::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().POST_INC));
	return result;
}

PREPEND PREPEND::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x26_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return PREPEND(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::PREPEND::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().PREPEND));
	return result;
}

PREPEND_ASSIGNMENT PREPEND_ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x26_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[5], w);
	return PREPEND_ASSIGNMENT(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5);
}

parlex::detail::acceptor const & plc::PREPEND_ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().PREPEND_ASSIGNMENT));
	return result;
}

PRE_DEC PRE_DEC::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2D0x2D_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	return PRE_DEC(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::PRE_DEC::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().PRE_DEC));
	return result;
}

PRE_INC PRE_INC::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2B0x2B_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	return PRE_INC(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::PRE_INC::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().PRE_INC));
	return result;
}

RADICAL RADICAL::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x880x9A_t>,
		parlex::detail::document::text<literal_sqrt_t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	return RADICAL(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::RADICAL::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().RADICAL));
	return result;
}

RADICAL_ASSIGNMENT RADICAL_ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x880x9A_t>,
		parlex::detail::document::text<literal_sqrt_t>
	>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	>>::build(&*children[3], w);
	return RADICAL_ASSIGNMENT(n.document_position, n.consumed_character_count, v0, v1, v2, v3);
}

parlex::detail::acceptor const & plc::RADICAL_ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().RADICAL_ASSIGNMENT));
	return result;
}


RANGE RANGE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return RANGE(parlex::detail::document::element<RANGE_base>::build(b, w));
}

RANGE1_t RANGE1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x28_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2E0x2E0x2E_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x5D_t>,
		parlex::detail::document::text<literal_0x29_t>
	>>::build(&*children[6], w);
	return RANGE1_t(v0, v1, v2, v3, v4, v5, v6);
}

RANGE2_t RANGE2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x5B_t>,
		parlex::detail::document::text<literal_0x28_t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2E0x2E0x2E_t>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<parlex::detail::document::text<literal_0x29_t>>::build(&*children[6], w);
	return RANGE2_t(v0, v1, v2, v3, v4, v5, v6);
}

RANGE3_t RANGE3_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x28_t>,
		parlex::detail::document::text<literal_0x5B_t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2E0x2E0x2E_t>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[6], w);
	auto v7 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[7], w);
	auto v8 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x5D_t>,
		parlex::detail::document::text<literal_0x29_t>
	>>::build(&*children[8], w);
	return RANGE3_t(v0, v1, v2, v3, v4, v5, v6, v7, v8);
}

parlex::detail::acceptor const & plc::RANGE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().RANGE));
	return result;
}

READ_LOCK READ_LOCK::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_read_lock_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<PARENTHETICAL>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return READ_LOCK(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::READ_LOCK::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().READ_LOCK));
	return result;
}

RECORD RECORD::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_record_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<IC>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<val<TYPE>>::build(&*children[3], w);
	return RECORD(n.document_position, n.consumed_character_count, v0, v1, v2, v3);
}

parlex::detail::acceptor const & plc::RECORD::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().RECORD));
	return result;
}

REGEX REGEX::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_R_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<void>>::build(&*children[1], w);
	return REGEX(n.document_position, n.consumed_character_count, v0, v1);
}

parlex::detail::acceptor const & plc::REGEX::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().REGEX));
	return result;
}


RELATIONAL_COLLECTION_OP RELATIONAL_COLLECTION_OP::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return RELATIONAL_COLLECTION_OP(parlex::detail::document::element<RELATIONAL_COLLECTION_OP_base>::build(b, w));
}

parlex::detail::acceptor const & plc::RELATIONAL_COLLECTION_OP::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().RELATIONAL_COLLECTION_OP));
	return result;
}


RELATIONAL_OP RELATIONAL_OP::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return RELATIONAL_OP(parlex::detail::document::element<RELATIONAL_OP_base>::build(b, w));
}

parlex::detail::acceptor const & plc::RELATIONAL_OP::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().RELATIONAL_OP));
	return result;
}

RETURN::field_1_t RETURN::field_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5B_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5D_t>>::build(&*children[5], w);
	return field_1_t(v0, v1, v2, v3, v4, v5);
}

RETURN::field_2_t RETURN::field_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[1], w);
	return field_2_t(v0, v1);
}

RETURN RETURN::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_return_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::optional<field_1_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<field_2_t>>::build(&*children[2], w);
	return RETURN(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::RETURN::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().RETURN));
	return result;
}

SET::elements_t::field_2_t SET::elements_t::field_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2C_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[3], w);
	return field_2_t(v0, v1, v2, v3);
}

SET::elements_t SET::elements_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<field_2_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	return elements_t(v0, v1, v2);
}

SET SET::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7B0x7C_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<elements_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7C0x7D_t>>::build(&*children[3], w);
	return SET(n.document_position, n.consumed_character_count, v0, v1, v2, v3);
}

parlex::detail::acceptor const & plc::SET::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().SET));
	return result;
}

SET_COMPREHENSION SET_COMPREHENSION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7B_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7C_t>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[6], w);
	auto v7 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[7], w);
	auto v8 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7D_t>>::build(&*children[8], w);
	return SET_COMPREHENSION(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5, v6, v7, v8);
}

parlex::detail::acceptor const & plc::SET_COMPREHENSION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().SET_COMPREHENSION));
	return result;
}

SHIFTL SHIFTL::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3C0x3C_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return SHIFTL(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::SHIFTL::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().SHIFTL));
	return result;
}

SHIFTL_ASSIGNMENT SHIFTL_ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3C0x3C_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[5], w);
	return SHIFTL_ASSIGNMENT(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5);
}

parlex::detail::acceptor const & plc::SHIFTL_ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().SHIFTL_ASSIGNMENT));
	return result;
}

SHIFTR SHIFTR::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3E0x3E_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return SHIFTR(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::SHIFTR::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().SHIFTR));
	return result;
}

SHIFTR_ASSIGNMENT SHIFTR_ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3E0x3E_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[5], w);
	return SHIFTR_ASSIGNMENT(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5);
}

parlex::detail::acceptor const & plc::SHIFTR_ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().SHIFTR_ASSIGNMENT));
	return result;
}

SLICE SLICE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3A_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return SLICE(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::SLICE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().SLICE));
	return result;
}

STANDARD_ARGUMENTS::tail_t::field_1_t STANDARD_ARGUMENTS::tail_t::field_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::variant<
		val<EXPRESSION>,
		val<ARGUMENT_PACK>
	>>::build(&*children[1], w);
	return field_1_t(v0, v1);
}

STANDARD_ARGUMENTS::tail_t STANDARD_ARGUMENTS::tail_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2C_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<field_1_t>>::build(&*children[2], w);
	return tail_t(v0, v1, v2);
}

STANDARD_ARGUMENTS STANDARD_ARGUMENTS::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::optional<std::variant<
		val<EXPRESSION>,
		val<ARGUMENT_PACK>
	>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<tail_t>>::build(&*children[1], w);
	return STANDARD_ARGUMENTS(n.document_position, n.consumed_character_count, v0, v1);
}

parlex::detail::acceptor const & plc::STANDARD_ARGUMENTS::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().STANDARD_ARGUMENTS));
	return result;
}

STATEMENT STATEMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		val<ASSIGNMENT>,
		val<BREAK>,
		val<CONTINUE>,
		val<DEFINITION>,
		val<DO>,
		val<EXPRESSION>,
		val<FOR>,
		val<FOR_COLLECTION>,
		val<FREE>,
		val<IMPORT>,
		val<LOCK>,
		val<LOOP>,
		val<OP_ASSIGNMENT>,
		val<READ_LOCK>,
		val<RETURN>,
		val<THROW>,
		val<TRY>,
		val<TYPE_CONSTRAINT>,
		val<WRITE_LOCK>,
		val<USING>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3B_t>>::build(&*children[2], w);
	return STATEMENT(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::STATEMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().STATEMENT));
	return result;
}


STATEMENT_SCOPE STATEMENT_SCOPE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return STATEMENT_SCOPE(parlex::detail::document::element<STATEMENT_SCOPE_base>::build(b, w));
}

parlex::detail::acceptor const & plc::STATEMENT_SCOPE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().STATEMENT_SCOPE));
	return result;
}

SUBSET SUBSET::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<SUBSET_NODE>>::build(&*children[2], w);
	return SUBSET(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::SUBSET::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().SUBSET));
	return result;
}

SUBSET_NODE::field_2_t SUBSET_NODE::field_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<SUBSET_NODE>>::build(&*children[1], w);
	return field_2_t(v0, v1);
}

SUBSET_NODE SUBSET_NODE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3D_t>,
		parlex::detail::document::text<literal_0xE20x8A0x86_t>,
		parlex::detail::document::text<literal_subs_t>,
		parlex::detail::document::text<literal_0xE20x8A0x82_t>,
		parlex::detail::document::text<literal_psubs_t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::optional<field_2_t>>::build(&*children[3], w);
	return SUBSET_NODE(n.document_position, n.consumed_character_count, v0, v1, v2, v3);
}

parlex::detail::acceptor const & plc::SUBSET_NODE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().SUBSET_NODE));
	return result;
}

SUBTRACTION SUBTRACTION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2D_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return SUBTRACTION(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::SUBTRACTION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().SUBTRACTION));
	return result;
}

SUBTRACTION_ASSIGNMENT SUBTRACTION_ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2D_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[5], w);
	return SUBTRACTION_ASSIGNMENT(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5);
}

parlex::detail::acceptor const & plc::SUBTRACTION_ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().SUBTRACTION_ASSIGNMENT));
	return result;
}

SUPERSET SUPERSET::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<SUPERSET_NODE>>::build(&*children[2], w);
	return SUPERSET(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::SUPERSET::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().SUPERSET));
	return result;
}

SUPERSET_NODE::field_2_t SUPERSET_NODE::field_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<SUPERSET_NODE>>::build(&*children[1], w);
	return field_2_t(v0, v1);
}

SUPERSET_NODE SUPERSET_NODE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3D_t>,
		parlex::detail::document::text<literal_0xE20x8A0x87_t>,
		parlex::detail::document::text<literal_sups_t>,
		parlex::detail::document::text<literal_0xE20x8A0x83_t>,
		parlex::detail::document::text<literal_psups_t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::optional<field_2_t>>::build(&*children[3], w);
	return SUPERSET_NODE(n.document_position, n.consumed_character_count, v0, v1, v2, v3);
}

parlex::detail::acceptor const & plc::SUPERSET_NODE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().SUPERSET_NODE));
	return result;
}

SWIZZLE SWIZZLE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x8B0xAE_t>,
		parlex::detail::document::text<literal__swiz__t>
	>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return SWIZZLE(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::SWIZZLE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().SWIZZLE));
	return result;
}

SYMMETRIC_DIFFERENCE SYMMETRIC_DIFFERENCE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0xE20x8A0x96_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return SYMMETRIC_DIFFERENCE(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::SYMMETRIC_DIFFERENCE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().SYMMETRIC_DIFFERENCE));
	return result;
}

SYMMETRIC_DIFFERENCE_ASSIGNMENT SYMMETRIC_DIFFERENCE_ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0xE20x8A0x96_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[5], w);
	return SYMMETRIC_DIFFERENCE_ASSIGNMENT(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5);
}

parlex::detail::acceptor const & plc::SYMMETRIC_DIFFERENCE_ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().SYMMETRIC_DIFFERENCE_ASSIGNMENT));
	return result;
}

THIS::field_1_t THIS::field_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5B_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5D_t>>::build(&*children[5], w);
	return field_1_t(v0, v1, v2, v3, v4, v5);
}

THIS THIS::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_this_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::optional<field_1_t>>::build(&*children[1], w);
	return THIS(n.document_position, n.consumed_character_count, v0, v1);
}

parlex::detail::acceptor const & plc::THIS::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().THIS));
	return result;
}

THIS_FUNC::field_1_t THIS_FUNC::field_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5B_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5D_t>>::build(&*children[5], w);
	return field_1_t(v0, v1, v2, v3, v4, v5);
}

THIS_FUNC THIS_FUNC::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_this_func_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::optional<field_1_t>>::build(&*children[1], w);
	return THIS_FUNC(n.document_position, n.consumed_character_count, v0, v1);
}

parlex::detail::acceptor const & plc::THIS_FUNC::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().THIS_FUNC));
	return result;
}

THIS_TYPE::field_1_t THIS_TYPE::field_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5B_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5D_t>>::build(&*children[5], w);
	return field_1_t(v0, v1, v2, v3, v4, v5);
}

THIS_TYPE THIS_TYPE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_this_type_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::optional<field_1_t>>::build(&*children[1], w);
	return THIS_TYPE(n.document_position, n.consumed_character_count, v0, v1);
}

parlex::detail::acceptor const & plc::THIS_TYPE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().THIS_TYPE));
	return result;
}

THROW::field_1_t THROW::field_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5B_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5D_t>>::build(&*children[5], w);
	return field_1_t(v0, v1, v2, v3, v4, v5);
}

THROW::field_2_t THROW::field_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[1], w);
	return field_2_t(v0, v1);
}

THROW THROW::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_throw_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::optional<field_1_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<field_2_t>>::build(&*children[2], w);
	return THROW(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::THROW::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().THROW));
	return result;
}

TIME::field_08_t TIME::field_08_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2E_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<parlex::detail::document::text<parlex::detail::decimal_digit_t>>>::build(&*children[2], w);
	return field_08_t(v0, v1, v2);
}

TIME::field_09_t2::field_4_t TIME::field_09_t2::field_4_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3A_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[2], w);
	return field_4_t(v0, v1, v2);
}

TIME::field_09_t2 TIME::field_09_t2::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x2B_t>,
		parlex::detail::document::text<literal_0x2D_t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::optional<field_4_t>>::build(&*children[3], w);
	return field_09_t2(v0, v1, v2, v3);
}

TIME TIME::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::optional<parlex::detail::document::text<literal_0x2D_t>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3A_t>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3A_t>>::build(&*children[6], w);
	auto v7 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[7], w);
	auto v8 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[8], w);
	auto v9 = parlex::detail::document::element<std::optional<field_08_t>>::build(&*children[9], w);
	auto v10 = parlex::detail::document::element<std::optional<std::variant<
		parlex::detail::document::text<literal_Z_t>,
		field_09_t2
	>>>::build(&*children[10], w);
	return TIME(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10);
}

parlex::detail::acceptor const & plc::TIME::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().TIME));
	return result;
}

TRY::field_06_t TRY::field_06_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_catch_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	return field_06_t(v0, v1, v2);
}

TRY::field_07_t TRY::field_07_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_finally_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[3], w);
	return field_07_t(v0, v1, v2, v3);
}

TRY TRY::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_try_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<parlex::detail::document::text<literal_catch_t>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[6], w);
	auto v7 = parlex::detail::document::element<std::vector<field_06_t>>::build(&*children[7], w);
	auto v8 = parlex::detail::document::element<std::optional<field_07_t>>::build(&*children[8], w);
	return TRY(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5, v6, v7, v8);
}

parlex::detail::acceptor const & plc::TRY::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().TRY));
	return result;
}

TUPLE::field_3_t TUPLE::field_3_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2C_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[3], w);
	return field_3_t(v0, v1, v2, v3);
}

TUPLE TUPLE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x280x7C_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<field_3_t>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7C0x29_t>>::build(&*children[5], w);
	return TUPLE(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5);
}

parlex::detail::acceptor const & plc::TUPLE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().TUPLE));
	return result;
}

TYPE::field_2_t TYPE::field_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_inheriting_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<INHERITANCE_LIST>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	return field_2_t(v0, v1, v2, v3);
}

TYPE::field_3_t TYPE::field_3_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_implementing_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<INHERITANCE_LIST>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	return field_3_t(v0, v1, v2, v3);
}

TYPE TYPE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_type_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<field_2_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::optional<field_3_t>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7B_t>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<val<TYPE_SCOPE>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7D_t>>::build(&*children[6], w);
	return TYPE(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5, v6);
}

parlex::detail::acceptor const & plc::TYPE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().TYPE));
	return result;
}

TYPE_CONSTRAINT::tail_t TYPE_CONSTRAINT::tail_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2C_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<val<TYPE_CONSTRAINT_ELEMENT>>::build(&*children[3], w);
	return tail_t(v0, v1, v2, v3);
}

TYPE_CONSTRAINT TYPE_CONSTRAINT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<TYPE_CONSTRAINT_SPECIFICATION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<TYPE_CONSTRAINT_ELEMENT>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<tail_t>>::build(&*children[3], w);
	return TYPE_CONSTRAINT(n.document_position, n.consumed_character_count, v0, v1, v2, v3);
}

parlex::detail::acceptor const & plc::TYPE_CONSTRAINT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().TYPE_CONSTRAINT));
	return result;
}

TYPE_CONSTRAINT_DECLARATION::args_t TYPE_CONSTRAINT_DECLARATION::args_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<PARENTHETICAL_INVOCATION>>::build(&*children[1], w);
	return args_t(v0, v1);
}

TYPE_CONSTRAINT_DECLARATION TYPE_CONSTRAINT_DECLARATION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<IDENTIFIER_SPECIFICATION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::optional<args_t>>::build(&*children[1], w);
	return TYPE_CONSTRAINT_DECLARATION(n.document_position, n.consumed_character_count, v0, v1);
}

parlex::detail::acceptor const & plc::TYPE_CONSTRAINT_DECLARATION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().TYPE_CONSTRAINT_DECLARATION));
	return result;
}


TYPE_CONSTRAINT_ELEMENT TYPE_CONSTRAINT_ELEMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return TYPE_CONSTRAINT_ELEMENT(parlex::detail::document::element<TYPE_CONSTRAINT_ELEMENT_base>::build(b, w));
}

parlex::detail::acceptor const & plc::TYPE_CONSTRAINT_ELEMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().TYPE_CONSTRAINT_ELEMENT));
	return result;
}

TYPE_CONSTRAINT_SPECIFICATION::attributes_t TYPE_CONSTRAINT_SPECIFICATION::attributes_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<ATTRIBUTE>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	return attributes_t(v0, v1);
}

TYPE_CONSTRAINT_SPECIFICATION::visibility_t TYPE_CONSTRAINT_SPECIFICATION::visibility_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<VISIBILITY_MODIFIER>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	return visibility_t(v0, v1);
}

TYPE_CONSTRAINT_SPECIFICATION::static__t TYPE_CONSTRAINT_SPECIFICATION::static__t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_static_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	return static__t(v0, v1);
}

TYPE_CONSTRAINT_SPECIFICATION::extern__t TYPE_CONSTRAINT_SPECIFICATION::extern__t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_extern_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	return extern__t(v0, v1);
}

TYPE_CONSTRAINT_SPECIFICATION TYPE_CONSTRAINT_SPECIFICATION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::optional<val<XML_DOC_STRING>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<attributes_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<visibility_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::optional<static__t>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::optional<extern__t>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<std::variant<
		val<TYPE_DEREFERENCE>,
		val<VOLATILE_TYPE_DEREFERENCE>,
		val<IMPLICIT_TYPE_DEREFERENCE>,
		val<VOLATILE_IMPLICIT_TYPE_DEREFERENCE>
	>>::build(&*children[5], w);
	return TYPE_CONSTRAINT_SPECIFICATION(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5);
}

parlex::detail::acceptor const & plc::TYPE_CONSTRAINT_SPECIFICATION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().TYPE_CONSTRAINT_SPECIFICATION));
	return result;
}

TYPE_DEREFERENCE TYPE_DEREFERENCE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3C_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3E_t>>::build(&*children[4], w);
	return TYPE_DEREFERENCE(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::TYPE_DEREFERENCE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().TYPE_DEREFERENCE));
	return result;
}

TYPE_INVOCATION::arguments_t TYPE_INVOCATION::arguments_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<STANDARD_ARGUMENTS>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	return arguments_t(v0, v1);
}

TYPE_INVOCATION TYPE_INVOCATION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3C_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<arguments_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3E_t>>::build(&*children[3], w);
	return TYPE_INVOCATION(n.document_position, n.consumed_character_count, v0, v1, v2, v3);
}

parlex::detail::acceptor const & plc::TYPE_INVOCATION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().TYPE_INVOCATION));
	return result;
}

TYPE_SCOPE::field_2_t TYPE_SCOPE::field_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<TYPE_STATEMENT>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	return field_2_t(v0, v1);
}

TYPE_SCOPE TYPE_SCOPE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<field_2_t>>::build(&*children[1], w);
	return TYPE_SCOPE(n.document_position, n.consumed_character_count, v0, v1);
}

parlex::detail::acceptor const & plc::TYPE_SCOPE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().TYPE_SCOPE));
	return result;
}

TYPE_SCOPE_ASSIGNMENT::field_1_t TYPE_SCOPE_ASSIGNMENT::field_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<MEMBER_OFFSET>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	return field_1_t(v0, v1);
}

TYPE_SCOPE_ASSIGNMENT TYPE_SCOPE_ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<IDENTIFIER_SPECIFICATION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<field_1_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<val<TYPE_SCOPE_ASSIGNMENT_NODE>>::build(&*children[3], w);
	return TYPE_SCOPE_ASSIGNMENT(n.document_position, n.consumed_character_count, v0, v1, v2, v3);
}

parlex::detail::acceptor const & plc::TYPE_SCOPE_ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().TYPE_SCOPE_ASSIGNMENT));
	return result;
}

TYPE_SCOPE_ASSIGNMENT_NODE::field_2_t::field_1_t TYPE_SCOPE_ASSIGNMENT_NODE::field_2_t::field_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<MEMBER_OFFSET>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	return field_1_t(v0, v1);
}

TYPE_SCOPE_ASSIGNMENT_NODE::field_2_t TYPE_SCOPE_ASSIGNMENT_NODE::field_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<IDENTIFIER_SPECIFICATION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::optional<field_1_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<val<TYPE_SCOPE_ASSIGNMENT_NODE>>::build(&*children[3], w);
	return field_2_t(v0, v1, v2, v3);
}

TYPE_SCOPE_ASSIGNMENT_NODE TYPE_SCOPE_ASSIGNMENT_NODE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x860x90_t>,
		parlex::detail::document::text<literal_0x3C0x2D_t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		val<EXPRESSION>,
		field_2_t
	>>::build(&*children[2], w);
	return TYPE_SCOPE_ASSIGNMENT_NODE(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::TYPE_SCOPE_ASSIGNMENT_NODE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().TYPE_SCOPE_ASSIGNMENT_NODE));
	return result;
}

TYPE_SCOPE_TYPE_CONSTRAINT::tail_t TYPE_SCOPE_TYPE_CONSTRAINT::tail_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2C_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<val<TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT>>::build(&*children[3], w);
	return tail_t(v0, v1, v2, v3);
}

TYPE_SCOPE_TYPE_CONSTRAINT TYPE_SCOPE_TYPE_CONSTRAINT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<TYPE_CONSTRAINT_SPECIFICATION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<tail_t>>::build(&*children[3], w);
	return TYPE_SCOPE_TYPE_CONSTRAINT(n.document_position, n.consumed_character_count, v0, v1, v2, v3);
}

parlex::detail::acceptor const & plc::TYPE_SCOPE_TYPE_CONSTRAINT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().TYPE_SCOPE_TYPE_CONSTRAINT));
	return result;
}

TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION::args_t TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION::args_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<PARENTHETICAL_INVOCATION>>::build(&*children[1], w);
	return args_t(v0, v1);
}

TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION::field_1_t TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION::field_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<MEMBER_OFFSET>>::build(&*children[1], w);
	return field_1_t(v0, v1);
}

TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<IDENTIFIER_SPECIFICATION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::optional<args_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<field_1_t>>::build(&*children[2], w);
	return TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION));
	return result;
}


TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT(parlex::detail::document::element<TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT_base>::build(b, w));
}

parlex::detail::acceptor const & plc::TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT));
	return result;
}

TYPE_STATEMENT::field_1_t1 TYPE_STATEMENT::field_1_t1::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<VISIBILITY_MODIFIER>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3A_t>>::build(&*children[2], w);
	return field_1_t1(v0, v1, v2);
}

TYPE_STATEMENT TYPE_STATEMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		field_1_t1,
		val<TYPE_SCOPE_TYPE_CONSTRAINT>,
		val<STATEMENT>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3B_t>>::build(&*children[1], w);
	return TYPE_STATEMENT(n.document_position, n.consumed_character_count, v0, v1);
}

parlex::detail::acceptor const & plc::TYPE_STATEMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().TYPE_STATEMENT));
	return result;
}


UNARY_ARITHMETIC_OP UNARY_ARITHMETIC_OP::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return UNARY_ARITHMETIC_OP(parlex::detail::document::element<UNARY_ARITHMETIC_OP_base>::build(b, w));
}

parlex::detail::acceptor const & plc::UNARY_ARITHMETIC_OP::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().UNARY_ARITHMETIC_OP));
	return result;
}


UNARY_LOGICAL_OP UNARY_LOGICAL_OP::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return UNARY_LOGICAL_OP(parlex::detail::document::element<UNARY_LOGICAL_OP_base>::build(b, w));
}

parlex::detail::acceptor const & plc::UNARY_LOGICAL_OP::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().UNARY_LOGICAL_OP));
	return result;
}


UNARY_OP UNARY_OP::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return UNARY_OP(parlex::detail::document::element<UNARY_OP_base>::build(b, w));
}

parlex::detail::acceptor const & plc::UNARY_OP::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().UNARY_OP));
	return result;
}

UNION UNION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0xE20x880xAA_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return UNION(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::UNION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().UNION));
	return result;
}

UNION_ASSIGNMENT UNION_ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0xE20x880xAA_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[5], w);
	return UNION_ASSIGNMENT(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5);
}

parlex::detail::acceptor const & plc::UNION_ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().UNION_ASSIGNMENT));
	return result;
}

UNIT_DIVISION UNIT_DIVISION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<DIMENSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2F_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<DIMENSION>>::build(&*children[2], w);
	return UNIT_DIVISION(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::UNIT_DIVISION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().UNIT_DIVISION));
	return result;
}

UNIT_EXPONENTIATION UNIT_EXPONENTIATION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<DIMENSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5E_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<NON_FRACTIONAL>>::build(&*children[2], w);
	return UNIT_EXPONENTIATION(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::UNIT_EXPONENTIATION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().UNIT_EXPONENTIATION));
	return result;
}

UNIT_MULTIPLICATION UNIT_MULTIPLICATION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<DIMENSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2A_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<DIMENSION>>::build(&*children[2], w);
	return UNIT_MULTIPLICATION(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::UNIT_MULTIPLICATION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().UNIT_MULTIPLICATION));
	return result;
}

UPCASTS UPCASTS::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_upcasts_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return UPCASTS(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::UPCASTS::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().UPCASTS));
	return result;
}

USING USING::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_using_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x28_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<parlex::detail::document::text<literal_0x29_t>>::build(&*children[6], w);
	auto v7 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[7], w);
	auto v8 = parlex::detail::document::element<val<BLOCK>>::build(&*children[8], w);
	return USING(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5, v6, v7, v8);
}

parlex::detail::acceptor const & plc::USING::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().USING));
	return result;
}

VECTOR_NORM VECTOR_NORM::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7C0x7C_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7C0x7C_t>>::build(&*children[4], w);
	return VECTOR_NORM(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::VECTOR_NORM::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().VECTOR_NORM));
	return result;
}


VISIBILITY_MODIFIER VISIBILITY_MODIFIER::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return VISIBILITY_MODIFIER(parlex::detail::document::element<VISIBILITY_MODIFIER_base>::build(b, w));
}

parlex::detail::acceptor const & plc::VISIBILITY_MODIFIER::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().VISIBILITY_MODIFIER));
	return result;
}

VOLATILE_IMPLICIT_TYPE_DEREFERENCE VOLATILE_IMPLICIT_TYPE_DEREFERENCE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3C_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_volatile_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3E_t>>::build(&*children[4], w);
	return VOLATILE_IMPLICIT_TYPE_DEREFERENCE(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::VOLATILE_IMPLICIT_TYPE_DEREFERENCE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().VOLATILE_IMPLICIT_TYPE_DEREFERENCE));
	return result;
}

VOLATILE_TYPE_DEREFERENCE VOLATILE_TYPE_DEREFERENCE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3C_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_volatile_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3E_t>>::build(&*children[6], w);
	return VOLATILE_TYPE_DEREFERENCE(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5, v6);
}

parlex::detail::acceptor const & plc::VOLATILE_TYPE_DEREFERENCE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().VOLATILE_TYPE_DEREFERENCE));
	return result;
}

WHOLE_NUMBER WHOLE_NUMBER::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<parlex::detail::document::text<literal_0_t>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<NON_ZERO_DECIMAL_DIGIT>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<parlex::detail::document::text<parlex::detail::decimal_digit_t>>>::build(&*children[2], w);
	return WHOLE_NUMBER(n.document_position, n.consumed_character_count, v0, v1, v2);
}

parlex::detail::acceptor const & plc::WHOLE_NUMBER::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().WHOLE_NUMBER));
	return result;
}

WRITE_LOCK WRITE_LOCK::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_write_lock_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<PARENTHETICAL>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return WRITE_LOCK(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::WRITE_LOCK::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().WRITE_LOCK));
	return result;
}

WS WS::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::white_space_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<parlex::detail::document::text<parlex::detail::white_space_t>>>::build(&*children[1], w);
	return WS(n.document_position, n.consumed_character_count, v0, v1);
}

parlex::detail::acceptor const & plc::WS::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().WS));
	return result;
}

XML_DOC_STRING XML_DOC_STRING::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x600x600x60_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<XML_DOC_STRING_INTERIOR>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x600x600x60_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	return XML_DOC_STRING(n.document_position, n.consumed_character_count, v0, v1, v2, v3);
}

parlex::detail::acceptor const & plc::XML_DOC_STRING::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().XML_DOC_STRING));
	return result;
}


XML_DOC_STRING_INTERIOR XML_DOC_STRING_INTERIOR::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return XML_DOC_STRING_INTERIOR(parlex::detail::document::element<XML_DOC_STRING_INTERIOR_base>::build(b, w));
}

XML_DOC_STRING_INTERIOR_t XML_DOC_STRING_INTERIOR_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x60_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<XML_DOC_STRING_INTERIOR>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x60_t>>::build(&*children[2], w);
	return XML_DOC_STRING_INTERIOR_t(v0, v1, v2);
}

parlex::detail::acceptor const & plc::XML_DOC_STRING_INTERIOR::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().XML_DOC_STRING_INTERIOR));
	return result;
}

XOR XOR::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x8A0x95_t>,
		parlex::detail::document::text<literal_xor_t>
	>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return XOR(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}

parlex::detail::acceptor const & plc::XOR::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().XOR));
	return result;
}

XOR_ASSIGNMENT XOR_ASSIGNMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x8A0x95_t>,
		parlex::detail::document::text<literal_xor_t>
	>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[5], w);
	return XOR_ASSIGNMENT(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4, v5);
}

parlex::detail::acceptor const & plc::XOR_ASSIGNMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().XOR_ASSIGNMENT));
	return result;
}

static parlex::production ADDITION() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"+");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("ADDITION", {v0, v2, v3, v5, v6});
	return parlex::production("ADDITION",v7, parlex::associativity::ANY);
}

static parlex::production ADDITION_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"+<-");
	parlex::literal const v4(U"+←");
	parlex::literal const v5(U"⥆");
	parlex::choice const v6({v3, v4, v5});
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10("ADDITION_ASSIGNMENT", {v0, v2, v6, v8, v9});
	return parlex::production("ADDITION_ASSIGNMENT",v10);
}

static parlex::production ADD_SUB() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"±");
	parlex::literal const v4(U"+-");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("ADD_SUB", {v0, v2, v5, v7, v8});
	return parlex::production("ADD_SUB",v9, parlex::associativity::LEFT);
}

static parlex::production ADD_SUB_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"±");
	parlex::literal const v4(U"+-");
	parlex::choice const v5({v3, v4});
	parlex::literal const v6(U"<-");
	parlex::literal const v7(U"←");
	parlex::choice const v8({v6, v7});
	parlex::reference const v9("IC");
	parlex::repetition const v10(v9);
	parlex::reference const v11("EXPRESSION");
	parlex::sequence const v12("ADD_SUB_ASSIGNMENT", {v0, v2, v5, v8, v10, v11});
	return parlex::production("ADD_SUB_ASSIGNMENT",v12);
}

static parlex::production ALL() {
	parlex::literal const v0(U"∀");
	parlex::literal const v1(U"all");
	parlex::choice const v2({v0, v1});
	parlex::reference const v3("IC");
	parlex::repetition const v4(v3);
	parlex::reference const v5("EXPRESSION");
	parlex::sequence const v6("ALL", {v2, v4, v5});
	return parlex::production("ALL",v6);
}

static parlex::production ALLOCATION() {
	parlex::literal const v0(U"alloc");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("PARENTHETICAL_INVOCATION");
	parlex::sequence const v4("ALLOCATION", {v0, v2, v3});
	return parlex::production("ALLOCATION",v4);
}

static parlex::production AND() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"∧");
	parlex::literal const v4(U"and");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("AND", {v0, v2, v5, v7, v8});
	return parlex::production("AND",v9, parlex::associativity::ANY, parlex::filter_function(), {"IFF", "IMPLICATION", "OR", "XOR", });
}

static parlex::production AND_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"∧");
	parlex::literal const v4(U"and");
	parlex::choice const v5({v3, v4});
	parlex::literal const v6(U"<-");
	parlex::literal const v7(U"←");
	parlex::choice const v8({v6, v7});
	parlex::reference const v9("IC");
	parlex::repetition const v10(v9);
	parlex::reference const v11("EXPRESSION");
	parlex::sequence const v12("AND_ASSIGNMENT", {v0, v2, v5, v8, v10, v11});
	return parlex::production("AND_ASSIGNMENT",v12);
}

static parlex::production ARGUMENT_PACK() {
	parlex::reference const v0("expression", "EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"...");
	parlex::sequence const v4("ARGUMENT_PACK", {v0, v2, v3});
	return parlex::production("ARGUMENT_PACK",v4);
}

static parlex::production ARRAY() {
	parlex::literal const v0(U"[");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("expression", "EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U",");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("expression", "EXPRESSION");
	parlex::sequence const v10({v5, v6, v8, v9});
	parlex::repetition const v11(v10);
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::sequence const v14({v3, v11, v13});
	parlex::optional const v15(v14);
	parlex::literal const v16(U"]");
	parlex::sequence const v17("ARRAY", {v0, v2, v15, v16});
	return parlex::production("ARRAY",v17);
}

static parlex::production ARRAY_ARGUMENTS() {
	parlex::reference const v0("array_indexer", "ARRAY_INDEXER");
	parlex::optional const v1("head", v0);
	parlex::reference const v2("IC");
	parlex::repetition const v3("ic", v2);
	parlex::literal const v4(U",");
	parlex::reference const v5("IC");
	parlex::repetition const v6("ic", v5);
	parlex::reference const v7("array_indexer", "ARRAY_INDEXER");
	parlex::sequence const v8({v6, v7});
	parlex::optional const v9(v8);
	parlex::sequence const v10({v3, v4, v9});
	parlex::repetition const v11("tail", v10);
	parlex::sequence const v12("ARRAY_ARGUMENTS", {v1, v11});
	return parlex::production("ARRAY_ARGUMENTS",v12);
}

static parlex::production ARRAY_INDEXER() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("ARGUMENT_PACK");
	parlex::reference const v2("SLICE");
	parlex::choice const v3("ARRAY_INDEXER", {v0, v1, v2});
	return parlex::production("ARRAY_INDEXER",v3);
}

static parlex::production ARRAY_INVOCATION() {
	parlex::literal const v0(U"[");
	parlex::reference const v1("IC");
	parlex::repetition const v2("ic", v1);
	parlex::reference const v3("array_arguments", "ARRAY_ARGUMENTS");
	parlex::reference const v4("IC");
	parlex::repetition const v5("ic", v4);
	parlex::sequence const v6({v3, v5});
	parlex::optional const v7("arguments", v6);
	parlex::literal const v8(U"]");
	parlex::sequence const v9("ARRAY_INVOCATION", {v0, v2, v7, v8});
	return parlex::production("ARRAY_INVOCATION",v9);
}

static parlex::production ASM_EXPRESSION() {
	parlex::reference const v0("ASM_IDENTIFIER");
	parlex::reference const v1("ASM_PTR_ARITHMETIC_ATT");
	parlex::reference const v2("ASM_PTR_ARITHMETIC_INTEL");
	parlex::reference const v3("NON_FRACTIONAL");
	parlex::choice const v4("ASM_EXPRESSION", {v0, v1, v2, v3});
	return parlex::production("ASM_EXPRESSION",v4);
}

static parlex::production ASM_FUNCTION() {
	parlex::literal const v0(U"(");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("parameter", "PARAMETER");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U",");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("parameter", "PARAMETER");
	parlex::sequence const v10({v5, v6, v8, v9});
	parlex::repetition const v11(v10);
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::sequence const v14({v3, v11, v13});
	parlex::optional const v15(v14);
	parlex::literal const v16(U")");
	parlex::reference const v17("IC");
	parlex::repetition const v18(v17);
	parlex::sequence const v19({v0, v2, v15, v16, v18});
	parlex::optional const v20(v19);
	parlex::reference const v21("FUNCTION_MODIFIER_0");
	parlex::optional const v22(v21);
	parlex::literal const v23(U"asm");
	parlex::reference const v24("IC");
	parlex::repetition const v25(v24);
	parlex::literal const v26(U"{");
	parlex::reference const v27("ASM_SCOPE");
	parlex::literal const v28(U"}");
	parlex::sequence const v29("ASM_FUNCTION", {v20, v22, v23, v25, v26, v27, v28});
	return parlex::production("ASM_FUNCTION",v29);
}

static parlex::production ASM_IDENTIFIER() {
	parlex::literal const v0(U"%");
	parlex::optional const v1(v0);
	parlex::reference const v2("IDENTIFIER");
	parlex::sequence const v3("ASM_IDENTIFIER", {v1, v2});
	return parlex::production("ASM_IDENTIFIER",v3);
}

static parlex::production ASM_OP() {
	parlex::reference const v0("lowercase_letter");
	parlex::reference const v1("lowercase_letter");
	parlex::repetition const v2(v1);
	parlex::sequence const v3("ASM_OP", {v0, v2});
	return parlex::production("ASM_OP",v3);
}

static parlex::production ASM_PTR_ARITHMETIC_ATT() {
	parlex::reference const v0("ASM_IDENTIFIER");
	parlex::literal const v1(U":");
	parlex::reference const v2("NON_FRACTIONAL");
	parlex::sequence const v3({v0, v1, v2});
	parlex::reference const v4("ASM_IDENTIFIER");
	parlex::literal const v5(U":");
	parlex::reference const v6("NON_FRACTIONAL");
	parlex::reference const v7("ASM_PTR_ARITHMETIC_ATT_REG");
	parlex::sequence const v8({v4, v5, v6, v7});
	parlex::reference const v9("NON_FRACTIONAL");
	parlex::reference const v10("ASM_PTR_ARITHMETIC_ATT_REG");
	parlex::sequence const v11({v9, v10});
	parlex::choice const v12("ASM_PTR_ARITHMETIC_ATT", {v3, v8, v11});
	return parlex::production("ASM_PTR_ARITHMETIC_ATT",v12);
}

static parlex::production ASM_PTR_ARITHMETIC_ATT_REG() {
	parlex::literal const v0(U"(");
	parlex::reference const v1("asm_identifier", "ASM_IDENTIFIER");
	parlex::optional const v2(v1);
	parlex::literal const v3(U",");
	parlex::reference const v4("asm_identifier", "ASM_IDENTIFIER");
	parlex::literal const v5(U",");
	parlex::reference const v6("NON_NEG_NON_FRACTIONAL");
	parlex::sequence const v7({v5, v6});
	parlex::optional const v8(v7);
	parlex::sequence const v9({v3, v4, v8});
	parlex::optional const v10(v9);
	parlex::literal const v11(U")");
	parlex::sequence const v12("ASM_PTR_ARITHMETIC_ATT_REG", {v0, v2, v10, v11});
	return parlex::production("ASM_PTR_ARITHMETIC_ATT_REG",v12);
}

static parlex::production ASM_PTR_ARITHMETIC_INTEL() {
	parlex::literal const v0(U"BYTE");
	parlex::literal const v1(U"WORD");
	parlex::literal const v2(U"DWORD");
	parlex::literal const v3(U"QWORD");
	parlex::choice const v4({v0, v1, v2, v3});
	parlex::literal const v5(U" PTR");
	parlex::sequence const v6({v4, v5});
	parlex::optional const v7(v6);
	parlex::literal const v8(U"[");
	parlex::reference const v9("ASM_IDENTIFIER");
	parlex::literal const v10(U":");
	parlex::sequence const v11({v9, v10});
	parlex::optional const v12(v11);
	parlex::reference const v13("ASM_IDENTIFIER");
	parlex::literal const v14(U"+");
	parlex::reference const v15("ASM_IDENTIFIER");
	parlex::literal const v16(U"*");
	parlex::reference const v17("NON_NEG_NON_FRACTIONAL");
	parlex::sequence const v18({v16, v17});
	parlex::optional const v19(v18);
	parlex::sequence const v20({v14, v15, v19});
	parlex::optional const v21(v20);
	parlex::literal const v22(U"+");
	parlex::literal const v23(U"-");
	parlex::choice const v24({v22, v23});
	parlex::reference const v25("NON_NEG_INTEGER");
	parlex::sequence const v26({v24, v25});
	parlex::optional const v27(v26);
	parlex::literal const v28(U"]");
	parlex::sequence const v29("ASM_PTR_ARITHMETIC_INTEL", {v7, v8, v12, v13, v21, v27, v28});
	return parlex::production("ASM_PTR_ARITHMETIC_INTEL",v29);
}

static parlex::production ASM_SCOPE() {
	parlex::reference const v0("IC");
	parlex::reference const v1("ASM_STATEMENT");
	parlex::choice const v2({v0, v1});
	parlex::repetition const v3("ASM_SCOPE", v2);
	return parlex::production("ASM_SCOPE",v3);
}

static parlex::production ASM_STATEMENT() {
	parlex::reference const v0("ASM_OP");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("ASM_EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U",");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("ASM_EXPRESSION");
	parlex::sequence const v10({v8, v9});
	parlex::optional const v11(v10);
	parlex::sequence const v12({v5, v6, v11});
	parlex::repetition const v13(v12);
	parlex::sequence const v14({v2, v3, v13});
	parlex::optional const v15(v14);
	parlex::reference const v16("IC");
	parlex::repetition const v17(v16);
	parlex::literal const v18(U"\n");
	parlex::sequence const v19("ASM_STATEMENT", {v0, v15, v17, v18});
	return parlex::production("ASM_STATEMENT",v19);
}

static parlex::production ASSIGNMENT() {
	parlex::reference const v0("identifier_specification", "IDENTIFIER_SPECIFICATION");
	parlex::reference const v1("IC");
	parlex::repetition const v2("ic", v1);
	parlex::reference const v3("assignment_node", "ASSIGNMENT_NODE");
	parlex::sequence const v4("ASSIGNMENT", {v0, v2, v3});
	return parlex::production("ASSIGNMENT",v4, parlex::associativity::NONE, parlex::filter_function(), {"EXPRESSION", "LESSER", });
}

static parlex::production ASSIGNMENT_NODE() {
	parlex::literal const v0(U"←");
	parlex::literal const v1(U"<-");
	parlex::choice const v2({v0, v1});
	parlex::reference const v3("IC");
	parlex::repetition const v4("ic", v3);
	parlex::reference const v5("expression", "EXPRESSION");
	parlex::reference const v6("identifier_specification", "IDENTIFIER_SPECIFICATION");
	parlex::reference const v7("IC");
	parlex::repetition const v8("ic", v7);
	parlex::reference const v9("next", "ASSIGNMENT_NODE");
	parlex::sequence const v10({v6, v8, v9});
	parlex::choice const v11("value", {v5, v10});
	parlex::sequence const v12("ASSIGNMENT_NODE", {v2, v4, v11});
	return parlex::production("ASSIGNMENT_NODE",v12);
}

static parlex::production ATTRIBUTE() {
	parlex::literal const v0(U"@");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("expression", "EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U"@");
	parlex::sequence const v7("ATTRIBUTE", {v0, v2, v3, v5, v6});
	return parlex::production("ATTRIBUTE",v7);
}

static parlex::production BIJECTION() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"↔");
	parlex::literal const v4(U"<->");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("BIJECTION", {v0, v2, v5, v7, v8});
	return parlex::production("BIJECTION",v9, parlex::associativity::ANY);
}

static parlex::production BINARY_ARITHMETIC_OP() {
	parlex::reference const v0("ADD_SUB");
	parlex::reference const v1("ADDITION");
	parlex::reference const v2("DIVISION");
	parlex::reference const v3("EXPONENTIATION");
	parlex::reference const v4("INTEGER_DIVISION");
	parlex::reference const v5("MODULATION");
	parlex::reference const v6("MULTIPLICATIVE_OP");
	parlex::reference const v7("SHIFTL");
	parlex::reference const v8("SHIFTR");
	parlex::reference const v9("SUBTRACTION");
	parlex::choice const v10("BINARY_ARITHMETIC_OP", {v0, v1, v2, v3, v4, v5, v6, v7, v8, v9});
	return parlex::production("BINARY_ARITHMETIC_OP",v10);
}

static parlex::production BINARY_COLLECTION_OP() {
	parlex::reference const v0("BIJECTION");
	parlex::reference const v1("INTERSECTION");
	parlex::reference const v2("SYMMETRIC_DIFFERENCE");
	parlex::reference const v3("UNION");
	parlex::choice const v4("BINARY_COLLECTION_OP", {v0, v1, v2, v3});
	return parlex::production("BINARY_COLLECTION_OP",v4);
}

static parlex::production BINARY_LOGICAL_OP() {
	parlex::reference const v0("AND");
	parlex::reference const v1("IFF");
	parlex::reference const v2("IMPLICATION");
	parlex::reference const v3("MAPS_TO");
	parlex::reference const v4("NAND");
	parlex::reference const v5("NOR");
	parlex::reference const v6("OR");
	parlex::reference const v7("XOR");
	parlex::choice const v8("BINARY_LOGICAL_OP", {v0, v1, v2, v3, v4, v5, v6, v7});
	return parlex::production("BINARY_LOGICAL_OP",v8);
}

static parlex::production BINARY_OP() {
	parlex::reference const v0("BINARY_ARITHMETIC_OP");
	parlex::reference const v1("BINARY_COLLECTION_OP");
	parlex::reference const v2("BINARY_LOGICAL_OP");
	parlex::reference const v3("BITWISE_OP");
	parlex::reference const v4("CONSTRUCTIVE_OP");
	parlex::reference const v5("RELATIONAL_OP");
	parlex::choice const v6("BINARY_OP", {v0, v1, v2, v3, v4, v5});
	return parlex::production("BINARY_OP",v6);
}

static parlex::production BITWISE_OP() {
	parlex::reference const v0("BIT_AND");
	parlex::reference const v1("BIT_OR");
	parlex::reference const v2("BIT_XOR");
	parlex::choice const v3("BITWISE_OP", {v0, v1, v2});
	return parlex::production("BITWISE_OP",v3);
}

static parlex::production BIT_AND() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"&&");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("BIT_AND", {v0, v2, v3, v5, v6});
	return parlex::production("BIT_AND",v7, parlex::associativity::ANY);
}

static parlex::production BIT_AND_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"&&");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10("BIT_AND_ASSIGNMENT", {v0, v2, v3, v6, v8, v9});
	return parlex::production("BIT_AND_ASSIGNMENT",v10);
}

static parlex::production BIT_NOT() {
	parlex::literal const v0(U"~~");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::sequence const v4("BIT_NOT", {v0, v2, v3});
	return parlex::production("BIT_NOT",v4);
}

static parlex::production BIT_NOT_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"~~");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::sequence const v7("BIT_NOT_ASSIGNMENT", {v0, v2, v3, v6});
	return parlex::production("BIT_NOT_ASSIGNMENT",v7);
}

static parlex::production BIT_OR() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"||");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("BIT_OR", {v0, v2, v3, v5, v6});
	return parlex::production("BIT_OR",v7, parlex::associativity::ANY);
}

static parlex::production BIT_OR_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"||");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10("BIT_OR_ASSIGNMENT", {v0, v2, v3, v6, v8, v9});
	return parlex::production("BIT_OR_ASSIGNMENT",v10);
}

static parlex::production BIT_XOR() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"^^");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("BIT_XOR", {v0, v2, v3, v5, v6});
	return parlex::production("BIT_XOR",v7, parlex::associativity::ANY);
}

static parlex::production BIT_XOR_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"^^");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10("BIT_XOR_ASSIGNMENT", {v0, v2, v3, v6, v8, v9});
	return parlex::production("BIT_XOR_ASSIGNMENT",v10);
}

static parlex::production BLOCK() {
	parlex::literal const v0(U"{");
	parlex::reference const v1("STATEMENT_SCOPE");
	parlex::literal const v2(U"}");
	parlex::sequence const v3("BLOCK", {v0, v1, v2});
	return parlex::production("BLOCK",v3);
}

static parlex::production BOOL() {
	parlex::literal const v0(U"true");
	parlex::literal const v1(U"false");
	parlex::choice const v2("BOOL", {v0, v1});
	return parlex::production("BOOL",v2);
}

static parlex::production BREAK() {
	parlex::literal const v0(U"break");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"[");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("expression", "EXPRESSION");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::literal const v9(U"]");
	parlex::sequence const v10({v2, v3, v5, v6, v8, v9});
	parlex::reference const v11("IC");
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::reference const v14("identifier", "IDENTIFIER");
	parlex::sequence const v15({v11, v13, v14});
	parlex::choice const v16({v10, v15});
	parlex::optional const v17(v16);
	parlex::sequence const v18("BREAK", {v0, v17});
	return parlex::production("BREAK",v18);
}

static parlex::production CARDINALITY() {
	parlex::literal const v0(U"#");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::sequence const v4("CARDINALITY", {v0, v2, v3});
	return parlex::production("CARDINALITY",v4, parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", });
}

static parlex::production CAST() {
	parlex::reference const v0("PARENTHETICAL");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::sequence const v4("CAST", {v0, v2, v3});
	return parlex::production("CAST",v4, parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", });
}

static parlex::production CASTS() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"casts");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("CASTS", {v0, v2, v3, v5, v6});
	return parlex::production("CASTS",v7);
}

static parlex::production CEILING() {
	parlex::literal const v0(U"⌈");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U"⌉");
	parlex::sequence const v7({v0, v2, v3, v5, v6});
	parlex::literal const v8(U"|\'");
	parlex::reference const v9("IC");
	parlex::repetition const v10(v9);
	parlex::reference const v11("EXPRESSION");
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::literal const v14(U"\'|");
	parlex::sequence const v15({v8, v10, v11, v13, v14});
	parlex::choice const v16("CEILING", {v7, v15});
	return parlex::production("CEILING",v16);
}

static parlex::production COMMENT() {
	parlex::literal const v0(U"/*");
	parlex::reference const v1("all");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"*/");
	parlex::sequence const v4("COMMENT", {v0, v2, v3});
	return parlex::production("COMMENT",v4, parlex::associativity::NONE, parlex::shortest());
}

static parlex::production COMPLEMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"ᶜ");
	parlex::sequence const v4("COMPLEMENT", {v0, v2, v3});
	return parlex::production("COMPLEMENT",v4, parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", });
}

static parlex::production COMPOSITION() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"∘");
	parlex::literal const v4(U"_o_");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("COMPOSITION", {v0, v2, v5, v7, v8});
	return parlex::production("COMPOSITION",v9, parlex::associativity::ANY);
}

static parlex::production COMPOSITION_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"∘");
	parlex::literal const v4(U"_o_");
	parlex::choice const v5({v3, v4});
	parlex::literal const v6(U"<-");
	parlex::literal const v7(U"←");
	parlex::choice const v8({v6, v7});
	parlex::reference const v9("IC");
	parlex::repetition const v10(v9);
	parlex::reference const v11("EXPRESSION");
	parlex::sequence const v12("COMPOSITION_ASSIGNMENT", {v0, v2, v5, v8, v10, v11});
	return parlex::production("COMPOSITION_ASSIGNMENT",v12);
}

static parlex::production COMPOUND() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"|");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("COMPOUND", {v0, v2, v3, v5, v6});
	return parlex::production("COMPOUND",v7, parlex::associativity::LEFT);
}

static parlex::production COMPOUND_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"|");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10("COMPOUND_ASSIGNMENT", {v0, v2, v3, v6, v8, v9});
	return parlex::production("COMPOUND_ASSIGNMENT",v10);
}

static parlex::production CONDITIONAL() {
	parlex::reference const v0("condition", "EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"\?");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("true_case", "EXPRESSION");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::literal const v9(U":");
	parlex::reference const v10("IC");
	parlex::repetition const v11(v10);
	parlex::reference const v12("false_case", "EXPRESSION");
	parlex::sequence const v13("CONDITIONAL", {v0, v2, v3, v5, v6, v8, v9, v11, v12});
	return parlex::production("CONDITIONAL",v13, parlex::associativity::RIGHT);
}

static parlex::production CONSTRUCTIVE_OP() {
	parlex::reference const v0("COMPOSITION");
	parlex::reference const v1("COMPOUND");
	parlex::reference const v2("PREPEND");
	parlex::reference const v3("NULL_COALESCE");
	parlex::choice const v4("CONSTRUCTIVE_OP", {v0, v1, v2, v3});
	return parlex::production("CONSTRUCTIVE_OP",v4);
}

static parlex::production CONTINUE() {
	parlex::literal const v0(U"continue");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"[");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("expression", "EXPRESSION");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::literal const v9(U"]");
	parlex::sequence const v10({v2, v3, v5, v6, v8, v9});
	parlex::reference const v11("IC");
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::reference const v14("identifier", "IDENTIFIER");
	parlex::sequence const v15({v11, v13, v14});
	parlex::choice const v16({v10, v15});
	parlex::optional const v17(v16);
	parlex::sequence const v18("CONTINUE", {v0, v17});
	return parlex::production("CONTINUE",v18);
}

static parlex::production CROSS_PRODUCT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"×");
	parlex::literal const v4(U"_x_");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("CROSS_PRODUCT", {v0, v2, v5, v7, v8});
	return parlex::production("CROSS_PRODUCT",v9, parlex::associativity::LEFT, parlex::filter_function(), {"DOT_PRODUCT", });
}

static parlex::production CROSS_PRODUCT_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"×");
	parlex::literal const v4(U"_x_");
	parlex::choice const v5({v3, v4});
	parlex::literal const v6(U"<-");
	parlex::literal const v7(U"←");
	parlex::choice const v8({v6, v7});
	parlex::reference const v9("IC");
	parlex::repetition const v10(v9);
	parlex::reference const v11("EXPRESSION");
	parlex::sequence const v12("CROSS_PRODUCT_ASSIGNMENT", {v0, v2, v5, v8, v10, v11});
	return parlex::production("CROSS_PRODUCT_ASSIGNMENT",v12);
}

static parlex::production DATE() {
	parlex::reference const v0("DATE_YEAR_MONTH_DAY");
	parlex::reference const v1("DATE_YEAR_DAY");
	parlex::choice const v2("DATE", {v0, v1});
	return parlex::production("DATE",v2);
}

static parlex::production DATE_TIME() {
	parlex::reference const v0("DATE");
	parlex::literal const v1(U"T");
	parlex::reference const v2("TIME");
	parlex::sequence const v3("DATE_TIME", {v0, v1, v2});
	return parlex::production("DATE_TIME",v3);
}

static parlex::production DATE_YEAR_DAY() {
	parlex::reference const v0("decimal_digit");
	parlex::reference const v1("decimal_digit");
	parlex::reference const v2("decimal_digit");
	parlex::reference const v3("decimal_digit");
	parlex::literal const v4(U"-");
	parlex::reference const v5("decimal_digit");
	parlex::reference const v6("decimal_digit");
	parlex::reference const v7("decimal_digit");
	parlex::sequence const v8("DATE_YEAR_DAY", {v0, v1, v2, v3, v4, v5, v6, v7});
	return parlex::production("DATE_YEAR_DAY",v8, parlex::associativity::NONE, parlex::filter_function(), {"SUBTRACTION", });
}

static parlex::production DATE_YEAR_MONTH_DAY() {
	parlex::reference const v0("decimal_digit");
	parlex::reference const v1("decimal_digit");
	parlex::reference const v2("decimal_digit");
	parlex::reference const v3("decimal_digit");
	parlex::literal const v4(U"-");
	parlex::reference const v5("decimal_digit");
	parlex::reference const v6("decimal_digit");
	parlex::literal const v7(U"-");
	parlex::reference const v8("decimal_digit");
	parlex::reference const v9("decimal_digit");
	parlex::sequence const v10("DATE_YEAR_MONTH_DAY", {v0, v1, v2, v3, v4, v5, v6, v7, v8, v9});
	return parlex::production("DATE_YEAR_MONTH_DAY",v10, parlex::associativity::NONE, parlex::filter_function(), {"SUBTRACTION", });
}

static parlex::production DEFINITION() {
	parlex::reference const v0("identifier_specification", "IDENTIFIER_SPECIFICATION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U":=");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("expression", "EXPRESSION");
	parlex::sequence const v7("DEFINITION", {v0, v2, v3, v5, v6});
	return parlex::production("DEFINITION",v7);
}

static parlex::production DELTA() {
	parlex::literal const v0(U"Δ");
	parlex::literal const v1(U"_delta_");
	parlex::choice const v2({v0, v1});
	parlex::literal const v3(U"^");
	parlex::reference const v4("whole_number", "WHOLE_NUMBER");
	parlex::sequence const v5({v3, v4});
	parlex::optional const v6(v5);
	parlex::reference const v7("expression", "EXPRESSION");
	parlex::sequence const v8("DELTA", {v2, v6, v7});
	return parlex::production("DELTA",v8, parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", "EXPONENTIATION", });
}

static parlex::production DIMENSION() {
	parlex::reference const v0("IDENTIFIER");
	parlex::reference const v1("DIMENSIONAL_ANALYSIS_OP");
	parlex::choice const v2("DIMENSION", {v0, v1});
	return parlex::production("DIMENSION",v2);
}

static parlex::production DIMENSIONAL_ANALYSIS_OP() {
	parlex::reference const v0("UNIT_DIVISION");
	parlex::reference const v1("UNIT_EXPONENTIATION");
	parlex::reference const v2("UNIT_MULTIPLICATION");
	parlex::choice const v3("DIMENSIONAL_ANALYSIS_OP", {v0, v1, v2});
	return parlex::production("DIMENSIONAL_ANALYSIS_OP",v3);
}

static parlex::production DIMENSIONAL_NUMBER() {
	parlex::reference const v0("NON_NEG_NUMBER");
	parlex::reference const v1("DIMENSION");
	parlex::sequence const v2("DIMENSIONAL_NUMBER", {v0, v1});
	return parlex::production("DIMENSIONAL_NUMBER",v2, parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", "EXPONENTIATION", });
}

static parlex::production DIVISION() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"÷");
	parlex::literal const v4(U"/");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("DIVISION", {v0, v2, v5, v7, v8});
	return parlex::production("DIVISION",v9, parlex::associativity::LEFT, parlex::filter_function(), {"ADDITION", "ADD_SUB", "INTEGER_DIVISION", "MAPS_TO", "MODULATION", "SUBTRACTION", });
}

static parlex::production DIVISION_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"÷");
	parlex::literal const v4(U"/");
	parlex::choice const v5({v3, v4});
	parlex::literal const v6(U"<-");
	parlex::literal const v7(U"←");
	parlex::choice const v8({v6, v7});
	parlex::reference const v9("IC");
	parlex::repetition const v10(v9);
	parlex::reference const v11("EXPRESSION");
	parlex::sequence const v12("DIVISION_ASSIGNMENT", {v0, v2, v5, v8, v10, v11});
	return parlex::production("DIVISION_ASSIGNMENT",v12);
}

static parlex::production DO() {
	parlex::literal const v0(U"do");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("expression", "EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U"while");
	parlex::literal const v7(U"until");
	parlex::choice const v8({v6, v7});
	parlex::reference const v9("IC");
	parlex::repetition const v10(v9);
	parlex::reference const v11("condition", "PARENTHETICAL");
	parlex::sequence const v12({v5, v8, v10, v11});
	parlex::optional const v13(v12);
	parlex::sequence const v14("DO", {v0, v2, v3, v13});
	return parlex::production("DO",v14);
}

static parlex::production DOT_PRODUCT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"⋅");
	parlex::literal const v4(U"_dot_");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("DOT_PRODUCT", {v0, v2, v5, v7, v8});
	return parlex::production("DOT_PRODUCT",v9, parlex::associativity::LEFT);
}

static parlex::production DOWNCASTS() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"downcasts");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("DOWNCASTS", {v0, v2, v3, v5, v6});
	return parlex::production("DOWNCASTS",v7);
}

static parlex::production EMBEDDED_COMMENT() {
	parlex::literal const v0(U"/***");
	parlex::reference const v1("EMBEDDED_COMMENT_INTERIOR");
	parlex::literal const v2(U"***/");
	parlex::sequence const v3("EMBEDDED_COMMENT", {v0, v1, v2});
	return parlex::production("EMBEDDED_COMMENT",v3, parlex::associativity::NONE, parlex::shortest(), {"COMMENT", });
}

static parlex::production EMBEDDED_COMMENT_INTERIOR() {
	parlex::reference const v0("payload", "PAYLOAD");
	parlex::literal const v1(U"*");
	parlex::reference const v2("EMBEDDED_COMMENT_INTERIOR");
	parlex::literal const v3(U"*");
	parlex::sequence const v4({v1, v2, v3});
	parlex::choice const v5("EMBEDDED_COMMENT_INTERIOR", {v0, v4});
	return parlex::production("EMBEDDED_COMMENT_INTERIOR",v5, parlex::associativity::NONE, parlex::filter_function(), {"PAYLOAD", });
}

static parlex::production EMBEDDED_NEWLINE_STRING() {
	parlex::literal const v0(U"\"\"\"");
	parlex::reference const v1("EMBEDDED_NEWLINE_STRING_INTERIOR");
	parlex::literal const v2(U"\"\"\"");
	parlex::sequence const v3("EMBEDDED_NEWLINE_STRING", {v0, v1, v2});
	return parlex::production("EMBEDDED_NEWLINE_STRING",v3, parlex::associativity::NONE, parlex::shortest(), {"EMBEDDED_STRING", });
}

static parlex::production EMBEDDED_NEWLINE_STRING_INTERIOR() {
	parlex::literal const v0(U"\n");
	parlex::reference const v1("payload", "PAYLOAD");
	parlex::literal const v2(U"\n");
	parlex::sequence const v3({v0, v1, v2});
	parlex::literal const v4(U"\"");
	parlex::reference const v5("EMBEDDED_NEWLINE_STRING_INTERIOR");
	parlex::literal const v6(U"\"");
	parlex::sequence const v7({v4, v5, v6});
	parlex::choice const v8("EMBEDDED_NEWLINE_STRING_INTERIOR", {v3, v7});
	return parlex::production("EMBEDDED_NEWLINE_STRING_INTERIOR",v8, parlex::associativity::NONE, parlex::filter_function(), {"PAYLOAD", });
}

static parlex::production EMBEDDED_STRING() {
	parlex::literal const v0(U"\"\"\"");
	parlex::reference const v1("EMBEDDED_STRING_INTERIOR");
	parlex::literal const v2(U"\"\"\"");
	parlex::sequence const v3("EMBEDDED_STRING", {v0, v1, v2});
	return parlex::production("EMBEDDED_STRING",v3, parlex::associativity::NONE, parlex::shortest());
}

static parlex::production EMBEDDED_STRING_INTERIOR() {
	parlex::reference const v0("payload", "PAYLOAD");
	parlex::literal const v1(U"\"");
	parlex::reference const v2("EMBEDDED_STRING_INTERIOR");
	parlex::literal const v3(U"\"");
	parlex::sequence const v4({v1, v2, v3});
	parlex::choice const v5("EMBEDDED_STRING_INTERIOR", {v0, v4});
	return parlex::production("EMBEDDED_STRING_INTERIOR",v5, parlex::associativity::NONE, parlex::filter_function(), {"PAYLOAD", });
}

static parlex::production END_OF_LINE_COMMENT() {
	parlex::literal const v0(U"//");
	parlex::reference const v1("not_newline");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"\n");
	parlex::sequence const v4("END_OF_LINE_COMMENT", {v0, v2, v3});
	return parlex::production("END_OF_LINE_COMMENT",v4);
}

static parlex::production ENUM() {
	parlex::literal const v0(U"enum");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"inheriting");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("INHERITANCE_LIST");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::sequence const v9({v3, v5, v6, v8});
	parlex::optional const v10(v9);
	parlex::literal const v11(U"implementing");
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::reference const v14("INHERITANCE_LIST");
	parlex::reference const v15("IC");
	parlex::repetition const v16(v15);
	parlex::sequence const v17({v11, v13, v14, v16});
	parlex::optional const v18(v17);
	parlex::literal const v19(U"{");
	parlex::reference const v20("enum_element", "ENUM_ELEMENT");
	parlex::reference const v21("IC");
	parlex::repetition const v22(v21);
	parlex::literal const v23(U";");
	parlex::reference const v24("IC");
	parlex::repetition const v25(v24);
	parlex::reference const v26("enum_element", "ENUM_ELEMENT");
	parlex::sequence const v27({v22, v23, v25, v26});
	parlex::repetition const v28(v27);
	parlex::sequence const v29({v20, v28});
	parlex::optional const v30(v29);
	parlex::literal const v31(U"}");
	parlex::sequence const v32("ENUM", {v0, v2, v10, v18, v19, v30, v31});
	return parlex::production("ENUM",v32);
}

static parlex::production ENUM_ELEMENT() {
	parlex::reference const v0("xml_doc_string", "XML_DOC_STRING");
	parlex::optional const v1("doc", v0);
	parlex::reference const v2("identifier", "IDENTIFIER");
	parlex::reference const v3("IC");
	parlex::repetition const v4(v3);
	parlex::literal const v5(U":=");
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("expression", "EXPRESSION");
	parlex::sequence const v9({v4, v5, v7, v8});
	parlex::optional const v10(v9);
	parlex::sequence const v11("ENUM_ELEMENT", {v1, v2, v10});
	return parlex::production("ENUM_ELEMENT",v11);
}

static parlex::production EQUALITY() {
	parlex::reference const v0("expression", "EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("equality_node", "EQUALITY_NODE");
	parlex::sequence const v4("EQUALITY", {v0, v2, v3});
	return parlex::production("EQUALITY",v4, parlex::associativity::NONE, parlex::filter_function(), {"GREATER", "LESSER", "SUBSET", "SUPERSET", });
}

static parlex::production EQUALITY_NODE() {
	parlex::literal const v0(U"=");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("expression", "EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("equality_node", "EQUALITY_NODE");
	parlex::sequence const v7({v5, v6});
	parlex::optional const v8(v7);
	parlex::sequence const v9("EQUALITY_NODE", {v0, v2, v3, v8});
	return parlex::production("EQUALITY_NODE",v9, parlex::associativity::NONE, parlex::filter_function(), {"EXPRESSION", });
}

static parlex::production EXACTLY() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"exactly");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("EXACTLY", {v0, v2, v3, v5, v6});
	return parlex::production("EXACTLY",v7);
}

static parlex::production EXISTS() {
	parlex::literal const v0(U"∃");
	parlex::literal const v1(U"exists");
	parlex::choice const v2({v0, v1});
	parlex::reference const v3("IC");
	parlex::repetition const v4(v3);
	parlex::reference const v5("EXPRESSION");
	parlex::sequence const v6("EXISTS", {v2, v4, v5});
	return parlex::production("EXISTS",v6);
}

static parlex::production EXISTS_ONE() {
	parlex::literal const v0(U"∃!");
	parlex::literal const v1(U"exists!");
	parlex::choice const v2({v0, v1});
	parlex::reference const v3("IC");
	parlex::repetition const v4(v3);
	parlex::reference const v5("EXPRESSION");
	parlex::sequence const v6("EXISTS_ONE", {v2, v4, v5});
	return parlex::production("EXISTS_ONE",v6);
}

static parlex::production EXPONENTIATION() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"^");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("EXPONENTIATION", {v0, v2, v3, v5, v6});
	return parlex::production("EXPONENTIATION",v7, parlex::associativity::RIGHT, parlex::filter_function(), {"ADDITION", "ADD_SUB", "DIVISION", "INTEGER_DIVISION", "MODULATION", "MULTIPLICATIVE_OP", "SUBTRACTION", });
}

static parlex::production EXPONENTIATION_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"^");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10("EXPONENTIATION_ASSIGNMENT", {v0, v2, v3, v6, v8, v9});
	return parlex::production("EXPONENTIATION_ASSIGNMENT",v10);
}

static parlex::production EXPRESSION() {
	parlex::reference const v0("ARRAY");
	parlex::reference const v1("ASM_FUNCTION");
	parlex::reference const v2("BINARY_OP");
	parlex::reference const v3("BOOL");
	parlex::reference const v4("CAST");
	parlex::reference const v5("CEILING");
	parlex::reference const v6("COMPLEMENT");
	parlex::reference const v7("CONDITIONAL");
	parlex::reference const v8("DATE");
	parlex::reference const v9("DATE_TIME");
	parlex::reference const v10("DELTA");
	parlex::reference const v11("DIMENSIONAL_NUMBER");
	parlex::reference const v12("EMBEDDED_STRING");
	parlex::reference const v13("ENUM");
	parlex::reference const v14("EQUALITY");
	parlex::reference const v15("FLOOR");
	parlex::reference const v16("FUNCTION");
	parlex::reference const v17("GREATER");
	parlex::reference const v18("IDENTIFIER");
	parlex::reference const v19("IF");
	parlex::reference const v20("INVOCATION");
	parlex::reference const v21("LESSER");
	parlex::reference const v22("LIST");
	parlex::reference const v23("MAGNITUDE");
	parlex::reference const v24("MAP");
	parlex::reference const v25("MEMBER_ACCESS");
	parlex::reference const v26("NEAREST_INTEGER");
	parlex::reference const v27("NON_NEG_NUMBER");
	parlex::reference const v28("OBJECT");
	parlex::reference const v29("PARENTHETICAL");
	parlex::reference const v30("RANGE");
	parlex::reference const v31("REGEX");
	parlex::reference const v32("SET");
	parlex::reference const v33("SET_COMPREHENSION");
	parlex::reference const v34("SUBSET");
	parlex::reference const v35("SUPERSET");
	parlex::reference const v36("SWIZZLE");
	parlex::reference const v37("THIS");
	parlex::reference const v38("THIS_FUNC");
	parlex::reference const v39("THIS_TYPE");
	parlex::reference const v40("TIME");
	parlex::reference const v41("TUPLE");
	parlex::reference const v42("TYPE");
	parlex::reference const v43("UNARY_OP");
	parlex::reference const v44("VECTOR_NORM");
	parlex::literal const v45(U"context");
	parlex::literal const v46(U"null");
	parlex::literal const v47(U"unit");
	parlex::reference const v48("c_string");
	parlex::choice const v49("EXPRESSION", {v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48});
	return parlex::production("EXPRESSION",v49);
}

static parlex::production FACTORIAL() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"!");
	parlex::sequence const v4("FACTORIAL", {v0, v2, v3});
	return parlex::production("FACTORIAL",v4, parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", });
}

static parlex::production FACTORIAL_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"!");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::sequence const v7("FACTORIAL_ASSIGNMENT", {v0, v2, v3, v6});
	return parlex::production("FACTORIAL_ASSIGNMENT",v7);
}

static parlex::production FLOOR() {
	parlex::literal const v0(U"⌊");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("expression", "EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U"⌋");
	parlex::sequence const v7({v0, v2, v3, v5, v6});
	parlex::literal const v8(U"|_");
	parlex::reference const v9("IC");
	parlex::repetition const v10(v9);
	parlex::reference const v11("expression", "EXPRESSION");
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::literal const v14(U"_|");
	parlex::sequence const v15({v8, v10, v11, v13, v14});
	parlex::choice const v16("FLOOR", {v7, v15});
	return parlex::production("FLOOR",v16);
}

static parlex::production FOR() {
	parlex::literal const v0(U"for");
	parlex::reference const v1("IC");
	parlex::repetition const v2("ic1", v1);
	parlex::literal const v3(U"(");
	parlex::reference const v4("IC");
	parlex::repetition const v5("ic2", v4);
	parlex::reference const v6("statement_scope", "STATEMENT_SCOPE");
	parlex::reference const v7("IC");
	parlex::repetition const v8("ic", v7);
	parlex::sequence const v9({v6, v8});
	parlex::optional const v10("initializer", v9);
	parlex::reference const v11("condition", "EXPRESSION");
	parlex::reference const v12("IC");
	parlex::repetition const v13("ic3", v12);
	parlex::literal const v14(U";");
	parlex::reference const v15("IC");
	parlex::repetition const v16("ic4", v15);
	parlex::reference const v17("for_step_list", "FOR_STEP_LIST");
	parlex::reference const v18("IC");
	parlex::repetition const v19("ic", v18);
	parlex::sequence const v20({v17, v19});
	parlex::optional const v21("step", v20);
	parlex::literal const v22(U")");
	parlex::reference const v23("IC");
	parlex::repetition const v24("ic5", v23);
	parlex::reference const v25("EXPRESSION");
	parlex::sequence const v26("FOR", {v0, v2, v3, v5, v10, v11, v13, v14, v16, v21, v22, v24, v25});
	return parlex::production("FOR",v26);
}

static parlex::production FOR_COLLECTION() {
	parlex::literal const v0(U"for");
	parlex::reference const v1("IC");
	parlex::repetition const v2("ic1", v1);
	parlex::literal const v3(U"(");
	parlex::reference const v4("IC");
	parlex::repetition const v5("ic2", v4);
	parlex::reference const v6("TYPE_DEREFERENCE");
	parlex::reference const v7("IMPLICIT_TYPE_DEREFERENCE");
	parlex::choice const v8({v6, v7});
	parlex::reference const v9("IC");
	parlex::repetition const v10("ic", v9);
	parlex::sequence const v11({v8, v10});
	parlex::optional const v12(v11);
	parlex::reference const v13("identifier", "IDENTIFIER");
	parlex::sequence const v14("declaration", {v12, v13});
	parlex::reference const v15("expression", "EXPRESSION");
	parlex::choice const v16({v14, v15});
	parlex::reference const v17("IC");
	parlex::repetition const v18("ic3", v17);
	parlex::literal const v19(U"in");
	parlex::literal const v20(U"∈");
	parlex::choice const v21({v19, v20});
	parlex::reference const v22("IC");
	parlex::repetition const v23("ic4", v22);
	parlex::reference const v24("collection", "EXPRESSION");
	parlex::reference const v25("IC");
	parlex::repetition const v26("ic5", v25);
	parlex::literal const v27(U")");
	parlex::reference const v28("IC");
	parlex::repetition const v29("ic6", v28);
	parlex::reference const v30("expression", "EXPRESSION");
	parlex::sequence const v31("FOR_COLLECTION", {v0, v2, v3, v5, v16, v18, v21, v23, v24, v26, v27, v29, v30});
	return parlex::production("FOR_COLLECTION",v31);
}

static parlex::production FOR_STEP() {
	parlex::reference const v0("identifier", "IDENTIFIER");
	parlex::reference const v1("IC");
	parlex::repetition const v2("ic", v1);
	parlex::reference const v3("for_step_node", "FOR_STEP_NODE");
	parlex::sequence const v4("FOR_STEP", {v0, v2, v3});
	return parlex::production("FOR_STEP",v4);
}

static parlex::production FOR_STEP_LIST() {
	parlex::reference const v0("for_step", "FOR_STEP");
	parlex::reference const v1("IC");
	parlex::repetition const v2("ic1", v1);
	parlex::literal const v3(U",");
	parlex::reference const v4("IC");
	parlex::repetition const v5("ic2", v4);
	parlex::reference const v6("for_step", "FOR_STEP");
	parlex::sequence const v7({v2, v3, v5, v6});
	parlex::repetition const v8("tail", v7);
	parlex::sequence const v9("FOR_STEP_LIST", {v0, v8});
	return parlex::production("FOR_STEP_LIST",v9);
}

static parlex::production FOR_STEP_NODE() {
	parlex::literal const v0(U"←");
	parlex::literal const v1(U"<-");
	parlex::choice const v2({v0, v1});
	parlex::reference const v3("IC");
	parlex::repetition const v4("ic", v3);
	parlex::reference const v5("expression", "EXPRESSION");
	parlex::reference const v6("identifier", "IDENTIFIER");
	parlex::reference const v7("IC");
	parlex::repetition const v8("ic", v7);
	parlex::reference const v9("next", "FOR_STEP_NODE");
	parlex::sequence const v10({v6, v8, v9});
	parlex::choice const v11("value", {v5, v10});
	parlex::sequence const v12("FOR_STEP_NODE", {v2, v4, v11});
	return parlex::production("FOR_STEP_NODE",v12);
}

static parlex::production FREE() {
	parlex::literal const v0(U"free");
	parlex::reference const v1("IC");
	parlex::repetition const v2("ic", v1);
	parlex::reference const v3("EXPRESSION");
	parlex::sequence const v4("FREE", {v0, v2, v3});
	return parlex::production("FREE",v4);
}

static parlex::production FUNCTION() {
	parlex::literal const v0(U"(");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("parameter", "PARAMETER");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U",");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("parameter", "PARAMETER");
	parlex::sequence const v10({v5, v6, v8, v9});
	parlex::repetition const v11(v10);
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::sequence const v14({v3, v11, v13});
	parlex::optional const v15(v14);
	parlex::literal const v16(U")");
	parlex::reference const v17("IC");
	parlex::repetition const v18(v17);
	parlex::sequence const v19({v0, v2, v15, v16, v18});
	parlex::optional const v20(v19);
	parlex::reference const v21("FUNCTION_MODIFIER_0");
	parlex::reference const v22("IC");
	parlex::repetition const v23(v22);
	parlex::sequence const v24({v21, v23});
	parlex::optional const v25(v24);
	parlex::reference const v26("block", "BLOCK");
	parlex::sequence const v27("FUNCTION", {v20, v25, v26});
	return parlex::production("FUNCTION",v27, parlex::associativity::NONE, parlex::filter_function(), {"CAST", });
}

static parlex::production FUNCTION_MODIFIER_0() {
	parlex::reference const v0("FUNCTION_MODIFIER_STABILITY");
	parlex::reference const v1("FUNCTION_MODIFIER_1");
	parlex::choice const v2("FUNCTION_MODIFIER_0", {v0, v1});
	return parlex::production("FUNCTION_MODIFIER_0",v2);
}

static parlex::production FUNCTION_MODIFIER_1() {
	parlex::reference const v0("FUNCTION_MODIFIER_THROWING");
	parlex::reference const v1("FUNCTION_MODIFIER_2");
	parlex::choice const v2("FUNCTION_MODIFIER_1", {v0, v1});
	return parlex::production("FUNCTION_MODIFIER_1",v2);
}

static parlex::production FUNCTION_MODIFIER_2() {
	parlex::reference const v0("FUNCTION_MODIFIER_ATOMIC");
	parlex::reference const v1("FUNCTION_MODIFIER_3");
	parlex::choice const v2("FUNCTION_MODIFIER_2", {v0, v1});
	return parlex::production("FUNCTION_MODIFIER_2",v2);
}

static parlex::production FUNCTION_MODIFIER_3() {
	parlex::reference const v0("FUNCTION_MODIFIER_PLATFORM");
	parlex::reference const v1("FUNCTION_MODIFIER_4");
	parlex::choice const v2("FUNCTION_MODIFIER_3", {v0, v1});
	return parlex::production("FUNCTION_MODIFIER_3",v2);
}

static parlex::production FUNCTION_MODIFIER_4() {
	parlex::reference const v0("FUNCTION_MODIFIER_MODEL");
	parlex::reference const v1("FUNCTION_MODIFIER_CALLING_CONVENTION");
	parlex::choice const v2("FUNCTION_MODIFIER_4", {v0, v1});
	return parlex::production("FUNCTION_MODIFIER_4",v2);
}

static parlex::production FUNCTION_MODIFIER_ATOMIC() {
	parlex::literal const v0(U"atomic");
	parlex::reference const v1("IC");
	parlex::reference const v2("IC");
	parlex::repetition const v3(v2);
	parlex::reference const v4("FUNCTION_MODIFIER_3");
	parlex::sequence const v5({v1, v3, v4});
	parlex::optional const v6(v5);
	parlex::sequence const v7("FUNCTION_MODIFIER_ATOMIC", {v0, v6});
	return parlex::production("FUNCTION_MODIFIER_ATOMIC",v7);
}

static parlex::production FUNCTION_MODIFIER_CALLING_CONVENTION() {
	parlex::literal const v0(U"c_call");
	parlex::literal const v1(U"fast_call");
	parlex::literal const v2(U"cold_call");
	parlex::literal const v3(U"ghc_call");
	parlex::literal const v4(U"hipe_call");
	parlex::literal const v5(U"webkit_js_call");
	parlex::literal const v6(U"any_reg_call");
	parlex::literal const v7(U"preserve_most_call");
	parlex::literal const v8(U"preserve_all_call");
	parlex::literal const v9(U"swift_call");
	parlex::literal const v10(U"cxx_fast_tls_call");
	parlex::literal const v11(U"first_target_call");
	parlex::literal const v12(U"x86_std_call");
	parlex::literal const v13(U"X86_fast_call");
	parlex::literal const v14(U"arm_apcs_call");
	parlex::literal const v15(U"arm_aapcs_call");
	parlex::literal const v16(U"arm_aapcs_vfp_call");
	parlex::literal const v17(U"msp430_intr_call");
	parlex::literal const v18(U"x86_this_call");
	parlex::literal const v19(U"ptx_kernel_call");
	parlex::literal const v20(U"ptx_device_call");
	parlex::literal const v21(U"spir_func_call");
	parlex::literal const v22(U"spir_kernel_call");
	parlex::literal const v23(U"intel_ocl_bi_call");
	parlex::literal const v24(U"x86_64_sysv_call");
	parlex::literal const v25(U"x86_64_win64_call");
	parlex::literal const v26(U"x86_vector_call");
	parlex::literal const v27(U"hhvm_call");
	parlex::literal const v28(U"x86_intr_call");
	parlex::literal const v29(U"avr_intr_call");
	parlex::literal const v30(U"avr_signal_call");
	parlex::literal const v31(U"avr_builtin_call");
	parlex::choice const v32("FUNCTION_MODIFIER_CALLING_CONVENTION", {v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31});
	return parlex::production("FUNCTION_MODIFIER_CALLING_CONVENTION",v32);
}

static parlex::production FUNCTION_MODIFIER_MODEL() {
	parlex::literal const v0(U"pure");
	parlex::literal const v1(U"imperative");
	parlex::literal const v2(U"opaque");
	parlex::choice const v3("model", {v0, v1, v2});
	parlex::reference const v4("IC");
	parlex::reference const v5("IC");
	parlex::repetition const v6(v5);
	parlex::reference const v7("FUNCTION_MODIFIER_CALLING_CONVENTION");
	parlex::sequence const v8({v4, v6, v7});
	parlex::optional const v9(v8);
	parlex::sequence const v10("FUNCTION_MODIFIER_MODEL", {v3, v9});
	return parlex::production("FUNCTION_MODIFIER_MODEL",v10);
}

static parlex::production FUNCTION_MODIFIER_PLATFORM() {
	parlex::reference const v0("PLATFORM");
	parlex::reference const v1("IC");
	parlex::reference const v2("IC");
	parlex::repetition const v3(v2);
	parlex::reference const v4("PLATFORM");
	parlex::sequence const v5({v1, v3, v4});
	parlex::repetition const v6(v5);
	parlex::reference const v7("IC");
	parlex::reference const v8("IC");
	parlex::repetition const v9(v8);
	parlex::reference const v10("FUNCTION_MODIFIER_4");
	parlex::sequence const v11({v7, v9, v10});
	parlex::optional const v12(v11);
	parlex::sequence const v13("FUNCTION_MODIFIER_PLATFORM", {v0, v6, v12});
	return parlex::production("FUNCTION_MODIFIER_PLATFORM",v13);
}

static parlex::production FUNCTION_MODIFIER_STABILITY() {
	parlex::literal const v0(U"stable");
	parlex::literal const v1(U"unstable");
	parlex::choice const v2("stability", {v0, v1});
	parlex::reference const v3("IC");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("FUNCTION_MODIFIER_1");
	parlex::sequence const v7({v3, v5, v6});
	parlex::optional const v8(v7);
	parlex::sequence const v9("FUNCTION_MODIFIER_STABILITY", {v2, v8});
	return parlex::production("FUNCTION_MODIFIER_STABILITY",v9);
}

static parlex::production FUNCTION_MODIFIER_THROWING() {
	parlex::literal const v0(U"throwing");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("ARRAY");
	parlex::sequence const v4({v2, v3});
	parlex::optional const v5(v4);
	parlex::reference const v6("IC");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("FUNCTION_MODIFIER_2");
	parlex::sequence const v10({v6, v8, v9});
	parlex::optional const v11(v10);
	parlex::sequence const v12("FUNCTION_MODIFIER_THROWING", {v0, v5, v11});
	return parlex::production("FUNCTION_MODIFIER_THROWING",v12);
}

static parlex::production GREATER() {
	parlex::reference const v0("expression", "EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("greater_node", "GREATER_NODE");
	parlex::sequence const v4("GREATER", {v0, v2, v3});
	return parlex::production("GREATER",v4);
}

static parlex::production GREATER_NODE() {
	parlex::literal const v0(U"=");
	parlex::literal const v1(U">");
	parlex::literal const v2(U"=>");
	parlex::literal const v3(U"≥");
	parlex::choice const v4({v0, v1, v2, v3});
	parlex::reference const v5("IC");
	parlex::repetition const v6(v5);
	parlex::reference const v7("expression", "EXPRESSION");
	parlex::reference const v8("IC");
	parlex::repetition const v9(v8);
	parlex::reference const v10("greater_node", "GREATER_NODE");
	parlex::sequence const v11({v9, v10});
	parlex::optional const v12(v11);
	parlex::sequence const v13("GREATER_NODE", {v4, v6, v7, v12});
	return parlex::production("GREATER_NODE",v13);
}

static parlex::production HAS() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"∋");
	parlex::literal const v4(U"has");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("HAS", {v0, v2, v5, v7, v8});
	return parlex::production("HAS",v9, parlex::associativity::LEFT);
}

static parlex::production HEX() {
	parlex::literal const v0(U"0x");
	parlex::reference const v1("hexadecimal_digit");
	parlex::reference const v2("hexadecimal_digit");
	parlex::repetition const v3(v2);
	parlex::sequence const v4("HEX", {v0, v1, v3});
	return parlex::production("HEX",v4);
}

static parlex::production IC() {
	parlex::reference const v0("COMMENT");
	parlex::reference const v1("EMBEDDED_COMMENT");
	parlex::reference const v2("END_OF_LINE_COMMENT");
	parlex::reference const v3("WS");
	parlex::choice const v4("IC", {v0, v1, v2, v3});
	return parlex::production("IC",v4);
}

static parlex::production IDENTIFIER() {
	parlex::reference const v0("letter");
	parlex::literal const v1(U"_");
	parlex::choice const v2("head", {v0, v1});
	parlex::reference const v3("letter");
	parlex::reference const v4("number");
	parlex::literal const v5(U"_");
	parlex::choice const v6({v3, v4, v5});
	parlex::repetition const v7("tail", v6);
	parlex::sequence const v8("IDENTIFIER", {v2, v7});
	return parlex::production("IDENTIFIER",v8, parlex::associativity::NONE, parlex::longest(), {"ALL", });
}

static parlex::production IDENTIFIER_SPECIFICATION() {
	parlex::reference const v0("xml_doc_string", "XML_DOC_STRING");
	parlex::optional const v1("doc", v0);
	parlex::reference const v2("attribute", "ATTRIBUTE");
	parlex::reference const v3("IC");
	parlex::repetition const v4("ic", v3);
	parlex::sequence const v5({v2, v4});
	parlex::repetition const v6("attributes", v5);
	parlex::reference const v7("visibility_modifier", "VISIBILITY_MODIFIER");
	parlex::reference const v8("IC");
	parlex::repetition const v9("ic", v8);
	parlex::sequence const v10({v7, v9});
	parlex::optional const v11("visibility", v10);
	parlex::literal const v12(U"static");
	parlex::reference const v13("IC");
	parlex::repetition const v14(v13);
	parlex::sequence const v15({v12, v14});
	parlex::optional const v16("static_", v15);
	parlex::literal const v17(U"extern");
	parlex::reference const v18("IC");
	parlex::repetition const v19(v18);
	parlex::sequence const v20({v17, v19});
	parlex::optional const v21("extern_", v20);
	parlex::reference const v22("identifier", "IDENTIFIER");
	parlex::sequence const v23("IDENTIFIER_SPECIFICATION", {v1, v6, v11, v16, v21, v22});
	return parlex::production("IDENTIFIER_SPECIFICATION",v23);
}

static parlex::production IF() {
	parlex::literal const v0(U"if");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("condition", "PARENTHETICAL");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("invoke", "EXPRESSION");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::literal const v9(U"elif");
	parlex::reference const v10("IC");
	parlex::repetition const v11(v10);
	parlex::reference const v12("condition", "PARENTHETICAL");
	parlex::reference const v13("IC");
	parlex::repetition const v14(v13);
	parlex::reference const v15("invoke", "EXPRESSION");
	parlex::sequence const v16({v8, v9, v11, v12, v14, v15});
	parlex::repetition const v17(v16);
	parlex::reference const v18("IC");
	parlex::repetition const v19(v18);
	parlex::literal const v20(U"else");
	parlex::reference const v21("IC");
	parlex::repetition const v22(v21);
	parlex::reference const v23("else_invoke", "EXPRESSION");
	parlex::sequence const v24({v19, v20, v22, v23});
	parlex::optional const v25(v24);
	parlex::sequence const v26("IF", {v0, v2, v3, v5, v6, v17, v25});
	return parlex::production("IF",v26);
}

static parlex::production IFF() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"⇔");
	parlex::literal const v4(U"<=>");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("IFF", {v0, v2, v5, v7, v8});
	return parlex::production("IFF",v9, parlex::associativity::ANY);
}

static parlex::production IMPLEMENTS() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"implements");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("IMPLEMENTS", {v0, v2, v3, v5, v6});
	return parlex::production("IMPLEMENTS",v7);
}

static parlex::production IMPLICATION() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"⇒");
	parlex::literal const v4(U"=>");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("IMPLICATION", {v0, v2, v5, v7, v8});
	return parlex::production("IMPLICATION",v9, parlex::associativity::RIGHT, parlex::filter_function(), {"IFF", "XOR", });
}

static parlex::production IMPLICATION_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"⇒");
	parlex::literal const v4(U"=>");
	parlex::choice const v5({v3, v4});
	parlex::literal const v6(U"<-");
	parlex::literal const v7(U"←");
	parlex::choice const v8({v6, v7});
	parlex::reference const v9("IC");
	parlex::repetition const v10(v9);
	parlex::reference const v11("EXPRESSION");
	parlex::sequence const v12("IMPLICATION_ASSIGNMENT", {v0, v2, v5, v8, v10, v11});
	return parlex::production("IMPLICATION_ASSIGNMENT",v12);
}

static parlex::production IMPLICIT_TYPE_DEREFERENCE() {
	parlex::literal const v0(U"<");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U">");
	parlex::sequence const v4("IMPLICIT_TYPE_DEREFERENCE", {v0, v2, v3});
	return parlex::production("IMPLICIT_TYPE_DEREFERENCE",v4);
}

static parlex::production IMPORT() {
	parlex::literal const v0(U"import");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::sequence const v4("IMPORT", {v0, v2, v3});
	return parlex::production("IMPORT",v4);
}

static parlex::production IN() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"∈");
	parlex::literal const v4(U"in");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("IN", {v0, v2, v5, v7, v8});
	return parlex::production("IN",v9, parlex::associativity::LEFT);
}

static parlex::production INEQUALITY() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"≠");
	parlex::literal const v4(U"/=");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("INEQUALITY", {v0, v2, v5, v7, v8});
	return parlex::production("INEQUALITY",v9, parlex::associativity::LEFT);
}

static parlex::production INHERITANCE_ITEM_PREFIX() {
	parlex::reference const v0("VISIBILITY_MODIFIER");
	parlex::reference const v1("VISIBILITY_MODIFIER");
	parlex::reference const v2("IC");
	parlex::reference const v3("IC");
	parlex::repetition const v4(v3);
	parlex::literal const v5(U"diamond");
	parlex::sequence const v6({v1, v2, v4, v5});
	parlex::literal const v7(U"diamond");
	parlex::choice const v8({v0, v6, v7});
	parlex::reference const v9("IC");
	parlex::reference const v10("IC");
	parlex::repetition const v11(v10);
	parlex::sequence const v12("INHERITANCE_ITEM_PREFIX", {v8, v9, v11});
	return parlex::production("INHERITANCE_ITEM_PREFIX",v12);
}

static parlex::production INHERITANCE_LIST() {
	parlex::reference const v0("INHERITANCE_ITEM_PREFIX");
	parlex::optional const v1(v0);
	parlex::reference const v2("expression", "EXPRESSION");
	parlex::reference const v3("IC");
	parlex::repetition const v4(v3);
	parlex::literal const v5(U",");
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("INHERITANCE_ITEM_PREFIX");
	parlex::optional const v9(v8);
	parlex::reference const v10("expression", "EXPRESSION");
	parlex::sequence const v11({v4, v5, v7, v9, v10});
	parlex::repetition const v12(v11);
	parlex::sequence const v13("INHERITANCE_LIST", {v1, v2, v12});
	return parlex::production("INHERITANCE_LIST",v13);
}

static parlex::production INHERITS() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"inherits");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("INHERITS", {v0, v2, v3, v5, v6});
	return parlex::production("INHERITS",v7);
}

static parlex::production INTEGER_DIVISION() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"\\");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("INTEGER_DIVISION", {v0, v2, v3, v5, v6});
	return parlex::production("INTEGER_DIVISION",v7, parlex::associativity::LEFT, parlex::filter_function(), {"ADDITION", "ADD_SUB", "SUBTRACTION", });
}

static parlex::production INTEGER_DIVISION_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"\\");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10("INTEGER_DIVISION_ASSIGNMENT", {v0, v2, v3, v6, v8, v9});
	return parlex::production("INTEGER_DIVISION_ASSIGNMENT",v10);
}

static parlex::production INTERSECTION() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"∩");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("INTERSECTION", {v0, v2, v3, v5, v6});
	return parlex::production("INTERSECTION",v7, parlex::associativity::ANY);
}

static parlex::production INTERSECTION_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"∩");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10("INTERSECTION_ASSIGNMENT", {v0, v2, v3, v6, v8, v9});
	return parlex::production("INTERSECTION_ASSIGNMENT",v10);
}

static parlex::production INVOCATION() {
	parlex::reference const v0("expression", "EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2("ic", v1);
	parlex::reference const v3("PARENTHETICAL_INVOCATION");
	parlex::reference const v4("ARRAY_INVOCATION");
	parlex::reference const v5("TYPE_INVOCATION");
	parlex::choice const v6("args", {v3, v4, v5});
	parlex::sequence const v7("INVOCATION", {v0, v2, v6});
	return parlex::production("INVOCATION",v7, parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", "NEGATION", "RADICAL", });
}

static parlex::production IS() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"is");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("IS", {v0, v2, v3, v5, v6});
	return parlex::production("IS",v7);
}

static parlex::production KLEENE_STAR() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"*");
	parlex::sequence const v4("KLEENE_STAR", {v0, v2, v3});
	return parlex::production("KLEENE_STAR",v4);
}

static parlex::production LESSER() {
	parlex::reference const v0("expression", "EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2("ic", v1);
	parlex::reference const v3("lesser_node", "LESSER_NODE");
	parlex::sequence const v4("LESSER", {v0, v2, v3});
	return parlex::production("LESSER",v4);
}

static parlex::production LESSER_NODE() {
	parlex::literal const v0(U"=");
	parlex::literal const v1(U"<");
	parlex::literal const v2(U"=<");
	parlex::literal const v3(U"≤");
	parlex::choice const v4({v0, v1, v2, v3});
	parlex::reference const v5("IC");
	parlex::repetition const v6("ic", v5);
	parlex::reference const v7("expression", "EXPRESSION");
	parlex::reference const v8("IC");
	parlex::repetition const v9("ic", v8);
	parlex::reference const v10("lesser_node", "LESSER_NODE");
	parlex::sequence const v11({v9, v10});
	parlex::optional const v12(v11);
	parlex::sequence const v13("LESSER_NODE", {v4, v6, v7, v12});
	return parlex::production("LESSER_NODE",v13);
}

static parlex::production LIST() {
	parlex::literal const v0(U"[|");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U", ");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10({v5, v6, v8, v9});
	parlex::repetition const v11(v10);
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::sequence const v14({v3, v11, v13});
	parlex::optional const v15("elements", v14);
	parlex::literal const v16(U"|]");
	parlex::sequence const v17("LIST", {v0, v2, v15, v16});
	return parlex::production("LIST",v17);
}

static parlex::production LOCK() {
	parlex::literal const v0(U"lock");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("PARENTHETICAL");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("BLOCK");
	parlex::sequence const v7("LOCK", {v0, v2, v3, v5, v6});
	return parlex::production("LOCK",v7);
}

static parlex::production LOOP() {
	parlex::literal const v0(U"while");
	parlex::literal const v1(U"until");
	parlex::choice const v2({v0, v1});
	parlex::reference const v3("IC");
	parlex::repetition const v4(v3);
	parlex::reference const v5("PARENTHETICAL");
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("LOOP", {v2, v4, v5, v7, v8});
	return parlex::production("LOOP",v9);
}

static parlex::production MAGNITUDE() {
	parlex::literal const v0(U"|");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U"|");
	parlex::sequence const v7("MAGNITUDE", {v0, v2, v3, v5, v6});
	return parlex::production("MAGNITUDE",v7);
}

static parlex::production MAP() {
	parlex::literal const v0(U"{");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U":");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::reference const v10("IC");
	parlex::repetition const v11(v10);
	parlex::literal const v12(U",");
	parlex::reference const v13("IC");
	parlex::repetition const v14(v13);
	parlex::reference const v15("EXPRESSION");
	parlex::reference const v16("IC");
	parlex::repetition const v17(v16);
	parlex::literal const v18(U":");
	parlex::reference const v19("IC");
	parlex::repetition const v20(v19);
	parlex::reference const v21("EXPRESSION");
	parlex::sequence const v22({v11, v12, v14, v15, v17, v18, v20, v21});
	parlex::repetition const v23(v22);
	parlex::sequence const v24({v2, v3, v5, v6, v8, v9, v23});
	parlex::optional const v25(v24);
	parlex::reference const v26("IC");
	parlex::repetition const v27(v26);
	parlex::literal const v28(U"}");
	parlex::sequence const v29("MAP", {v0, v25, v27, v28});
	return parlex::production("MAP",v29, parlex::associativity::NONE, parlex::filter_function(), {"FUNCTION", });
}

static parlex::production MAPS_TO() {
	parlex::literal const v0(U"volatile");
	parlex::reference const v1("IC");
	parlex::reference const v2("IC");
	parlex::repetition const v3(v2);
	parlex::sequence const v4({v0, v1, v3});
	parlex::optional const v5(v4);
	parlex::literal const v6(U"const");
	parlex::reference const v7("IC");
	parlex::reference const v8("IC");
	parlex::repetition const v9(v8);
	parlex::sequence const v10({v6, v7, v9});
	parlex::optional const v11(v10);
	parlex::reference const v12("lhs", "EXPRESSION");
	parlex::reference const v13("IC");
	parlex::repetition const v14("ic1", v13);
	parlex::literal const v15(U"→");
	parlex::literal const v16(U"->");
	parlex::choice const v17({v15, v16});
	parlex::reference const v18("IC");
	parlex::repetition const v19("ic2", v18);
	parlex::reference const v20("rhs", "EXPRESSION");
	parlex::sequence const v21("MAPS_TO", {v5, v11, v12, v14, v17, v19, v20});
	return parlex::production("MAPS_TO",v21, parlex::associativity::RIGHT);
}

static parlex::production MEMBER_ACCESS() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U".");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("IDENTIFIER");
	parlex::sequence const v7("MEMBER_ACCESS", {v0, v2, v3, v5, v6});
	return parlex::production("MEMBER_ACCESS",v7, parlex::associativity::LEFT);
}

static parlex::production MEMBER_OFFSET() {
	parlex::literal const v0(U"@");
	parlex::reference const v1("IC");
	parlex::repetition const v2("ic", v1);
	parlex::reference const v3("offset", "NATURAL_NUMBER");
	parlex::sequence const v4("MEMBER_OFFSET", {v0, v2, v3});
	return parlex::production("MEMBER_OFFSET",v4);
}

static parlex::production MODULATION() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"%");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("MODULATION", {v0, v2, v3, v5, v6});
	return parlex::production("MODULATION",v7, parlex::associativity::LEFT, parlex::filter_function(), {"ADDITION", "ADD_SUB", "SUBTRACTION", });
}

static parlex::production MODULATION_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"%");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10("MODULATION_ASSIGNMENT", {v0, v2, v3, v6, v8, v9});
	return parlex::production("MODULATION_ASSIGNMENT",v10);
}

static parlex::production MULTIPLICATION() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"*");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("MULTIPLICATION", {v0, v2, v3, v5, v6});
	return parlex::production("MULTIPLICATION",v7, parlex::associativity::ANY);
}

static parlex::production MULTIPLICATION_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"*");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10("MULTIPLICATION_ASSIGNMENT", {v0, v2, v3, v6, v8, v9});
	return parlex::production("MULTIPLICATION_ASSIGNMENT",v10);
}

static parlex::production MULTIPLICATIVE_OP() {
	parlex::reference const v0("CROSS_PRODUCT");
	parlex::reference const v1("DOT_PRODUCT");
	parlex::reference const v2("MULTIPLICATION");
	parlex::choice const v3("MULTIPLICATIVE_OP", {v0, v1, v2});
	return parlex::production("MULTIPLICATIVE_OP",v3, parlex::associativity::NONE, parlex::filter_function(), {"ADDITION", "ADD_SUB", "INTEGER_DIVISION", "MAPS_TO", "MODULATION", "SUBTRACTION", });
}

static parlex::production NAND() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"↑");
	parlex::literal const v4(U"nand");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("NAND", {v0, v2, v5, v7, v8});
	return parlex::production("NAND",v9, parlex::associativity::LEFT, parlex::filter_function(), {"IFF", "IMPLICATION", "OR", "XOR", });
}

static parlex::production NAND_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"↑");
	parlex::literal const v4(U"nand");
	parlex::choice const v5({v3, v4});
	parlex::literal const v6(U"<-");
	parlex::literal const v7(U"←");
	parlex::choice const v8({v6, v7});
	parlex::reference const v9("IC");
	parlex::repetition const v10(v9);
	parlex::reference const v11("EXPRESSION");
	parlex::sequence const v12("NAND_ASSIGNMENT", {v0, v2, v5, v8, v10, v11});
	return parlex::production("NAND_ASSIGNMENT",v12);
}

static parlex::production NATURAL_NUMBER() {
	parlex::reference const v0("decimal_digit");
	parlex::reference const v1("decimal_digit");
	parlex::repetition const v2(v1);
	parlex::sequence const v3("NATURAL_NUMBER", {v0, v2});
	return parlex::production("NATURAL_NUMBER",v3);
}

static parlex::production NEAREST_INTEGER() {
	parlex::literal const v0(U"⌊");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U"⌉");
	parlex::sequence const v7({v0, v2, v3, v5, v6});
	parlex::literal const v8(U"|_");
	parlex::reference const v9("IC");
	parlex::repetition const v10(v9);
	parlex::reference const v11("EXPRESSION");
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::literal const v14(U"\'|");
	parlex::sequence const v15({v8, v10, v11, v13, v14});
	parlex::choice const v16("NEAREST_INTEGER", {v7, v15});
	return parlex::production("NEAREST_INTEGER",v16);
}

static parlex::production NEGATION() {
	parlex::literal const v0(U"-");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::sequence const v4("NEGATION", {v0, v2, v3});
	return parlex::production("NEGATION",v4, parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", });
}

static parlex::production NEGATION_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"-");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::sequence const v7("NEGATION_ASSIGNMENT", {v0, v2, v3, v6});
	return parlex::production("NEGATION_ASSIGNMENT",v7);
}

static parlex::production NON_FRACTIONAL() {
	parlex::literal const v0(U"-");
	parlex::optional const v1(v0);
	parlex::reference const v2("NON_NEG_NON_FRACTIONAL");
	parlex::sequence const v3("NON_FRACTIONAL", {v1, v2});
	return parlex::production("NON_FRACTIONAL",v3);
}

static parlex::production NON_NEG_FRACTIONAL() {
	parlex::reference const v0("decimal_digit");
	parlex::reference const v1("decimal_digit");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U".");
	parlex::reference const v4("decimal_digit");
	parlex::repetition const v5(v4);
	parlex::sequence const v6({v0, v2, v3, v5});
	parlex::literal const v7(U".");
	parlex::reference const v8("decimal_digit");
	parlex::reference const v9("decimal_digit");
	parlex::repetition const v10(v9);
	parlex::sequence const v11({v7, v8, v10});
	parlex::choice const v12("NON_NEG_FRACTIONAL", {v6, v11});
	return parlex::production("NON_NEG_FRACTIONAL",v12);
}

static parlex::production NON_NEG_INTEGER() {
	parlex::reference const v0("NON_ZERO_DECIMAL_DIGIT");
	parlex::reference const v1("decimal_digit");
	parlex::repetition const v2(v1);
	parlex::sequence const v3({v0, v2});
	parlex::literal const v4(U"0");
	parlex::choice const v5("NON_NEG_INTEGER", {v3, v4});
	return parlex::production("NON_NEG_INTEGER",v5);
}

static parlex::production NON_NEG_NON_FRACTIONAL() {
	parlex::reference const v0("NON_NEG_INTEGER");
	parlex::reference const v1("HEX");
	parlex::reference const v2("OCTAL");
	parlex::choice const v3("NON_NEG_NON_FRACTIONAL", {v0, v1, v2});
	return parlex::production("NON_NEG_NON_FRACTIONAL",v3);
}

static parlex::production NON_NEG_NUMBER() {
	parlex::reference const v0("NON_NEG_NON_FRACTIONAL");
	parlex::reference const v1("NON_NEG_FRACTIONAL");
	parlex::choice const v2("NON_NEG_NUMBER", {v0, v1});
	return parlex::production("NON_NEG_NUMBER",v2);
}

static parlex::production NON_ZERO_DECIMAL_DIGIT() {
	parlex::literal const v0(U"1");
	parlex::literal const v1(U"2");
	parlex::literal const v2(U"3");
	parlex::literal const v3(U"4");
	parlex::literal const v4(U"5");
	parlex::literal const v5(U"6");
	parlex::literal const v6(U"7");
	parlex::literal const v7(U"8");
	parlex::literal const v8(U"9");
	parlex::choice const v9("NON_ZERO_DECIMAL_DIGIT", {v0, v1, v2, v3, v4, v5, v6, v7, v8});
	return parlex::production("NON_ZERO_DECIMAL_DIGIT",v9);
}

static parlex::production NOR() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"↓");
	parlex::literal const v4(U"nor");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("NOR", {v0, v2, v5, v7, v8});
	return parlex::production("NOR",v9, parlex::associativity::LEFT, parlex::filter_function(), {"IFF", "IMPLICATION", "OR", "XOR", });
}

static parlex::production NOR_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"↓");
	parlex::literal const v4(U"nor");
	parlex::choice const v5({v3, v4});
	parlex::literal const v6(U"<-");
	parlex::literal const v7(U"←");
	parlex::choice const v8({v6, v7});
	parlex::reference const v9("IC");
	parlex::repetition const v10(v9);
	parlex::reference const v11("EXPRESSION");
	parlex::sequence const v12("NOR_ASSIGNMENT", {v0, v2, v5, v8, v10, v11});
	return parlex::production("NOR_ASSIGNMENT",v12);
}

static parlex::production NOT() {
	parlex::literal const v0(U"¬");
	parlex::literal const v1(U"~");
	parlex::choice const v2({v0, v1});
	parlex::reference const v3("IC");
	parlex::repetition const v4(v3);
	parlex::reference const v5("EXPRESSION");
	parlex::sequence const v6("NOT", {v2, v4, v5});
	return parlex::production("NOT",v6, parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", });
}

static parlex::production NOT_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"¬");
	parlex::literal const v4(U"~");
	parlex::choice const v5({v3, v4});
	parlex::literal const v6(U"<-");
	parlex::literal const v7(U"←");
	parlex::choice const v8({v6, v7});
	parlex::sequence const v9("NOT_ASSIGNMENT", {v0, v2, v5, v8});
	return parlex::production("NOT_ASSIGNMENT",v9);
}

static parlex::production NOT_HAS() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"∌");
	parlex::literal const v4(U"/has");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("NOT_HAS", {v0, v2, v5, v7, v8});
	return parlex::production("NOT_HAS",v9, parlex::associativity::LEFT);
}

static parlex::production NOT_IN() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"∉");
	parlex::literal const v4(U"/in");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("NOT_IN", {v0, v2, v5, v7, v8});
	return parlex::production("NOT_IN",v9, parlex::associativity::LEFT);
}

static parlex::production NULL_COALESCE() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"\?\?");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("NULL_COALESCE", {v0, v2, v3, v5, v6});
	return parlex::production("NULL_COALESCE",v7, parlex::associativity::LEFT);
}

static parlex::production NULL_COALESCE_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"\?\?");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10("NULL_COALESCE_ASSIGNMENT", {v0, v2, v3, v6, v8, v9});
	return parlex::production("NULL_COALESCE_ASSIGNMENT",v10);
}

static parlex::production OBJECT() {
	parlex::literal const v0(U"object");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"inheriting");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("INHERITANCE_LIST");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::sequence const v9({v3, v5, v6, v8});
	parlex::optional const v10(v9);
	parlex::literal const v11(U"implementing");
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::reference const v14("INHERITANCE_LIST");
	parlex::reference const v15("IC");
	parlex::repetition const v16(v15);
	parlex::sequence const v17({v11, v13, v14, v16});
	parlex::optional const v18(v17);
	parlex::literal const v19(U"{");
	parlex::reference const v20("TYPE_SCOPE");
	parlex::literal const v21(U"}");
	parlex::sequence const v22("OBJECT", {v0, v2, v10, v18, v19, v20, v21});
	return parlex::production("OBJECT",v22);
}

static parlex::production OCTAL() {
	parlex::literal const v0(U"0");
	parlex::reference const v1("octal_digit");
	parlex::reference const v2("octal_digit");
	parlex::repetition const v3(v2);
	parlex::sequence const v4("OCTAL", {v0, v1, v3});
	return parlex::production("OCTAL",v4);
}

static parlex::production OP_ASSIGNMENT() {
	parlex::reference const v0("ADD_SUB_ASSIGNMENT");
	parlex::reference const v1("ADDITION_ASSIGNMENT");
	parlex::reference const v2("AND_ASSIGNMENT");
	parlex::reference const v3("BIT_AND_ASSIGNMENT");
	parlex::reference const v4("BIT_NOT_ASSIGNMENT");
	parlex::reference const v5("BIT_OR_ASSIGNMENT");
	parlex::reference const v6("BIT_XOR_ASSIGNMENT");
	parlex::reference const v7("COMPOUND_ASSIGNMENT");
	parlex::reference const v8("COMPOSITION_ASSIGNMENT");
	parlex::reference const v9("CROSS_PRODUCT_ASSIGNMENT");
	parlex::reference const v10("DIVISION_ASSIGNMENT");
	parlex::reference const v11("EXPONENTIATION_ASSIGNMENT");
	parlex::reference const v12("FACTORIAL_ASSIGNMENT");
	parlex::reference const v13("IMPLICATION_ASSIGNMENT");
	parlex::reference const v14("INTEGER_DIVISION_ASSIGNMENT");
	parlex::reference const v15("INTERSECTION_ASSIGNMENT");
	parlex::reference const v16("MODULATION_ASSIGNMENT");
	parlex::reference const v17("MULTIPLICATION_ASSIGNMENT");
	parlex::reference const v18("NAND_ASSIGNMENT");
	parlex::reference const v19("NEGATION_ASSIGNMENT");
	parlex::reference const v20("NOR_ASSIGNMENT");
	parlex::reference const v21("NOT_ASSIGNMENT");
	parlex::reference const v22("NULL_COALESCE_ASSIGNMENT");
	parlex::reference const v23("OR_ASSIGNMENT");
	parlex::reference const v24("PRE_DEC");
	parlex::reference const v25("PRE_INC");
	parlex::reference const v26("PREPEND_ASSIGNMENT");
	parlex::reference const v27("POST_DEC");
	parlex::reference const v28("POST_INC");
	parlex::reference const v29("RADICAL_ASSIGNMENT");
	parlex::reference const v30("SHIFTL_ASSIGNMENT");
	parlex::reference const v31("SHIFTR_ASSIGNMENT");
	parlex::reference const v32("SUBTRACTION_ASSIGNMENT");
	parlex::reference const v33("SYMMETRIC_DIFFERENCE_ASSIGNMENT");
	parlex::reference const v34("UNION_ASSIGNMENT");
	parlex::reference const v35("XOR_ASSIGNMENT");
	parlex::choice const v36("OP_ASSIGNMENT", {v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35});
	return parlex::production("OP_ASSIGNMENT",v36);
}

static parlex::production OR() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"∨");
	parlex::literal const v4(U"or");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("OR", {v0, v2, v5, v7, v8});
	return parlex::production("OR",v9, parlex::associativity::ANY, parlex::filter_function(), {"IFF", "IMPLICATION", "XOR", });
}

static parlex::production OR_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"∨");
	parlex::literal const v4(U"or");
	parlex::choice const v5({v3, v4});
	parlex::literal const v6(U"<-");
	parlex::literal const v7(U"←");
	parlex::choice const v8({v6, v7});
	parlex::reference const v9("IC");
	parlex::repetition const v10(v9);
	parlex::reference const v11("EXPRESSION");
	parlex::sequence const v12("OR_ASSIGNMENT", {v0, v2, v5, v8, v10, v11});
	return parlex::production("OR_ASSIGNMENT",v12);
}

static parlex::production PARAMETER() {
	parlex::reference const v0("PARAMETER_NATURAL");
	parlex::reference const v1("PARAMETER_ANALYTIC");
	parlex::choice const v2("PARAMETER", {v0, v1});
	return parlex::production("PARAMETER",v2);
}

static parlex::production PARAMETER_ANALYTIC() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"=");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7({v2, v3, v5, v6});
	parlex::optional const v8(v7);
	parlex::sequence const v9("PARAMETER_ANALYTIC", {v0, v8});
	return parlex::production("PARAMETER_ANALYTIC",v9);
}

static parlex::production PARAMETER_NATURAL() {
	parlex::reference const v0("TYPE_DEREFERENCE");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::sequence const v3({v0, v2});
	parlex::optional const v4(v3);
	parlex::reference const v5("IDENTIFIER");
	parlex::literal const v6(U"...");
	parlex::optional const v7(v6);
	parlex::sequence const v8({v4, v5, v7});
	parlex::reference const v9("TYPE_DEREFERENCE");
	parlex::reference const v10("IMPLICIT_TYPE_DEREFERENCE");
	parlex::choice const v11({v9, v10});
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::sequence const v14({v11, v13});
	parlex::optional const v15(v14);
	parlex::reference const v16("IDENTIFIER");
	parlex::literal const v17(U"...");
	parlex::optional const v18(v17);
	parlex::reference const v19("IC");
	parlex::repetition const v20(v19);
	parlex::literal const v21(U"=");
	parlex::reference const v22("IC");
	parlex::repetition const v23(v22);
	parlex::reference const v24("EXPRESSION");
	parlex::literal const v25(U"...");
	parlex::optional const v26(v25);
	parlex::sequence const v27({v15, v16, v18, v20, v21, v23, v24, v26});
	parlex::choice const v28("PARAMETER_NATURAL", {v8, v27});
	return parlex::production("PARAMETER_NATURAL",v28, parlex::associativity::NONE, parlex::filter_function(), {"PARAMETER_ANALYTIC", });
}

static parlex::production PARENTHETICAL() {
	parlex::literal const v0(U"(");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U")");
	parlex::sequence const v7("PARENTHETICAL", {v0, v2, v3, v5, v6});
	return parlex::production("PARENTHETICAL",v7);
}

static parlex::production PARENTHETICAL_INVOCATION() {
	parlex::literal const v0(U"(");
	parlex::reference const v1("IC");
	parlex::repetition const v2("ic", v1);
	parlex::reference const v3("standard_arguments", "STANDARD_ARGUMENTS");
	parlex::reference const v4("IC");
	parlex::repetition const v5("ic", v4);
	parlex::sequence const v6({v3, v5});
	parlex::optional const v7("arguments", v6);
	parlex::literal const v8(U")");
	parlex::sequence const v9("PARENTHETICAL_INVOCATION", {v0, v2, v7, v8});
	return parlex::production("PARENTHETICAL_INVOCATION",v9);
}

static parlex::production PAYLOAD() {
	parlex::reference const v0("all");
	parlex::reference const v1("all");
	parlex::repetition const v2(v1);
	parlex::sequence const v3("PAYLOAD", {v0, v2});
	return parlex::production("PAYLOAD",v3);
}

static parlex::production PLATFORM() {
	parlex::literal const v0(U"_");
	parlex::reference const v1("letter");
	parlex::reference const v2("number");
	parlex::choice const v3({v1, v2});
	parlex::reference const v4("letter");
	parlex::reference const v5("number");
	parlex::literal const v6(U"_");
	parlex::choice const v7({v4, v5, v6});
	parlex::repetition const v8(v7);
	parlex::sequence const v9("PLATFORM", {v0, v3, v8});
	return parlex::production("PLATFORM",v9, parlex::associativity::NONE, parlex::longest());
}

static parlex::production POST_DEC() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"--");
	parlex::sequence const v4("POST_DEC", {v0, v2, v3});
	return parlex::production("POST_DEC",v4, parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", "NEGATION", });
}

static parlex::production POST_INC() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"++");
	parlex::sequence const v4("POST_INC", {v0, v2, v3});
	return parlex::production("POST_INC",v4, parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", "NEGATION", });
}

static parlex::production PREPEND() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"&");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("PREPEND", {v0, v2, v3, v5, v6});
	return parlex::production("PREPEND",v7, parlex::associativity::RIGHT);
}

static parlex::production PREPEND_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"&");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10("PREPEND_ASSIGNMENT", {v0, v2, v3, v6, v8, v9});
	return parlex::production("PREPEND_ASSIGNMENT",v10);
}

static parlex::production PRE_DEC() {
	parlex::literal const v0(U"--");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::sequence const v4("PRE_DEC", {v0, v2, v3});
	return parlex::production("PRE_DEC",v4, parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", "NEGATION", });
}

static parlex::production PRE_INC() {
	parlex::literal const v0(U"++");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::sequence const v4("PRE_INC", {v0, v2, v3});
	return parlex::production("PRE_INC",v4, parlex::associativity::NONE, parlex::filter_function(), {"BINARY_OP", "NEGATION", });
}

static parlex::production RADICAL() {
	parlex::literal const v0(U"√");
	parlex::literal const v1(U"sqrt");
	parlex::choice const v2({v0, v1});
	parlex::reference const v3("IC");
	parlex::repetition const v4(v3);
	parlex::reference const v5("EXPRESSION");
	parlex::sequence const v6("RADICAL", {v2, v4, v5});
	return parlex::production("RADICAL",v6, parlex::associativity::NONE, parlex::filter_function(), {"ADDITION", "ADD_SUB", "DIVISION", "INTEGER_DIVISION", "MODULATION", "MULTIPLICATIVE_OP", "SUBTRACTION", });
}

static parlex::production RADICAL_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"√");
	parlex::literal const v4(U"sqrt");
	parlex::choice const v5({v3, v4});
	parlex::literal const v6(U"<-");
	parlex::literal const v7(U"←");
	parlex::choice const v8({v6, v7});
	parlex::sequence const v9("RADICAL_ASSIGNMENT", {v0, v2, v5, v8});
	return parlex::production("RADICAL_ASSIGNMENT",v9);
}

static parlex::production RANGE() {
	parlex::literal const v0(U"(");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"...");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::literal const v9(U"]");
	parlex::literal const v10(U")");
	parlex::choice const v11({v9, v10});
	parlex::sequence const v12({v0, v2, v3, v5, v6, v8, v11});
	parlex::literal const v13(U"[");
	parlex::literal const v14(U"(");
	parlex::choice const v15({v13, v14});
	parlex::reference const v16("IC");
	parlex::repetition const v17(v16);
	parlex::reference const v18("EXPRESSION");
	parlex::reference const v19("IC");
	parlex::repetition const v20(v19);
	parlex::literal const v21(U"...");
	parlex::reference const v22("IC");
	parlex::repetition const v23(v22);
	parlex::literal const v24(U")");
	parlex::sequence const v25({v15, v17, v18, v20, v21, v23, v24});
	parlex::literal const v26(U"(");
	parlex::literal const v27(U"[");
	parlex::choice const v28({v26, v27});
	parlex::reference const v29("IC");
	parlex::repetition const v30(v29);
	parlex::reference const v31("EXPRESSION");
	parlex::reference const v32("IC");
	parlex::repetition const v33(v32);
	parlex::literal const v34(U"...");
	parlex::reference const v35("IC");
	parlex::repetition const v36(v35);
	parlex::reference const v37("EXPRESSION");
	parlex::reference const v38("IC");
	parlex::repetition const v39(v38);
	parlex::literal const v40(U"]");
	parlex::literal const v41(U")");
	parlex::choice const v42({v40, v41});
	parlex::sequence const v43({v28, v30, v31, v33, v34, v36, v37, v39, v42});
	parlex::choice const v44("RANGE", {v12, v25, v43});
	return parlex::production("RANGE",v44);
}

static parlex::production READ_LOCK() {
	parlex::literal const v0(U"read_lock");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("PARENTHETICAL");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("READ_LOCK", {v0, v2, v3, v5, v6});
	return parlex::production("READ_LOCK",v7);
}

static parlex::production RECORD() {
	parlex::literal const v0(U"record");
	parlex::reference const v1("IC");
	parlex::reference const v2("IC");
	parlex::repetition const v3(v2);
	parlex::reference const v4("TYPE");
	parlex::sequence const v5("RECORD", {v0, v1, v3, v4});
	return parlex::production("RECORD",v5);
}

static parlex::production REGEX() {
	parlex::literal const v0(U"R");
	parlex::reference const v1("c_string");
	parlex::sequence const v2("REGEX", {v0, v1});
	return parlex::production("REGEX",v2);
}

static parlex::production RELATIONAL_COLLECTION_OP() {
	parlex::reference const v0("HAS");
	parlex::reference const v1("IN");
	parlex::reference const v2("NOT_HAS");
	parlex::reference const v3("NOT_IN");
	parlex::choice const v4("RELATIONAL_COLLECTION_OP", {v0, v1, v2, v3});
	return parlex::production("RELATIONAL_COLLECTION_OP",v4);
}

static parlex::production RELATIONAL_OP() {
	parlex::reference const v0("CASTS");
	parlex::reference const v1("DOWNCASTS");
	parlex::reference const v2("EXACTLY");
	parlex::reference const v3("IMPLEMENTS");
	parlex::reference const v4("INEQUALITY");
	parlex::reference const v5("INHERITS");
	parlex::reference const v6("IS");
	parlex::reference const v7("RELATIONAL_COLLECTION_OP");
	parlex::reference const v8("UPCASTS");
	parlex::choice const v9("RELATIONAL_OP", {v0, v1, v2, v3, v4, v5, v6, v7, v8});
	return parlex::production("RELATIONAL_OP",v9, parlex::associativity::NONE, parlex::filter_function(), {"BINARY_LOGICAL_OP", });
}

static parlex::production RETURN() {
	parlex::literal const v0(U"return");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"[");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::literal const v9(U"]");
	parlex::sequence const v10({v2, v3, v5, v6, v8, v9});
	parlex::optional const v11(v10);
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::reference const v14("EXPRESSION");
	parlex::sequence const v15({v13, v14});
	parlex::optional const v16(v15);
	parlex::sequence const v17("RETURN", {v0, v11, v16});
	return parlex::production("RETURN",v17);
}

static parlex::production SET() {
	parlex::literal const v0(U"{|");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U",");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10({v5, v6, v8, v9});
	parlex::repetition const v11(v10);
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::sequence const v14({v3, v11, v13});
	parlex::optional const v15("elements", v14);
	parlex::literal const v16(U"|}");
	parlex::sequence const v17("SET", {v0, v2, v15, v16});
	return parlex::production("SET",v17, parlex::associativity::NONE, parlex::filter_function(), {"MAGNITUDE", });
}

static parlex::production SET_COMPREHENSION() {
	parlex::literal const v0(U"{");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U"|");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::reference const v10("IC");
	parlex::repetition const v11(v10);
	parlex::literal const v12(U"}");
	parlex::sequence const v13("SET_COMPREHENSION", {v0, v2, v3, v5, v6, v8, v9, v11, v12});
	return parlex::production("SET_COMPREHENSION",v13);
}

static parlex::production SHIFTL() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"<<");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("SHIFTL", {v0, v2, v3, v5, v6});
	return parlex::production("SHIFTL",v7, parlex::associativity::LEFT);
}

static parlex::production SHIFTL_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"<<");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10("SHIFTL_ASSIGNMENT", {v0, v2, v3, v6, v8, v9});
	return parlex::production("SHIFTL_ASSIGNMENT",v10);
}

static parlex::production SHIFTR() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U">>");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("SHIFTR", {v0, v2, v3, v5, v6});
	return parlex::production("SHIFTR",v7, parlex::associativity::LEFT);
}

static parlex::production SHIFTR_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U">>");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10("SHIFTR_ASSIGNMENT", {v0, v2, v3, v6, v8, v9});
	return parlex::production("SHIFTR_ASSIGNMENT",v10);
}

static parlex::production SLICE() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U":");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("SLICE", {v0, v2, v3, v5, v6});
	return parlex::production("SLICE",v7);
}

static parlex::production STANDARD_ARGUMENTS() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("ARGUMENT_PACK");
	parlex::choice const v2("argument", {v0, v1});
	parlex::optional const v3("head", v2);
	parlex::reference const v4("IC");
	parlex::repetition const v5("ic", v4);
	parlex::literal const v6(U",");
	parlex::reference const v7("IC");
	parlex::repetition const v8("ic", v7);
	parlex::reference const v9("EXPRESSION");
	parlex::reference const v10("ARGUMENT_PACK");
	parlex::choice const v11("argument", {v9, v10});
	parlex::sequence const v12({v8, v11});
	parlex::optional const v13(v12);
	parlex::sequence const v14({v5, v6, v13});
	parlex::repetition const v15("tail", v14);
	parlex::sequence const v16("STANDARD_ARGUMENTS", {v3, v15});
	return parlex::production("STANDARD_ARGUMENTS",v16);
}

static parlex::production STATEMENT() {
	parlex::reference const v0("ASSIGNMENT");
	parlex::reference const v1("BREAK");
	parlex::reference const v2("CONTINUE");
	parlex::reference const v3("DEFINITION");
	parlex::reference const v4("DO");
	parlex::reference const v5("EXPRESSION");
	parlex::reference const v6("FOR");
	parlex::reference const v7("FOR_COLLECTION");
	parlex::reference const v8("FREE");
	parlex::reference const v9("IMPORT");
	parlex::reference const v10("LOCK");
	parlex::reference const v11("LOOP");
	parlex::reference const v12("OP_ASSIGNMENT");
	parlex::reference const v13("READ_LOCK");
	parlex::reference const v14("RETURN");
	parlex::reference const v15("THROW");
	parlex::reference const v16("TRY");
	parlex::reference const v17("TYPE_CONSTRAINT");
	parlex::reference const v18("WRITE_LOCK");
	parlex::reference const v19("USING");
	parlex::choice const v20("value", {v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19});
	parlex::reference const v21("IC");
	parlex::repetition const v22("ic", v21);
	parlex::literal const v23(U";");
	parlex::sequence const v24("STATEMENT", {v20, v22, v23});
	return parlex::production("STATEMENT",v24);
}

static parlex::production STATEMENT_SCOPE() {
	parlex::reference const v0("IC");
	parlex::reference const v1("STATEMENT");
	parlex::choice const v2({v0, v1});
	parlex::repetition const v3("STATEMENT_SCOPE", v2);
	return parlex::production("STATEMENT_SCOPE",v3);
}

static parlex::production SUBSET() {
	parlex::reference const v0("expression", "EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2("ic", v1);
	parlex::reference const v3("subset_node", "SUBSET_NODE");
	parlex::sequence const v4("SUBSET", {v0, v2, v3});
	return parlex::production("SUBSET",v4);
}

static parlex::production SUBSET_NODE() {
	parlex::literal const v0(U"=");
	parlex::literal const v1(U"⊆");
	parlex::literal const v2(U"subs");
	parlex::literal const v3(U"⊂");
	parlex::literal const v4(U"psubs");
	parlex::choice const v5({v0, v1, v2, v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7("ic", v6);
	parlex::reference const v8("expression", "EXPRESSION");
	parlex::reference const v9("IC");
	parlex::repetition const v10("ic", v9);
	parlex::reference const v11("subset_node", "SUBSET_NODE");
	parlex::sequence const v12({v10, v11});
	parlex::optional const v13(v12);
	parlex::sequence const v14("SUBSET_NODE", {v5, v7, v8, v13});
	return parlex::production("SUBSET_NODE",v14, parlex::associativity::NONE, parlex::filter_function(), {"EXPRESSION", });
}

static parlex::production SUBTRACTION() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"-");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("SUBTRACTION", {v0, v2, v3, v5, v6});
	return parlex::production("SUBTRACTION",v7, parlex::associativity::LEFT);
}

static parlex::production SUBTRACTION_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"-");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10("SUBTRACTION_ASSIGNMENT", {v0, v2, v3, v6, v8, v9});
	return parlex::production("SUBTRACTION_ASSIGNMENT",v10);
}

static parlex::production SUPERSET() {
	parlex::reference const v0("expression", "EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2("ic", v1);
	parlex::reference const v3("superset_node", "SUPERSET_NODE");
	parlex::sequence const v4("SUPERSET", {v0, v2, v3});
	return parlex::production("SUPERSET",v4);
}

static parlex::production SUPERSET_NODE() {
	parlex::literal const v0(U"=");
	parlex::literal const v1(U"⊇");
	parlex::literal const v2(U"sups");
	parlex::literal const v3(U"⊃");
	parlex::literal const v4(U"psups");
	parlex::choice const v5({v0, v1, v2, v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7("ic", v6);
	parlex::reference const v8("expression", "EXPRESSION");
	parlex::reference const v9("IC");
	parlex::repetition const v10("ic", v9);
	parlex::reference const v11("superset_node", "SUPERSET_NODE");
	parlex::sequence const v12({v10, v11});
	parlex::optional const v13(v12);
	parlex::sequence const v14("SUPERSET_NODE", {v5, v7, v8, v13});
	return parlex::production("SUPERSET_NODE",v14, parlex::associativity::NONE, parlex::filter_function(), {"EXPRESSION", });
}

static parlex::production SWIZZLE() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"⋮");
	parlex::literal const v4(U"_swiz_");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("SWIZZLE", {v0, v2, v5, v7, v8});
	return parlex::production("SWIZZLE",v9);
}

static parlex::production SYMMETRIC_DIFFERENCE() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"⊖");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("SYMMETRIC_DIFFERENCE", {v0, v2, v3, v5, v6});
	return parlex::production("SYMMETRIC_DIFFERENCE",v7, parlex::associativity::LEFT);
}

static parlex::production SYMMETRIC_DIFFERENCE_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"⊖");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10("SYMMETRIC_DIFFERENCE_ASSIGNMENT", {v0, v2, v3, v6, v8, v9});
	return parlex::production("SYMMETRIC_DIFFERENCE_ASSIGNMENT",v10);
}

static parlex::production THIS() {
	parlex::literal const v0(U"this");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"[");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::literal const v9(U"]");
	parlex::sequence const v10({v2, v3, v5, v6, v8, v9});
	parlex::optional const v11(v10);
	parlex::sequence const v12("THIS", {v0, v11});
	return parlex::production("THIS",v12);
}

static parlex::production THIS_FUNC() {
	parlex::literal const v0(U"this_func");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"[");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::literal const v9(U"]");
	parlex::sequence const v10({v2, v3, v5, v6, v8, v9});
	parlex::optional const v11(v10);
	parlex::sequence const v12("THIS_FUNC", {v0, v11});
	return parlex::production("THIS_FUNC",v12);
}

static parlex::production THIS_TYPE() {
	parlex::literal const v0(U"this_type");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"[");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::literal const v9(U"]");
	parlex::sequence const v10({v2, v3, v5, v6, v8, v9});
	parlex::optional const v11(v10);
	parlex::sequence const v12("THIS_TYPE", {v0, v11});
	return parlex::production("THIS_TYPE",v12);
}

static parlex::production THROW() {
	parlex::literal const v0(U"throw");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"[");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::literal const v9(U"]");
	parlex::sequence const v10({v2, v3, v5, v6, v8, v9});
	parlex::optional const v11(v10);
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::reference const v14("EXPRESSION");
	parlex::sequence const v15({v13, v14});
	parlex::optional const v16(v15);
	parlex::sequence const v17("THROW", {v0, v11, v16});
	return parlex::production("THROW",v17);
}

static parlex::production TIME() {
	parlex::literal const v0(U"-");
	parlex::optional const v1(v0);
	parlex::reference const v2("decimal_digit");
	parlex::reference const v3("decimal_digit");
	parlex::literal const v4(U":");
	parlex::reference const v5("decimal_digit");
	parlex::reference const v6("decimal_digit");
	parlex::literal const v7(U":");
	parlex::reference const v8("decimal_digit");
	parlex::reference const v9("decimal_digit");
	parlex::literal const v10(U".");
	parlex::reference const v11("decimal_digit");
	parlex::reference const v12("decimal_digit");
	parlex::repetition const v13(v12);
	parlex::sequence const v14({v10, v11, v13});
	parlex::optional const v15(v14);
	parlex::literal const v16(U"Z");
	parlex::literal const v17(U"+");
	parlex::literal const v18(U"-");
	parlex::choice const v19({v17, v18});
	parlex::reference const v20("decimal_digit");
	parlex::reference const v21("decimal_digit");
	parlex::literal const v22(U":");
	parlex::reference const v23("decimal_digit");
	parlex::reference const v24("decimal_digit");
	parlex::sequence const v25({v22, v23, v24});
	parlex::optional const v26(v25);
	parlex::sequence const v27({v19, v20, v21, v26});
	parlex::choice const v28({v16, v27});
	parlex::optional const v29(v28);
	parlex::sequence const v30("TIME", {v1, v2, v3, v4, v5, v6, v7, v8, v9, v15, v29});
	return parlex::production("TIME",v30);
}

static parlex::production TRY() {
	parlex::literal const v0(U"try");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U"catch");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::literal const v10(U"catch");
	parlex::reference const v11("IC");
	parlex::repetition const v12(v11);
	parlex::reference const v13("EXPRESSION");
	parlex::sequence const v14({v10, v12, v13});
	parlex::repetition const v15(v14);
	parlex::reference const v16("IC");
	parlex::repetition const v17(v16);
	parlex::literal const v18(U"finally");
	parlex::reference const v19("IC");
	parlex::repetition const v20(v19);
	parlex::reference const v21("EXPRESSION");
	parlex::sequence const v22({v17, v18, v20, v21});
	parlex::optional const v23(v22);
	parlex::sequence const v24("TRY", {v0, v2, v3, v5, v6, v8, v9, v15, v23});
	return parlex::production("TRY",v24);
}

static parlex::production TUPLE() {
	parlex::literal const v0(U"(|");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U",");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10({v5, v6, v8, v9});
	parlex::repetition const v11(v10);
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::literal const v14(U"|)");
	parlex::sequence const v15("TUPLE", {v0, v2, v3, v11, v13, v14});
	return parlex::production("TUPLE",v15, parlex::associativity::NONE, parlex::filter_function(), {"MAGNITUDE", });
}

static parlex::production TYPE() {
	parlex::literal const v0(U"type");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"inheriting");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("INHERITANCE_LIST");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::sequence const v9({v3, v5, v6, v8});
	parlex::optional const v10(v9);
	parlex::literal const v11(U"implementing");
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::reference const v14("INHERITANCE_LIST");
	parlex::reference const v15("IC");
	parlex::repetition const v16(v15);
	parlex::sequence const v17({v11, v13, v14, v16});
	parlex::optional const v18(v17);
	parlex::literal const v19(U"{");
	parlex::reference const v20("TYPE_SCOPE");
	parlex::literal const v21(U"}");
	parlex::sequence const v22("TYPE", {v0, v2, v10, v18, v19, v20, v21});
	return parlex::production("TYPE",v22);
}

static parlex::production TYPE_CONSTRAINT() {
	parlex::reference const v0("specification", "TYPE_CONSTRAINT_SPECIFICATION");
	parlex::reference const v1("IC");
	parlex::repetition const v2("ic", v1);
	parlex::reference const v3("head", "TYPE_CONSTRAINT_ELEMENT");
	parlex::reference const v4("IC");
	parlex::repetition const v5("ic1", v4);
	parlex::literal const v6(U",");
	parlex::reference const v7("IC");
	parlex::repetition const v8("ic2", v7);
	parlex::reference const v9("type_constraint_element", "TYPE_CONSTRAINT_ELEMENT");
	parlex::sequence const v10({v5, v6, v8, v9});
	parlex::repetition const v11("tail", v10);
	parlex::sequence const v12("TYPE_CONSTRAINT", {v0, v2, v3, v11});
	return parlex::production("TYPE_CONSTRAINT",v12, parlex::associativity::NONE, parlex::filter_function(), {"EXPRESSION", });
}

static parlex::production TYPE_CONSTRAINT_DECLARATION() {
	parlex::reference const v0("identifier_specification", "IDENTIFIER_SPECIFICATION");
	parlex::reference const v1("IC");
	parlex::repetition const v2("ic", v1);
	parlex::reference const v3("parenthetical_invocation", "PARENTHETICAL_INVOCATION");
	parlex::sequence const v4({v2, v3});
	parlex::optional const v5("args", v4);
	parlex::sequence const v6("TYPE_CONSTRAINT_DECLARATION", {v0, v5});
	return parlex::production("TYPE_CONSTRAINT_DECLARATION",v6);
}

static parlex::production TYPE_CONSTRAINT_ELEMENT() {
	parlex::reference const v0("TYPE_CONSTRAINT_DECLARATION");
	parlex::reference const v1("ASSIGNMENT");
	parlex::reference const v2("DEFINITION");
	parlex::choice const v3("TYPE_CONSTRAINT_ELEMENT", {v0, v1, v2});
	return parlex::production("TYPE_CONSTRAINT_ELEMENT",v3);
}

static parlex::production TYPE_CONSTRAINT_SPECIFICATION() {
	parlex::reference const v0("xml_doc_string", "XML_DOC_STRING");
	parlex::optional const v1("doc", v0);
	parlex::reference const v2("attribute", "ATTRIBUTE");
	parlex::reference const v3("IC");
	parlex::repetition const v4("ic", v3);
	parlex::sequence const v5({v2, v4});
	parlex::repetition const v6("attributes", v5);
	parlex::reference const v7("visibility_modifier", "VISIBILITY_MODIFIER");
	parlex::reference const v8("IC");
	parlex::repetition const v9("ic", v8);
	parlex::sequence const v10({v7, v9});
	parlex::optional const v11("visibility", v10);
	parlex::literal const v12(U"static");
	parlex::reference const v13("IC");
	parlex::repetition const v14(v13);
	parlex::sequence const v15({v12, v14});
	parlex::optional const v16("static_", v15);
	parlex::literal const v17(U"extern");
	parlex::reference const v18("IC");
	parlex::repetition const v19(v18);
	parlex::sequence const v20({v17, v19});
	parlex::optional const v21("extern_", v20);
	parlex::reference const v22("TYPE_DEREFERENCE");
	parlex::reference const v23("VOLATILE_TYPE_DEREFERENCE");
	parlex::reference const v24("IMPLICIT_TYPE_DEREFERENCE");
	parlex::reference const v25("VOLATILE_IMPLICIT_TYPE_DEREFERENCE");
	parlex::choice const v26("type_dereference", {v22, v23, v24, v25});
	parlex::sequence const v27("TYPE_CONSTRAINT_SPECIFICATION", {v1, v6, v11, v16, v21, v26});
	return parlex::production("TYPE_CONSTRAINT_SPECIFICATION",v27);
}

static parlex::production TYPE_DEREFERENCE() {
	parlex::literal const v0(U"<");
	parlex::reference const v1("IC");
	parlex::repetition const v2("ic1", v1);
	parlex::reference const v3("expression", "EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5("ic2", v4);
	parlex::literal const v6(U">");
	parlex::sequence const v7("TYPE_DEREFERENCE", {v0, v2, v3, v5, v6});
	return parlex::production("TYPE_DEREFERENCE",v7);
}

static parlex::production TYPE_INVOCATION() {
	parlex::literal const v0(U"<");
	parlex::reference const v1("IC");
	parlex::repetition const v2("ic", v1);
	parlex::reference const v3("standard_arguments", "STANDARD_ARGUMENTS");
	parlex::reference const v4("IC");
	parlex::repetition const v5("ic", v4);
	parlex::sequence const v6({v3, v5});
	parlex::optional const v7("arguments", v6);
	parlex::literal const v8(U">");
	parlex::sequence const v9("TYPE_INVOCATION", {v0, v2, v7, v8});
	return parlex::production("TYPE_INVOCATION",v9);
}

static parlex::production TYPE_SCOPE() {
	parlex::reference const v0("IC");
	parlex::repetition const v1(v0);
	parlex::reference const v2("TYPE_STATEMENT");
	parlex::reference const v3("IC");
	parlex::repetition const v4(v3);
	parlex::sequence const v5({v2, v4});
	parlex::repetition const v6(v5);
	parlex::sequence const v7("TYPE_SCOPE", {v1, v6});
	return parlex::production("TYPE_SCOPE",v7);
}

static parlex::production TYPE_SCOPE_ASSIGNMENT() {
	parlex::reference const v0("identifier_specification", "IDENTIFIER_SPECIFICATION");
	parlex::reference const v1("IC");
	parlex::repetition const v2("ic", v1);
	parlex::reference const v3("member_offset", "MEMBER_OFFSET");
	parlex::reference const v4("IC");
	parlex::repetition const v5("ic", v4);
	parlex::sequence const v6({v3, v5});
	parlex::optional const v7(v6);
	parlex::reference const v8("type_scope_assignment_node", "TYPE_SCOPE_ASSIGNMENT_NODE");
	parlex::sequence const v9("TYPE_SCOPE_ASSIGNMENT", {v0, v2, v7, v8});
	return parlex::production("TYPE_SCOPE_ASSIGNMENT",v9, parlex::associativity::NONE, parlex::filter_function(), {"EXPRESSION", });
}

static parlex::production TYPE_SCOPE_ASSIGNMENT_NODE() {
	parlex::literal const v0(U"←");
	parlex::literal const v1(U"<-");
	parlex::choice const v2({v0, v1});
	parlex::reference const v3("IC");
	parlex::repetition const v4("ic", v3);
	parlex::reference const v5("expression", "EXPRESSION");
	parlex::reference const v6("identifier_specification", "IDENTIFIER_SPECIFICATION");
	parlex::reference const v7("MEMBER_OFFSET");
	parlex::reference const v8("IC");
	parlex::repetition const v9("ic", v8);
	parlex::sequence const v10({v7, v9});
	parlex::optional const v11(v10);
	parlex::reference const v12("IC");
	parlex::repetition const v13(v12);
	parlex::reference const v14("next", "TYPE_SCOPE_ASSIGNMENT_NODE");
	parlex::sequence const v15({v6, v11, v13, v14});
	parlex::choice const v16({v5, v15});
	parlex::sequence const v17("TYPE_SCOPE_ASSIGNMENT_NODE", {v2, v4, v16});
	return parlex::production("TYPE_SCOPE_ASSIGNMENT_NODE",v17);
}

static parlex::production TYPE_SCOPE_TYPE_CONSTRAINT() {
	parlex::reference const v0("constraint", "TYPE_CONSTRAINT_SPECIFICATION");
	parlex::reference const v1("IC");
	parlex::repetition const v2("ic", v1);
	parlex::reference const v3("head", "TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT");
	parlex::reference const v4("IC");
	parlex::repetition const v5("ic1", v4);
	parlex::literal const v6(U",");
	parlex::reference const v7("IC");
	parlex::repetition const v8("ic2", v7);
	parlex::reference const v9("TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT");
	parlex::sequence const v10({v5, v6, v8, v9});
	parlex::repetition const v11("tail", v10);
	parlex::sequence const v12("TYPE_SCOPE_TYPE_CONSTRAINT", {v0, v2, v3, v11});
	return parlex::production("TYPE_SCOPE_TYPE_CONSTRAINT",v12, parlex::associativity::NONE, parlex::filter_function(), {"TYPE_CONSTRAINT", });
}

static parlex::production TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION() {
	parlex::reference const v0("identifier_specification", "IDENTIFIER_SPECIFICATION");
	parlex::reference const v1("IC");
	parlex::repetition const v2("ic", v1);
	parlex::reference const v3("PARENTHETICAL_INVOCATION");
	parlex::sequence const v4({v2, v3});
	parlex::optional const v5("args", v4);
	parlex::reference const v6("IC");
	parlex::repetition const v7("ic", v6);
	parlex::reference const v8("member_offset", "MEMBER_OFFSET");
	parlex::sequence const v9({v7, v8});
	parlex::optional const v10(v9);
	parlex::sequence const v11("TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION", {v0, v5, v10});
	return parlex::production("TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION",v11);
}

static parlex::production TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT() {
	parlex::reference const v0("TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION");
	parlex::reference const v1("TYPE_SCOPE_ASSIGNMENT");
	parlex::reference const v2("DEFINITION");
	parlex::choice const v3("TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT", {v0, v1, v2});
	return parlex::production("TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT",v3);
}

static parlex::production TYPE_STATEMENT() {
	parlex::reference const v0("VISIBILITY_MODIFIER");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U":");
	parlex::sequence const v4({v0, v2, v3});
	parlex::reference const v5("TYPE_SCOPE_TYPE_CONSTRAINT");
	parlex::reference const v6("STATEMENT");
	parlex::choice const v7({v4, v5, v6});
	parlex::literal const v8(U";");
	parlex::sequence const v9("TYPE_STATEMENT", {v7, v8});
	return parlex::production("TYPE_STATEMENT",v9);
}

static parlex::production UNARY_ARITHMETIC_OP() {
	parlex::reference const v0("FACTORIAL");
	parlex::reference const v1("NEGATION");
	parlex::reference const v2("RADICAL");
	parlex::choice const v3("UNARY_ARITHMETIC_OP", {v0, v1, v2});
	return parlex::production("UNARY_ARITHMETIC_OP",v3);
}

static parlex::production UNARY_LOGICAL_OP() {
	parlex::reference const v0("ALL");
	parlex::reference const v1("EXISTS");
	parlex::reference const v2("EXISTS_ONE");
	parlex::reference const v3("NOT");
	parlex::choice const v4("UNARY_LOGICAL_OP", {v0, v1, v2, v3});
	return parlex::production("UNARY_LOGICAL_OP",v4, parlex::associativity::NONE, parlex::filter_function(), {"BINARY_LOGICAL_OP", });
}

static parlex::production UNARY_OP() {
	parlex::reference const v0("ALLOCATION");
	parlex::reference const v1("CARDINALITY");
	parlex::reference const v2("KLEENE_STAR");
	parlex::reference const v3("UNARY_ARITHMETIC_OP");
	parlex::reference const v4("UNARY_LOGICAL_OP");
	parlex::choice const v5("UNARY_OP", {v0, v1, v2, v3, v4});
	return parlex::production("UNARY_OP",v5);
}

static parlex::production UNION() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"∪");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("UNION", {v0, v2, v3, v5, v6});
	return parlex::production("UNION",v7, parlex::associativity::ANY);
}

static parlex::production UNION_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"∪");
	parlex::literal const v4(U"<-");
	parlex::literal const v5(U"←");
	parlex::choice const v6({v4, v5});
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::reference const v9("EXPRESSION");
	parlex::sequence const v10("UNION_ASSIGNMENT", {v0, v2, v3, v6, v8, v9});
	return parlex::production("UNION_ASSIGNMENT",v10);
}

static parlex::production UNIT_DIVISION() {
	parlex::reference const v0("DIMENSION");
	parlex::literal const v1(U"/");
	parlex::reference const v2("DIMENSION");
	parlex::sequence const v3("UNIT_DIVISION", {v0, v1, v2});
	return parlex::production("UNIT_DIVISION",v3, parlex::associativity::LEFT);
}

static parlex::production UNIT_EXPONENTIATION() {
	parlex::reference const v0("DIMENSION");
	parlex::literal const v1(U"^");
	parlex::reference const v2("NON_FRACTIONAL");
	parlex::sequence const v3("UNIT_EXPONENTIATION", {v0, v1, v2});
	return parlex::production("UNIT_EXPONENTIATION",v3, parlex::associativity::RIGHT, parlex::filter_function(), {"UNIT_DIVISION", "UNIT_MULTIPLICATION", });
}

static parlex::production UNIT_MULTIPLICATION() {
	parlex::reference const v0("DIMENSION");
	parlex::literal const v1(U"*");
	parlex::reference const v2("DIMENSION");
	parlex::sequence const v3("UNIT_MULTIPLICATION", {v0, v1, v2});
	return parlex::production("UNIT_MULTIPLICATION",v3, parlex::associativity::LEFT);
}

static parlex::production UPCASTS() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"upcasts");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("UPCASTS", {v0, v2, v3, v5, v6});
	return parlex::production("UPCASTS",v7);
}

static parlex::production USING() {
	parlex::literal const v0(U"using");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"(");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::reference const v7("IC");
	parlex::repetition const v8(v7);
	parlex::literal const v9(U")");
	parlex::reference const v10("IC");
	parlex::repetition const v11(v10);
	parlex::reference const v12("BLOCK");
	parlex::sequence const v13("USING", {v0, v2, v3, v5, v6, v8, v9, v11, v12});
	return parlex::production("USING",v13);
}

static parlex::production VECTOR_NORM() {
	parlex::literal const v0(U"||");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("EXPRESSION");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U"||");
	parlex::sequence const v7("VECTOR_NORM", {v0, v2, v3, v5, v6});
	return parlex::production("VECTOR_NORM",v7);
}

static parlex::production VISIBILITY_MODIFIER() {
	parlex::literal const v0(U"public");
	parlex::literal const v1(U"protected");
	parlex::literal const v2(U"protected internal");
	parlex::literal const v3(U"internal");
	parlex::literal const v4(U"private");
	parlex::choice const v5("VISIBILITY_MODIFIER", {v0, v1, v2, v3, v4});
	return parlex::production("VISIBILITY_MODIFIER",v5);
}

static parlex::production VOLATILE_IMPLICIT_TYPE_DEREFERENCE() {
	parlex::literal const v0(U"<");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"volatile");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::literal const v6(U">");
	parlex::sequence const v7("VOLATILE_IMPLICIT_TYPE_DEREFERENCE", {v0, v2, v3, v5, v6});
	return parlex::production("VOLATILE_IMPLICIT_TYPE_DEREFERENCE",v7);
}

static parlex::production VOLATILE_TYPE_DEREFERENCE() {
	parlex::literal const v0(U"<");
	parlex::reference const v1("IC");
	parlex::repetition const v2("ic1", v1);
	parlex::literal const v3(U"volatile");
	parlex::reference const v4("IC");
	parlex::repetition const v5("ic2", v4);
	parlex::reference const v6("expression", "EXPRESSION");
	parlex::reference const v7("IC");
	parlex::repetition const v8("ic3", v7);
	parlex::literal const v9(U">");
	parlex::sequence const v10("VOLATILE_TYPE_DEREFERENCE", {v0, v2, v3, v5, v6, v8, v9});
	return parlex::production("VOLATILE_TYPE_DEREFERENCE",v10);
}

static parlex::production WHOLE_NUMBER() {
	parlex::literal const v0(U"0");
	parlex::repetition const v1(v0);
	parlex::reference const v2("NON_ZERO_DECIMAL_DIGIT");
	parlex::reference const v3("decimal_digit");
	parlex::repetition const v4(v3);
	parlex::sequence const v5("WHOLE_NUMBER", {v1, v2, v4});
	return parlex::production("WHOLE_NUMBER",v5);
}

static parlex::production WRITE_LOCK() {
	parlex::literal const v0(U"write_lock");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::reference const v3("PARENTHETICAL");
	parlex::reference const v4("IC");
	parlex::repetition const v5(v4);
	parlex::reference const v6("EXPRESSION");
	parlex::sequence const v7("WRITE_LOCK", {v0, v2, v3, v5, v6});
	return parlex::production("WRITE_LOCK",v7);
}

static parlex::production WS() {
	parlex::reference const v0("white_space");
	parlex::reference const v1("white_space");
	parlex::repetition const v2(v1);
	parlex::sequence const v3("WS", {v0, v2});
	return parlex::production("WS",v3, parlex::associativity::NONE, parlex::longest());
}

static parlex::production XML_DOC_STRING() {
	parlex::literal const v0(U"```");
	parlex::reference const v1("interior", "XML_DOC_STRING_INTERIOR");
	parlex::literal const v2(U"```");
	parlex::reference const v3("IC");
	parlex::repetition const v4("ic", v3);
	parlex::sequence const v5("XML_DOC_STRING", {v0, v1, v2, v4});
	return parlex::production("XML_DOC_STRING",v5);
}

static parlex::production XML_DOC_STRING_INTERIOR() {
	parlex::reference const v0("payload", "PAYLOAD");
	parlex::literal const v1(U"`");
	parlex::reference const v2("interior", "XML_DOC_STRING_INTERIOR");
	parlex::literal const v3(U"`");
	parlex::sequence const v4({v1, v2, v3});
	parlex::choice const v5("XML_DOC_STRING_INTERIOR", {v0, v4});
	return parlex::production("XML_DOC_STRING_INTERIOR",v5, parlex::associativity::NONE, parlex::filter_function(), {"PAYLOAD", });
}

static parlex::production XOR() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"⊕");
	parlex::literal const v4(U"xor");
	parlex::choice const v5({v3, v4});
	parlex::reference const v6("IC");
	parlex::repetition const v7(v6);
	parlex::reference const v8("EXPRESSION");
	parlex::sequence const v9("XOR", {v0, v2, v5, v7, v8});
	return parlex::production("XOR",v9, parlex::associativity::LEFT);
}

static parlex::production XOR_ASSIGNMENT() {
	parlex::reference const v0("EXPRESSION");
	parlex::reference const v1("IC");
	parlex::repetition const v2(v1);
	parlex::literal const v3(U"⊕");
	parlex::literal const v4(U"xor");
	parlex::choice const v5({v3, v4});
	parlex::literal const v6(U"<-");
	parlex::literal const v7(U"←");
	parlex::choice const v8({v6, v7});
	parlex::reference const v9("IC");
	parlex::repetition const v10(v9);
	parlex::reference const v11("EXPRESSION");
	parlex::sequence const v12("XOR_ASSIGNMENT", {v0, v2, v5, v8, v10, v11});
	return parlex::production("XOR_ASSIGNMENT",v12);
}

static parlex::builder const & builder() {
	static parlex::builder const result("STATEMENT_SCOPE", {
		ADDITION(),
		ADDITION_ASSIGNMENT(),
		ADD_SUB(),
		ADD_SUB_ASSIGNMENT(),
		ALL(),
		ALLOCATION(),
		AND(),
		AND_ASSIGNMENT(),
		ARGUMENT_PACK(),
		ARRAY(),
		ARRAY_ARGUMENTS(),
		ARRAY_INDEXER(),
		ARRAY_INVOCATION(),
		ASM_EXPRESSION(),
		ASM_FUNCTION(),
		ASM_IDENTIFIER(),
		ASM_OP(),
		ASM_PTR_ARITHMETIC_ATT(),
		ASM_PTR_ARITHMETIC_ATT_REG(),
		ASM_PTR_ARITHMETIC_INTEL(),
		ASM_SCOPE(),
		ASM_STATEMENT(),
		ASSIGNMENT(),
		ASSIGNMENT_NODE(),
		ATTRIBUTE(),
		BIJECTION(),
		BINARY_ARITHMETIC_OP(),
		BINARY_COLLECTION_OP(),
		BINARY_LOGICAL_OP(),
		BINARY_OP(),
		BITWISE_OP(),
		BIT_AND(),
		BIT_AND_ASSIGNMENT(),
		BIT_NOT(),
		BIT_NOT_ASSIGNMENT(),
		BIT_OR(),
		BIT_OR_ASSIGNMENT(),
		BIT_XOR(),
		BIT_XOR_ASSIGNMENT(),
		BLOCK(),
		BOOL(),
		BREAK(),
		CARDINALITY(),
		CAST(),
		CASTS(),
		CEILING(),
		COMMENT(),
		COMPLEMENT(),
		COMPOSITION(),
		COMPOSITION_ASSIGNMENT(),
		COMPOUND(),
		COMPOUND_ASSIGNMENT(),
		CONDITIONAL(),
		CONSTRUCTIVE_OP(),
		CONTINUE(),
		CROSS_PRODUCT(),
		CROSS_PRODUCT_ASSIGNMENT(),
		DATE(),
		DATE_TIME(),
		DATE_YEAR_DAY(),
		DATE_YEAR_MONTH_DAY(),
		DEFINITION(),
		DELTA(),
		DIMENSION(),
		DIMENSIONAL_ANALYSIS_OP(),
		DIMENSIONAL_NUMBER(),
		DIVISION(),
		DIVISION_ASSIGNMENT(),
		DO(),
		DOT_PRODUCT(),
		DOWNCASTS(),
		EMBEDDED_COMMENT(),
		EMBEDDED_COMMENT_INTERIOR(),
		EMBEDDED_NEWLINE_STRING(),
		EMBEDDED_NEWLINE_STRING_INTERIOR(),
		EMBEDDED_STRING(),
		EMBEDDED_STRING_INTERIOR(),
		END_OF_LINE_COMMENT(),
		ENUM(),
		ENUM_ELEMENT(),
		EQUALITY(),
		EQUALITY_NODE(),
		EXACTLY(),
		EXISTS(),
		EXISTS_ONE(),
		EXPONENTIATION(),
		EXPONENTIATION_ASSIGNMENT(),
		EXPRESSION(),
		FACTORIAL(),
		FACTORIAL_ASSIGNMENT(),
		FLOOR(),
		FOR(),
		FOR_COLLECTION(),
		FOR_STEP(),
		FOR_STEP_LIST(),
		FOR_STEP_NODE(),
		FREE(),
		FUNCTION(),
		FUNCTION_MODIFIER_0(),
		FUNCTION_MODIFIER_1(),
		FUNCTION_MODIFIER_2(),
		FUNCTION_MODIFIER_3(),
		FUNCTION_MODIFIER_4(),
		FUNCTION_MODIFIER_ATOMIC(),
		FUNCTION_MODIFIER_CALLING_CONVENTION(),
		FUNCTION_MODIFIER_MODEL(),
		FUNCTION_MODIFIER_PLATFORM(),
		FUNCTION_MODIFIER_STABILITY(),
		FUNCTION_MODIFIER_THROWING(),
		GREATER(),
		GREATER_NODE(),
		HAS(),
		HEX(),
		IC(),
		IDENTIFIER(),
		IDENTIFIER_SPECIFICATION(),
		IF(),
		IFF(),
		IMPLEMENTS(),
		IMPLICATION(),
		IMPLICATION_ASSIGNMENT(),
		IMPLICIT_TYPE_DEREFERENCE(),
		IMPORT(),
		IN(),
		INEQUALITY(),
		INHERITANCE_ITEM_PREFIX(),
		INHERITANCE_LIST(),
		INHERITS(),
		INTEGER_DIVISION(),
		INTEGER_DIVISION_ASSIGNMENT(),
		INTERSECTION(),
		INTERSECTION_ASSIGNMENT(),
		INVOCATION(),
		IS(),
		KLEENE_STAR(),
		LESSER(),
		LESSER_NODE(),
		LIST(),
		LOCK(),
		LOOP(),
		MAGNITUDE(),
		MAP(),
		MAPS_TO(),
		MEMBER_ACCESS(),
		MEMBER_OFFSET(),
		MODULATION(),
		MODULATION_ASSIGNMENT(),
		MULTIPLICATION(),
		MULTIPLICATION_ASSIGNMENT(),
		MULTIPLICATIVE_OP(),
		NAND(),
		NAND_ASSIGNMENT(),
		NATURAL_NUMBER(),
		NEAREST_INTEGER(),
		NEGATION(),
		NEGATION_ASSIGNMENT(),
		NON_FRACTIONAL(),
		NON_NEG_FRACTIONAL(),
		NON_NEG_INTEGER(),
		NON_NEG_NON_FRACTIONAL(),
		NON_NEG_NUMBER(),
		NON_ZERO_DECIMAL_DIGIT(),
		NOR(),
		NOR_ASSIGNMENT(),
		NOT(),
		NOT_ASSIGNMENT(),
		NOT_HAS(),
		NOT_IN(),
		NULL_COALESCE(),
		NULL_COALESCE_ASSIGNMENT(),
		OBJECT(),
		OCTAL(),
		OP_ASSIGNMENT(),
		OR(),
		OR_ASSIGNMENT(),
		PARAMETER(),
		PARAMETER_ANALYTIC(),
		PARAMETER_NATURAL(),
		PARENTHETICAL(),
		PARENTHETICAL_INVOCATION(),
		PAYLOAD(),
		PLATFORM(),
		POST_DEC(),
		POST_INC(),
		PREPEND(),
		PREPEND_ASSIGNMENT(),
		PRE_DEC(),
		PRE_INC(),
		RADICAL(),
		RADICAL_ASSIGNMENT(),
		RANGE(),
		READ_LOCK(),
		RECORD(),
		REGEX(),
		RELATIONAL_COLLECTION_OP(),
		RELATIONAL_OP(),
		RETURN(),
		SET(),
		SET_COMPREHENSION(),
		SHIFTL(),
		SHIFTL_ASSIGNMENT(),
		SHIFTR(),
		SHIFTR_ASSIGNMENT(),
		SLICE(),
		STANDARD_ARGUMENTS(),
		STATEMENT(),
		STATEMENT_SCOPE(),
		SUBSET(),
		SUBSET_NODE(),
		SUBTRACTION(),
		SUBTRACTION_ASSIGNMENT(),
		SUPERSET(),
		SUPERSET_NODE(),
		SWIZZLE(),
		SYMMETRIC_DIFFERENCE(),
		SYMMETRIC_DIFFERENCE_ASSIGNMENT(),
		THIS(),
		THIS_FUNC(),
		THIS_TYPE(),
		THROW(),
		TIME(),
		TRY(),
		TUPLE(),
		TYPE(),
		TYPE_CONSTRAINT(),
		TYPE_CONSTRAINT_DECLARATION(),
		TYPE_CONSTRAINT_ELEMENT(),
		TYPE_CONSTRAINT_SPECIFICATION(),
		TYPE_DEREFERENCE(),
		TYPE_INVOCATION(),
		TYPE_SCOPE(),
		TYPE_SCOPE_ASSIGNMENT(),
		TYPE_SCOPE_ASSIGNMENT_NODE(),
		TYPE_SCOPE_TYPE_CONSTRAINT(),
		TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION(),
		TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT(),
		TYPE_STATEMENT(),
		UNARY_ARITHMETIC_OP(),
		UNARY_LOGICAL_OP(),
		UNARY_OP(),
		UNION(),
		UNION_ASSIGNMENT(),
		UNIT_DIVISION(),
		UNIT_EXPONENTIATION(),
		UNIT_MULTIPLICATION(),
		UPCASTS(),
		USING(),
		VECTOR_NORM(),
		VISIBILITY_MODIFIER(),
		VOLATILE_IMPLICIT_TYPE_DEREFERENCE(),
		VOLATILE_TYPE_DEREFERENCE(),
		WHOLE_NUMBER(),
		WRITE_LOCK(),
		WS(),
		XML_DOC_STRING(),
		XML_DOC_STRING_INTERIOR(),
		XOR(),
		XOR_ASSIGNMENT(),
	});
	return result;
}

plange_grammar::plange_grammar() : grammar(builder()),
			ADDITION(this->lookup_recognizer_index("ADDITION")),
			ADDITION_ASSIGNMENT(this->lookup_recognizer_index("ADDITION_ASSIGNMENT")),
			ADD_SUB(this->lookup_recognizer_index("ADD_SUB")),
			ADD_SUB_ASSIGNMENT(this->lookup_recognizer_index("ADD_SUB_ASSIGNMENT")),
			ALL(this->lookup_recognizer_index("ALL")),
			ALLOCATION(this->lookup_recognizer_index("ALLOCATION")),
			AND(this->lookup_recognizer_index("AND")),
			AND_ASSIGNMENT(this->lookup_recognizer_index("AND_ASSIGNMENT")),
			ARGUMENT_PACK(this->lookup_recognizer_index("ARGUMENT_PACK")),
			ARRAY(this->lookup_recognizer_index("ARRAY")),
			ARRAY_ARGUMENTS(this->lookup_recognizer_index("ARRAY_ARGUMENTS")),
			ARRAY_INDEXER(this->lookup_recognizer_index("ARRAY_INDEXER")),
			ARRAY_INVOCATION(this->lookup_recognizer_index("ARRAY_INVOCATION")),
			ASM_EXPRESSION(this->lookup_recognizer_index("ASM_EXPRESSION")),
			ASM_FUNCTION(this->lookup_recognizer_index("ASM_FUNCTION")),
			ASM_IDENTIFIER(this->lookup_recognizer_index("ASM_IDENTIFIER")),
			ASM_OP(this->lookup_recognizer_index("ASM_OP")),
			ASM_PTR_ARITHMETIC_ATT(this->lookup_recognizer_index("ASM_PTR_ARITHMETIC_ATT")),
			ASM_PTR_ARITHMETIC_ATT_REG(this->lookup_recognizer_index("ASM_PTR_ARITHMETIC_ATT_REG")),
			ASM_PTR_ARITHMETIC_INTEL(this->lookup_recognizer_index("ASM_PTR_ARITHMETIC_INTEL")),
			ASM_SCOPE(this->lookup_recognizer_index("ASM_SCOPE")),
			ASM_STATEMENT(this->lookup_recognizer_index("ASM_STATEMENT")),
			ASSIGNMENT(this->lookup_recognizer_index("ASSIGNMENT")),
			ASSIGNMENT_NODE(this->lookup_recognizer_index("ASSIGNMENT_NODE")),
			ATTRIBUTE(this->lookup_recognizer_index("ATTRIBUTE")),
			BIJECTION(this->lookup_recognizer_index("BIJECTION")),
			BINARY_ARITHMETIC_OP(this->lookup_recognizer_index("BINARY_ARITHMETIC_OP")),
			BINARY_COLLECTION_OP(this->lookup_recognizer_index("BINARY_COLLECTION_OP")),
			BINARY_LOGICAL_OP(this->lookup_recognizer_index("BINARY_LOGICAL_OP")),
			BINARY_OP(this->lookup_recognizer_index("BINARY_OP")),
			BITWISE_OP(this->lookup_recognizer_index("BITWISE_OP")),
			BIT_AND(this->lookup_recognizer_index("BIT_AND")),
			BIT_AND_ASSIGNMENT(this->lookup_recognizer_index("BIT_AND_ASSIGNMENT")),
			BIT_NOT(this->lookup_recognizer_index("BIT_NOT")),
			BIT_NOT_ASSIGNMENT(this->lookup_recognizer_index("BIT_NOT_ASSIGNMENT")),
			BIT_OR(this->lookup_recognizer_index("BIT_OR")),
			BIT_OR_ASSIGNMENT(this->lookup_recognizer_index("BIT_OR_ASSIGNMENT")),
			BIT_XOR(this->lookup_recognizer_index("BIT_XOR")),
			BIT_XOR_ASSIGNMENT(this->lookup_recognizer_index("BIT_XOR_ASSIGNMENT")),
			BLOCK(this->lookup_recognizer_index("BLOCK")),
			BOOL(this->lookup_recognizer_index("BOOL")),
			BREAK(this->lookup_recognizer_index("BREAK")),
			CARDINALITY(this->lookup_recognizer_index("CARDINALITY")),
			CAST(this->lookup_recognizer_index("CAST")),
			CASTS(this->lookup_recognizer_index("CASTS")),
			CEILING(this->lookup_recognizer_index("CEILING")),
			COMMENT(this->lookup_recognizer_index("COMMENT")),
			COMPLEMENT(this->lookup_recognizer_index("COMPLEMENT")),
			COMPOSITION(this->lookup_recognizer_index("COMPOSITION")),
			COMPOSITION_ASSIGNMENT(this->lookup_recognizer_index("COMPOSITION_ASSIGNMENT")),
			COMPOUND(this->lookup_recognizer_index("COMPOUND")),
			COMPOUND_ASSIGNMENT(this->lookup_recognizer_index("COMPOUND_ASSIGNMENT")),
			CONDITIONAL(this->lookup_recognizer_index("CONDITIONAL")),
			CONSTRUCTIVE_OP(this->lookup_recognizer_index("CONSTRUCTIVE_OP")),
			CONTINUE(this->lookup_recognizer_index("CONTINUE")),
			CROSS_PRODUCT(this->lookup_recognizer_index("CROSS_PRODUCT")),
			CROSS_PRODUCT_ASSIGNMENT(this->lookup_recognizer_index("CROSS_PRODUCT_ASSIGNMENT")),
			DATE(this->lookup_recognizer_index("DATE")),
			DATE_TIME(this->lookup_recognizer_index("DATE_TIME")),
			DATE_YEAR_DAY(this->lookup_recognizer_index("DATE_YEAR_DAY")),
			DATE_YEAR_MONTH_DAY(this->lookup_recognizer_index("DATE_YEAR_MONTH_DAY")),
			DEFINITION(this->lookup_recognizer_index("DEFINITION")),
			DELTA(this->lookup_recognizer_index("DELTA")),
			DIMENSION(this->lookup_recognizer_index("DIMENSION")),
			DIMENSIONAL_ANALYSIS_OP(this->lookup_recognizer_index("DIMENSIONAL_ANALYSIS_OP")),
			DIMENSIONAL_NUMBER(this->lookup_recognizer_index("DIMENSIONAL_NUMBER")),
			DIVISION(this->lookup_recognizer_index("DIVISION")),
			DIVISION_ASSIGNMENT(this->lookup_recognizer_index("DIVISION_ASSIGNMENT")),
			DO(this->lookup_recognizer_index("DO")),
			DOT_PRODUCT(this->lookup_recognizer_index("DOT_PRODUCT")),
			DOWNCASTS(this->lookup_recognizer_index("DOWNCASTS")),
			EMBEDDED_COMMENT(this->lookup_recognizer_index("EMBEDDED_COMMENT")),
			EMBEDDED_COMMENT_INTERIOR(this->lookup_recognizer_index("EMBEDDED_COMMENT_INTERIOR")),
			EMBEDDED_NEWLINE_STRING(this->lookup_recognizer_index("EMBEDDED_NEWLINE_STRING")),
			EMBEDDED_NEWLINE_STRING_INTERIOR(this->lookup_recognizer_index("EMBEDDED_NEWLINE_STRING_INTERIOR")),
			EMBEDDED_STRING(this->lookup_recognizer_index("EMBEDDED_STRING")),
			EMBEDDED_STRING_INTERIOR(this->lookup_recognizer_index("EMBEDDED_STRING_INTERIOR")),
			END_OF_LINE_COMMENT(this->lookup_recognizer_index("END_OF_LINE_COMMENT")),
			ENUM(this->lookup_recognizer_index("ENUM")),
			ENUM_ELEMENT(this->lookup_recognizer_index("ENUM_ELEMENT")),
			EQUALITY(this->lookup_recognizer_index("EQUALITY")),
			EQUALITY_NODE(this->lookup_recognizer_index("EQUALITY_NODE")),
			EXACTLY(this->lookup_recognizer_index("EXACTLY")),
			EXISTS(this->lookup_recognizer_index("EXISTS")),
			EXISTS_ONE(this->lookup_recognizer_index("EXISTS_ONE")),
			EXPONENTIATION(this->lookup_recognizer_index("EXPONENTIATION")),
			EXPONENTIATION_ASSIGNMENT(this->lookup_recognizer_index("EXPONENTIATION_ASSIGNMENT")),
			EXPRESSION(this->lookup_recognizer_index("EXPRESSION")),
			FACTORIAL(this->lookup_recognizer_index("FACTORIAL")),
			FACTORIAL_ASSIGNMENT(this->lookup_recognizer_index("FACTORIAL_ASSIGNMENT")),
			FLOOR(this->lookup_recognizer_index("FLOOR")),
			FOR(this->lookup_recognizer_index("FOR")),
			FOR_COLLECTION(this->lookup_recognizer_index("FOR_COLLECTION")),
			FOR_STEP(this->lookup_recognizer_index("FOR_STEP")),
			FOR_STEP_LIST(this->lookup_recognizer_index("FOR_STEP_LIST")),
			FOR_STEP_NODE(this->lookup_recognizer_index("FOR_STEP_NODE")),
			FREE(this->lookup_recognizer_index("FREE")),
			FUNCTION(this->lookup_recognizer_index("FUNCTION")),
			FUNCTION_MODIFIER_0(this->lookup_recognizer_index("FUNCTION_MODIFIER_0")),
			FUNCTION_MODIFIER_1(this->lookup_recognizer_index("FUNCTION_MODIFIER_1")),
			FUNCTION_MODIFIER_2(this->lookup_recognizer_index("FUNCTION_MODIFIER_2")),
			FUNCTION_MODIFIER_3(this->lookup_recognizer_index("FUNCTION_MODIFIER_3")),
			FUNCTION_MODIFIER_4(this->lookup_recognizer_index("FUNCTION_MODIFIER_4")),
			FUNCTION_MODIFIER_ATOMIC(this->lookup_recognizer_index("FUNCTION_MODIFIER_ATOMIC")),
			FUNCTION_MODIFIER_CALLING_CONVENTION(this->lookup_recognizer_index("FUNCTION_MODIFIER_CALLING_CONVENTION")),
			FUNCTION_MODIFIER_MODEL(this->lookup_recognizer_index("FUNCTION_MODIFIER_MODEL")),
			FUNCTION_MODIFIER_PLATFORM(this->lookup_recognizer_index("FUNCTION_MODIFIER_PLATFORM")),
			FUNCTION_MODIFIER_STABILITY(this->lookup_recognizer_index("FUNCTION_MODIFIER_STABILITY")),
			FUNCTION_MODIFIER_THROWING(this->lookup_recognizer_index("FUNCTION_MODIFIER_THROWING")),
			GREATER(this->lookup_recognizer_index("GREATER")),
			GREATER_NODE(this->lookup_recognizer_index("GREATER_NODE")),
			HAS(this->lookup_recognizer_index("HAS")),
			HEX(this->lookup_recognizer_index("HEX")),
			IC(this->lookup_recognizer_index("IC")),
			IDENTIFIER(this->lookup_recognizer_index("IDENTIFIER")),
			IDENTIFIER_SPECIFICATION(this->lookup_recognizer_index("IDENTIFIER_SPECIFICATION")),
			IF(this->lookup_recognizer_index("IF")),
			IFF(this->lookup_recognizer_index("IFF")),
			IMPLEMENTS(this->lookup_recognizer_index("IMPLEMENTS")),
			IMPLICATION(this->lookup_recognizer_index("IMPLICATION")),
			IMPLICATION_ASSIGNMENT(this->lookup_recognizer_index("IMPLICATION_ASSIGNMENT")),
			IMPLICIT_TYPE_DEREFERENCE(this->lookup_recognizer_index("IMPLICIT_TYPE_DEREFERENCE")),
			IMPORT(this->lookup_recognizer_index("IMPORT")),
			IN(this->lookup_recognizer_index("IN")),
			INEQUALITY(this->lookup_recognizer_index("INEQUALITY")),
			INHERITANCE_ITEM_PREFIX(this->lookup_recognizer_index("INHERITANCE_ITEM_PREFIX")),
			INHERITANCE_LIST(this->lookup_recognizer_index("INHERITANCE_LIST")),
			INHERITS(this->lookup_recognizer_index("INHERITS")),
			INTEGER_DIVISION(this->lookup_recognizer_index("INTEGER_DIVISION")),
			INTEGER_DIVISION_ASSIGNMENT(this->lookup_recognizer_index("INTEGER_DIVISION_ASSIGNMENT")),
			INTERSECTION(this->lookup_recognizer_index("INTERSECTION")),
			INTERSECTION_ASSIGNMENT(this->lookup_recognizer_index("INTERSECTION_ASSIGNMENT")),
			INVOCATION(this->lookup_recognizer_index("INVOCATION")),
			IS(this->lookup_recognizer_index("IS")),
			KLEENE_STAR(this->lookup_recognizer_index("KLEENE_STAR")),
			LESSER(this->lookup_recognizer_index("LESSER")),
			LESSER_NODE(this->lookup_recognizer_index("LESSER_NODE")),
			LIST(this->lookup_recognizer_index("LIST")),
			LOCK(this->lookup_recognizer_index("LOCK")),
			LOOP(this->lookup_recognizer_index("LOOP")),
			MAGNITUDE(this->lookup_recognizer_index("MAGNITUDE")),
			MAP(this->lookup_recognizer_index("MAP")),
			MAPS_TO(this->lookup_recognizer_index("MAPS_TO")),
			MEMBER_ACCESS(this->lookup_recognizer_index("MEMBER_ACCESS")),
			MEMBER_OFFSET(this->lookup_recognizer_index("MEMBER_OFFSET")),
			MODULATION(this->lookup_recognizer_index("MODULATION")),
			MODULATION_ASSIGNMENT(this->lookup_recognizer_index("MODULATION_ASSIGNMENT")),
			MULTIPLICATION(this->lookup_recognizer_index("MULTIPLICATION")),
			MULTIPLICATION_ASSIGNMENT(this->lookup_recognizer_index("MULTIPLICATION_ASSIGNMENT")),
			MULTIPLICATIVE_OP(this->lookup_recognizer_index("MULTIPLICATIVE_OP")),
			NAND(this->lookup_recognizer_index("NAND")),
			NAND_ASSIGNMENT(this->lookup_recognizer_index("NAND_ASSIGNMENT")),
			NATURAL_NUMBER(this->lookup_recognizer_index("NATURAL_NUMBER")),
			NEAREST_INTEGER(this->lookup_recognizer_index("NEAREST_INTEGER")),
			NEGATION(this->lookup_recognizer_index("NEGATION")),
			NEGATION_ASSIGNMENT(this->lookup_recognizer_index("NEGATION_ASSIGNMENT")),
			NON_FRACTIONAL(this->lookup_recognizer_index("NON_FRACTIONAL")),
			NON_NEG_FRACTIONAL(this->lookup_recognizer_index("NON_NEG_FRACTIONAL")),
			NON_NEG_INTEGER(this->lookup_recognizer_index("NON_NEG_INTEGER")),
			NON_NEG_NON_FRACTIONAL(this->lookup_recognizer_index("NON_NEG_NON_FRACTIONAL")),
			NON_NEG_NUMBER(this->lookup_recognizer_index("NON_NEG_NUMBER")),
			NON_ZERO_DECIMAL_DIGIT(this->lookup_recognizer_index("NON_ZERO_DECIMAL_DIGIT")),
			NOR(this->lookup_recognizer_index("NOR")),
			NOR_ASSIGNMENT(this->lookup_recognizer_index("NOR_ASSIGNMENT")),
			NOT(this->lookup_recognizer_index("NOT")),
			NOT_ASSIGNMENT(this->lookup_recognizer_index("NOT_ASSIGNMENT")),
			NOT_HAS(this->lookup_recognizer_index("NOT_HAS")),
			NOT_IN(this->lookup_recognizer_index("NOT_IN")),
			NULL_COALESCE(this->lookup_recognizer_index("NULL_COALESCE")),
			NULL_COALESCE_ASSIGNMENT(this->lookup_recognizer_index("NULL_COALESCE_ASSIGNMENT")),
			OBJECT(this->lookup_recognizer_index("OBJECT")),
			OCTAL(this->lookup_recognizer_index("OCTAL")),
			OP_ASSIGNMENT(this->lookup_recognizer_index("OP_ASSIGNMENT")),
			OR(this->lookup_recognizer_index("OR")),
			OR_ASSIGNMENT(this->lookup_recognizer_index("OR_ASSIGNMENT")),
			PARAMETER(this->lookup_recognizer_index("PARAMETER")),
			PARAMETER_ANALYTIC(this->lookup_recognizer_index("PARAMETER_ANALYTIC")),
			PARAMETER_NATURAL(this->lookup_recognizer_index("PARAMETER_NATURAL")),
			PARENTHETICAL(this->lookup_recognizer_index("PARENTHETICAL")),
			PARENTHETICAL_INVOCATION(this->lookup_recognizer_index("PARENTHETICAL_INVOCATION")),
			PAYLOAD(this->lookup_recognizer_index("PAYLOAD")),
			PLATFORM(this->lookup_recognizer_index("PLATFORM")),
			POST_DEC(this->lookup_recognizer_index("POST_DEC")),
			POST_INC(this->lookup_recognizer_index("POST_INC")),
			PREPEND(this->lookup_recognizer_index("PREPEND")),
			PREPEND_ASSIGNMENT(this->lookup_recognizer_index("PREPEND_ASSIGNMENT")),
			PRE_DEC(this->lookup_recognizer_index("PRE_DEC")),
			PRE_INC(this->lookup_recognizer_index("PRE_INC")),
			RADICAL(this->lookup_recognizer_index("RADICAL")),
			RADICAL_ASSIGNMENT(this->lookup_recognizer_index("RADICAL_ASSIGNMENT")),
			RANGE(this->lookup_recognizer_index("RANGE")),
			READ_LOCK(this->lookup_recognizer_index("READ_LOCK")),
			RECORD(this->lookup_recognizer_index("RECORD")),
			REGEX(this->lookup_recognizer_index("REGEX")),
			RELATIONAL_COLLECTION_OP(this->lookup_recognizer_index("RELATIONAL_COLLECTION_OP")),
			RELATIONAL_OP(this->lookup_recognizer_index("RELATIONAL_OP")),
			RETURN(this->lookup_recognizer_index("RETURN")),
			SET(this->lookup_recognizer_index("SET")),
			SET_COMPREHENSION(this->lookup_recognizer_index("SET_COMPREHENSION")),
			SHIFTL(this->lookup_recognizer_index("SHIFTL")),
			SHIFTL_ASSIGNMENT(this->lookup_recognizer_index("SHIFTL_ASSIGNMENT")),
			SHIFTR(this->lookup_recognizer_index("SHIFTR")),
			SHIFTR_ASSIGNMENT(this->lookup_recognizer_index("SHIFTR_ASSIGNMENT")),
			SLICE(this->lookup_recognizer_index("SLICE")),
			STANDARD_ARGUMENTS(this->lookup_recognizer_index("STANDARD_ARGUMENTS")),
			STATEMENT(this->lookup_recognizer_index("STATEMENT")),
			STATEMENT_SCOPE(this->lookup_recognizer_index("STATEMENT_SCOPE")),
			SUBSET(this->lookup_recognizer_index("SUBSET")),
			SUBSET_NODE(this->lookup_recognizer_index("SUBSET_NODE")),
			SUBTRACTION(this->lookup_recognizer_index("SUBTRACTION")),
			SUBTRACTION_ASSIGNMENT(this->lookup_recognizer_index("SUBTRACTION_ASSIGNMENT")),
			SUPERSET(this->lookup_recognizer_index("SUPERSET")),
			SUPERSET_NODE(this->lookup_recognizer_index("SUPERSET_NODE")),
			SWIZZLE(this->lookup_recognizer_index("SWIZZLE")),
			SYMMETRIC_DIFFERENCE(this->lookup_recognizer_index("SYMMETRIC_DIFFERENCE")),
			SYMMETRIC_DIFFERENCE_ASSIGNMENT(this->lookup_recognizer_index("SYMMETRIC_DIFFERENCE_ASSIGNMENT")),
			THIS(this->lookup_recognizer_index("THIS")),
			THIS_FUNC(this->lookup_recognizer_index("THIS_FUNC")),
			THIS_TYPE(this->lookup_recognizer_index("THIS_TYPE")),
			THROW(this->lookup_recognizer_index("THROW")),
			TIME(this->lookup_recognizer_index("TIME")),
			TRY(this->lookup_recognizer_index("TRY")),
			TUPLE(this->lookup_recognizer_index("TUPLE")),
			TYPE(this->lookup_recognizer_index("TYPE")),
			TYPE_CONSTRAINT(this->lookup_recognizer_index("TYPE_CONSTRAINT")),
			TYPE_CONSTRAINT_DECLARATION(this->lookup_recognizer_index("TYPE_CONSTRAINT_DECLARATION")),
			TYPE_CONSTRAINT_ELEMENT(this->lookup_recognizer_index("TYPE_CONSTRAINT_ELEMENT")),
			TYPE_CONSTRAINT_SPECIFICATION(this->lookup_recognizer_index("TYPE_CONSTRAINT_SPECIFICATION")),
			TYPE_DEREFERENCE(this->lookup_recognizer_index("TYPE_DEREFERENCE")),
			TYPE_INVOCATION(this->lookup_recognizer_index("TYPE_INVOCATION")),
			TYPE_SCOPE(this->lookup_recognizer_index("TYPE_SCOPE")),
			TYPE_SCOPE_ASSIGNMENT(this->lookup_recognizer_index("TYPE_SCOPE_ASSIGNMENT")),
			TYPE_SCOPE_ASSIGNMENT_NODE(this->lookup_recognizer_index("TYPE_SCOPE_ASSIGNMENT_NODE")),
			TYPE_SCOPE_TYPE_CONSTRAINT(this->lookup_recognizer_index("TYPE_SCOPE_TYPE_CONSTRAINT")),
			TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION(this->lookup_recognizer_index("TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION")),
			TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT(this->lookup_recognizer_index("TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT")),
			TYPE_STATEMENT(this->lookup_recognizer_index("TYPE_STATEMENT")),
			UNARY_ARITHMETIC_OP(this->lookup_recognizer_index("UNARY_ARITHMETIC_OP")),
			UNARY_LOGICAL_OP(this->lookup_recognizer_index("UNARY_LOGICAL_OP")),
			UNARY_OP(this->lookup_recognizer_index("UNARY_OP")),
			UNION(this->lookup_recognizer_index("UNION")),
			UNION_ASSIGNMENT(this->lookup_recognizer_index("UNION_ASSIGNMENT")),
			UNIT_DIVISION(this->lookup_recognizer_index("UNIT_DIVISION")),
			UNIT_EXPONENTIATION(this->lookup_recognizer_index("UNIT_EXPONENTIATION")),
			UNIT_MULTIPLICATION(this->lookup_recognizer_index("UNIT_MULTIPLICATION")),
			UPCASTS(this->lookup_recognizer_index("UPCASTS")),
			USING(this->lookup_recognizer_index("USING")),
			VECTOR_NORM(this->lookup_recognizer_index("VECTOR_NORM")),
			VISIBILITY_MODIFIER(this->lookup_recognizer_index("VISIBILITY_MODIFIER")),
			VOLATILE_IMPLICIT_TYPE_DEREFERENCE(this->lookup_recognizer_index("VOLATILE_IMPLICIT_TYPE_DEREFERENCE")),
			VOLATILE_TYPE_DEREFERENCE(this->lookup_recognizer_index("VOLATILE_TYPE_DEREFERENCE")),
			WHOLE_NUMBER(this->lookup_recognizer_index("WHOLE_NUMBER")),
			WRITE_LOCK(this->lookup_recognizer_index("WRITE_LOCK")),
			WS(this->lookup_recognizer_index("WS")),
			XML_DOC_STRING(this->lookup_recognizer_index("XML_DOC_STRING")),
			XML_DOC_STRING_INTERIOR(this->lookup_recognizer_index("XML_DOC_STRING_INTERIOR")),
			XOR(this->lookup_recognizer_index("XOR")),
			XOR_ASSIGNMENT(this->lookup_recognizer_index("XOR_ASSIGNMENT"))
{}
} // namespace plc
