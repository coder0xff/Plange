// This file was generated using Parlex's cpp_generator

#include "TYPE_INVOCATION.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "ARGUMENT.hpp"
#include "ARGUMENT_PACK.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"

plc::TYPE_INVOCATION::field_1_t::argsHead_t_1_t plc::TYPE_INVOCATION::field_1_t::argsHead_t_1_t::build(parlex::detail::behavior::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<std::variant<
		erased<ARGUMENT>,
		erased<ARGUMENT_PACK>
	>>::build(&*children[1], w);
	return argsHead_t_1_t(std::move(v_0), std::move(v_1));
}

plc::TYPE_INVOCATION::field_1_t::argsTail_t_1_t::field_2_t_1_t plc::TYPE_INVOCATION::field_1_t::argsTail_t_1_t::field_2_t_1_t::build(parlex::detail::behavior::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<std::variant<
		erased<ARGUMENT>,
		erased<ARGUMENT_PACK>
	>>::build(&*children[1], w);
	return field_2_t_1_t(std::move(v_0), std::move(v_1));
}

plc::TYPE_INVOCATION::field_1_t::argsTail_t_1_t plc::TYPE_INVOCATION::field_1_t::argsTail_t_1_t::build(parlex::detail::behavior::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2C_t>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<std::optional<field_2_t_1_t>>::build(&*children[2], w);
	return argsTail_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2));
}

plc::TYPE_INVOCATION::field_1_t plc::TYPE_INVOCATION::field_1_t::build(parlex::detail::behavior::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3C_t>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<std::optional<argsHead_t_1_t>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<std::vector<argsTail_t_1_t>>::build(&*children[2], w);
	auto v_3 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	auto v_4 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3E_t>>::build(&*children[4], w);
	return field_1_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4));
}

plc::TYPE_INVOCATION plc::TYPE_INVOCATION::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().TYPE_INVOCATION.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<field_1_t>::build(&*children[1], w);
	return TYPE_INVOCATION(std::move(v_0), std::move(v_1));
}


parlex::detail::recognizer const & plc::TYPE_INVOCATION::recognizer() {
	return plange_grammar::get().TYPE_INVOCATION.get_recognizer();
}
