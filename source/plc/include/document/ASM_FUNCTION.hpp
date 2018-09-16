// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASM_FUNCTION_HPP
#define INCLUDED_ASM_FUNCTION_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ASM_SCOPE;
struct FUNCTION_MODIFIER_0;
struct IC;
struct PARAMETER;

struct ASM_FUNCTION {
	int32_t document_position, consumed_character_count;

	struct field_1_t {
		struct field_2_t {
			struct field_1_t {
				std::vector<erased<IC>> field_1;
				
				parlex::detail::document::text<literal_0x2C_t> dont_care1;
				
				std::vector<erased<IC>> field_2;
				
				erased<PARAMETER> parameter;
				
			
			
				explicit field_1_t
					(std::vector<erased<IC>> && field_1, parlex::detail::document::text<literal_0x2C_t> && dont_care1, std::vector<erased<IC>> && field_2, erased<PARAMETER> && parameter)
					: field_1(std::move(field_1)), dont_care1(std::move(dont_care1)), field_2(std::move(field_2)), parameter(std::move(parameter)) {}
			
				field_1_t(field_1_t const & other) = default;
				field_1_t(field_1_t && move) = default;
			
				static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
			};
		
			erased<PARAMETER> parameter;
			
			std::vector<field_1_t> field_1;
			
			std::vector<erased<IC>> field_2;
			
		
		
			explicit field_2_t
				(erased<PARAMETER> && parameter, std::vector<field_1_t> && field_1, std::vector<erased<IC>> && field_2)
				: parameter(std::move(parameter)), field_1(std::move(field_1)), field_2(std::move(field_2)) {}
		
			field_2_t(field_2_t const & other) = default;
			field_2_t(field_2_t && move) = default;
		
			static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		parlex::detail::document::text<literal_0x28_t> dont_care0;
		
		std::vector<erased<IC>> field_1;
		
		std::optional<field_2_t> field_2;
		
		parlex::detail::document::text<literal_0x29_t> dont_care3;
		
		std::vector<erased<IC>> field_3;
		
	
	
		explicit field_1_t
			(parlex::detail::document::text<literal_0x28_t> && dont_care0, std::vector<erased<IC>> && field_1, std::optional<field_2_t> && field_2, parlex::detail::document::text<literal_0x29_t> && dont_care3, std::vector<erased<IC>> && field_3)
			: dont_care0(std::move(dont_care0)), field_1(std::move(field_1)), field_2(std::move(field_2)), dont_care3(std::move(dont_care3)), field_3(std::move(field_3)) {}
	
		field_1_t(field_1_t const & other) = default;
		field_1_t(field_1_t && move) = default;
	
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::optional<field_1_t> field_1;
	
	std::optional<erased<FUNCTION_MODIFIER_0>> field_2;
	
	parlex::detail::document::text<literal_asm_t> dont_care2;
	
	std::vector<erased<IC>> field_3;
	
	parlex::detail::document::text<literal_0x7B_t> dont_care4;
	
	erased<ASM_SCOPE> field_4;
	
	parlex::detail::document::text<literal_0x7D_t> dont_care6;
	


	explicit ASM_FUNCTION
		(int32_t documentPosition, int32_t consumedCharacterCount, std::optional<field_1_t> && field_1, std::optional<erased<FUNCTION_MODIFIER_0>> && field_2, parlex::detail::document::text<literal_asm_t> && dont_care2, std::vector<erased<IC>> && field_3, parlex::detail::document::text<literal_0x7B_t> && dont_care4, erased<ASM_SCOPE> && field_4, parlex::detail::document::text<literal_0x7D_t> && dont_care6)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(std::move(field_1)), field_2(std::move(field_2)), dont_care2(std::move(dont_care2)), field_3(std::move(field_3)), dont_care4(std::move(dont_care4)), field_4(std::move(field_4)), dont_care6(std::move(dont_care6)) {}

	ASM_FUNCTION(ASM_FUNCTION const & other) = default;
	ASM_FUNCTION(ASM_FUNCTION && move) = default;

	static ASM_FUNCTION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_ASM_FUNCTION_HPP
