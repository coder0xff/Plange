// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASM_PTR_ARITHMETIC_ATT_REG_HPP
#define INCLUDED_ASM_PTR_ARITHMETIC_ATT_REG_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ASM_IDENTIFIER;
struct NON_NEG_NON_FRACTIONAL;

struct ASM_PTR_ARITHMETIC_ATT_REG {
	struct field_2_t_1_t {
		struct field_1_t_1_t {
			parlex::detail::document::text<literal_0x2C_t> dontCare0;
			
			erased<NON_NEG_NON_FRACTIONAL> field_1;
			
		
		
			explicit field_1_t_1_t(
				parlex::detail::document::text<literal_0x2C_t> && dontCare0, erased<NON_NEG_NON_FRACTIONAL> && field_1) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)) {}
		
			field_1_t_1_t(field_1_t_1_t const & other) = default;
			field_1_t_1_t(field_1_t_1_t && move) = default;
		
			static field_1_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		parlex::detail::document::text<literal_0x2C_t> dontCare0;
		
		erased<ASM_IDENTIFIER> asm_identifier;
		
		std::optional<field_1_t_1_t> field_1;
		
	
	
		explicit field_2_t_1_t(
			parlex::detail::document::text<literal_0x2C_t> && dontCare0, erased<ASM_IDENTIFIER> && asm_identifier, std::optional<field_1_t_1_t> && field_1) : dontCare0(std::move(dontCare0)), asm_identifier(std::move(asm_identifier)), field_1(std::move(field_1)) {}
	
		field_2_t_1_t(field_2_t_1_t const & other) = default;
		field_2_t_1_t(field_2_t_1_t && move) = default;
	
		static field_2_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_0x28_t> dontCare0;
	
	std::optional<erased<ASM_IDENTIFIER>> field_1;
	
	std::optional<field_2_t_1_t> field_2;
	
	parlex::detail::document::text<literal_0x29_t> dontCare3;
	


	explicit ASM_PTR_ARITHMETIC_ATT_REG(
		parlex::detail::document::text<literal_0x28_t> && dontCare0, std::optional<erased<ASM_IDENTIFIER>> && field_1, std::optional<field_2_t_1_t> && field_2, parlex::detail::document::text<literal_0x29_t> && dontCare3) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), field_2(std::move(field_2)), dontCare3(std::move(dontCare3)) {}

	ASM_PTR_ARITHMETIC_ATT_REG(ASM_PTR_ARITHMETIC_ATT_REG const & other) = default;
	ASM_PTR_ARITHMETIC_ATT_REG(ASM_PTR_ARITHMETIC_ATT_REG && move) = default;

	static ASM_PTR_ARITHMETIC_ATT_REG build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_ASM_PTR_ARITHMETIC_ATT_REG_HPP
