// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_MAP_HPP
#define INCLUDED_MAP_HPP

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

struct MAP {
	int32_t document_position, consumed_character_count;

	struct field_1_t {
		struct field_6_t {
			std::vector<val<IC>> field_1;
			
			parlex::detail::document::text<literal_0x2C_t> dont_care1;
			
			std::vector<val<IC>> field_2;
			
			val<EXPRESSION> field_3;
			
			std::vector<val<IC>> field_4;
			
			parlex::detail::document::text<literal_0x3A_t> dont_care5;
			
			std::vector<val<IC>> field_5;
			
			val<EXPRESSION> field_6;
			
		
		
			explicit field_6_t
				(std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_0x2C_t> const & dont_care1, std::vector<val<IC>> const & field_2, val<EXPRESSION> const & field_3, std::vector<val<IC>> const & field_4, parlex::detail::document::text<literal_0x3A_t> const & dont_care5, std::vector<val<IC>> const & field_5, val<EXPRESSION> const & field_6)
				: field_1(field_1), dont_care1(dont_care1), field_2(field_2), field_3(field_3), field_4(field_4), dont_care5(dont_care5), field_5(field_5), field_6(field_6) {}
		
			field_6_t(field_6_t const & other) = default;
			static field_6_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		std::vector<val<IC>> field_1;
		
		val<EXPRESSION> field_2;
		
		std::vector<val<IC>> field_3;
		
		parlex::detail::document::text<literal_0x3A_t> dont_care3;
		
		std::vector<val<IC>> field_4;
		
		val<EXPRESSION> field_5;
		
		std::vector<field_6_t> field_6;
		
	
	
		explicit field_1_t
			(std::vector<val<IC>> const & field_1, val<EXPRESSION> const & field_2, std::vector<val<IC>> const & field_3, parlex::detail::document::text<literal_0x3A_t> const & dont_care3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5, std::vector<field_6_t> const & field_6)
			: field_1(field_1), field_2(field_2), field_3(field_3), dont_care3(dont_care3), field_4(field_4), field_5(field_5), field_6(field_6) {}
	
		field_1_t(field_1_t const & other) = default;
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_0x7B_t> dont_care0;
	
	std::optional<field_1_t> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x7D_t> dont_care3;
	


	explicit MAP
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x7B_t> const & dont_care0, std::optional<field_1_t> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x7D_t> const & dont_care3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), field_2(field_2), dont_care3(dont_care3) {}

	MAP(MAP const & other) = default;
	static MAP build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_MAP_HPP
