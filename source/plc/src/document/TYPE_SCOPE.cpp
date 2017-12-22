// This file was generated using Parlex's cpp_generator

#include "TYPE_SCOPE.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "IC.hpp"
#include "TYPE_STATEMENT.hpp"

plc::TYPE_SCOPE::field_2_t_1_t plc::TYPE_SCOPE::field_2_t_1_t::build(parlex::detail::behavior::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<erased<TYPE_STATEMENT>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	return field_2_t_1_t(std::move(v_0), std::move(v_1));
}

plc::TYPE_SCOPE plc::TYPE_SCOPE::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().TYPE_SCOPE.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<std::vector<field_2_t_1_t>>::build(&*children[1], w);
	return TYPE_SCOPE(std::move(v_0), std::move(v_1));
}


parlex::detail::recognizer const & plc::TYPE_SCOPE::recognizer() {
	return plange_grammar::get().TYPE_SCOPE.get_recognizer();
}
