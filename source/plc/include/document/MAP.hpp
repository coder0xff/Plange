// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_MAP_HPP
#define INCLUDED_MAP_HPP

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

struct MAP {
	int32_t document_position, consumed_character_count;

	struct field_1_t {
		struct field_6_t {
			std::vector<erased<IC>> field_1;
			
			parlex::detail::document::text<literal_0x2C_t> dont_care1;
			
			std::vector<erased<IC>> field_2;
			
			erased<EXPRESSION> field_3;
			
			std::vector<erased<IC>> field_4;
			
			parlex::detail::document::text<literal_0x3A_t> dont_care5;
			
			std::vector<erased<IC>> field_5;
			
			erased<EXPRESSION> field_6;
			
		
		
			explicit field_6_t
				(std::vector<erased<IC>> && field_1, parlex::detail::document::text<literal_0x2C_t> && dont_care1, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && field_3, std::vector<erased<IC>> && field_4, parlex::detail::document::text<literal_0x3A_t> && dont_care5, std::vector<erased<IC>> && field_5, erased<EXPRESSION> && field_6)
				: field_1(std::move(field_1)), dont_care1(std::move(dont_care1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), dont_care5(std::move(dont_care5)), field_5(std::move(field_5)), field_6(std::move(field_6)) {}
		
			field_6_t(field_6_t const & other) = default;
			field_6_t(field_6_t && move) = default;
		
			static field_6_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		std::vector<erased<IC>> field_1;
		
		erased<EXPRESSION> field_2;
		
		std::vector<erased<IC>> field_3;
		
		parlex::detail::document::text<literal_0x3A_t> dont_care3;
		
		std::vector<erased<IC>> field_4;
		
		erased<EXPRESSION> field_5;
		
		std::vector<field_6_t> field_6;
		
	
	
		explicit field_1_t
			(std::vector<erased<IC>> && field_1, erased<EXPRESSION> && field_2, std::vector<erased<IC>> && field_3, parlex::detail::document::text<literal_0x3A_t> && dont_care3, std::vector<erased<IC>> && field_4, erased<EXPRESSION> && field_5, std::vector<field_6_t> && field_6)
			: field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), dont_care3(std::move(dont_care3)), field_4(std::move(field_4)), field_5(std::move(field_5)), field_6(std::move(field_6)) {}
	
		field_1_t(field_1_t const & other) = default;
		field_1_t(field_1_t && move) = default;
	
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_0x7B_t> dont_care0;
	
	std::optional<field_1_t> field_1;
	
	std::vector<erased<IC>> field_2;
	
	parlex::detail::document::text<literal_0x7D_t> dont_care3;
	


	explicit MAP
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x7B_t> && dont_care0, std::optional<field_1_t> && field_1, std::vector<erased<IC>> && field_2, parlex::detail::document::text<literal_0x7D_t> && dont_care3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(std::move(dont_care0)), field_1(std::move(field_1)), field_2(std::move(field_2)), dont_care3(std::move(dont_care3)) {}

	MAP(MAP const & other) = default;
	MAP(MAP && move) = default;

	static MAP build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_MAP_HPP
