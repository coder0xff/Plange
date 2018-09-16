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
	int32_t document_position, consumed_character_count;

	struct field_2_t {
		struct field_1_t {
			parlex::detail::document::text<literal_0x2C_t> dont_care0;
			
			erased<NON_NEG_NON_FRACTIONAL> field_1;
			
		
		
			explicit field_1_t
				(parlex::detail::document::text<literal_0x2C_t> && dont_care0, erased<NON_NEG_NON_FRACTIONAL> && field_1)
				: dont_care0(std::move(dont_care0)), field_1(std::move(field_1)) {}
		
			field_1_t(field_1_t const & other) = default;
			field_1_t(field_1_t && move) = default;
		
			static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		parlex::detail::document::text<literal_0x2C_t> dont_care0;
		
		erased<ASM_IDENTIFIER> asm_identifier;
		
		std::optional<field_1_t> field_1;
		
	
	
		explicit field_2_t
			(parlex::detail::document::text<literal_0x2C_t> && dont_care0, erased<ASM_IDENTIFIER> && asm_identifier, std::optional<field_1_t> && field_1)
			: dont_care0(std::move(dont_care0)), asm_identifier(std::move(asm_identifier)), field_1(std::move(field_1)) {}
	
		field_2_t(field_2_t const & other) = default;
		field_2_t(field_2_t && move) = default;
	
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_0x28_t> dont_care0;
	
	std::optional<erased<ASM_IDENTIFIER>> field_1;
	
	std::optional<field_2_t> field_2;
	
	parlex::detail::document::text<literal_0x29_t> dont_care3;
	


	explicit ASM_PTR_ARITHMETIC_ATT_REG
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x28_t> && dont_care0, std::optional<erased<ASM_IDENTIFIER>> && field_1, std::optional<field_2_t> && field_2, parlex::detail::document::text<literal_0x29_t> && dont_care3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(std::move(dont_care0)), field_1(std::move(field_1)), field_2(std::move(field_2)), dont_care3(std::move(dont_care3)) {}

	ASM_PTR_ARITHMETIC_ATT_REG(ASM_PTR_ARITHMETIC_ATT_REG const & other) = default;
	ASM_PTR_ARITHMETIC_ATT_REG(ASM_PTR_ARITHMETIC_ATT_REG && move) = default;

	static ASM_PTR_ARITHMETIC_ATT_REG build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_ASM_PTR_ARITHMETIC_ATT_REG_HPP
