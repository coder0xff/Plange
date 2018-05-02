// This file was generated using Parlex's cpp_generator

#include "TYPE_CONSTRAINT_HEAD.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "ATTRIBUTE.hpp"
#include "EXTERN.hpp"
#include "IC.hpp"
#include "IMPLICIT_TYPE_DEREFERENCE.hpp"
#include "STATIC.hpp"
#include "TYPE_DEREFERENCE.hpp"
#include "VISIBILITY_MODIFIER.hpp"
#include "VOLATILE_IMPLICIT_TYPE_DEREFERENCE.hpp"
#include "VOLATILE_TYPE_DEREFERENCE.hpp"
#include "XML_DOC_STRING.hpp"

plc::TYPE_CONSTRAINT_HEAD::field_1_t_1_t plc::TYPE_CONSTRAINT_HEAD::field_1_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<erased<XML_DOC_STRING>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	return field_1_t_1_t(std::move(v0), std::move(v1));
}

plc::TYPE_CONSTRAINT_HEAD::field_2_t_1_t plc::TYPE_CONSTRAINT_HEAD::field_2_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<erased<ATTRIBUTE>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	return field_2_t_1_t(std::move(v0), std::move(v1));
}

plc::TYPE_CONSTRAINT_HEAD::field_3_t_1_t plc::TYPE_CONSTRAINT_HEAD::field_3_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<erased<VISIBILITY_MODIFIER>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	return field_3_t_1_t(std::move(v0), std::move(v1));
}

plc::TYPE_CONSTRAINT_HEAD::field_4_t_1_t plc::TYPE_CONSTRAINT_HEAD::field_4_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<erased<STATIC>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	return field_4_t_1_t(std::move(v0), std::move(v1));
}

plc::TYPE_CONSTRAINT_HEAD::field_5_t_1_t plc::TYPE_CONSTRAINT_HEAD::field_5_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<erased<EXTERN>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	return field_5_t_1_t(std::move(v0), std::move(v1));
}

plc::TYPE_CONSTRAINT_HEAD plc::TYPE_CONSTRAINT_HEAD::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::optional<field_1_t_1_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<field_2_t_1_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<field_3_t_1_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::optional<field_4_t_1_t>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::optional<field_5_t_1_t>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<std::variant<
		erased<TYPE_DEREFERENCE>,
		erased<VOLATILE_TYPE_DEREFERENCE>,
		erased<IMPLICIT_TYPE_DEREFERENCE>,
		erased<VOLATILE_IMPLICIT_TYPE_DEREFERENCE>
	>>::build(&*children[5], w);
	return TYPE_CONSTRAINT_HEAD(std::move(v0), std::move(v1), std::move(v2), std::move(v3), std::move(v4), std::move(v5));
}


parlex::detail::acceptor const & plc::TYPE_CONSTRAINT_HEAD::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().TYPE_CONSTRAINT_HEAD));
	return result;
}
