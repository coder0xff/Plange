// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_SET_COMPREHENSION_HPP
#define INCLUDED_SET_COMPREHENSION_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct SET_COMPREHENSION {
	parlex::detail::document::text<literal_0x7B_t> dontCare0;
	
	std::vector<erased<IC>> field_01;
	
	erased<EXPRESSION> field_02;
	
	std::vector<erased<IC>> field_03;
	
	parlex::detail::document::text<literal_0x7C_t> dontCare4;
	
	std::vector<erased<IC>> field_04;
	
	erased<EXPRESSION> field_05;
	
	std::vector<erased<IC>> field_06;
	
	parlex::detail::document::text<literal_0x7D_t> dontCare8;
	


	explicit SET_COMPREHENSION(
		parlex::detail::document::text<literal_0x7B_t> && dontCare0, std::vector<erased<IC>> && field_01, erased<EXPRESSION> && field_02, std::vector<erased<IC>> && field_03, parlex::detail::document::text<literal_0x7C_t> && dontCare4, std::vector<erased<IC>> && field_04, erased<EXPRESSION> && field_05, std::vector<erased<IC>> && field_06, parlex::detail::document::text<literal_0x7D_t> && dontCare8) : dontCare0(std::move(dontCare0)), field_01(std::move(field_01)), field_02(std::move(field_02)), field_03(std::move(field_03)), dontCare4(std::move(dontCare4)), field_04(std::move(field_04)), field_05(std::move(field_05)), field_06(std::move(field_06)), dontCare8(std::move(dontCare8)) {}

	SET_COMPREHENSION(SET_COMPREHENSION const & other) = default;
	SET_COMPREHENSION(SET_COMPREHENSION && move) = default;

	static SET_COMPREHENSION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_SET_COMPREHENSION_HPP
