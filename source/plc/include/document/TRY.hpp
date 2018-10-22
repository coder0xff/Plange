// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TRY_HPP
#define INCLUDED_TRY_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct TRY {
	int32_t document_position, consumed_character_count;

	struct field_06_t {
		parlex::detail::document::text<literal_catch_t> dont_care0;
		
		std::vector<val<IC>> field_1;
		
		val<EXPRESSION> field_2;
		
	
	
		explicit field_06_t
			(parlex::detail::document::text<literal_catch_t> const & dont_care0, std::vector<val<IC>> const & field_1, val<EXPRESSION> const & field_2)
			: dont_care0(dont_care0), field_1(field_1), field_2(field_2) {}
	
		field_06_t(field_06_t const & other) = default;
		static field_06_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_07_t {
		std::vector<val<IC>> field_1;
		
		parlex::detail::document::text<literal_finally_t> dont_care1;
		
		std::vector<val<IC>> field_2;
		
		val<EXPRESSION> field_3;
		
	
	
		explicit field_07_t
			(std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_finally_t> const & dont_care1, std::vector<val<IC>> const & field_2, val<EXPRESSION> const & field_3)
			: field_1(field_1), dont_care1(dont_care1), field_2(field_2), field_3(field_3) {}
	
		field_07_t(field_07_t const & other) = default;
		static field_07_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_try_t> dont_care0;
	
	std::vector<val<IC>> field_01;
	
	val<EXPRESSION> field_02;
	
	std::vector<val<IC>> field_03;
	
	parlex::detail::document::text<literal_catch_t> dont_care4;
	
	std::vector<val<IC>> field_04;
	
	val<EXPRESSION> field_05;
	
	std::vector<field_06_t> field_06;
	
	std::optional<field_07_t> field_07;
	


	explicit TRY
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_try_t> const & dont_care0, std::vector<val<IC>> const & field_01, val<EXPRESSION> const & field_02, std::vector<val<IC>> const & field_03, parlex::detail::document::text<literal_catch_t> const & dont_care4, std::vector<val<IC>> const & field_04, val<EXPRESSION> const & field_05, std::vector<field_06_t> const & field_06, std::optional<field_07_t> const & field_07)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_01(field_01), field_02(field_02), field_03(field_03), dont_care4(dont_care4), field_04(field_04), field_05(field_05), field_06(field_06), field_07(field_07) {}

	TRY(TRY const & other) = default;
	static TRY build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_TRY_HPP
