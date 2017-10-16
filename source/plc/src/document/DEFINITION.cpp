// This file was generated using Parlex's cpp_generator

#include "DEFINITION.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "IDENTIFIER.hpp"
#include "XML_DOC_STRING.hpp"

plc::DEFINITION::field_1_t_1_t plc::DEFINITION::field_1_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<erased<XML_DOC_STRING>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[1], w);
	return field_1_t_1_t(std::move(v_0), std::move(v_1));
}

plc::DEFINITION plc::DEFINITION::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().DEFINITION.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<std::optional<field_1_t_1_t>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<erased<IDENTIFIER>>::build(document, *children[1], w);
	auto v_2 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[2], w);
	assert(w.pos != w.end); ++w.pos; //:= 
	auto v_3 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[4], w);
	auto v_4 = parlex::details::document::element<erased<EXPRESSION>>::build(document, *children[5], w);
	return DEFINITION(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4));
}

