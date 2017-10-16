// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASM_PTR_ARITHMETIC_ATT_REG_HPP
#define INCLUDED_ASM_PTR_ARITHMETIC_ATT_REG_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ASM_IDENTIFIER;
struct NON_NEG_NON_FRACTIONAL;

struct ASM_PTR_ARITHMETIC_ATT_REG {
	struct field_2_t_1_t {
		struct field_1_t_1_t {
			erased<NON_NEG_NON_FRACTIONAL> field_1;
			
		
		
			explicit field_1_t_1_t(
				erased<NON_NEG_NON_FRACTIONAL> && field_1) : field_1(std::move(field_1)) {}
		
			field_1_t_1_t(field_1_t_1_t const & other) = default;
			field_1_t_1_t(field_1_t_1_t && move) = default;
		
			static field_1_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
		
		};
	
		erased<ASM_IDENTIFIER> asm_identifier;
		
		std::optional<field_1_t_1_t> field_1;
		
	
	
		explicit field_2_t_1_t(
			erased<ASM_IDENTIFIER> && asm_identifier, std::optional<field_1_t_1_t> && field_1) : asm_identifier(std::move(asm_identifier)), field_1(std::move(field_1)) {}
	
		field_2_t_1_t(field_2_t_1_t const & other) = default;
		field_2_t_1_t(field_2_t_1_t && move) = default;
	
		static field_2_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
	
	};

	std::optional<erased<ASM_IDENTIFIER>> field_1;
	
	std::optional<field_2_t_1_t> field_2;
	


	explicit ASM_PTR_ARITHMETIC_ATT_REG(
		std::optional<erased<ASM_IDENTIFIER>> && field_1, std::optional<field_2_t_1_t> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	ASM_PTR_ARITHMETIC_ATT_REG(ASM_PTR_ARITHMETIC_ATT_REG const & other) = default;
	ASM_PTR_ARITHMETIC_ATT_REG(ASM_PTR_ARITHMETIC_ATT_REG && move) = default;

	static ASM_PTR_ARITHMETIC_ATT_REG build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_ASM_PTR_ARITHMETIC_ATT_REG_HPP
