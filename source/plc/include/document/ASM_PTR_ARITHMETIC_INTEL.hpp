// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASM_PTR_ARITHMETIC_INTEL_HPP
#define INCLUDED_ASM_PTR_ARITHMETIC_INTEL_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ASM_IDENTIFIER;
struct NON_NEG_INTEGER;
struct NON_NEG_NON_FRACTIONAL;

struct ASM_PTR_ARITHMETIC_INTEL {
	int32_t document_position, consumed_character_count;

	struct field_1_t {
		std::variant<
			parlex::detail::document::text<literal_BYTE_t>,
			parlex::detail::document::text<literal_WORD_t>,
			parlex::detail::document::text<literal_DWORD_t>,
			parlex::detail::document::text<literal_QWORD_t>
		> field_1;
		
		parlex::detail::document::text<literal_0x20PTR_t> dont_care1;
		
	
	
		explicit field_1_t
			(std::variant<
		parlex::detail::document::text<literal_BYTE_t>,
		parlex::detail::document::text<literal_WORD_t>,
		parlex::detail::document::text<literal_DWORD_t>,
		parlex::detail::document::text<literal_QWORD_t>
	> const & field_1, parlex::detail::document::text<literal_0x20PTR_t> const & dont_care1)
			: field_1(field_1), dont_care1(dont_care1) {}
	
		field_1_t(field_1_t const & other) = default;
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_2_t {
		val<ASM_IDENTIFIER> field_1;
		
		parlex::detail::document::text<literal_0x3A_t> dont_care1;
		
	
	
		explicit field_2_t
			(val<ASM_IDENTIFIER> const & field_1, parlex::detail::document::text<literal_0x3A_t> const & dont_care1)
			: field_1(field_1), dont_care1(dont_care1) {}
	
		field_2_t(field_2_t const & other) = default;
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_4_t {
		struct field_2_t {
			parlex::detail::document::text<literal_0x2A_t> dont_care0;
			
			val<NON_NEG_NON_FRACTIONAL> field_1;
			
		
		
			explicit field_2_t
				(parlex::detail::document::text<literal_0x2A_t> const & dont_care0, val<NON_NEG_NON_FRACTIONAL> const & field_1)
				: dont_care0(dont_care0), field_1(field_1) {}
		
			field_2_t(field_2_t const & other) = default;
			static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		parlex::detail::document::text<literal_0x2B_t> dont_care0;
		
		val<ASM_IDENTIFIER> field_1;
		
		std::optional<field_2_t> field_2;
		
	
	
		explicit field_4_t
			(parlex::detail::document::text<literal_0x2B_t> const & dont_care0, val<ASM_IDENTIFIER> const & field_1, std::optional<field_2_t> const & field_2)
			: dont_care0(dont_care0), field_1(field_1), field_2(field_2) {}
	
		field_4_t(field_4_t const & other) = default;
		static field_4_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_5_t {
		std::variant<
			parlex::detail::document::text<literal_0x2B_t>,
			parlex::detail::document::text<literal_0x2D_t>
		> field_1;
		
		val<NON_NEG_INTEGER> field_2;
		
	
	
		explicit field_5_t
			(std::variant<
		parlex::detail::document::text<literal_0x2B_t>,
		parlex::detail::document::text<literal_0x2D_t>
	> const & field_1, val<NON_NEG_INTEGER> const & field_2)
			: field_1(field_1), field_2(field_2) {}
	
		field_5_t(field_5_t const & other) = default;
		static field_5_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::optional<field_1_t> field_1;
	
	parlex::detail::document::text<literal_0x5B_t> dont_care1;
	
	std::optional<field_2_t> field_2;
	
	val<ASM_IDENTIFIER> field_3;
	
	std::optional<field_4_t> field_4;
	
	std::optional<field_5_t> field_5;
	
	parlex::detail::document::text<literal_0x5D_t> dont_care6;
	


	explicit ASM_PTR_ARITHMETIC_INTEL
		(int32_t documentPosition, int32_t consumedCharacterCount, std::optional<field_1_t> const & field_1, parlex::detail::document::text<literal_0x5B_t> const & dont_care1, std::optional<field_2_t> const & field_2, val<ASM_IDENTIFIER> const & field_3, std::optional<field_4_t> const & field_4, std::optional<field_5_t> const & field_5, parlex::detail::document::text<literal_0x5D_t> const & dont_care6)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), dont_care1(dont_care1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5), dont_care6(dont_care6) {}

	ASM_PTR_ARITHMETIC_INTEL(ASM_PTR_ARITHMETIC_INTEL const & other) = default;
	static ASM_PTR_ARITHMETIC_INTEL build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_ASM_PTR_ARITHMETIC_INTEL_HPP
