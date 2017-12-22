// This file was generated using Parlex's cpp_generator

#include "OBJECT.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "IC.hpp"
#include "INHERITANCE_LIST.hpp"
#include "TYPE_SCOPE.hpp"

plc::OBJECT::field_2_t_1_t plc::OBJECT::field_2_t_1_t::build(parlex::detail::behavior::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<parlex::detail::document::text<literal_inheriting_t>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<erased<INHERITANCE_LIST>>::build(&*children[2], w);
	auto v_3 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	return field_2_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3));
}

plc::OBJECT::field_3_t_1_t plc::OBJECT::field_3_t_1_t::build(parlex::detail::behavior::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<parlex::detail::document::text<literal_implementing_t>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<erased<INHERITANCE_LIST>>::build(&*children[2], w);
	auto v_3 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	return field_3_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3));
}

plc::OBJECT plc::OBJECT::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().OBJECT.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<parlex::detail::document::text<literal_object_t>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<std::optional<field_2_t_1_t>>::build(&*children[2], w);
	auto v_3 = parlex::detail::document::element<std::optional<field_3_t_1_t>>::build(&*children[3], w);
	auto v_4 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7B_t>>::build(&*children[4], w);
	auto v_5 = parlex::detail::document::element<erased<TYPE_SCOPE>>::build(&*children[5], w);
	auto v_6 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7D_t>>::build(&*children[6], w);
	return OBJECT(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4), std::move(v_5), std::move(v_6));
}


parlex::detail::recognizer const & plc::OBJECT::recognizer() {
	return plange_grammar::get().OBJECT.get_recognizer();
}
