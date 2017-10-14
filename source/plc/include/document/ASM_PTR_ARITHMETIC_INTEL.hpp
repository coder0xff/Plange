// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASM_PTR_ARITHMETIC_INTEL_HPP
#define INCLUDED_ASM_PTR_ARITHMETIC_INTEL_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ASM_IDENTIFIER;
struct NON_NEG_INTEGER;
struct NON_NEG_NON_FRACTIONAL;

struct ASM_PTR_ARITHMETIC_INTEL {
	struct field_1_t_1_t {
		struct field_1_t {
			enum type {
				literal_BYTE,
				literal_DWORD,
				literal_QWORD,
				literal_WORD
			} value;
		
			static field_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
				static ::std::unordered_map<parlex::details::recognizer const *, type> const table {
					{ &plange_grammar::get().get_literal("literal_BYTE"), literal_BYTE },
					{ &plange_grammar::get().get_literal("literal_DWORD"), literal_DWORD },
					{ &plange_grammar::get().get_literal("literal_QWORD"), literal_QWORD },
					{ &plange_grammar::get().get_literal("literal_WORD"), literal_WORD },
				};
				return field_1_t{ table.find(&n.r)->second };
			}
		};
	
	
		field_1_t field_1;
	
	
		explicit field_1_t_1_t(
			field_1_t && field_1
		) : field_1(std::move(field_1)) {}
	
		field_1_t_1_t(field_1_t_1_t const & other) = default;
		field_1_t_1_t(field_1_t_1_t && move) = default;
	
		static field_1_t_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);
	
	};

	struct field_2_t_1_t {
		erased<ASM_IDENTIFIER> field_1;
	
	
		explicit field_2_t_1_t(
			erased<ASM_IDENTIFIER> && field_1
		) : field_1(std::move(field_1)) {}
	
		field_2_t_1_t(field_2_t_1_t const & other) = default;
		field_2_t_1_t(field_2_t_1_t && move) = default;
	
		static field_2_t_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);
	
	};

	struct field_4_t_1_t {
		struct field_2_t_1_t {
			erased<NON_NEG_NON_FRACTIONAL> field_1;
		
		
			explicit field_2_t_1_t(
				erased<NON_NEG_NON_FRACTIONAL> && field_1
			) : field_1(std::move(field_1)) {}
		
			field_2_t_1_t(field_2_t_1_t const & other) = default;
			field_2_t_1_t(field_2_t_1_t && move) = default;
		
			static field_2_t_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);
		
		};
	
		erased<ASM_IDENTIFIER> field_1;
		std::optional<field_2_t_1_t> field_2;
	
	
		explicit field_4_t_1_t(
			erased<ASM_IDENTIFIER> && field_1,
			std::optional<field_2_t_1_t> && field_2
		) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_4_t_1_t(field_4_t_1_t const & other) = default;
		field_4_t_1_t(field_4_t_1_t && move) = default;
	
		static field_4_t_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);
	
	};

	struct field_5_t_1_t {
		struct field_1_t {
			enum type {
				literal_0x2B,
				literal_0x2D
			} value;
		
			static field_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
				static ::std::unordered_map<parlex::details::recognizer const *, type> const table {
					{ &plange_grammar::get().get_literal("literal_0x2B"), literal_0x2B },
					{ &plange_grammar::get().get_literal("literal_0x2D"), literal_0x2D },
				};
				return field_1_t{ table.find(&n.r)->second };
			}
		};
	
	
		field_1_t field_1;
		erased<NON_NEG_INTEGER> field_2;
	
	
		explicit field_5_t_1_t(
			field_1_t && field_1,
			erased<NON_NEG_INTEGER> && field_2
		) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_5_t_1_t(field_5_t_1_t const & other) = default;
		field_5_t_1_t(field_5_t_1_t && move) = default;
	
		static field_5_t_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);
	
	};

	std::optional<field_1_t_1_t> field_1;
	std::optional<field_2_t_1_t> field_2;
	erased<ASM_IDENTIFIER> field_3;
	std::optional<field_4_t_1_t> field_4;
	std::optional<field_5_t_1_t> field_5;


	explicit ASM_PTR_ARITHMETIC_INTEL(
		std::optional<field_1_t_1_t> && field_1,
		std::optional<field_2_t_1_t> && field_2,
		erased<ASM_IDENTIFIER> && field_3,
		std::optional<field_4_t_1_t> && field_4,
		std::optional<field_5_t_1_t> && field_5
	) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), field_5(std::move(field_5)) {}

	ASM_PTR_ARITHMETIC_INTEL(ASM_PTR_ARITHMETIC_INTEL const & other) = default;
	ASM_PTR_ARITHMETIC_INTEL(ASM_PTR_ARITHMETIC_INTEL && move) = default;

	static ASM_PTR_ARITHMETIC_INTEL build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_ASM_PTR_ARITHMETIC_INTEL_HPP
