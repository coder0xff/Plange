// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASM_STATEMENT_HPP
#define INCLUDED_ASM_STATEMENT_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ASM_EXPRESSION;
struct ASM_OP;
struct IC;

struct ASM_STATEMENT {
	int32_t document_position, consumed_character_count;

	struct field_2_t {
		struct field_3_t {
			struct field_2_t {
				std::vector<val<IC>> field_1;
				
				val<ASM_EXPRESSION> field_2;
				
			
			
				explicit field_2_t
					(std::vector<val<IC>> const & field_1, val<ASM_EXPRESSION> const & field_2)
					: field_1(field_1), field_2(field_2) {}
			
				field_2_t(field_2_t const & other) = default;
				static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
			};
		
			std::vector<val<IC>> field_1;
			
			parlex::detail::document::text<literal_0x2C_t> dont_care1;
			
			std::optional<field_2_t> field_2;
			
		
		
			explicit field_3_t
				(std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_0x2C_t> const & dont_care1, std::optional<field_2_t> const & field_2)
				: field_1(field_1), dont_care1(dont_care1), field_2(field_2) {}
		
			field_3_t(field_3_t const & other) = default;
			static field_3_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		std::vector<val<IC>> field_1;
		
		val<ASM_EXPRESSION> field_2;
		
		std::vector<field_3_t> field_3;
		
	
	
		explicit field_2_t
			(std::vector<val<IC>> const & field_1, val<ASM_EXPRESSION> const & field_2, std::vector<field_3_t> const & field_3)
			: field_1(field_1), field_2(field_2), field_3(field_3) {}
	
		field_2_t(field_2_t const & other) = default;
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	val<ASM_OP> field_1;
	
	std::optional<field_2_t> field_2;
	
	std::vector<val<IC>> field_3;
	
	parlex::detail::document::text<literal_0x0A_t> dont_care3;
	


	explicit ASM_STATEMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<ASM_OP> const & field_1, std::optional<field_2_t> const & field_2, std::vector<val<IC>> const & field_3, parlex::detail::document::text<literal_0x0A_t> const & dont_care3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), dont_care3(dont_care3) {}

	ASM_STATEMENT(ASM_STATEMENT const & other) = default;
	static ASM_STATEMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_ASM_STATEMENT_HPP
