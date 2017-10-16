// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASM_PTR_ARITHMETIC_INTEL_HPP
#define INCLUDED_ASM_PTR_ARITHMETIC_INTEL_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ASM_IDENTIFIER;
struct NON_NEG_INTEGER;
struct NON_NEG_NON_FRACTIONAL;

struct ASM_PTR_ARITHMETIC_INTEL {
	struct field_1_t_1_t {
		std::variant<
			literal_BYTE_t,
			literal_WORD_t,
			literal_DWORD_t,
			literal_QWORD_t
		> field_1;
		
	
	
		explicit field_1_t_1_t(
			std::variant<
				literal_BYTE_t,
				literal_WORD_t,
				literal_DWORD_t,
				literal_QWORD_t
			> && field_1) : field_1(std::move(field_1)) {}
	
		field_1_t_1_t(field_1_t_1_t const & other) = default;
		field_1_t_1_t(field_1_t_1_t && move) = default;
	
		static field_1_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
	
	};

	struct field_2_t_1_t {
		erased<ASM_IDENTIFIER> field_1;
		
	
	
		explicit field_2_t_1_t(
			erased<ASM_IDENTIFIER> && field_1) : field_1(std::move(field_1)) {}
	
		field_2_t_1_t(field_2_t_1_t const & other) = default;
		field_2_t_1_t(field_2_t_1_t && move) = default;
	
		static field_2_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
	
	};

	struct field_4_t_1_t {
		struct field_2_t_1_t {
			erased<NON_NEG_NON_FRACTIONAL> field_1;
			
		
		
			explicit field_2_t_1_t(
				erased<NON_NEG_NON_FRACTIONAL> && field_1) : field_1(std::move(field_1)) {}
		
			field_2_t_1_t(field_2_t_1_t const & other) = default;
			field_2_t_1_t(field_2_t_1_t && move) = default;
		
			static field_2_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
		
		};
	
		erased<ASM_IDENTIFIER> field_1;
		
		std::optional<field_2_t_1_t> field_2;
		
	
	
		explicit field_4_t_1_t(
			erased<ASM_IDENTIFIER> && field_1, std::optional<field_2_t_1_t> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_4_t_1_t(field_4_t_1_t const & other) = default;
		field_4_t_1_t(field_4_t_1_t && move) = default;
	
		static field_4_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
	
	};

	struct field_5_t_1_t {
		std::variant<
			literal_0x2B_t,
			literal_0x2D_t
		> field_1;
		
		erased<NON_NEG_INTEGER> field_2;
		
	
	
		explicit field_5_t_1_t(
			std::variant<
				literal_0x2B_t,
				literal_0x2D_t
			> && field_1, erased<NON_NEG_INTEGER> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_5_t_1_t(field_5_t_1_t const & other) = default;
		field_5_t_1_t(field_5_t_1_t && move) = default;
	
		static field_5_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
	
	};

	std::optional<field_1_t_1_t> field_1;
	
	std::optional<field_2_t_1_t> field_2;
	
	erased<ASM_IDENTIFIER> field_3;
	
	std::optional<field_4_t_1_t> field_4;
	
	std::optional<field_5_t_1_t> field_5;
	


	explicit ASM_PTR_ARITHMETIC_INTEL(
		std::optional<field_1_t_1_t> && field_1, std::optional<field_2_t_1_t> && field_2, erased<ASM_IDENTIFIER> && field_3, std::optional<field_4_t_1_t> && field_4, std::optional<field_5_t_1_t> && field_5) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), field_5(std::move(field_5)) {}

	ASM_PTR_ARITHMETIC_INTEL(ASM_PTR_ARITHMETIC_INTEL const & other) = default;
	ASM_PTR_ARITHMETIC_INTEL(ASM_PTR_ARITHMETIC_INTEL && move) = default;

	static ASM_PTR_ARITHMETIC_INTEL build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_ASM_PTR_ARITHMETIC_INTEL_HPP
