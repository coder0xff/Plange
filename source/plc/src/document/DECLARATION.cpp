// This file was generated using Parlex's cpp_generator

#include "DECLARATION.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "IC.hpp"
#include "IDENTIFIER.hpp"
#include "XML_DOC_STRING.hpp"

plc::DECLARATION::field_1_t_1_t plc::DECLARATION::field_1_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<erased<XML_DOC_STRING>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[1], w);
	return field_1_t_1_t(std::move(v_0), std::move(v_1));
}

plc::DECLARATION plc::DECLARATION::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().DECLARATION.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<std::optional<field_1_t_1_t>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<erased<IDENTIFIER>>::build(document, *children[1], w);
	return DECLARATION(std::move(v_0), std::move(v_1));
}

