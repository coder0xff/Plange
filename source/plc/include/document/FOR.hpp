// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FOR_HPP
#define INCLUDED_FOR_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ASSIGNMENT_CHAIN;
struct EXPRESSION;
struct IC;
struct STATEMENT_SCOPE;

struct FOR {
	int32_t document_position, consumed_character_count;

	struct initializer_t {
		erased<STATEMENT_SCOPE> field_1;
		
		std::vector<erased<IC>> field_2;
		
	
	
		explicit initializer_t
			(erased<STATEMENT_SCOPE> && field_1, std::vector<erased<IC>> && field_2)
			: field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		initializer_t(initializer_t const & other) = default;
		initializer_t(initializer_t && move) = default;
	
		static initializer_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct step_t {
		struct field_2_t {
			std::vector<erased<IC>> field_1;
			
			parlex::detail::document::text<literal_0x2C_t> dont_care1;
			
			std::vector<erased<IC>> field_2;
			
			erased<ASSIGNMENT_CHAIN> field_3;
			
		
		
			explicit field_2_t
				(std::vector<erased<IC>> && field_1, parlex::detail::document::text<literal_0x2C_t> && dont_care1, std::vector<erased<IC>> && field_2, erased<ASSIGNMENT_CHAIN> && field_3)
				: field_1(std::move(field_1)), dont_care1(std::move(dont_care1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}
		
			field_2_t(field_2_t const & other) = default;
			field_2_t(field_2_t && move) = default;
		
			static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		erased<ASSIGNMENT_CHAIN> field_1;
		
		std::vector<field_2_t> field_2;
		
		std::vector<erased<IC>> field_3;
		
	
	
		explicit step_t
			(erased<ASSIGNMENT_CHAIN> && field_1, std::vector<field_2_t> && field_2, std::vector<erased<IC>> && field_3)
			: field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}
	
		step_t(step_t const & other) = default;
		step_t(step_t && move) = default;
	
		static step_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_for_t> dont_care0;
	
	std::vector<erased<IC>> field_01;
	
	parlex::detail::document::text<literal_0x28_t> dont_care2;
	
	std::vector<erased<IC>> field_02;
	
	std::optional<initializer_t> initializer;
	
	erased<EXPRESSION> condition;
	
	std::vector<erased<IC>> field_03;
	
	parlex::detail::document::text<literal_0x3B_t> dont_care7;
	
	std::vector<erased<IC>> field_04;
	
	std::optional<step_t> step;
	
	parlex::detail::document::text<literal_0x29_t> dont_care10;
	
	std::vector<erased<IC>> field_05;
	
	erased<EXPRESSION> field_06;
	


	explicit FOR
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_for_t> && dont_care0, std::vector<erased<IC>> && field_01, parlex::detail::document::text<literal_0x28_t> && dont_care2, std::vector<erased<IC>> && field_02, std::optional<initializer_t> && initializer, erased<EXPRESSION> && condition, std::vector<erased<IC>> && field_03, parlex::detail::document::text<literal_0x3B_t> && dont_care7, std::vector<erased<IC>> && field_04, std::optional<step_t> && step, parlex::detail::document::text<literal_0x29_t> && dont_care10, std::vector<erased<IC>> && field_05, erased<EXPRESSION> && field_06)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(std::move(dont_care0)), field_01(std::move(field_01)), dont_care2(std::move(dont_care2)), field_02(std::move(field_02)), initializer(std::move(initializer)), condition(std::move(condition)), field_03(std::move(field_03)), dont_care7(std::move(dont_care7)), field_04(std::move(field_04)), step(std::move(step)), dont_care10(std::move(dont_care10)), field_05(std::move(field_05)), field_06(std::move(field_06)) {}

	FOR(FOR const & other) = default;
	FOR(FOR && move) = default;

	static FOR build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_FOR_HPP
