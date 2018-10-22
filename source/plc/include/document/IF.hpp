// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_IF_HPP
#define INCLUDED_IF_HPP

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
struct PARENTHETICAL;

struct IF {
	int32_t document_position, consumed_character_count;

	struct field_3_t {
		std::vector<val<IC>> field_1;
		
		parlex::detail::document::text<literal_elif_t> dont_care1;
		
		std::vector<val<IC>> field_2;
		
		val<PARENTHETICAL> condition;
		
		std::vector<val<IC>> field_3;
		
		val<EXPRESSION> invoke;
		
	
	
		explicit field_3_t
			(std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_elif_t> const & dont_care1, std::vector<val<IC>> const & field_2, val<PARENTHETICAL> const & condition, std::vector<val<IC>> const & field_3, val<EXPRESSION> const & invoke)
			: field_1(field_1), dont_care1(dont_care1), field_2(field_2), condition(condition), field_3(field_3), invoke(invoke) {}
	
		field_3_t(field_3_t const & other) = default;
		static field_3_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_4_t {
		std::vector<val<IC>> field_1;
		
		parlex::detail::document::text<literal_else_t> dont_care1;
		
		std::vector<val<IC>> field_2;
		
		val<EXPRESSION> else_invoke;
		
	
	
		explicit field_4_t
			(std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_else_t> const & dont_care1, std::vector<val<IC>> const & field_2, val<EXPRESSION> const & else_invoke)
			: field_1(field_1), dont_care1(dont_care1), field_2(field_2), else_invoke(else_invoke) {}
	
		field_4_t(field_4_t const & other) = default;
		static field_4_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_if_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<PARENTHETICAL> condition;
	
	std::vector<val<IC>> field_2;
	
	val<EXPRESSION> invoke;
	
	std::vector<field_3_t> field_3;
	
	std::optional<field_4_t> field_4;
	


	explicit IF
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_if_t> const & dont_care0, std::vector<val<IC>> const & field_1, val<PARENTHETICAL> const & condition, std::vector<val<IC>> const & field_2, val<EXPRESSION> const & invoke, std::vector<field_3_t> const & field_3, std::optional<field_4_t> const & field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), condition(condition), field_2(field_2), invoke(invoke), field_3(field_3), field_4(field_4) {}

	IF(IF const & other) = default;
	static IF build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_IF_HPP
