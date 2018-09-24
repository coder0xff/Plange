// This file was generated using Parlex's cpp_generator

#include "TYPE_CONSTRAINT_SPECIFICATION.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "ATTRIBUTE.hpp"
#include "IC.hpp"
#include "IMPLICIT_TYPE_DEREFERENCE.hpp"
#include "TYPE_DEREFERENCE.hpp"
#include "VISIBILITY_MODIFIER.hpp"
#include "VOLATILE_IMPLICIT_TYPE_DEREFERENCE.hpp"
#include "VOLATILE_TYPE_DEREFERENCE.hpp"
#include "XML_DOC_STRING.hpp"

plc::TYPE_CONSTRAINT_SPECIFICATION::attributes_t plc::TYPE_CONSTRAINT_SPECIFICATION::attributes_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<ATTRIBUTE>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	return attributes_t(std::move(v0), std::move(v1));
}

plc::TYPE_CONSTRAINT_SPECIFICATION::visibility_t plc::TYPE_CONSTRAINT_SPECIFICATION::visibility_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<VISIBILITY_MODIFIER>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	return visibility_t(std::move(v0), std::move(v1));
}

plc::TYPE_CONSTRAINT_SPECIFICATION::static__t plc::TYPE_CONSTRAINT_SPECIFICATION::static__t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_static_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	return static__t(std::move(v0), std::move(v1));
}

plc::TYPE_CONSTRAINT_SPECIFICATION::extern__t plc::TYPE_CONSTRAINT_SPECIFICATION::extern__t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_extern_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	return extern__t(std::move(v0), std::move(v1));
}

plc::TYPE_CONSTRAINT_SPECIFICATION plc::TYPE_CONSTRAINT_SPECIFICATION::build(parlex::detail::ast_node const & n) {
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
	return TYPE_CONSTRAINT_SPECIFICATION(n.document_position, n.consumed_character_count, std::move(v0), std::move(v1), std::move(v2), std::move(v3), std::move(v4), std::move(v5));
}


parlex::detail::acceptor const & plc::TYPE_CONSTRAINT_SPECIFICATION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().TYPE_CONSTRAINT_SPECIFICATION));
	return result;
}
