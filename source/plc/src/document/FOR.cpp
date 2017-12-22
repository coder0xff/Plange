// This file was generated using Parlex's cpp_generator

#include "FOR.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "ASSIGNMENT_CHAIN.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "STATEMENT_SCOPE.hpp"

plc::FOR::initializer_t_1_t plc::FOR::initializer_t_1_t::build(parlex::detail::behavior::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<erased<STATEMENT_SCOPE>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	return initializer_t_1_t(std::move(v_0), std::move(v_1));
}

plc::FOR::step_t_1_t::field_2_t_1_t plc::FOR::step_t_1_t::field_2_t_1_t::build(parlex::detail::behavior::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2C_t>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[2], w);
	auto v_3 = parlex::detail::document::element<erased<ASSIGNMENT_CHAIN>>::build(&*children[3], w);
	return field_2_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3));
}

plc::FOR::step_t_1_t plc::FOR::step_t_1_t::build(parlex::detail::behavior::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<erased<ASSIGNMENT_CHAIN>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<std::vector<field_2_t_1_t>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[2], w);
	return step_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2));
}

plc::FOR plc::FOR::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().FOR.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<parlex::detail::document::text<literal_for_t>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x28_t>>::build(&*children[2], w);
	auto v_3 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	auto v_4 = parlex::detail::document::element<std::optional<initializer_t_1_t>>::build(&*children[4], w);
	auto v_5 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[5], w);
	auto v_6 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[6], w);
	auto v_7 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3B_t>>::build(&*children[7], w);
	auto v_8 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[8], w);
	auto v_9 = parlex::detail::document::element<std::optional<step_t_1_t>>::build(&*children[9], w);
	auto v_10 = parlex::detail::document::element<parlex::detail::document::text<literal_0x29_t>>::build(&*children[10], w);
	auto v_11 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[11], w);
	auto v_12 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[12], w);
	return FOR(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4), std::move(v_5), std::move(v_6), std::move(v_7), std::move(v_8), std::move(v_9), std::move(v_10), std::move(v_11), std::move(v_12));
}


parlex::detail::recognizer const & plc::FOR::recognizer() {
	return plange_grammar::get().FOR.get_recognizer();
}
