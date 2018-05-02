// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TRY_HPP
#define INCLUDED_TRY_HPP

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

struct TRY {
	struct field_06_t_1_t {
		parlex::detail::document::text<literal_catch_t> dontCare0;
		
		std::vector<erased<IC>> field_1;
		
		erased<EXPRESSION> field_2;
		
	
	
		explicit field_06_t_1_t(
			parlex::detail::document::text<literal_catch_t> && dontCare0, std::vector<erased<IC>> && field_1, erased<EXPRESSION> && field_2) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_06_t_1_t(field_06_t_1_t const & other) = default;
		field_06_t_1_t(field_06_t_1_t && move) = default;
	
		static field_06_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_07_t_1_t {
		std::vector<erased<IC>> field_1;
		
		parlex::detail::document::text<literal_finally_t> dontCare1;
		
		std::vector<erased<IC>> field_2;
		
		erased<EXPRESSION> field_3;
		
	
	
		explicit field_07_t_1_t(
			std::vector<erased<IC>> && field_1, parlex::detail::document::text<literal_finally_t> && dontCare1, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && field_3) : field_1(std::move(field_1)), dontCare1(std::move(dontCare1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}
	
		field_07_t_1_t(field_07_t_1_t const & other) = default;
		field_07_t_1_t(field_07_t_1_t && move) = default;
	
		static field_07_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_try_t> dontCare0;
	
	std::vector<erased<IC>> field_01;
	
	erased<EXPRESSION> field_02;
	
	std::vector<erased<IC>> field_03;
	
	parlex::detail::document::text<literal_catch_t> dontCare4;
	
	std::vector<erased<IC>> field_04;
	
	erased<EXPRESSION> field_05;
	
	std::vector<field_06_t_1_t> field_06;
	
	std::optional<field_07_t_1_t> field_07;
	


	explicit TRY(
		parlex::detail::document::text<literal_try_t> && dontCare0, std::vector<erased<IC>> && field_01, erased<EXPRESSION> && field_02, std::vector<erased<IC>> && field_03, parlex::detail::document::text<literal_catch_t> && dontCare4, std::vector<erased<IC>> && field_04, erased<EXPRESSION> && field_05, std::vector<field_06_t_1_t> && field_06, std::optional<field_07_t_1_t> && field_07) : dontCare0(std::move(dontCare0)), field_01(std::move(field_01)), field_02(std::move(field_02)), field_03(std::move(field_03)), dontCare4(std::move(dontCare4)), field_04(std::move(field_04)), field_05(std::move(field_05)), field_06(std::move(field_06)), field_07(std::move(field_07)) {}

	TRY(TRY const & other) = default;
	TRY(TRY && move) = default;

	static TRY build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_TRY_HPP
