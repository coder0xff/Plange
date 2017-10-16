// This file was generated using Parlex's cpp_generator

#include "PARAMETER_NATURAL.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "IDENTIFIER.hpp"
#include "IMPLICIT_TYPE_DEREFERENCE.hpp"
#include "TYPE_DEREFERENCE.hpp"

#include "PARAMETER_NATURAL.hpp"

namespace plc {

PARAMETER_NATURAL PARAMETER_NATURAL::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().PARAMETER_NATURAL.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return PARAMETER_NATURAL(parlex::details::document::element<PARAMETER_NATURAL_base>::build(document, b, w));
}

} // namespace plc
plc::PARAMETER_NATURAL_1_t::field_1_t_1_t plc::PARAMETER_NATURAL_1_t::field_1_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<erased<TYPE_DEREFERENCE>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[1], w);
	return field_1_t_1_t(std::move(v_0), std::move(v_1));
}

plc::PARAMETER_NATURAL_1_t plc::PARAMETER_NATURAL_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<std::optional<field_1_t_1_t>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<erased<IDENTIFIER>>::build(document, *children[1], w);
	auto v_2 = parlex::details::document::element<bool>::build(document, *children[2], w);
	return PARAMETER_NATURAL_1_t(std::move(v_0), std::move(v_1), std::move(v_2));
}

plc::PARAMETER_NATURAL_2_t::field_1_t_1_t plc::PARAMETER_NATURAL_2_t::field_1_t_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<std::variant<
		erased<TYPE_DEREFERENCE>,
		erased<IMPLICIT_TYPE_DEREFERENCE>
	>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[1], w);
	return field_1_t_1_t(std::move(v_0), std::move(v_1));
}

plc::PARAMETER_NATURAL_2_t plc::PARAMETER_NATURAL_2_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<std::optional<field_1_t_1_t>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<erased<IDENTIFIER>>::build(document, *children[1], w);
	auto v_2 = parlex::details::document::element<bool>::build(document, *children[2], w);
	auto v_3 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[3], w);
	assert(w.pos != w.end); ++w.pos; //= 
	auto v_4 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[5], w);
	auto v_5 = parlex::details::document::element<erased<EXPRESSION>>::build(document, *children[6], w);
	auto v_6 = parlex::details::document::element<bool>::build(document, *children[7], w);
	return PARAMETER_NATURAL_2_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4), std::move(v_5), std::move(v_6));
}

