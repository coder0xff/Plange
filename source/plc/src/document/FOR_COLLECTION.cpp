// This file was generated using Parlex's cpp_generator

#include "FOR_COLLECTION.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "IDENTIFIER.hpp"
#include "IMPLICIT_TYPE_DEREFERENCE.hpp"
#include "TYPE_DEREFERENCE.hpp"

plc::FOR_COLLECTION::declaration::field_1_t_1_t plc::FOR_COLLECTION::declaration::field_1_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<std::variant<
		erased<TYPE_DEREFERENCE>,
		erased<IMPLICIT_TYPE_DEREFERENCE>
	>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[1], w);
	return field_1_t_1_t(std::move(v_0), std::move(v_1));
}

plc::FOR_COLLECTION::declaration plc::FOR_COLLECTION::declaration::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<std::optional<field_1_t_1_t>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<erased<IDENTIFIER>>::build(document, *children[1], w);
	return declaration(std::move(v_0), std::move(v_1));
}

plc::FOR_COLLECTION plc::FOR_COLLECTION::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().FOR_COLLECTION.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	assert(w.pos != w.end); ++w.pos; //for 
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[1], w);
	assert(w.pos != w.end); ++w.pos; //( 
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[3], w);
	auto v_2 = parlex::details::document::element<std::variant<
		declaration,
		erased<EXPRESSION>
	>>::build(document, *children[4], w);
	auto v_3 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[5], w);
	auto v_4 = parlex::details::document::element<std::variant<
		literal_in_t,
		literal_0xE20x880x88_t
	>>::build(document, *children[6], w);
	auto v_5 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[7], w);
	auto v_6 = parlex::details::document::element<erased<EXPRESSION>>::build(document, *children[8], w);
	auto v_7 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[9], w);
	assert(w.pos != w.end); ++w.pos; //) 
	auto v_8 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[11], w);
	auto v_9 = parlex::details::document::element<erased<EXPRESSION>>::build(document, *children[12], w);
	return FOR_COLLECTION(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4), std::move(v_5), std::move(v_6), std::move(v_7), std::move(v_8), std::move(v_9));
}

