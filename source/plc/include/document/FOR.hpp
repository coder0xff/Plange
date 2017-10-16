// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FOR_HPP
#define INCLUDED_FOR_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ASSIGNMENT_CHAIN;
struct EXPRESSION;
struct IC;
struct STATEMENT_SCOPE;

struct FOR {
	struct initializer_t_1_t {
		erased<STATEMENT_SCOPE> field_1;
		
		std::vector<erased<IC>> field_2;
		
	
	
		explicit initializer_t_1_t(
			erased<STATEMENT_SCOPE> && field_1, std::vector<erased<IC>> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		initializer_t_1_t(initializer_t_1_t const & other) = default;
		initializer_t_1_t(initializer_t_1_t && move) = default;
	
		static initializer_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
	
	};

	struct step_t_1_t {
		struct field_2_t_1_t {
			std::vector<erased<IC>> field_1;
			
			std::vector<erased<IC>> field_2;
			
			erased<ASSIGNMENT_CHAIN> field_3;
			
		
		
			explicit field_2_t_1_t(
				std::vector<erased<IC>> && field_1, std::vector<erased<IC>> && field_2, erased<ASSIGNMENT_CHAIN> && field_3) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}
		
			field_2_t_1_t(field_2_t_1_t const & other) = default;
			field_2_t_1_t(field_2_t_1_t && move) = default;
		
			static field_2_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
		
		};
	
		erased<ASSIGNMENT_CHAIN> field_1;
		
		std::vector<field_2_t_1_t> field_2;
		
		std::vector<erased<IC>> field_3;
		
	
	
		explicit step_t_1_t(
			erased<ASSIGNMENT_CHAIN> && field_1, std::vector<field_2_t_1_t> && field_2, std::vector<erased<IC>> && field_3) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}
	
		step_t_1_t(step_t_1_t const & other) = default;
		step_t_1_t(step_t_1_t && move) = default;
	
		static step_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
	
	};

	std::vector<erased<IC>> field_01;
	
	std::vector<erased<IC>> field_02;
	
	std::optional<initializer_t_1_t> initializer;
	
	erased<EXPRESSION> condition;
	
	std::vector<erased<IC>> field_03;
	
	std::vector<erased<IC>> field_04;
	
	std::optional<step_t_1_t> step;
	
	std::vector<erased<IC>> field_05;
	
	erased<EXPRESSION> field_06;
	


	explicit FOR(
		std::vector<erased<IC>> && field_01, std::vector<erased<IC>> && field_02, std::optional<initializer_t_1_t> && initializer, erased<EXPRESSION> && condition, std::vector<erased<IC>> && field_03, std::vector<erased<IC>> && field_04, std::optional<step_t_1_t> && step, std::vector<erased<IC>> && field_05, erased<EXPRESSION> && field_06) : field_01(std::move(field_01)), field_02(std::move(field_02)), initializer(std::move(initializer)), condition(std::move(condition)), field_03(std::move(field_03)), field_04(std::move(field_04)), step(std::move(step)), field_05(std::move(field_05)), field_06(std::move(field_06)) {}

	FOR(FOR const & other) = default;
	FOR(FOR && move) = default;

	static FOR build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_FOR_HPP
