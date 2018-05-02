// This file was generated using Parlex's cpp_generator

#include "FOR.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "ASSIGNMENT_CHAIN.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "STATEMENT_SCOPE.hpp"

plc::FOR::initializer_t_1_t plc::FOR::initializer_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<erased<STATEMENT_SCOPE>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	return initializer_t_1_t(std::move(v0), std::move(v1));
}

plc::FOR::step_t_1_t::field_2_t_1_t plc::FOR::step_t_1_t::field_2_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2C_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<erased<ASSIGNMENT_CHAIN>>::build(&*children[3], w);
	return field_2_t_1_t(std::move(v0), std::move(v1), std::move(v2), std::move(v3));
}

plc::FOR::step_t_1_t plc::FOR::step_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<erased<ASSIGNMENT_CHAIN>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<field_2_t_1_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[2], w);
	return step_t_1_t(std::move(v0), std::move(v1), std::move(v2));
}

plc::FOR plc::FOR::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_for_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x28_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::optional<initializer_t_1_t>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[6], w);
	auto v7 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3B_t>>::build(&*children[7], w);
	auto v8 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[8], w);
	auto v9 = parlex::detail::document::element<std::optional<step_t_1_t>>::build(&*children[9], w);
	auto v10 = parlex::detail::document::element<parlex::detail::document::text<literal_0x29_t>>::build(&*children[10], w);
	auto v11 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[11], w);
	auto v12 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[12], w);
	return FOR(std::move(v0), std::move(v1), std::move(v2), std::move(v3), std::move(v4), std::move(v5), std::move(v6), std::move(v7), std::move(v8), std::move(v9), std::move(v10), std::move(v11), std::move(v12));
}


parlex::detail::acceptor const & plc::FOR::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().FOR));
	return result;
}
