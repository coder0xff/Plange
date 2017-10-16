// This file was generated using Parlex's cpp_generator

#include "XOR.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"

plc::XOR plc::XOR::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().XOR.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<erased<EXPRESSION>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[1], w);
	auto v_2 = parlex::details::document::element<std::variant<
		literal_0xE20x8A0x95_t,
		literal_xor_t
	>>::build(document, *children[2], w);
	auto v_3 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[3], w);
	auto v_4 = parlex::details::document::element<erased<EXPRESSION>>::build(document, *children[4], w);
	return XOR(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4));
}

