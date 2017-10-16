// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_IF_HPP
#define INCLUDED_IF_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;
struct PARENTHETICAL;

struct IF {
	struct field_3_t_1_t {
		std::vector<erased<IC>> field_1;
		
		std::vector<erased<IC>> field_2;
		
		erased<PARENTHETICAL> condition;
		
		std::vector<erased<IC>> field_3;
		
		erased<EXPRESSION> invoke;
		
	
	
		explicit field_3_t_1_t(
			std::vector<erased<IC>> && field_1, std::vector<erased<IC>> && field_2, erased<PARENTHETICAL> && condition, std::vector<erased<IC>> && field_3, erased<EXPRESSION> && invoke) : field_1(std::move(field_1)), field_2(std::move(field_2)), condition(std::move(condition)), field_3(std::move(field_3)), invoke(std::move(invoke)) {}
	
		field_3_t_1_t(field_3_t_1_t const & other) = default;
		field_3_t_1_t(field_3_t_1_t && move) = default;
	
		static field_3_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
	
	};

	struct field_4_t_1_t {
		std::vector<erased<IC>> field_1;
		
		std::vector<erased<IC>> field_2;
		
		erased<EXPRESSION> else_invoke;
		
	
	
		explicit field_4_t_1_t(
			std::vector<erased<IC>> && field_1, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && else_invoke) : field_1(std::move(field_1)), field_2(std::move(field_2)), else_invoke(std::move(else_invoke)) {}
	
		field_4_t_1_t(field_4_t_1_t const & other) = default;
		field_4_t_1_t(field_4_t_1_t && move) = default;
	
		static field_4_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
	
	};

	std::vector<erased<IC>> field_1;
	
	erased<PARENTHETICAL> condition;
	
	std::vector<erased<IC>> field_2;
	
	erased<EXPRESSION> invoke;
	
	std::vector<field_3_t_1_t> field_3;
	
	std::optional<field_4_t_1_t> field_4;
	


	explicit IF(
		std::vector<erased<IC>> && field_1, erased<PARENTHETICAL> && condition, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && invoke, std::vector<field_3_t_1_t> && field_3, std::optional<field_4_t_1_t> && field_4) : field_1(std::move(field_1)), condition(std::move(condition)), field_2(std::move(field_2)), invoke(std::move(invoke)), field_3(std::move(field_3)), field_4(std::move(field_4)) {}

	IF(IF const & other) = default;
	IF(IF && move) = default;

	static IF build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_IF_HPP
