// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_USING_HPP
#define INCLUDED_USING_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct BLOCK;
struct EXPRESSION;
struct IC;

struct USING {
	parlex::detail::document::text<literal_using_t> dontCare0;
	
	std::vector<erased<IC>> field_01;
	
	parlex::detail::document::text<literal_0x28_t> dontCare2;
	
	std::vector<erased<IC>> field_02;
	
	erased<EXPRESSION> field_03;
	
	std::vector<erased<IC>> field_04;
	
	parlex::detail::document::text<literal_0x29_t> dontCare6;
	
	std::vector<erased<IC>> field_05;
	
	erased<BLOCK> field_06;
	


	explicit USING(
		parlex::detail::document::text<literal_using_t> && dontCare0, std::vector<erased<IC>> && field_01, parlex::detail::document::text<literal_0x28_t> && dontCare2, std::vector<erased<IC>> && field_02, erased<EXPRESSION> && field_03, std::vector<erased<IC>> && field_04, parlex::detail::document::text<literal_0x29_t> && dontCare6, std::vector<erased<IC>> && field_05, erased<BLOCK> && field_06) : dontCare0(std::move(dontCare0)), field_01(std::move(field_01)), dontCare2(std::move(dontCare2)), field_02(std::move(field_02)), field_03(std::move(field_03)), field_04(std::move(field_04)), dontCare6(std::move(dontCare6)), field_05(std::move(field_05)), field_06(std::move(field_06)) {}

	USING(USING const & other) = default;
	USING(USING && move) = default;

	static USING build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_USING_HPP
