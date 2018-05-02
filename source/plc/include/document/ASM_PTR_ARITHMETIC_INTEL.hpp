// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASM_PTR_ARITHMETIC_INTEL_HPP
#define INCLUDED_ASM_PTR_ARITHMETIC_INTEL_HPP

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
struct NON_NEG_INTEGER;
struct NON_NEG_NON_FRACTIONAL;

struct ASM_PTR_ARITHMETIC_INTEL {
	struct field_1_t_1_t {
		std::variant<
			parlex::detail::document::text<literal_BYTE_t>,
			parlex::detail::document::text<literal_WORD_t>,
			parlex::detail::document::text<literal_DWORD_t>,
			parlex::detail::document::text<literal_QWORD_t>
		> field_1;
		
		parlex::detail::document::text<literal_0x20PTR_t> dontCare1;
		
	
	
		explicit field_1_t_1_t(
			std::variant<
				parlex::detail::document::text<literal_BYTE_t>,
				parlex::detail::document::text<literal_WORD_t>,
				parlex::detail::document::text<literal_DWORD_t>,
				parlex::detail::document::text<literal_QWORD_t>
			> && field_1, parlex::detail::document::text<literal_0x20PTR_t> && dontCare1) : field_1(std::move(field_1)), dontCare1(std::move(dontCare1)) {}
	
		field_1_t_1_t(field_1_t_1_t const & other) = default;
		field_1_t_1_t(field_1_t_1_t && move) = default;
	
		static field_1_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_2_t_1_t {
		erased<ASM_IDENTIFIER> field_1;
		
		parlex::detail::document::text<literal_0x3A_t> dontCare1;
		
	
	
		explicit field_2_t_1_t(
			erased<ASM_IDENTIFIER> && field_1, parlex::detail::document::text<literal_0x3A_t> && dontCare1) : field_1(std::move(field_1)), dontCare1(std::move(dontCare1)) {}
	
		field_2_t_1_t(field_2_t_1_t const & other) = default;
		field_2_t_1_t(field_2_t_1_t && move) = default;
	
		static field_2_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_4_t_1_t {
		struct field_2_t_1_t {
			parlex::detail::document::text<literal_0x2A_t> dontCare0;
			
			erased<NON_NEG_NON_FRACTIONAL> field_1;
			
		
		
			explicit field_2_t_1_t(
				parlex::detail::document::text<literal_0x2A_t> && dontCare0, erased<NON_NEG_NON_FRACTIONAL> && field_1) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)) {}
		
			field_2_t_1_t(field_2_t_1_t const & other) = default;
			field_2_t_1_t(field_2_t_1_t && move) = default;
		
			static field_2_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		parlex::detail::document::text<literal_0x2B_t> dontCare0;
		
		erased<ASM_IDENTIFIER> field_1;
		
		std::optional<field_2_t_1_t> field_2;
		
	
	
		explicit field_4_t_1_t(
			parlex::detail::document::text<literal_0x2B_t> && dontCare0, erased<ASM_IDENTIFIER> && field_1, std::optional<field_2_t_1_t> && field_2) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_4_t_1_t(field_4_t_1_t const & other) = default;
		field_4_t_1_t(field_4_t_1_t && move) = default;
	
		static field_4_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_5_t_1_t {
		std::variant<
			parlex::detail::document::text<literal_0x2B_t>,
			parlex::detail::document::text<literal_0x2D_t>
		> field_1;
		
		erased<NON_NEG_INTEGER> field_2;
		
	
	
		explicit field_5_t_1_t(
			std::variant<
				parlex::detail::document::text<literal_0x2B_t>,
				parlex::detail::document::text<literal_0x2D_t>
			> && field_1, erased<NON_NEG_INTEGER> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_5_t_1_t(field_5_t_1_t const & other) = default;
		field_5_t_1_t(field_5_t_1_t && move) = default;
	
		static field_5_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::optional<field_1_t_1_t> field_1;
	
	parlex::detail::document::text<literal_0x5B_t> dontCare1;
	
	std::optional<field_2_t_1_t> field_2;
	
	erased<ASM_IDENTIFIER> field_3;
	
	std::optional<field_4_t_1_t> field_4;
	
	std::optional<field_5_t_1_t> field_5;
	
	parlex::detail::document::text<literal_0x5D_t> dontCare6;
	


	explicit ASM_PTR_ARITHMETIC_INTEL(
		std::optional<field_1_t_1_t> && field_1, parlex::detail::document::text<literal_0x5B_t> && dontCare1, std::optional<field_2_t_1_t> && field_2, erased<ASM_IDENTIFIER> && field_3, std::optional<field_4_t_1_t> && field_4, std::optional<field_5_t_1_t> && field_5, parlex::detail::document::text<literal_0x5D_t> && dontCare6) : field_1(std::move(field_1)), dontCare1(std::move(dontCare1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), field_5(std::move(field_5)), dontCare6(std::move(dontCare6)) {}

	ASM_PTR_ARITHMETIC_INTEL(ASM_PTR_ARITHMETIC_INTEL const & other) = default;
	ASM_PTR_ARITHMETIC_INTEL(ASM_PTR_ARITHMETIC_INTEL && move) = default;

	static ASM_PTR_ARITHMETIC_INTEL build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_ASM_PTR_ARITHMETIC_INTEL_HPP
