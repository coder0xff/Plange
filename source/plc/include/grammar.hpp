// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_PLANGE_HPP
#define INCLUDED_PLANGE_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/acceptor.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"
#include "parlex/detail/grammar.hpp"

namespace plc {

// "\n"
struct literal_0x0A_t { };
// " PTR"
struct literal_0x20PTR_t { };
// "!"
struct literal_0x21_t { };
// "\""
struct literal_0x22_t { };
// "\"\"\""
struct literal_0x220x220x22_t { };
// "#"
struct literal_0x23_t { };
// "%"
struct literal_0x25_t { };
// "&"
struct literal_0x26_t { };
// "&&"
struct literal_0x260x26_t { };
// "\'|"
struct literal_0x270x7C_t { };
// "("
struct literal_0x28_t { };
// "(|"
struct literal_0x280x7C_t { };
// ")"
struct literal_0x29_t { };
// "*"
struct literal_0x2A_t { };
// "***/"
struct literal_0x2A0x2A0x2A0x2F_t { };
// "*/"
struct literal_0x2A0x2F_t { };
// "+"
struct literal_0x2B_t { };
// "++"
struct literal_0x2B0x2B_t { };
// "+-"
struct literal_0x2B0x2D_t { };
// "+<-"
struct literal_0x2B0x3C0x2D_t { };
// "+←"
struct literal_0x2B0xE20x860x90_t { };
// ","
struct literal_0x2C_t { };
// ", "
struct literal_0x2C0x20_t { };
// "-"
struct literal_0x2D_t { };
// "--"
struct literal_0x2D0x2D_t { };
// "->"
struct literal_0x2D0x3E_t { };
// "."
struct literal_0x2E_t { };
// "..."
struct literal_0x2E0x2E0x2E_t { };
// "/"
struct literal_0x2F_t { };
// "/*"
struct literal_0x2F0x2A_t { };
// "/***"
struct literal_0x2F0x2A0x2A0x2A_t { };
// "//"
struct literal_0x2F0x2F_t { };
// "/="
struct literal_0x2F0x3D_t { };
// "/has"
struct literal_0x2Fhas_t { };
// "/in"
struct literal_0x2Fin_t { };
// "0"
struct literal_0_t { };
// "0x"
struct literal_0x_t { };
// "1"
struct literal_1_t { };
// "2"
struct literal_2_t { };
// "3"
struct literal_3_t { };
// "4"
struct literal_4_t { };
// "5"
struct literal_5_t { };
// "6"
struct literal_6_t { };
// "7"
struct literal_7_t { };
// "8"
struct literal_8_t { };
// "9"
struct literal_9_t { };
// ":"
struct literal_0x3A_t { };
// ":="
struct literal_0x3A0x3D_t { };
// ";"
struct literal_0x3B_t { };
// "<"
struct literal_0x3C_t { };
// "<-"
struct literal_0x3C0x2D_t { };
// "<->"
struct literal_0x3C0x2D0x3E_t { };
// "<<"
struct literal_0x3C0x3C_t { };
// "<=>"
struct literal_0x3C0x3D0x3E_t { };
// "="
struct literal_0x3D_t { };
// "=<"
struct literal_0x3D0x3C_t { };
// "=>"
struct literal_0x3D0x3E_t { };
// ">"
struct literal_0x3E_t { };
// ">>"
struct literal_0x3E0x3E_t { };
// "\?"
struct literal_0x3F_t { };
// "\?\?"
struct literal_0x3F0x3F_t { };
// "@"
struct literal_0x40_t { };
// "BYTE"
struct literal_BYTE_t { };
// "DWORD"
struct literal_DWORD_t { };
// "QWORD"
struct literal_QWORD_t { };
// "R"
struct literal_R_t { };
// "T"
struct literal_T_t { };
// "WORD"
struct literal_WORD_t { };
// "X86_fast_call"
struct literal_X86_fast_call_t { };
// "Z"
struct literal_Z_t { };
// "["
struct literal_0x5B_t { };
// "[|"
struct literal_0x5B0x7C_t { };
// "\\"
struct literal_0x5C_t { };
// "]"
struct literal_0x5D_t { };
// "^"
struct literal_0x5E_t { };
// "^^"
struct literal_0x5E0x5E_t { };
// "_"
struct literal___t { };
// "_delta_"
struct literal__delta__t { };
// "_dot_"
struct literal__dot__t { };
// "_o_"
struct literal__o__t { };
// "_swiz_"
struct literal__swiz__t { };
// "_x_"
struct literal__x__t { };
// "_|"
struct literal__0x7C_t { };
// "`"
struct literal_0x60_t { };
// "```"
struct literal_0x600x600x60_t { };
// "all"
struct literal_all_t { };
// "alloc"
struct literal_alloc_t { };
// "and"
struct literal_and_t { };
// "any_reg_call"
struct literal_any_reg_call_t { };
// "arm_aapcs_call"
struct literal_arm_aapcs_call_t { };
// "arm_aapcs_vfp_call"
struct literal_arm_aapcs_vfp_call_t { };
// "arm_apcs_call"
struct literal_arm_apcs_call_t { };
// "asm"
struct literal_asm_t { };
// "atomic"
struct literal_atomic_t { };
// "avr_builtin_call"
struct literal_avr_builtin_call_t { };
// "avr_intr_call"
struct literal_avr_intr_call_t { };
// "avr_signal_call"
struct literal_avr_signal_call_t { };
// "break"
struct literal_break_t { };
// "c_call"
struct literal_c_call_t { };
// "casts"
struct literal_casts_t { };
// "catch"
struct literal_catch_t { };
// "cold_call"
struct literal_cold_call_t { };
// "const"
struct literal_const_t { };
// "context"
struct literal_context_t { };
// "continue"
struct literal_continue_t { };
// "cxx_fast_tls_call"
struct literal_cxx_fast_tls_call_t { };
// "diamond"
struct literal_diamond_t { };
// "do"
struct literal_do_t { };
// "downcasts"
struct literal_downcasts_t { };
// "elif"
struct literal_elif_t { };
// "else"
struct literal_else_t { };
// "enum"
struct literal_enum_t { };
// "exactly"
struct literal_exactly_t { };
// "exists"
struct literal_exists_t { };
// "exists!"
struct literal_exists0x21_t { };
// "extern"
struct literal_extern_t { };
// "false"
struct literal_false_t { };
// "fast_call"
struct literal_fast_call_t { };
// "finally"
struct literal_finally_t { };
// "first_target_call"
struct literal_first_target_call_t { };
// "for"
struct literal_for_t { };
// "free"
struct literal_free_t { };
// "ghc_call"
struct literal_ghc_call_t { };
// "has"
struct literal_has_t { };
// "hhvm_call"
struct literal_hhvm_call_t { };
// "hipe_call"
struct literal_hipe_call_t { };
// "if"
struct literal_if_t { };
// "imperative"
struct literal_imperative_t { };
// "implementing"
struct literal_implementing_t { };
// "implements"
struct literal_implements_t { };
// "import"
struct literal_import_t { };
// "in"
struct literal_in_t { };
// "inheriting"
struct literal_inheriting_t { };
// "inherits"
struct literal_inherits_t { };
// "intel_ocl_bi_call"
struct literal_intel_ocl_bi_call_t { };
// "internal"
struct literal_internal_t { };
// "is"
struct literal_is_t { };
// "lock"
struct literal_lock_t { };
// "msp430_intr_call"
struct literal_msp430_intr_call_t { };
// "nand"
struct literal_nand_t { };
// "nor"
struct literal_nor_t { };
// "null"
struct literal_null_t { };
// "object"
struct literal_object_t { };
// "opaque"
struct literal_opaque_t { };
// "or"
struct literal_or_t { };
// "preserve_all_call"
struct literal_preserve_all_call_t { };
// "preserve_most_call"
struct literal_preserve_most_call_t { };
// "private"
struct literal_private_t { };
// "protected"
struct literal_protected_t { };
// "protected internal"
struct literal_protected0x20internal_t { };
// "psubs"
struct literal_psubs_t { };
// "psups"
struct literal_psups_t { };
// "ptx_device_call"
struct literal_ptx_device_call_t { };
// "ptx_kernel_call"
struct literal_ptx_kernel_call_t { };
// "public"
struct literal_public_t { };
// "pure"
struct literal_pure_t { };
// "read_lock"
struct literal_read_lock_t { };
// "record"
struct literal_record_t { };
// "return"
struct literal_return_t { };
// "spir_func_call"
struct literal_spir_func_call_t { };
// "spir_kernel_call"
struct literal_spir_kernel_call_t { };
// "sqrt"
struct literal_sqrt_t { };
// "stable"
struct literal_stable_t { };
// "static"
struct literal_static_t { };
// "subs"
struct literal_subs_t { };
// "sups"
struct literal_sups_t { };
// "swift_call"
struct literal_swift_call_t { };
// "this"
struct literal_this_t { };
// "this_func"
struct literal_this_func_t { };
// "this_type"
struct literal_this_type_t { };
// "throw"
struct literal_throw_t { };
// "throwing"
struct literal_throwing_t { };
// "true"
struct literal_true_t { };
// "try"
struct literal_try_t { };
// "type"
struct literal_type_t { };
// "unit"
struct literal_unit_t { };
// "unstable"
struct literal_unstable_t { };
// "until"
struct literal_until_t { };
// "upcasts"
struct literal_upcasts_t { };
// "using"
struct literal_using_t { };
// "volatile"
struct literal_volatile_t { };
// "webkit_js_call"
struct literal_webkit_js_call_t { };
// "while"
struct literal_while_t { };
// "write_lock"
struct literal_write_lock_t { };
// "x86_64_sysv_call"
struct literal_x86_64_sysv_call_t { };
// "x86_64_win64_call"
struct literal_x86_64_win64_call_t { };
// "x86_intr_call"
struct literal_x86_intr_call_t { };
// "x86_std_call"
struct literal_x86_std_call_t { };
// "x86_this_call"
struct literal_x86_this_call_t { };
// "x86_vector_call"
struct literal_x86_vector_call_t { };
// "xor"
struct literal_xor_t { };
// "{"
struct literal_0x7B_t { };
// "{|"
struct literal_0x7B0x7C_t { };
// "|"
struct literal_0x7C_t { };
// "|\'"
struct literal_0x7C0x27_t { };
// "|)"
struct literal_0x7C0x29_t { };
// "|]"
struct literal_0x7C0x5D_t { };
// "|_"
struct literal_0x7C__t { };
// "||"
struct literal_0x7C0x7C_t { };
// "|}"
struct literal_0x7C0x7D_t { };
// "}"
struct literal_0x7D_t { };
// "~"
struct literal_0x7E_t { };
// "~~"
struct literal_0x7E0x7E_t { };
// "¬"
struct literal_0xC20xAC_t { };
// "±"
struct literal_0xC20xB1_t { };
// "×"
struct literal_0xC30x97_t { };
// "÷"
struct literal_0xC30xB7_t { };
// "Δ"
struct literal_0xCE0x94_t { };
// "ᶜ"
struct literal_0xE10xB60x9C_t { };
// "←"
struct literal_0xE20x860x90_t { };
// "↑"
struct literal_0xE20x860x91_t { };
// "→"
struct literal_0xE20x860x92_t { };
// "↓"
struct literal_0xE20x860x93_t { };
// "↔"
struct literal_0xE20x860x94_t { };
// "⇒"
struct literal_0xE20x870x92_t { };
// "⇔"
struct literal_0xE20x870x94_t { };
// "∀"
struct literal_0xE20x880x80_t { };
// "∃"
struct literal_0xE20x880x83_t { };
// "∃!"
struct literal_0xE20x880x830x21_t { };
// "∈"
struct literal_0xE20x880x88_t { };
// "∉"
struct literal_0xE20x880x89_t { };
// "∋"
struct literal_0xE20x880x8B_t { };
// "∌"
struct literal_0xE20x880x8C_t { };
// "∘"
struct literal_0xE20x880x98_t { };
// "√"
struct literal_0xE20x880x9A_t { };
// "∧"
struct literal_0xE20x880xA7_t { };
// "∨"
struct literal_0xE20x880xA8_t { };
// "∩"
struct literal_0xE20x880xA9_t { };
// "∪"
struct literal_0xE20x880xAA_t { };
// "≠"
struct literal_0xE20x890xA0_t { };
// "≤"
struct literal_0xE20x890xA4_t { };
// "≥"
struct literal_0xE20x890xA5_t { };
// "⊂"
struct literal_0xE20x8A0x82_t { };
// "⊃"
struct literal_0xE20x8A0x83_t { };
// "⊆"
struct literal_0xE20x8A0x86_t { };
// "⊇"
struct literal_0xE20x8A0x87_t { };
// "⊕"
struct literal_0xE20x8A0x95_t { };
// "⊖"
struct literal_0xE20x8A0x96_t { };
// "⋅"
struct literal_0xE20x8B0x85_t { };
// "⋮"
struct literal_0xE20x8B0xAE_t { };
// "⌈"
struct literal_0xE20x8C0x88_t { };
// "⌉"
struct literal_0xE20x8C0x89_t { };
// "⌊"
struct literal_0xE20x8C0x8A_t { };
// "⌋"
struct literal_0xE20x8C0x8B_t { };
// "⥆"
struct literal_0xE20xA50x86_t { };

struct ADDITION;
struct ADDITION_ASSIGNMENT;
struct ADD_SUB;
struct ADD_SUB_ASSIGNMENT;
struct ALL;
struct ALLOCATION;
struct AND;
struct AND_ASSIGNMENT;
struct ARGUMENT_PACK;
struct ARRAY;
struct ARRAY_ARGUMENTS;
struct ARRAY_INDEXER;
struct ARRAY_INVOCATION;
struct ASM_EXPRESSION;
struct ASM_FUNCTION;
struct ASM_IDENTIFIER;
struct ASM_OP;
struct ASM_PTR_ARITHMETIC_ATT;
struct ASM_PTR_ARITHMETIC_ATT_REG;
struct ASM_PTR_ARITHMETIC_INTEL;
struct ASM_SCOPE;
struct ASM_STATEMENT;
struct ASSIGNMENT;
struct ASSIGNMENT_NODE;
struct ATTRIBUTE;
struct BIJECTION;
struct BINARY_ARITHMETIC_OP;
struct BINARY_COLLECTION_OP;
struct BINARY_LOGICAL_OP;
struct BINARY_OP;
struct BITWISE_OP;
struct BIT_AND;
struct BIT_AND_ASSIGNMENT;
struct BIT_NOT;
struct BIT_NOT_ASSIGNMENT;
struct BIT_OR;
struct BIT_OR_ASSIGNMENT;
struct BIT_XOR;
struct BIT_XOR_ASSIGNMENT;
struct BLOCK;
struct BOOL;
struct BREAK;
struct CARDINALITY;
struct CAST;
struct CASTS;
struct CEILING;
struct COMMENT;
struct COMPLEMENT;
struct COMPOSITION;
struct COMPOSITION_ASSIGNMENT;
struct COMPOUND;
struct COMPOUND_ASSIGNMENT;
struct CONDITIONAL;
struct CONSTRUCTIVE_OP;
struct CONTINUE;
struct CROSS_PRODUCT;
struct CROSS_PRODUCT_ASSIGNMENT;
struct DATE;
struct DATE_TIME;
struct DATE_YEAR_DAY;
struct DATE_YEAR_MONTH_DAY;
struct DEFINITION;
struct DELTA;
struct DIMENSION;
struct DIMENSIONAL_ANALYSIS_OP;
struct DIMENSIONAL_NUMBER;
struct DIVISION;
struct DIVISION_ASSIGNMENT;
struct DO;
struct DOT_PRODUCT;
struct DOWNCASTS;
struct EMBEDDED_COMMENT;
struct EMBEDDED_COMMENT_INTERIOR;
struct EMBEDDED_NEWLINE_STRING;
struct EMBEDDED_NEWLINE_STRING_INTERIOR;
struct EMBEDDED_STRING;
struct EMBEDDED_STRING_INTERIOR;
struct END_OF_LINE_COMMENT;
struct ENUM;
struct ENUM_ELEMENT;
struct EQUALITY;
struct EQUALITY_NODE;
struct EXACTLY;
struct EXISTS;
struct EXISTS_ONE;
struct EXPONENTIATION;
struct EXPONENTIATION_ASSIGNMENT;
struct EXPRESSION;
struct FACTORIAL;
struct FACTORIAL_ASSIGNMENT;
struct FLOOR;
struct FOR;
struct FOR_COLLECTION;
struct FOR_STEP;
struct FOR_STEP_LIST;
struct FOR_STEP_NODE;
struct FREE;
struct FUNCTION;
struct FUNCTION_MODIFIER_0;
struct FUNCTION_MODIFIER_1;
struct FUNCTION_MODIFIER_2;
struct FUNCTION_MODIFIER_3;
struct FUNCTION_MODIFIER_4;
struct FUNCTION_MODIFIER_ATOMIC;
struct FUNCTION_MODIFIER_CALLING_CONVENTION;
struct FUNCTION_MODIFIER_MODEL;
struct FUNCTION_MODIFIER_PLATFORM;
struct FUNCTION_MODIFIER_STABILITY;
struct FUNCTION_MODIFIER_THROWING;
struct GREATER;
struct GREATER_NODE;
struct HAS;
struct HEX;
struct IC;
struct IDENTIFIER;
struct IDENTIFIER_SPECIFICATION;
struct IF;
struct IFF;
struct IMPLEMENTS;
struct IMPLICATION;
struct IMPLICATION_ASSIGNMENT;
struct IMPLICIT_TYPE_DEREFERENCE;
struct IMPORT;
struct IN;
struct INEQUALITY;
struct INHERITANCE_ITEM_PREFIX;
struct INHERITANCE_LIST;
struct INHERITS;
struct INTEGER_DIVISION;
struct INTEGER_DIVISION_ASSIGNMENT;
struct INTERSECTION;
struct INTERSECTION_ASSIGNMENT;
struct INVOCATION;
struct IS;
struct KLEENE_STAR;
struct LESSER;
struct LESSER_NODE;
struct LIST;
struct LOCK;
struct LOOP;
struct MAGNITUDE;
struct MAP;
struct MAPS_TO;
struct MEMBER_ACCESS;
struct MEMBER_OFFSET;
struct MODULATION;
struct MODULATION_ASSIGNMENT;
struct MULTIPLICATION;
struct MULTIPLICATION_ASSIGNMENT;
struct MULTIPLICATIVE_OP;
struct NAND;
struct NAND_ASSIGNMENT;
struct NATURAL_NUMBER;
struct NEAREST_INTEGER;
struct NEGATION;
struct NEGATION_ASSIGNMENT;
struct NON_FRACTIONAL;
struct NON_NEG_FRACTIONAL;
struct NON_NEG_INTEGER;
struct NON_NEG_NON_FRACTIONAL;
struct NON_NEG_NUMBER;
struct NON_ZERO_DECIMAL_DIGIT;
struct NOR;
struct NOR_ASSIGNMENT;
struct NOT;
struct NOT_ASSIGNMENT;
struct NOT_HAS;
struct NOT_IN;
struct NULL_COALESCE;
struct NULL_COALESCE_ASSIGNMENT;
struct OBJECT;
struct OCTAL;
struct OP_ASSIGNMENT;
struct OR;
struct OR_ASSIGNMENT;
struct PARAMETER;
struct PARAMETER_ANALYTIC;
struct PARAMETER_NATURAL;
struct PARENTHETICAL;
struct PARENTHETICAL_INVOCATION;
struct PAYLOAD;
struct PLATFORM;
struct POST_DEC;
struct POST_INC;
struct PREPEND;
struct PREPEND_ASSIGNMENT;
struct PRE_DEC;
struct PRE_INC;
struct RADICAL;
struct RADICAL_ASSIGNMENT;
struct RANGE;
struct READ_LOCK;
struct RECORD;
struct REGEX;
struct RELATIONAL_COLLECTION_OP;
struct RELATIONAL_OP;
struct RETURN;
struct SET;
struct SET_COMPREHENSION;
struct SHIFTL;
struct SHIFTL_ASSIGNMENT;
struct SHIFTR;
struct SHIFTR_ASSIGNMENT;
struct SLICE;
struct STANDARD_ARGUMENTS;
struct STATEMENT;
struct STATEMENT_SCOPE;
struct SUBSET;
struct SUBSET_NODE;
struct SUBTRACTION;
struct SUBTRACTION_ASSIGNMENT;
struct SUPERSET;
struct SUPERSET_NODE;
struct SWIZZLE;
struct SYMMETRIC_DIFFERENCE;
struct SYMMETRIC_DIFFERENCE_ASSIGNMENT;
struct THIS;
struct THIS_FUNC;
struct THIS_TYPE;
struct THROW;
struct TIME;
struct TRY;
struct TUPLE;
struct TYPE;
struct TYPE_CONSTRAINT;
struct TYPE_CONSTRAINT_DECLARATION;
struct TYPE_CONSTRAINT_ELEMENT;
struct TYPE_CONSTRAINT_SPECIFICATION;
struct TYPE_DEREFERENCE;
struct TYPE_INVOCATION;
struct TYPE_SCOPE;
struct TYPE_SCOPE_ASSIGNMENT;
struct TYPE_SCOPE_ASSIGNMENT_NODE;
struct TYPE_SCOPE_TYPE_CONSTRAINT;
struct TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION;
struct TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT;
struct TYPE_STATEMENT;
struct UNARY_ARITHMETIC_OP;
struct UNARY_LOGICAL_OP;
struct UNARY_OP;
struct UNION;
struct UNION_ASSIGNMENT;
struct UNIT_DIVISION;
struct UNIT_EXPONENTIATION;
struct UNIT_MULTIPLICATION;
struct UPCASTS;
struct USING;
struct VECTOR_NORM;
struct VISIBILITY_MODIFIER;
struct VOLATILE_IMPLICIT_TYPE_DEREFERENCE;
struct VOLATILE_TYPE_DEREFERENCE;
struct WHOLE_NUMBER;
struct WRITE_LOCK;
struct WS;
struct XML_DOC_STRING;
struct XML_DOC_STRING_INTERIOR;
struct XOR;
struct XOR_ASSIGNMENT;

struct ADDITION {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x2B_t> dont_care2;
	
	std::vector<val<IC>> field_3;
	
	val<EXPRESSION> field_4;
	


	explicit ADDITION
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x2B_t> const & dont_care2, std::vector<val<IC>> const & field_3, val<EXPRESSION> const & field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4) {}

	ADDITION(ADDITION const & other) = default;
	static ADDITION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct ADDITION_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0x2B0x3C0x2D_t>,
		parlex::detail::document::text<literal_0x2B0xE20x860x90_t>,
		parlex::detail::document::text<literal_0xE20xA50x86_t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit ADDITION_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0x2B0x3C0x2D_t>,
	parlex::detail::document::text<literal_0x2B0xE20x860x90_t>,
	parlex::detail::document::text<literal_0xE20xA50x86_t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	ADDITION_ASSIGNMENT(ADDITION_ASSIGNMENT const & other) = default;
	static ADDITION_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct ADD_SUB {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xC20xB1_t>,
		parlex::detail::document::text<literal_0x2B0x2D_t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit ADD_SUB
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0xC20xB1_t>,
	parlex::detail::document::text<literal_0x2B0x2D_t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	ADD_SUB(ADD_SUB const & other) = default;
	static ADD_SUB build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct ADD_SUB_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xC20xB1_t>,
		parlex::detail::document::text<literal_0x2B0x2D_t>
	> field_3;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_4;
	
	std::vector<val<IC>> field_5;
	
	val<EXPRESSION> field_6;
	


	explicit ADD_SUB_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0xC20xB1_t>,
	parlex::detail::document::text<literal_0x2B0x2D_t>
> const & field_3, std::variant<
	parlex::detail::document::text<literal_0x3C0x2D_t>,
	parlex::detail::document::text<literal_0xE20x860x90_t>
> const & field_4, std::vector<val<IC>> const & field_5, val<EXPRESSION> const & field_6)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5), field_6(field_6) {}

	ADD_SUB_ASSIGNMENT(ADD_SUB_ASSIGNMENT const & other) = default;
	static ADD_SUB_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct ALL {
	int32_t document_position, consumed_character_count;

	std::variant<
		parlex::detail::document::text<literal_0xE20x880x80_t>,
		parlex::detail::document::text<literal_all_t>
	> field_1;
	
	std::vector<val<IC>> field_2;
	
	val<EXPRESSION> field_3;
	


	explicit ALL
		(int32_t documentPosition, int32_t consumedCharacterCount, std::variant<
	parlex::detail::document::text<literal_0xE20x880x80_t>,
	parlex::detail::document::text<literal_all_t>
> const & field_1, std::vector<val<IC>> const & field_2, val<EXPRESSION> const & field_3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3) {}

	ALL(ALL const & other) = default;
	static ALL build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct ALLOCATION {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_alloc_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<PARENTHETICAL_INVOCATION> field_2;
	


	explicit ALLOCATION
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_alloc_t> const & dont_care0, std::vector<val<IC>> const & field_1, val<PARENTHETICAL_INVOCATION> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), field_2(field_2) {}

	ALLOCATION(ALLOCATION const & other) = default;
	static ALLOCATION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct AND {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xE20x880xA7_t>,
		parlex::detail::document::text<literal_and_t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit AND
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0xE20x880xA7_t>,
	parlex::detail::document::text<literal_and_t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	AND(AND const & other) = default;
	static AND build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct AND_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xE20x880xA7_t>,
		parlex::detail::document::text<literal_and_t>
	> field_3;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_4;
	
	std::vector<val<IC>> field_5;
	
	val<EXPRESSION> field_6;
	


	explicit AND_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0xE20x880xA7_t>,
	parlex::detail::document::text<literal_and_t>
> const & field_3, std::variant<
	parlex::detail::document::text<literal_0x3C0x2D_t>,
	parlex::detail::document::text<literal_0xE20x860x90_t>
> const & field_4, std::vector<val<IC>> const & field_5, val<EXPRESSION> const & field_6)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5), field_6(field_6) {}

	AND_ASSIGNMENT(AND_ASSIGNMENT const & other) = default;
	static AND_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct ARGUMENT_PACK {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> expression;
	
	std::vector<val<IC>> field_1;
	
	parlex::detail::document::text<literal_0x2E0x2E0x2E_t> dont_care2;
	


	explicit ARGUMENT_PACK
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & expression, std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_0x2E0x2E0x2E_t> const & dont_care2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), expression(expression), field_1(field_1), dont_care2(dont_care2) {}

	ARGUMENT_PACK(ARGUMENT_PACK const & other) = default;
	static ARGUMENT_PACK build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct ARRAY {
	int32_t document_position, consumed_character_count;

	struct field_2_t {
		struct field_1_t {
			std::vector<val<IC>> field_1;
			
			parlex::detail::document::text<literal_0x2C_t> dont_care1;
			
			std::vector<val<IC>> field_2;
			
			val<EXPRESSION> expression;
			
		
		
			explicit field_1_t
				(std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_0x2C_t> const & dont_care1, std::vector<val<IC>> const & field_2, val<EXPRESSION> const & expression)
				: field_1(field_1), dont_care1(dont_care1), field_2(field_2), expression(expression) {}
		
			field_1_t(field_1_t const & other) = default;
			static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		val<EXPRESSION> expression;
		
		std::vector<field_1_t> field_1;
		
		std::vector<val<IC>> field_2;
		
	
	
		explicit field_2_t
			(val<EXPRESSION> const & expression, std::vector<field_1_t> const & field_1, std::vector<val<IC>> const & field_2)
			: expression(expression), field_1(field_1), field_2(field_2) {}
	
		field_2_t(field_2_t const & other) = default;
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_0x5B_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	std::optional<field_2_t> field_2;
	
	parlex::detail::document::text<literal_0x5D_t> dont_care3;
	


	explicit ARRAY
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x5B_t> const & dont_care0, std::vector<val<IC>> const & field_1, std::optional<field_2_t> const & field_2, parlex::detail::document::text<literal_0x5D_t> const & dont_care3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), field_2(field_2), dont_care3(dont_care3) {}

	ARRAY(ARRAY const & other) = default;
	static ARRAY build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct ARRAY_ARGUMENTS {
	int32_t document_position, consumed_character_count;

	struct tail_t {
		struct field_1_t {
			std::vector<val<IC>> ic;
			
			val<ARRAY_INDEXER> array_indexer;
			
		
		
			explicit field_1_t
				(std::vector<val<IC>> const & ic, val<ARRAY_INDEXER> const & array_indexer)
				: ic(ic), array_indexer(array_indexer) {}
		
			field_1_t(field_1_t const & other) = default;
			static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		std::vector<val<IC>> ic;
		
		parlex::detail::document::text<literal_0x2C_t> comma;
		
		std::optional<field_1_t> field_1;
		
	
	
		explicit tail_t
			(std::vector<val<IC>> const & ic, parlex::detail::document::text<literal_0x2C_t> const & comma, std::optional<field_1_t> const & field_1)
			: ic(ic), comma(comma), field_1(field_1) {}
	
		tail_t(tail_t const & other) = default;
		static tail_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::optional<val<ARRAY_INDEXER>> head;
	
	std::vector<tail_t> tail;
	


	explicit ARRAY_ARGUMENTS
		(int32_t documentPosition, int32_t consumedCharacterCount, std::optional<val<ARRAY_INDEXER>> const & head, std::vector<tail_t> const & tail)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), head(head), tail(tail) {}

	ARRAY_ARGUMENTS(ARRAY_ARGUMENTS const & other) = default;
	static ARRAY_ARGUMENTS build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


typedef std::variant<
	val<EXPRESSION>,
	val<ARGUMENT_PACK>,
	val<SLICE>
> ARRAY_INDEXER_base;

struct ARRAY_INDEXER: ARRAY_INDEXER_base {
	static ARRAY_INDEXER build(parlex::detail::ast_node const & n);
	explicit ARRAY_INDEXER(ARRAY_INDEXER_base const & value) : ARRAY_INDEXER_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
struct ARRAY_INVOCATION {
	int32_t document_position, consumed_character_count;

	struct arguments_t {
		val<ARRAY_ARGUMENTS> array_arguments;
		
		std::vector<val<IC>> ic;
		
	
	
		explicit arguments_t
			(val<ARRAY_ARGUMENTS> const & array_arguments, std::vector<val<IC>> const & ic)
			: array_arguments(array_arguments), ic(ic) {}
	
		arguments_t(arguments_t const & other) = default;
		static arguments_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_0x5B_t> dont_care0;
	
	std::vector<val<IC>> ic;
	
	std::optional<arguments_t> arguments;
	
	parlex::detail::document::text<literal_0x5D_t> dont_care3;
	


	explicit ARRAY_INVOCATION
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x5B_t> const & dont_care0, std::vector<val<IC>> const & ic, std::optional<arguments_t> const & arguments, parlex::detail::document::text<literal_0x5D_t> const & dont_care3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), ic(ic), arguments(arguments), dont_care3(dont_care3) {}

	ARRAY_INVOCATION(ARRAY_INVOCATION const & other) = default;
	static ARRAY_INVOCATION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


typedef std::variant<
	val<ASM_IDENTIFIER>,
	val<ASM_PTR_ARITHMETIC_ATT>,
	val<ASM_PTR_ARITHMETIC_INTEL>,
	val<NON_FRACTIONAL>
> ASM_EXPRESSION_base;

struct ASM_EXPRESSION: ASM_EXPRESSION_base {
	static ASM_EXPRESSION build(parlex::detail::ast_node const & n);
	explicit ASM_EXPRESSION(ASM_EXPRESSION_base const & value) : ASM_EXPRESSION_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
struct ASM_FUNCTION {
	int32_t document_position, consumed_character_count;

	struct field_1_t {
		struct field_2_t {
			struct field_1_t {
				std::vector<val<IC>> field_1;
				
				parlex::detail::document::text<literal_0x2C_t> dont_care1;
				
				std::vector<val<IC>> field_2;
				
				val<PARAMETER> parameter;
				
			
			
				explicit field_1_t
					(std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_0x2C_t> const & dont_care1, std::vector<val<IC>> const & field_2, val<PARAMETER> const & parameter)
					: field_1(field_1), dont_care1(dont_care1), field_2(field_2), parameter(parameter) {}
			
				field_1_t(field_1_t const & other) = default;
				static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
			};
		
			val<PARAMETER> parameter;
			
			std::vector<field_1_t> field_1;
			
			std::vector<val<IC>> field_2;
			
		
		
			explicit field_2_t
				(val<PARAMETER> const & parameter, std::vector<field_1_t> const & field_1, std::vector<val<IC>> const & field_2)
				: parameter(parameter), field_1(field_1), field_2(field_2) {}
		
			field_2_t(field_2_t const & other) = default;
			static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		parlex::detail::document::text<literal_0x28_t> dont_care0;
		
		std::vector<val<IC>> field_1;
		
		std::optional<field_2_t> field_2;
		
		parlex::detail::document::text<literal_0x29_t> dont_care3;
		
		std::vector<val<IC>> field_3;
		
	
	
		explicit field_1_t
			(parlex::detail::document::text<literal_0x28_t> const & dont_care0, std::vector<val<IC>> const & field_1, std::optional<field_2_t> const & field_2, parlex::detail::document::text<literal_0x29_t> const & dont_care3, std::vector<val<IC>> const & field_3)
			: dont_care0(dont_care0), field_1(field_1), field_2(field_2), dont_care3(dont_care3), field_3(field_3) {}
	
		field_1_t(field_1_t const & other) = default;
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::optional<field_1_t> field_1;
	
	std::optional<val<FUNCTION_MODIFIER_0>> field_2;
	
	parlex::detail::document::text<literal_asm_t> dont_care2;
	
	std::vector<val<IC>> field_3;
	
	parlex::detail::document::text<literal_0x7B_t> dont_care4;
	
	val<ASM_SCOPE> field_4;
	
	parlex::detail::document::text<literal_0x7D_t> dont_care6;
	


	explicit ASM_FUNCTION
		(int32_t documentPosition, int32_t consumedCharacterCount, std::optional<field_1_t> const & field_1, std::optional<val<FUNCTION_MODIFIER_0>> const & field_2, parlex::detail::document::text<literal_asm_t> const & dont_care2, std::vector<val<IC>> const & field_3, parlex::detail::document::text<literal_0x7B_t> const & dont_care4, val<ASM_SCOPE> const & field_4, parlex::detail::document::text<literal_0x7D_t> const & dont_care6)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), dont_care4(dont_care4), field_4(field_4), dont_care6(dont_care6) {}

	ASM_FUNCTION(ASM_FUNCTION const & other) = default;
	static ASM_FUNCTION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct ASM_IDENTIFIER {
	int32_t document_position, consumed_character_count;

	std::optional<parlex::detail::document::text<literal_0x25_t>> field_1;
	
	val<IDENTIFIER> field_2;
	


	explicit ASM_IDENTIFIER
		(int32_t documentPosition, int32_t consumedCharacterCount, std::optional<parlex::detail::document::text<literal_0x25_t>> const & field_1, val<IDENTIFIER> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2) {}

	ASM_IDENTIFIER(ASM_IDENTIFIER const & other) = default;
	static ASM_IDENTIFIER build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct ASM_OP {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<parlex::detail::lowercase_letter_t> field_1;
	
	std::vector<parlex::detail::document::text<parlex::detail::lowercase_letter_t>> field_2;
	


	explicit ASM_OP
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<parlex::detail::lowercase_letter_t> const & field_1, std::vector<parlex::detail::document::text<parlex::detail::lowercase_letter_t>> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2) {}

	ASM_OP(ASM_OP const & other) = default;
	static ASM_OP build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct ASM_PTR_ARITHMETIC_ATT1_t {
	val<ASM_IDENTIFIER> field_1;
	
	parlex::detail::document::text<literal_0x3A_t> dont_care1;
	
	val<NON_FRACTIONAL> field_2;
	


	explicit ASM_PTR_ARITHMETIC_ATT1_t
		(val<ASM_IDENTIFIER> const & field_1, parlex::detail::document::text<literal_0x3A_t> const & dont_care1, val<NON_FRACTIONAL> const & field_2)
		: field_1(field_1), dont_care1(dont_care1), field_2(field_2) {}

	ASM_PTR_ARITHMETIC_ATT1_t(ASM_PTR_ARITHMETIC_ATT1_t const & other) = default;
	static ASM_PTR_ARITHMETIC_ATT1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

struct ASM_PTR_ARITHMETIC_ATT2_t {
	val<ASM_IDENTIFIER> field_1;
	
	parlex::detail::document::text<literal_0x3A_t> dont_care1;
	
	val<NON_FRACTIONAL> field_2;
	
	val<ASM_PTR_ARITHMETIC_ATT_REG> field_3;
	


	explicit ASM_PTR_ARITHMETIC_ATT2_t
		(val<ASM_IDENTIFIER> const & field_1, parlex::detail::document::text<literal_0x3A_t> const & dont_care1, val<NON_FRACTIONAL> const & field_2, val<ASM_PTR_ARITHMETIC_ATT_REG> const & field_3)
		: field_1(field_1), dont_care1(dont_care1), field_2(field_2), field_3(field_3) {}

	ASM_PTR_ARITHMETIC_ATT2_t(ASM_PTR_ARITHMETIC_ATT2_t const & other) = default;
	static ASM_PTR_ARITHMETIC_ATT2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

struct ASM_PTR_ARITHMETIC_ATT3_t {
	val<NON_FRACTIONAL> field_1;
	
	val<ASM_PTR_ARITHMETIC_ATT_REG> field_2;
	


	explicit ASM_PTR_ARITHMETIC_ATT3_t
		(val<NON_FRACTIONAL> const & field_1, val<ASM_PTR_ARITHMETIC_ATT_REG> const & field_2)
		: field_1(field_1), field_2(field_2) {}

	ASM_PTR_ARITHMETIC_ATT3_t(ASM_PTR_ARITHMETIC_ATT3_t const & other) = default;
	static ASM_PTR_ARITHMETIC_ATT3_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

typedef std::variant<
	ASM_PTR_ARITHMETIC_ATT1_t,
	ASM_PTR_ARITHMETIC_ATT2_t,
	ASM_PTR_ARITHMETIC_ATT3_t
> ASM_PTR_ARITHMETIC_ATT_base;

struct ASM_PTR_ARITHMETIC_ATT: ASM_PTR_ARITHMETIC_ATT_base {
	static ASM_PTR_ARITHMETIC_ATT build(parlex::detail::ast_node const & n);
	explicit ASM_PTR_ARITHMETIC_ATT(ASM_PTR_ARITHMETIC_ATT_base const & value) : ASM_PTR_ARITHMETIC_ATT_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
struct ASM_PTR_ARITHMETIC_ATT_REG {
	int32_t document_position, consumed_character_count;

	struct field_2_t {
		struct field_1_t {
			parlex::detail::document::text<literal_0x2C_t> dont_care0;
			
			val<NON_NEG_NON_FRACTIONAL> field_1;
			
		
		
			explicit field_1_t
				(parlex::detail::document::text<literal_0x2C_t> const & dont_care0, val<NON_NEG_NON_FRACTIONAL> const & field_1)
				: dont_care0(dont_care0), field_1(field_1) {}
		
			field_1_t(field_1_t const & other) = default;
			static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		parlex::detail::document::text<literal_0x2C_t> dont_care0;
		
		val<ASM_IDENTIFIER> asm_identifier;
		
		std::optional<field_1_t> field_1;
		
	
	
		explicit field_2_t
			(parlex::detail::document::text<literal_0x2C_t> const & dont_care0, val<ASM_IDENTIFIER> const & asm_identifier, std::optional<field_1_t> const & field_1)
			: dont_care0(dont_care0), asm_identifier(asm_identifier), field_1(field_1) {}
	
		field_2_t(field_2_t const & other) = default;
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_0x28_t> dont_care0;
	
	std::optional<val<ASM_IDENTIFIER>> field_1;
	
	std::optional<field_2_t> field_2;
	
	parlex::detail::document::text<literal_0x29_t> dont_care3;
	


	explicit ASM_PTR_ARITHMETIC_ATT_REG
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x28_t> const & dont_care0, std::optional<val<ASM_IDENTIFIER>> const & field_1, std::optional<field_2_t> const & field_2, parlex::detail::document::text<literal_0x29_t> const & dont_care3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), field_2(field_2), dont_care3(dont_care3) {}

	ASM_PTR_ARITHMETIC_ATT_REG(ASM_PTR_ARITHMETIC_ATT_REG const & other) = default;
	static ASM_PTR_ARITHMETIC_ATT_REG build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


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


typedef std::vector<std::variant<
	val<IC>,
	val<ASM_STATEMENT>
>> ASM_SCOPE_base;

struct ASM_SCOPE: ASM_SCOPE_base {
	static ASM_SCOPE build(parlex::detail::ast_node const & n);
	explicit ASM_SCOPE(ASM_SCOPE_base const & value) : ASM_SCOPE_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
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


struct ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<IDENTIFIER_SPECIFICATION> identifier_specification;
	
	std::vector<val<IC>> ic;
	
	val<ASSIGNMENT_NODE> assignment_node;
	


	explicit ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<IDENTIFIER_SPECIFICATION> const & identifier_specification, std::vector<val<IC>> const & ic, val<ASSIGNMENT_NODE> const & assignment_node)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), identifier_specification(identifier_specification), ic(ic), assignment_node(assignment_node) {}

	ASSIGNMENT(ASSIGNMENT const & other) = default;
	static ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct ASSIGNMENT_NODE {
	int32_t document_position, consumed_character_count;

	struct value_t {
		val<IDENTIFIER_SPECIFICATION> identifier_specification;
		
		std::vector<val<IC>> ic;
		
		val<ASSIGNMENT_NODE> next;
		
	
	
		explicit value_t
			(val<IDENTIFIER_SPECIFICATION> const & identifier_specification, std::vector<val<IC>> const & ic, val<ASSIGNMENT_NODE> const & next)
			: identifier_specification(identifier_specification), ic(ic), next(next) {}
	
		value_t(value_t const & other) = default;
		static value_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::variant<
		parlex::detail::document::text<literal_0xE20x860x90_t>,
		parlex::detail::document::text<literal_0x3C0x2D_t>
	> field_1;
	
	std::vector<val<IC>> ic;
	
	std::variant<
		val<EXPRESSION>,
		value_t
	> value;
	


	explicit ASSIGNMENT_NODE
		(int32_t documentPosition, int32_t consumedCharacterCount, std::variant<
	parlex::detail::document::text<literal_0xE20x860x90_t>,
	parlex::detail::document::text<literal_0x3C0x2D_t>
> const & field_1, std::vector<val<IC>> const & ic, std::variant<
	val<EXPRESSION>,
	value_t
> const & value)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), ic(ic), value(value) {}

	ASSIGNMENT_NODE(ASSIGNMENT_NODE const & other) = default;
	static ASSIGNMENT_NODE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct ATTRIBUTE {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0x40_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<EXPRESSION> expression;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x40_t> dont_care4;
	


	explicit ATTRIBUTE
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x40_t> const & dont_care0, std::vector<val<IC>> const & field_1, val<EXPRESSION> const & expression, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x40_t> const & dont_care4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), expression(expression), field_2(field_2), dont_care4(dont_care4) {}

	ATTRIBUTE(ATTRIBUTE const & other) = default;
	static ATTRIBUTE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct BIJECTION {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xE20x860x94_t>,
		parlex::detail::document::text<literal_0x3C0x2D0x3E_t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit BIJECTION
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0xE20x860x94_t>,
	parlex::detail::document::text<literal_0x3C0x2D0x3E_t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	BIJECTION(BIJECTION const & other) = default;
	static BIJECTION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


typedef std::variant<
	val<ADD_SUB>,
	val<ADDITION>,
	val<DIVISION>,
	val<EXPONENTIATION>,
	val<INTEGER_DIVISION>,
	val<MODULATION>,
	val<MULTIPLICATIVE_OP>,
	val<SHIFTL>,
	val<SHIFTR>,
	val<SUBTRACTION>
> BINARY_ARITHMETIC_OP_base;

struct BINARY_ARITHMETIC_OP: BINARY_ARITHMETIC_OP_base {
	static BINARY_ARITHMETIC_OP build(parlex::detail::ast_node const & n);
	explicit BINARY_ARITHMETIC_OP(BINARY_ARITHMETIC_OP_base const & value) : BINARY_ARITHMETIC_OP_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
typedef std::variant<
	val<BIJECTION>,
	val<INTERSECTION>,
	val<SYMMETRIC_DIFFERENCE>,
	val<UNION>
> BINARY_COLLECTION_OP_base;

struct BINARY_COLLECTION_OP: BINARY_COLLECTION_OP_base {
	static BINARY_COLLECTION_OP build(parlex::detail::ast_node const & n);
	explicit BINARY_COLLECTION_OP(BINARY_COLLECTION_OP_base const & value) : BINARY_COLLECTION_OP_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
typedef std::variant<
	val<AND>,
	val<IFF>,
	val<IMPLICATION>,
	val<MAPS_TO>,
	val<NAND>,
	val<NOR>,
	val<OR>,
	val<XOR>
> BINARY_LOGICAL_OP_base;

struct BINARY_LOGICAL_OP: BINARY_LOGICAL_OP_base {
	static BINARY_LOGICAL_OP build(parlex::detail::ast_node const & n);
	explicit BINARY_LOGICAL_OP(BINARY_LOGICAL_OP_base const & value) : BINARY_LOGICAL_OP_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
typedef std::variant<
	val<BINARY_ARITHMETIC_OP>,
	val<BINARY_COLLECTION_OP>,
	val<BINARY_LOGICAL_OP>,
	val<BITWISE_OP>,
	val<CONSTRUCTIVE_OP>,
	val<RELATIONAL_OP>
> BINARY_OP_base;

struct BINARY_OP: BINARY_OP_base {
	static BINARY_OP build(parlex::detail::ast_node const & n);
	explicit BINARY_OP(BINARY_OP_base const & value) : BINARY_OP_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
typedef std::variant<
	val<BIT_AND>,
	val<BIT_OR>,
	val<BIT_XOR>
> BITWISE_OP_base;

struct BITWISE_OP: BITWISE_OP_base {
	static BITWISE_OP build(parlex::detail::ast_node const & n);
	explicit BITWISE_OP(BITWISE_OP_base const & value) : BITWISE_OP_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
struct BIT_AND {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x260x26_t> dont_care2;
	
	std::vector<val<IC>> field_3;
	
	val<EXPRESSION> field_4;
	


	explicit BIT_AND
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x260x26_t> const & dont_care2, std::vector<val<IC>> const & field_3, val<EXPRESSION> const & field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4) {}

	BIT_AND(BIT_AND const & other) = default;
	static BIT_AND build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct BIT_AND_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x260x26_t> dont_care2;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit BIT_AND_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x260x26_t> const & dont_care2, std::variant<
	parlex::detail::document::text<literal_0x3C0x2D_t>,
	parlex::detail::document::text<literal_0xE20x860x90_t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	BIT_AND_ASSIGNMENT(BIT_AND_ASSIGNMENT const & other) = default;
	static BIT_AND_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct BIT_NOT {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0x7E0x7E_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<EXPRESSION> field_2;
	


	explicit BIT_NOT
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x7E0x7E_t> const & dont_care0, std::vector<val<IC>> const & field_1, val<EXPRESSION> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), field_2(field_2) {}

	BIT_NOT(BIT_NOT const & other) = default;
	static BIT_NOT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct BIT_NOT_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x7E0x7E_t> dont_care2;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_3;
	


	explicit BIT_NOT_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x7E0x7E_t> const & dont_care2, std::variant<
	parlex::detail::document::text<literal_0x3C0x2D_t>,
	parlex::detail::document::text<literal_0xE20x860x90_t>
> const & field_3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3) {}

	BIT_NOT_ASSIGNMENT(BIT_NOT_ASSIGNMENT const & other) = default;
	static BIT_NOT_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct BIT_OR {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x7C0x7C_t> dont_care2;
	
	std::vector<val<IC>> field_3;
	
	val<EXPRESSION> field_4;
	


	explicit BIT_OR
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x7C0x7C_t> const & dont_care2, std::vector<val<IC>> const & field_3, val<EXPRESSION> const & field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4) {}

	BIT_OR(BIT_OR const & other) = default;
	static BIT_OR build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct BIT_OR_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x7C0x7C_t> dont_care2;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit BIT_OR_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x7C0x7C_t> const & dont_care2, std::variant<
	parlex::detail::document::text<literal_0x3C0x2D_t>,
	parlex::detail::document::text<literal_0xE20x860x90_t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	BIT_OR_ASSIGNMENT(BIT_OR_ASSIGNMENT const & other) = default;
	static BIT_OR_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct BIT_XOR {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x5E0x5E_t> dont_care2;
	
	std::vector<val<IC>> field_3;
	
	val<EXPRESSION> field_4;
	


	explicit BIT_XOR
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x5E0x5E_t> const & dont_care2, std::vector<val<IC>> const & field_3, val<EXPRESSION> const & field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4) {}

	BIT_XOR(BIT_XOR const & other) = default;
	static BIT_XOR build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct BIT_XOR_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x5E0x5E_t> dont_care2;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit BIT_XOR_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x5E0x5E_t> const & dont_care2, std::variant<
	parlex::detail::document::text<literal_0x3C0x2D_t>,
	parlex::detail::document::text<literal_0xE20x860x90_t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	BIT_XOR_ASSIGNMENT(BIT_XOR_ASSIGNMENT const & other) = default;
	static BIT_XOR_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct BLOCK {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0x7B_t> dont_care0;
	
	val<STATEMENT_SCOPE> field_1;
	
	parlex::detail::document::text<literal_0x7D_t> dont_care2;
	


	explicit BLOCK
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x7B_t> const & dont_care0, val<STATEMENT_SCOPE> const & field_1, parlex::detail::document::text<literal_0x7D_t> const & dont_care2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), dont_care2(dont_care2) {}

	BLOCK(BLOCK const & other) = default;
	static BLOCK build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


typedef std::variant<
	parlex::detail::document::text<literal_true_t>,
	parlex::detail::document::text<literal_false_t>
> BOOL_base;

struct BOOL: BOOL_base {
	static BOOL build(parlex::detail::ast_node const & n);
	explicit BOOL(BOOL_base const & value) : BOOL_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
struct BREAK {
	int32_t document_position, consumed_character_count;

	struct field_1_t1 {
		std::vector<val<IC>> field_1;
		
		parlex::detail::document::text<literal_0x5B_t> dont_care1;
		
		std::vector<val<IC>> field_2;
		
		val<EXPRESSION> expression;
		
		std::vector<val<IC>> field_3;
		
		parlex::detail::document::text<literal_0x5D_t> dont_care5;
		
	
	
		explicit field_1_t1
			(std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_0x5B_t> const & dont_care1, std::vector<val<IC>> const & field_2, val<EXPRESSION> const & expression, std::vector<val<IC>> const & field_3, parlex::detail::document::text<literal_0x5D_t> const & dont_care5)
			: field_1(field_1), dont_care1(dont_care1), field_2(field_2), expression(expression), field_3(field_3), dont_care5(dont_care5) {}
	
		field_1_t1(field_1_t1 const & other) = default;
		static field_1_t1 build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_1_t2 {
		val<IC> field_1;
		
		std::vector<val<IC>> field_2;
		
		val<IDENTIFIER> identifier;
		
	
	
		explicit field_1_t2
			(val<IC> const & field_1, std::vector<val<IC>> const & field_2, val<IDENTIFIER> const & identifier)
			: field_1(field_1), field_2(field_2), identifier(identifier) {}
	
		field_1_t2(field_1_t2 const & other) = default;
		static field_1_t2 build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_break_t> dont_care0;
	
	std::optional<std::variant<
		field_1_t1,
		field_1_t2
	>> field_1;
	


	explicit BREAK
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_break_t> const & dont_care0, std::optional<std::variant<
	field_1_t1,
	field_1_t2
>> const & field_1)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1) {}

	BREAK(BREAK const & other) = default;
	static BREAK build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct CARDINALITY {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0x23_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<EXPRESSION> field_2;
	


	explicit CARDINALITY
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x23_t> const & dont_care0, std::vector<val<IC>> const & field_1, val<EXPRESSION> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), field_2(field_2) {}

	CARDINALITY(CARDINALITY const & other) = default;
	static CARDINALITY build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct CAST {
	int32_t document_position, consumed_character_count;

	val<PARENTHETICAL> field_1;
	
	std::vector<val<IC>> field_2;
	
	val<EXPRESSION> field_3;
	


	explicit CAST
		(int32_t documentPosition, int32_t consumedCharacterCount, val<PARENTHETICAL> const & field_1, std::vector<val<IC>> const & field_2, val<EXPRESSION> const & field_3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3) {}

	CAST(CAST const & other) = default;
	static CAST build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct CASTS {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_casts_t> dont_care2;
	
	std::vector<val<IC>> field_3;
	
	val<EXPRESSION> field_4;
	


	explicit CASTS
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_casts_t> const & dont_care2, std::vector<val<IC>> const & field_3, val<EXPRESSION> const & field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4) {}

	CASTS(CASTS const & other) = default;
	static CASTS build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct CEILING1_t {
	parlex::detail::document::text<literal_0xE20x8C0x88_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<EXPRESSION> field_2;
	
	std::vector<val<IC>> field_3;
	
	parlex::detail::document::text<literal_0xE20x8C0x89_t> dont_care4;
	


	explicit CEILING1_t
		(parlex::detail::document::text<literal_0xE20x8C0x88_t> const & dont_care0, std::vector<val<IC>> const & field_1, val<EXPRESSION> const & field_2, std::vector<val<IC>> const & field_3, parlex::detail::document::text<literal_0xE20x8C0x89_t> const & dont_care4)
		: dont_care0(dont_care0), field_1(field_1), field_2(field_2), field_3(field_3), dont_care4(dont_care4) {}

	CEILING1_t(CEILING1_t const & other) = default;
	static CEILING1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

struct CEILING2_t {
	parlex::detail::document::text<literal_0x7C0x27_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<EXPRESSION> field_2;
	
	std::vector<val<IC>> field_3;
	
	parlex::detail::document::text<literal_0x270x7C_t> dont_care4;
	


	explicit CEILING2_t
		(parlex::detail::document::text<literal_0x7C0x27_t> const & dont_care0, std::vector<val<IC>> const & field_1, val<EXPRESSION> const & field_2, std::vector<val<IC>> const & field_3, parlex::detail::document::text<literal_0x270x7C_t> const & dont_care4)
		: dont_care0(dont_care0), field_1(field_1), field_2(field_2), field_3(field_3), dont_care4(dont_care4) {}

	CEILING2_t(CEILING2_t const & other) = default;
	static CEILING2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

typedef std::variant<
	CEILING1_t,
	CEILING2_t
> CEILING_base;

struct CEILING: CEILING_base {
	static CEILING build(parlex::detail::ast_node const & n);
	explicit CEILING(CEILING_base const & value) : CEILING_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
struct COMMENT {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0x2F0x2A_t> dont_care0;
	
	std::vector<parlex::detail::document::text<parlex::detail::all_t>> field_1;
	
	parlex::detail::document::text<literal_0x2A0x2F_t> dont_care2;
	


	explicit COMMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x2F0x2A_t> const & dont_care0, std::vector<parlex::detail::document::text<parlex::detail::all_t>> const & field_1, parlex::detail::document::text<literal_0x2A0x2F_t> const & dont_care2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), dont_care2(dont_care2) {}

	COMMENT(COMMENT const & other) = default;
	static COMMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct COMPLEMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0xE10xB60x9C_t> dont_care2;
	


	explicit COMPLEMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0xE10xB60x9C_t> const & dont_care2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2) {}

	COMPLEMENT(COMPLEMENT const & other) = default;
	static COMPLEMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct COMPOSITION {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xE20x880x98_t>,
		parlex::detail::document::text<literal__o__t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit COMPOSITION
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0xE20x880x98_t>,
	parlex::detail::document::text<literal__o__t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	COMPOSITION(COMPOSITION const & other) = default;
	static COMPOSITION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct COMPOSITION_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xE20x880x98_t>,
		parlex::detail::document::text<literal__o__t>
	> field_3;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_4;
	
	std::vector<val<IC>> field_5;
	
	val<EXPRESSION> field_6;
	


	explicit COMPOSITION_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0xE20x880x98_t>,
	parlex::detail::document::text<literal__o__t>
> const & field_3, std::variant<
	parlex::detail::document::text<literal_0x3C0x2D_t>,
	parlex::detail::document::text<literal_0xE20x860x90_t>
> const & field_4, std::vector<val<IC>> const & field_5, val<EXPRESSION> const & field_6)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5), field_6(field_6) {}

	COMPOSITION_ASSIGNMENT(COMPOSITION_ASSIGNMENT const & other) = default;
	static COMPOSITION_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct COMPOUND {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x7C_t> dont_care2;
	
	std::vector<val<IC>> field_3;
	
	val<EXPRESSION> field_4;
	


	explicit COMPOUND
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x7C_t> const & dont_care2, std::vector<val<IC>> const & field_3, val<EXPRESSION> const & field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4) {}

	COMPOUND(COMPOUND const & other) = default;
	static COMPOUND build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct COMPOUND_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x7C_t> dont_care2;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit COMPOUND_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x7C_t> const & dont_care2, std::variant<
	parlex::detail::document::text<literal_0x3C0x2D_t>,
	parlex::detail::document::text<literal_0xE20x860x90_t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	COMPOUND_ASSIGNMENT(COMPOUND_ASSIGNMENT const & other) = default;
	static COMPOUND_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct CONDITIONAL {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> condition;
	
	std::vector<val<IC>> field_01;
	
	parlex::detail::document::text<literal_0x3F_t> dont_care2;
	
	std::vector<val<IC>> field_02;
	
	val<EXPRESSION> true_case;
	
	std::vector<val<IC>> field_03;
	
	parlex::detail::document::text<literal_0x3A_t> dont_care6;
	
	std::vector<val<IC>> field_04;
	
	val<EXPRESSION> false_case;
	


	explicit CONDITIONAL
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & condition, std::vector<val<IC>> const & field_01, parlex::detail::document::text<literal_0x3F_t> const & dont_care2, std::vector<val<IC>> const & field_02, val<EXPRESSION> const & true_case, std::vector<val<IC>> const & field_03, parlex::detail::document::text<literal_0x3A_t> const & dont_care6, std::vector<val<IC>> const & field_04, val<EXPRESSION> const & false_case)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), condition(condition), field_01(field_01), dont_care2(dont_care2), field_02(field_02), true_case(true_case), field_03(field_03), dont_care6(dont_care6), field_04(field_04), false_case(false_case) {}

	CONDITIONAL(CONDITIONAL const & other) = default;
	static CONDITIONAL build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


typedef std::variant<
	val<COMPOSITION>,
	val<COMPOUND>,
	val<PREPEND>,
	val<NULL_COALESCE>
> CONSTRUCTIVE_OP_base;

struct CONSTRUCTIVE_OP: CONSTRUCTIVE_OP_base {
	static CONSTRUCTIVE_OP build(parlex::detail::ast_node const & n);
	explicit CONSTRUCTIVE_OP(CONSTRUCTIVE_OP_base const & value) : CONSTRUCTIVE_OP_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
struct CONTINUE {
	int32_t document_position, consumed_character_count;

	struct field_1_t1 {
		std::vector<val<IC>> field_1;
		
		parlex::detail::document::text<literal_0x5B_t> dont_care1;
		
		std::vector<val<IC>> field_2;
		
		val<EXPRESSION> expression;
		
		std::vector<val<IC>> field_3;
		
		parlex::detail::document::text<literal_0x5D_t> dont_care5;
		
	
	
		explicit field_1_t1
			(std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_0x5B_t> const & dont_care1, std::vector<val<IC>> const & field_2, val<EXPRESSION> const & expression, std::vector<val<IC>> const & field_3, parlex::detail::document::text<literal_0x5D_t> const & dont_care5)
			: field_1(field_1), dont_care1(dont_care1), field_2(field_2), expression(expression), field_3(field_3), dont_care5(dont_care5) {}
	
		field_1_t1(field_1_t1 const & other) = default;
		static field_1_t1 build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_1_t2 {
		val<IC> field_1;
		
		std::vector<val<IC>> field_2;
		
		val<IDENTIFIER> identifier;
		
	
	
		explicit field_1_t2
			(val<IC> const & field_1, std::vector<val<IC>> const & field_2, val<IDENTIFIER> const & identifier)
			: field_1(field_1), field_2(field_2), identifier(identifier) {}
	
		field_1_t2(field_1_t2 const & other) = default;
		static field_1_t2 build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_continue_t> dont_care0;
	
	std::optional<std::variant<
		field_1_t1,
		field_1_t2
	>> field_1;
	


	explicit CONTINUE
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_continue_t> const & dont_care0, std::optional<std::variant<
	field_1_t1,
	field_1_t2
>> const & field_1)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1) {}

	CONTINUE(CONTINUE const & other) = default;
	static CONTINUE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct CROSS_PRODUCT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xC30x97_t>,
		parlex::detail::document::text<literal__x__t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit CROSS_PRODUCT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0xC30x97_t>,
	parlex::detail::document::text<literal__x__t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	CROSS_PRODUCT(CROSS_PRODUCT const & other) = default;
	static CROSS_PRODUCT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct CROSS_PRODUCT_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xC30x97_t>,
		parlex::detail::document::text<literal__x__t>
	> field_3;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_4;
	
	std::vector<val<IC>> field_5;
	
	val<EXPRESSION> field_6;
	


	explicit CROSS_PRODUCT_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0xC30x97_t>,
	parlex::detail::document::text<literal__x__t>
> const & field_3, std::variant<
	parlex::detail::document::text<literal_0x3C0x2D_t>,
	parlex::detail::document::text<literal_0xE20x860x90_t>
> const & field_4, std::vector<val<IC>> const & field_5, val<EXPRESSION> const & field_6)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5), field_6(field_6) {}

	CROSS_PRODUCT_ASSIGNMENT(CROSS_PRODUCT_ASSIGNMENT const & other) = default;
	static CROSS_PRODUCT_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


typedef std::variant<
	val<DATE_YEAR_MONTH_DAY>,
	val<DATE_YEAR_DAY>
> DATE_base;

struct DATE: DATE_base {
	static DATE build(parlex::detail::ast_node const & n);
	explicit DATE(DATE_base const & value) : DATE_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
struct DATE_TIME {
	int32_t document_position, consumed_character_count;

	val<DATE> field_1;
	
	parlex::detail::document::text<literal_T_t> dont_care1;
	
	val<TIME> field_2;
	


	explicit DATE_TIME
		(int32_t documentPosition, int32_t consumedCharacterCount, val<DATE> const & field_1, parlex::detail::document::text<literal_T_t> const & dont_care1, val<TIME> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), dont_care1(dont_care1), field_2(field_2) {}

	DATE_TIME(DATE_TIME const & other) = default;
	static DATE_TIME build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct DATE_YEAR_DAY {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_1;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_2;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_3;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_4;
	
	parlex::detail::document::text<literal_0x2D_t> dont_care4;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_5;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_6;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_7;
	


	explicit DATE_YEAR_DAY
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_1, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_2, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_3, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_4, parlex::detail::document::text<literal_0x2D_t> const & dont_care4, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_5, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_6, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_7)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), dont_care4(dont_care4), field_5(field_5), field_6(field_6), field_7(field_7) {}

	DATE_YEAR_DAY(DATE_YEAR_DAY const & other) = default;
	static DATE_YEAR_DAY build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct DATE_YEAR_MONTH_DAY {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_01;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_02;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_03;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_04;
	
	parlex::detail::document::text<literal_0x2D_t> dont_care4;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_05;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_06;
	
	parlex::detail::document::text<literal_0x2D_t> dont_care7;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_07;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_08;
	


	explicit DATE_YEAR_MONTH_DAY
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_01, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_02, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_03, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_04, parlex::detail::document::text<literal_0x2D_t> const & dont_care4, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_05, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_06, parlex::detail::document::text<literal_0x2D_t> const & dont_care7, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_07, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_08)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_01(field_01), field_02(field_02), field_03(field_03), field_04(field_04), dont_care4(dont_care4), field_05(field_05), field_06(field_06), dont_care7(dont_care7), field_07(field_07), field_08(field_08) {}

	DATE_YEAR_MONTH_DAY(DATE_YEAR_MONTH_DAY const & other) = default;
	static DATE_YEAR_MONTH_DAY build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct DEFINITION {
	int32_t document_position, consumed_character_count;

	val<IDENTIFIER_SPECIFICATION> identifier_specification;
	
	std::vector<val<IC>> field_1;
	
	parlex::detail::document::text<literal_0x3A0x3D_t> dont_care2;
	
	std::vector<val<IC>> field_2;
	
	val<EXPRESSION> expression;
	


	explicit DEFINITION
		(int32_t documentPosition, int32_t consumedCharacterCount, val<IDENTIFIER_SPECIFICATION> const & identifier_specification, std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_0x3A0x3D_t> const & dont_care2, std::vector<val<IC>> const & field_2, val<EXPRESSION> const & expression)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), identifier_specification(identifier_specification), field_1(field_1), dont_care2(dont_care2), field_2(field_2), expression(expression) {}

	DEFINITION(DEFINITION const & other) = default;
	static DEFINITION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct DELTA {
	int32_t document_position, consumed_character_count;

	struct field_2_t {
		parlex::detail::document::text<literal_0x5E_t> dont_care0;
		
		val<WHOLE_NUMBER> whole_number;
		
	
	
		explicit field_2_t
			(parlex::detail::document::text<literal_0x5E_t> const & dont_care0, val<WHOLE_NUMBER> const & whole_number)
			: dont_care0(dont_care0), whole_number(whole_number) {}
	
		field_2_t(field_2_t const & other) = default;
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::variant<
		parlex::detail::document::text<literal_0xCE0x94_t>,
		parlex::detail::document::text<literal__delta__t>
	> field_1;
	
	std::optional<field_2_t> field_2;
	
	val<EXPRESSION> expression;
	


	explicit DELTA
		(int32_t documentPosition, int32_t consumedCharacterCount, std::variant<
	parlex::detail::document::text<literal_0xCE0x94_t>,
	parlex::detail::document::text<literal__delta__t>
> const & field_1, std::optional<field_2_t> const & field_2, val<EXPRESSION> const & expression)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), expression(expression) {}

	DELTA(DELTA const & other) = default;
	static DELTA build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


typedef std::variant<
	val<IDENTIFIER>,
	val<DIMENSIONAL_ANALYSIS_OP>
> DIMENSION_base;

struct DIMENSION: DIMENSION_base {
	static DIMENSION build(parlex::detail::ast_node const & n);
	explicit DIMENSION(DIMENSION_base const & value) : DIMENSION_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
typedef std::variant<
	val<UNIT_DIVISION>,
	val<UNIT_EXPONENTIATION>,
	val<UNIT_MULTIPLICATION>
> DIMENSIONAL_ANALYSIS_OP_base;

struct DIMENSIONAL_ANALYSIS_OP: DIMENSIONAL_ANALYSIS_OP_base {
	static DIMENSIONAL_ANALYSIS_OP build(parlex::detail::ast_node const & n);
	explicit DIMENSIONAL_ANALYSIS_OP(DIMENSIONAL_ANALYSIS_OP_base const & value) : DIMENSIONAL_ANALYSIS_OP_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
struct DIMENSIONAL_NUMBER {
	int32_t document_position, consumed_character_count;

	val<NON_NEG_NUMBER> field_1;
	
	val<DIMENSION> field_2;
	


	explicit DIMENSIONAL_NUMBER
		(int32_t documentPosition, int32_t consumedCharacterCount, val<NON_NEG_NUMBER> const & field_1, val<DIMENSION> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2) {}

	DIMENSIONAL_NUMBER(DIMENSIONAL_NUMBER const & other) = default;
	static DIMENSIONAL_NUMBER build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct DIVISION {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xC30xB7_t>,
		parlex::detail::document::text<literal_0x2F_t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit DIVISION
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0xC30xB7_t>,
	parlex::detail::document::text<literal_0x2F_t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	DIVISION(DIVISION const & other) = default;
	static DIVISION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct DIVISION_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xC30xB7_t>,
		parlex::detail::document::text<literal_0x2F_t>
	> field_3;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_4;
	
	std::vector<val<IC>> field_5;
	
	val<EXPRESSION> field_6;
	


	explicit DIVISION_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0xC30xB7_t>,
	parlex::detail::document::text<literal_0x2F_t>
> const & field_3, std::variant<
	parlex::detail::document::text<literal_0x3C0x2D_t>,
	parlex::detail::document::text<literal_0xE20x860x90_t>
> const & field_4, std::vector<val<IC>> const & field_5, val<EXPRESSION> const & field_6)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5), field_6(field_6) {}

	DIVISION_ASSIGNMENT(DIVISION_ASSIGNMENT const & other) = default;
	static DIVISION_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct DO {
	int32_t document_position, consumed_character_count;

	struct field_2_t {
		std::vector<val<IC>> field_1;
		
		std::variant<
			parlex::detail::document::text<literal_while_t>,
			parlex::detail::document::text<literal_until_t>
		> field_2;
		
		std::vector<val<IC>> field_3;
		
		val<PARENTHETICAL> condition;
		
	
	
		explicit field_2_t
			(std::vector<val<IC>> const & field_1, std::variant<
		parlex::detail::document::text<literal_while_t>,
		parlex::detail::document::text<literal_until_t>
	> const & field_2, std::vector<val<IC>> const & field_3, val<PARENTHETICAL> const & condition)
			: field_1(field_1), field_2(field_2), field_3(field_3), condition(condition) {}
	
		field_2_t(field_2_t const & other) = default;
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_do_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<EXPRESSION> expression;
	
	std::optional<field_2_t> field_2;
	


	explicit DO
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_do_t> const & dont_care0, std::vector<val<IC>> const & field_1, val<EXPRESSION> const & expression, std::optional<field_2_t> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), expression(expression), field_2(field_2) {}

	DO(DO const & other) = default;
	static DO build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct DOT_PRODUCT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xE20x8B0x85_t>,
		parlex::detail::document::text<literal__dot__t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit DOT_PRODUCT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0xE20x8B0x85_t>,
	parlex::detail::document::text<literal__dot__t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	DOT_PRODUCT(DOT_PRODUCT const & other) = default;
	static DOT_PRODUCT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct DOWNCASTS {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_downcasts_t> dont_care2;
	
	std::vector<val<IC>> field_3;
	
	val<EXPRESSION> field_4;
	


	explicit DOWNCASTS
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_downcasts_t> const & dont_care2, std::vector<val<IC>> const & field_3, val<EXPRESSION> const & field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4) {}

	DOWNCASTS(DOWNCASTS const & other) = default;
	static DOWNCASTS build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct EMBEDDED_COMMENT {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0x2F0x2A0x2A0x2A_t> dont_care0;
	
	val<EMBEDDED_COMMENT_INTERIOR> field_1;
	
	parlex::detail::document::text<literal_0x2A0x2A0x2A0x2F_t> dont_care2;
	


	explicit EMBEDDED_COMMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x2F0x2A0x2A0x2A_t> const & dont_care0, val<EMBEDDED_COMMENT_INTERIOR> const & field_1, parlex::detail::document::text<literal_0x2A0x2A0x2A0x2F_t> const & dont_care2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), dont_care2(dont_care2) {}

	EMBEDDED_COMMENT(EMBEDDED_COMMENT const & other) = default;
	static EMBEDDED_COMMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct EMBEDDED_COMMENT_INTERIOR_t {
	parlex::detail::document::text<literal_0x2A_t> dont_care0;
	
	val<EMBEDDED_COMMENT_INTERIOR> field_1;
	
	parlex::detail::document::text<literal_0x2A_t> dont_care2;
	


	explicit EMBEDDED_COMMENT_INTERIOR_t
		(parlex::detail::document::text<literal_0x2A_t> const & dont_care0, val<EMBEDDED_COMMENT_INTERIOR> const & field_1, parlex::detail::document::text<literal_0x2A_t> const & dont_care2)
		: dont_care0(dont_care0), field_1(field_1), dont_care2(dont_care2) {}

	EMBEDDED_COMMENT_INTERIOR_t(EMBEDDED_COMMENT_INTERIOR_t const & other) = default;
	static EMBEDDED_COMMENT_INTERIOR_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

typedef std::variant<
	val<PAYLOAD>,
	EMBEDDED_COMMENT_INTERIOR_t
> EMBEDDED_COMMENT_INTERIOR_base;

struct EMBEDDED_COMMENT_INTERIOR: EMBEDDED_COMMENT_INTERIOR_base {
	static EMBEDDED_COMMENT_INTERIOR build(parlex::detail::ast_node const & n);
	explicit EMBEDDED_COMMENT_INTERIOR(EMBEDDED_COMMENT_INTERIOR_base const & value) : EMBEDDED_COMMENT_INTERIOR_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
struct EMBEDDED_NEWLINE_STRING {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0x220x220x22_t> dont_care0;
	
	val<EMBEDDED_NEWLINE_STRING_INTERIOR> field_1;
	
	parlex::detail::document::text<literal_0x220x220x22_t> dont_care2;
	


	explicit EMBEDDED_NEWLINE_STRING
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x220x220x22_t> const & dont_care0, val<EMBEDDED_NEWLINE_STRING_INTERIOR> const & field_1, parlex::detail::document::text<literal_0x220x220x22_t> const & dont_care2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), dont_care2(dont_care2) {}

	EMBEDDED_NEWLINE_STRING(EMBEDDED_NEWLINE_STRING const & other) = default;
	static EMBEDDED_NEWLINE_STRING build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct EMBEDDED_NEWLINE_STRING_INTERIOR1_t {
	parlex::detail::document::text<literal_0x0A_t> dont_care0;
	
	val<PAYLOAD> payload;
	
	parlex::detail::document::text<literal_0x0A_t> dont_care2;
	


	explicit EMBEDDED_NEWLINE_STRING_INTERIOR1_t
		(parlex::detail::document::text<literal_0x0A_t> const & dont_care0, val<PAYLOAD> const & payload, parlex::detail::document::text<literal_0x0A_t> const & dont_care2)
		: dont_care0(dont_care0), payload(payload), dont_care2(dont_care2) {}

	EMBEDDED_NEWLINE_STRING_INTERIOR1_t(EMBEDDED_NEWLINE_STRING_INTERIOR1_t const & other) = default;
	static EMBEDDED_NEWLINE_STRING_INTERIOR1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

struct EMBEDDED_NEWLINE_STRING_INTERIOR2_t {
	parlex::detail::document::text<literal_0x22_t> dont_care0;
	
	val<EMBEDDED_NEWLINE_STRING_INTERIOR> field_1;
	
	parlex::detail::document::text<literal_0x22_t> dont_care2;
	


	explicit EMBEDDED_NEWLINE_STRING_INTERIOR2_t
		(parlex::detail::document::text<literal_0x22_t> const & dont_care0, val<EMBEDDED_NEWLINE_STRING_INTERIOR> const & field_1, parlex::detail::document::text<literal_0x22_t> const & dont_care2)
		: dont_care0(dont_care0), field_1(field_1), dont_care2(dont_care2) {}

	EMBEDDED_NEWLINE_STRING_INTERIOR2_t(EMBEDDED_NEWLINE_STRING_INTERIOR2_t const & other) = default;
	static EMBEDDED_NEWLINE_STRING_INTERIOR2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

typedef std::variant<
	EMBEDDED_NEWLINE_STRING_INTERIOR1_t,
	EMBEDDED_NEWLINE_STRING_INTERIOR2_t
> EMBEDDED_NEWLINE_STRING_INTERIOR_base;

struct EMBEDDED_NEWLINE_STRING_INTERIOR: EMBEDDED_NEWLINE_STRING_INTERIOR_base {
	static EMBEDDED_NEWLINE_STRING_INTERIOR build(parlex::detail::ast_node const & n);
	explicit EMBEDDED_NEWLINE_STRING_INTERIOR(EMBEDDED_NEWLINE_STRING_INTERIOR_base const & value) : EMBEDDED_NEWLINE_STRING_INTERIOR_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
struct EMBEDDED_STRING {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0x220x220x22_t> dont_care0;
	
	val<EMBEDDED_STRING_INTERIOR> field_1;
	
	parlex::detail::document::text<literal_0x220x220x22_t> dont_care2;
	


	explicit EMBEDDED_STRING
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x220x220x22_t> const & dont_care0, val<EMBEDDED_STRING_INTERIOR> const & field_1, parlex::detail::document::text<literal_0x220x220x22_t> const & dont_care2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), dont_care2(dont_care2) {}

	EMBEDDED_STRING(EMBEDDED_STRING const & other) = default;
	static EMBEDDED_STRING build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct EMBEDDED_STRING_INTERIOR_t {
	parlex::detail::document::text<literal_0x22_t> dont_care0;
	
	val<EMBEDDED_STRING_INTERIOR> field_1;
	
	parlex::detail::document::text<literal_0x22_t> dont_care2;
	


	explicit EMBEDDED_STRING_INTERIOR_t
		(parlex::detail::document::text<literal_0x22_t> const & dont_care0, val<EMBEDDED_STRING_INTERIOR> const & field_1, parlex::detail::document::text<literal_0x22_t> const & dont_care2)
		: dont_care0(dont_care0), field_1(field_1), dont_care2(dont_care2) {}

	EMBEDDED_STRING_INTERIOR_t(EMBEDDED_STRING_INTERIOR_t const & other) = default;
	static EMBEDDED_STRING_INTERIOR_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

typedef std::variant<
	val<PAYLOAD>,
	EMBEDDED_STRING_INTERIOR_t
> EMBEDDED_STRING_INTERIOR_base;

struct EMBEDDED_STRING_INTERIOR: EMBEDDED_STRING_INTERIOR_base {
	static EMBEDDED_STRING_INTERIOR build(parlex::detail::ast_node const & n);
	explicit EMBEDDED_STRING_INTERIOR(EMBEDDED_STRING_INTERIOR_base const & value) : EMBEDDED_STRING_INTERIOR_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
struct END_OF_LINE_COMMENT {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0x2F0x2F_t> dont_care0;
	
	std::vector<parlex::detail::document::text<parlex::detail::not_newline_t>> field_1;
	
	parlex::detail::document::text<literal_0x0A_t> dont_care2;
	


	explicit END_OF_LINE_COMMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x2F0x2F_t> const & dont_care0, std::vector<parlex::detail::document::text<parlex::detail::not_newline_t>> const & field_1, parlex::detail::document::text<literal_0x0A_t> const & dont_care2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), dont_care2(dont_care2) {}

	END_OF_LINE_COMMENT(END_OF_LINE_COMMENT const & other) = default;
	static END_OF_LINE_COMMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct ENUM {
	int32_t document_position, consumed_character_count;

	struct field_2_t {
		parlex::detail::document::text<literal_inheriting_t> dont_care0;
		
		std::vector<val<IC>> field_1;
		
		val<INHERITANCE_LIST> field_2;
		
		std::vector<val<IC>> field_3;
		
	
	
		explicit field_2_t
			(parlex::detail::document::text<literal_inheriting_t> const & dont_care0, std::vector<val<IC>> const & field_1, val<INHERITANCE_LIST> const & field_2, std::vector<val<IC>> const & field_3)
			: dont_care0(dont_care0), field_1(field_1), field_2(field_2), field_3(field_3) {}
	
		field_2_t(field_2_t const & other) = default;
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_3_t {
		parlex::detail::document::text<literal_implementing_t> dont_care0;
		
		std::vector<val<IC>> field_1;
		
		val<INHERITANCE_LIST> field_2;
		
		std::vector<val<IC>> field_3;
		
	
	
		explicit field_3_t
			(parlex::detail::document::text<literal_implementing_t> const & dont_care0, std::vector<val<IC>> const & field_1, val<INHERITANCE_LIST> const & field_2, std::vector<val<IC>> const & field_3)
			: dont_care0(dont_care0), field_1(field_1), field_2(field_2), field_3(field_3) {}
	
		field_3_t(field_3_t const & other) = default;
		static field_3_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_4_t {
		struct field_1_t {
			std::vector<val<IC>> field_1;
			
			parlex::detail::document::text<literal_0x3B_t> dont_care1;
			
			std::vector<val<IC>> field_2;
			
			val<ENUM_ELEMENT> enum_element;
			
		
		
			explicit field_1_t
				(std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_0x3B_t> const & dont_care1, std::vector<val<IC>> const & field_2, val<ENUM_ELEMENT> const & enum_element)
				: field_1(field_1), dont_care1(dont_care1), field_2(field_2), enum_element(enum_element) {}
		
			field_1_t(field_1_t const & other) = default;
			static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		val<ENUM_ELEMENT> enum_element;
		
		std::vector<field_1_t> field_1;
		
	
	
		explicit field_4_t
			(val<ENUM_ELEMENT> const & enum_element, std::vector<field_1_t> const & field_1)
			: enum_element(enum_element), field_1(field_1) {}
	
		field_4_t(field_4_t const & other) = default;
		static field_4_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_enum_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	std::optional<field_2_t> field_2;
	
	std::optional<field_3_t> field_3;
	
	parlex::detail::document::text<literal_0x7B_t> dont_care4;
	
	std::optional<field_4_t> field_4;
	
	parlex::detail::document::text<literal_0x7D_t> dont_care6;
	


	explicit ENUM
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_enum_t> const & dont_care0, std::vector<val<IC>> const & field_1, std::optional<field_2_t> const & field_2, std::optional<field_3_t> const & field_3, parlex::detail::document::text<literal_0x7B_t> const & dont_care4, std::optional<field_4_t> const & field_4, parlex::detail::document::text<literal_0x7D_t> const & dont_care6)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), field_2(field_2), field_3(field_3), dont_care4(dont_care4), field_4(field_4), dont_care6(dont_care6) {}

	ENUM(ENUM const & other) = default;
	static ENUM build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct ENUM_ELEMENT {
	int32_t document_position, consumed_character_count;

	struct field_1_t {
		std::vector<val<IC>> field_1;
		
		parlex::detail::document::text<literal_0x3A0x3D_t> dont_care1;
		
		std::vector<val<IC>> field_2;
		
		val<EXPRESSION> expression;
		
	
	
		explicit field_1_t
			(std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_0x3A0x3D_t> const & dont_care1, std::vector<val<IC>> const & field_2, val<EXPRESSION> const & expression)
			: field_1(field_1), dont_care1(dont_care1), field_2(field_2), expression(expression) {}
	
		field_1_t(field_1_t const & other) = default;
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::optional<val<XML_DOC_STRING>> doc;
	
	val<IDENTIFIER> identifier;
	
	std::optional<field_1_t> field_1;
	


	explicit ENUM_ELEMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, std::optional<val<XML_DOC_STRING>> const & doc, val<IDENTIFIER> const & identifier, std::optional<field_1_t> const & field_1)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), doc(doc), identifier(identifier), field_1(field_1) {}

	ENUM_ELEMENT(ENUM_ELEMENT const & other) = default;
	static ENUM_ELEMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct EQUALITY {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> expression;
	
	std::vector<val<IC>> field_1;
	
	val<EQUALITY_NODE> equality_node;
	


	explicit EQUALITY
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & expression, std::vector<val<IC>> const & field_1, val<EQUALITY_NODE> const & equality_node)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), expression(expression), field_1(field_1), equality_node(equality_node) {}

	EQUALITY(EQUALITY const & other) = default;
	static EQUALITY build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct EQUALITY_NODE {
	int32_t document_position, consumed_character_count;

	struct field_2_t {
		std::vector<val<IC>> field_1;
		
		val<EQUALITY_NODE> equality_node;
		
	
	
		explicit field_2_t
			(std::vector<val<IC>> const & field_1, val<EQUALITY_NODE> const & equality_node)
			: field_1(field_1), equality_node(equality_node) {}
	
		field_2_t(field_2_t const & other) = default;
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_0x3D_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<EXPRESSION> expression;
	
	std::optional<field_2_t> field_2;
	


	explicit EQUALITY_NODE
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x3D_t> const & dont_care0, std::vector<val<IC>> const & field_1, val<EXPRESSION> const & expression, std::optional<field_2_t> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), expression(expression), field_2(field_2) {}

	EQUALITY_NODE(EQUALITY_NODE const & other) = default;
	static EQUALITY_NODE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct EXACTLY {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_exactly_t> dont_care2;
	
	std::vector<val<IC>> field_3;
	
	val<EXPRESSION> field_4;
	


	explicit EXACTLY
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_exactly_t> const & dont_care2, std::vector<val<IC>> const & field_3, val<EXPRESSION> const & field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4) {}

	EXACTLY(EXACTLY const & other) = default;
	static EXACTLY build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct EXISTS {
	int32_t document_position, consumed_character_count;

	std::variant<
		parlex::detail::document::text<literal_0xE20x880x83_t>,
		parlex::detail::document::text<literal_exists_t>
	> field_1;
	
	std::vector<val<IC>> field_2;
	
	val<EXPRESSION> field_3;
	


	explicit EXISTS
		(int32_t documentPosition, int32_t consumedCharacterCount, std::variant<
	parlex::detail::document::text<literal_0xE20x880x83_t>,
	parlex::detail::document::text<literal_exists_t>
> const & field_1, std::vector<val<IC>> const & field_2, val<EXPRESSION> const & field_3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3) {}

	EXISTS(EXISTS const & other) = default;
	static EXISTS build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct EXISTS_ONE {
	int32_t document_position, consumed_character_count;

	std::variant<
		parlex::detail::document::text<literal_0xE20x880x830x21_t>,
		parlex::detail::document::text<literal_exists0x21_t>
	> field_1;
	
	std::vector<val<IC>> field_2;
	
	val<EXPRESSION> field_3;
	


	explicit EXISTS_ONE
		(int32_t documentPosition, int32_t consumedCharacterCount, std::variant<
	parlex::detail::document::text<literal_0xE20x880x830x21_t>,
	parlex::detail::document::text<literal_exists0x21_t>
> const & field_1, std::vector<val<IC>> const & field_2, val<EXPRESSION> const & field_3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3) {}

	EXISTS_ONE(EXISTS_ONE const & other) = default;
	static EXISTS_ONE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct EXPONENTIATION {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x5E_t> dont_care2;
	
	std::vector<val<IC>> field_3;
	
	val<EXPRESSION> field_4;
	


	explicit EXPONENTIATION
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x5E_t> const & dont_care2, std::vector<val<IC>> const & field_3, val<EXPRESSION> const & field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4) {}

	EXPONENTIATION(EXPONENTIATION const & other) = default;
	static EXPONENTIATION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct EXPONENTIATION_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x5E_t> dont_care2;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit EXPONENTIATION_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x5E_t> const & dont_care2, std::variant<
	parlex::detail::document::text<literal_0x3C0x2D_t>,
	parlex::detail::document::text<literal_0xE20x860x90_t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	EXPONENTIATION_ASSIGNMENT(EXPONENTIATION_ASSIGNMENT const & other) = default;
	static EXPONENTIATION_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


typedef std::variant<
	val<ARRAY>,
	val<ASM_FUNCTION>,
	val<BINARY_OP>,
	val<BOOL>,
	val<CAST>,
	val<CEILING>,
	val<COMPLEMENT>,
	val<CONDITIONAL>,
	val<DATE>,
	val<DATE_TIME>,
	val<DELTA>,
	val<DIMENSIONAL_NUMBER>,
	val<EMBEDDED_STRING>,
	val<ENUM>,
	val<EQUALITY>,
	val<FLOOR>,
	val<FUNCTION>,
	val<GREATER>,
	val<IDENTIFIER>,
	val<IF>,
	val<INVOCATION>,
	val<LESSER>,
	val<LIST>,
	val<MAGNITUDE>,
	val<MAP>,
	val<MEMBER_ACCESS>,
	val<NEAREST_INTEGER>,
	val<NON_NEG_NUMBER>,
	val<OBJECT>,
	val<PARENTHETICAL>,
	val<RANGE>,
	val<REGEX>,
	val<SET>,
	val<SET_COMPREHENSION>,
	val<SUBSET>,
	val<SUPERSET>,
	val<SWIZZLE>,
	val<THIS>,
	val<THIS_FUNC>,
	val<THIS_TYPE>,
	val<TIME>,
	val<TUPLE>,
	val<TYPE>,
	val<UNARY_OP>,
	val<VECTOR_NORM>,
	parlex::detail::document::text<literal_context_t>,
	parlex::detail::document::text<literal_null_t>,
	parlex::detail::document::text<literal_unit_t>,
	parlex::detail::document::text<void>
> EXPRESSION_base;

struct EXPRESSION: EXPRESSION_base {
	static EXPRESSION build(parlex::detail::ast_node const & n);
	explicit EXPRESSION(EXPRESSION_base const & value) : EXPRESSION_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
struct FACTORIAL {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x21_t> dont_care2;
	


	explicit FACTORIAL
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x21_t> const & dont_care2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2) {}

	FACTORIAL(FACTORIAL const & other) = default;
	static FACTORIAL build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct FACTORIAL_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x21_t> dont_care2;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_3;
	


	explicit FACTORIAL_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x21_t> const & dont_care2, std::variant<
	parlex::detail::document::text<literal_0x3C0x2D_t>,
	parlex::detail::document::text<literal_0xE20x860x90_t>
> const & field_3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3) {}

	FACTORIAL_ASSIGNMENT(FACTORIAL_ASSIGNMENT const & other) = default;
	static FACTORIAL_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct FLOOR1_t {
	parlex::detail::document::text<literal_0xE20x8C0x8A_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<EXPRESSION> expression;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0xE20x8C0x8B_t> dont_care4;
	


	explicit FLOOR1_t
		(parlex::detail::document::text<literal_0xE20x8C0x8A_t> const & dont_care0, std::vector<val<IC>> const & field_1, val<EXPRESSION> const & expression, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0xE20x8C0x8B_t> const & dont_care4)
		: dont_care0(dont_care0), field_1(field_1), expression(expression), field_2(field_2), dont_care4(dont_care4) {}

	FLOOR1_t(FLOOR1_t const & other) = default;
	static FLOOR1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

struct FLOOR2_t {
	parlex::detail::document::text<literal_0x7C__t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<EXPRESSION> expression;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal__0x7C_t> dont_care4;
	


	explicit FLOOR2_t
		(parlex::detail::document::text<literal_0x7C__t> const & dont_care0, std::vector<val<IC>> const & field_1, val<EXPRESSION> const & expression, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal__0x7C_t> const & dont_care4)
		: dont_care0(dont_care0), field_1(field_1), expression(expression), field_2(field_2), dont_care4(dont_care4) {}

	FLOOR2_t(FLOOR2_t const & other) = default;
	static FLOOR2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

typedef std::variant<
	FLOOR1_t,
	FLOOR2_t
> FLOOR_base;

struct FLOOR: FLOOR_base {
	static FLOOR build(parlex::detail::ast_node const & n);
	explicit FLOOR(FLOOR_base const & value) : FLOOR_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
struct FOR {
	int32_t document_position, consumed_character_count;

	struct initializer_t {
		val<STATEMENT_SCOPE> statement_scope;
		
		std::vector<val<IC>> ic;
		
	
	
		explicit initializer_t
			(val<STATEMENT_SCOPE> const & statement_scope, std::vector<val<IC>> const & ic)
			: statement_scope(statement_scope), ic(ic) {}
	
		initializer_t(initializer_t const & other) = default;
		static initializer_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct step_t {
		val<FOR_STEP_LIST> for_step_list;
		
		std::vector<val<IC>> ic;
		
	
	
		explicit step_t
			(val<FOR_STEP_LIST> const & for_step_list, std::vector<val<IC>> const & ic)
			: for_step_list(for_step_list), ic(ic) {}
	
		step_t(step_t const & other) = default;
		static step_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_for_t> dont_care0;
	
	std::vector<val<IC>> ic1;
	
	parlex::detail::document::text<literal_0x28_t> dont_care2;
	
	std::vector<val<IC>> ic2;
	
	std::optional<initializer_t> initializer;
	
	val<EXPRESSION> condition;
	
	std::vector<val<IC>> ic3;
	
	parlex::detail::document::text<literal_0x3B_t> dont_care7;
	
	std::vector<val<IC>> ic4;
	
	std::optional<step_t> step;
	
	parlex::detail::document::text<literal_0x29_t> dont_care10;
	
	std::vector<val<IC>> ic5;
	
	val<EXPRESSION> field_01;
	


	explicit FOR
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_for_t> const & dont_care0, std::vector<val<IC>> const & ic1, parlex::detail::document::text<literal_0x28_t> const & dont_care2, std::vector<val<IC>> const & ic2, std::optional<initializer_t> const & initializer, val<EXPRESSION> const & condition, std::vector<val<IC>> const & ic3, parlex::detail::document::text<literal_0x3B_t> const & dont_care7, std::vector<val<IC>> const & ic4, std::optional<step_t> const & step, parlex::detail::document::text<literal_0x29_t> const & dont_care10, std::vector<val<IC>> const & ic5, val<EXPRESSION> const & field_01)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), ic1(ic1), dont_care2(dont_care2), ic2(ic2), initializer(initializer), condition(condition), ic3(ic3), dont_care7(dont_care7), ic4(ic4), step(step), dont_care10(dont_care10), ic5(ic5), field_01(field_01) {}

	FOR(FOR const & other) = default;
	static FOR build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct FOR_COLLECTION {
	int32_t document_position, consumed_character_count;

	struct declaration {
		struct field_1_t {
			std::variant<
				val<TYPE_DEREFERENCE>,
				val<IMPLICIT_TYPE_DEREFERENCE>
			> field_1;
			
			std::vector<val<IC>> ic;
			
		
		
			explicit field_1_t
				(std::variant<
			val<TYPE_DEREFERENCE>,
			val<IMPLICIT_TYPE_DEREFERENCE>
		> const & field_1, std::vector<val<IC>> const & ic)
				: field_1(field_1), ic(ic) {}
		
			field_1_t(field_1_t const & other) = default;
			static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		std::optional<field_1_t> field_1;
		
		val<IDENTIFIER> identifier;
		
	
	
		explicit declaration
			(std::optional<field_1_t> const & field_1, val<IDENTIFIER> const & identifier)
			: field_1(field_1), identifier(identifier) {}
	
		declaration(declaration const & other) = default;
		static declaration build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_for_t> dont_care0;
	
	std::vector<val<IC>> ic1;
	
	parlex::detail::document::text<literal_0x28_t> dont_care2;
	
	std::vector<val<IC>> ic2;
	
	std::variant<
		declaration,
		val<EXPRESSION>
	> field_01;
	
	std::vector<val<IC>> ic3;
	
	std::variant<
		parlex::detail::document::text<literal_in_t>,
		parlex::detail::document::text<literal_0xE20x880x88_t>
	> field_02;
	
	std::vector<val<IC>> ic4;
	
	val<EXPRESSION> collection;
	
	std::vector<val<IC>> ic5;
	
	parlex::detail::document::text<literal_0x29_t> dont_care10;
	
	std::vector<val<IC>> ic6;
	
	val<EXPRESSION> expression;
	


	explicit FOR_COLLECTION
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_for_t> const & dont_care0, std::vector<val<IC>> const & ic1, parlex::detail::document::text<literal_0x28_t> const & dont_care2, std::vector<val<IC>> const & ic2, std::variant<
	declaration,
	val<EXPRESSION>
> const & field_01, std::vector<val<IC>> const & ic3, std::variant<
	parlex::detail::document::text<literal_in_t>,
	parlex::detail::document::text<literal_0xE20x880x88_t>
> const & field_02, std::vector<val<IC>> const & ic4, val<EXPRESSION> const & collection, std::vector<val<IC>> const & ic5, parlex::detail::document::text<literal_0x29_t> const & dont_care10, std::vector<val<IC>> const & ic6, val<EXPRESSION> const & expression)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), ic1(ic1), dont_care2(dont_care2), ic2(ic2), field_01(field_01), ic3(ic3), field_02(field_02), ic4(ic4), collection(collection), ic5(ic5), dont_care10(dont_care10), ic6(ic6), expression(expression) {}

	FOR_COLLECTION(FOR_COLLECTION const & other) = default;
	static FOR_COLLECTION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct FOR_STEP {
	int32_t document_position, consumed_character_count;

	val<IDENTIFIER> identifier;
	
	std::vector<val<IC>> ic;
	
	val<FOR_STEP_NODE> for_step_node;
	


	explicit FOR_STEP
		(int32_t documentPosition, int32_t consumedCharacterCount, val<IDENTIFIER> const & identifier, std::vector<val<IC>> const & ic, val<FOR_STEP_NODE> const & for_step_node)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), identifier(identifier), ic(ic), for_step_node(for_step_node) {}

	FOR_STEP(FOR_STEP const & other) = default;
	static FOR_STEP build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct FOR_STEP_LIST {
	int32_t document_position, consumed_character_count;

	struct tail_t {
		std::vector<val<IC>> ic1;
		
		parlex::detail::document::text<literal_0x2C_t> comma;
		
		std::vector<val<IC>> ic2;
		
		val<FOR_STEP> for_step;
		
	
	
		explicit tail_t
			(std::vector<val<IC>> const & ic1, parlex::detail::document::text<literal_0x2C_t> const & comma, std::vector<val<IC>> const & ic2, val<FOR_STEP> const & for_step)
			: ic1(ic1), comma(comma), ic2(ic2), for_step(for_step) {}
	
		tail_t(tail_t const & other) = default;
		static tail_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	val<FOR_STEP> for_step;
	
	std::vector<tail_t> tail;
	


	explicit FOR_STEP_LIST
		(int32_t documentPosition, int32_t consumedCharacterCount, val<FOR_STEP> const & for_step, std::vector<tail_t> const & tail)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), for_step(for_step), tail(tail) {}

	FOR_STEP_LIST(FOR_STEP_LIST const & other) = default;
	static FOR_STEP_LIST build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct FOR_STEP_NODE {
	int32_t document_position, consumed_character_count;

	struct value_t {
		val<IDENTIFIER> identifier;
		
		std::vector<val<IC>> ic;
		
		val<FOR_STEP_NODE> next;
		
	
	
		explicit value_t
			(val<IDENTIFIER> const & identifier, std::vector<val<IC>> const & ic, val<FOR_STEP_NODE> const & next)
			: identifier(identifier), ic(ic), next(next) {}
	
		value_t(value_t const & other) = default;
		static value_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::variant<
		parlex::detail::document::text<literal_0xE20x860x90_t>,
		parlex::detail::document::text<literal_0x3C0x2D_t>
	> field_1;
	
	std::vector<val<IC>> ic;
	
	std::variant<
		val<EXPRESSION>,
		value_t
	> value;
	


	explicit FOR_STEP_NODE
		(int32_t documentPosition, int32_t consumedCharacterCount, std::variant<
	parlex::detail::document::text<literal_0xE20x860x90_t>,
	parlex::detail::document::text<literal_0x3C0x2D_t>
> const & field_1, std::vector<val<IC>> const & ic, std::variant<
	val<EXPRESSION>,
	value_t
> const & value)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), ic(ic), value(value) {}

	FOR_STEP_NODE(FOR_STEP_NODE const & other) = default;
	static FOR_STEP_NODE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct FREE {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_free_t> dont_care0;
	
	std::vector<val<IC>> ic;
	
	val<EXPRESSION> field_1;
	


	explicit FREE
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_free_t> const & dont_care0, std::vector<val<IC>> const & ic, val<EXPRESSION> const & field_1)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), ic(ic), field_1(field_1) {}

	FREE(FREE const & other) = default;
	static FREE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct FUNCTION {
	int32_t document_position, consumed_character_count;

	struct field_1_t {
		struct field_2_t {
			struct field_1_t {
				std::vector<val<IC>> field_1;
				
				parlex::detail::document::text<literal_0x2C_t> dont_care1;
				
				std::vector<val<IC>> field_2;
				
				val<PARAMETER> parameter;
				
			
			
				explicit field_1_t
					(std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_0x2C_t> const & dont_care1, std::vector<val<IC>> const & field_2, val<PARAMETER> const & parameter)
					: field_1(field_1), dont_care1(dont_care1), field_2(field_2), parameter(parameter) {}
			
				field_1_t(field_1_t const & other) = default;
				static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
			};
		
			val<PARAMETER> parameter;
			
			std::vector<field_1_t> field_1;
			
			std::vector<val<IC>> field_2;
			
		
		
			explicit field_2_t
				(val<PARAMETER> const & parameter, std::vector<field_1_t> const & field_1, std::vector<val<IC>> const & field_2)
				: parameter(parameter), field_1(field_1), field_2(field_2) {}
		
			field_2_t(field_2_t const & other) = default;
			static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		parlex::detail::document::text<literal_0x28_t> dont_care0;
		
		std::vector<val<IC>> field_1;
		
		std::optional<field_2_t> field_2;
		
		parlex::detail::document::text<literal_0x29_t> dont_care3;
		
		std::vector<val<IC>> field_3;
		
	
	
		explicit field_1_t
			(parlex::detail::document::text<literal_0x28_t> const & dont_care0, std::vector<val<IC>> const & field_1, std::optional<field_2_t> const & field_2, parlex::detail::document::text<literal_0x29_t> const & dont_care3, std::vector<val<IC>> const & field_3)
			: dont_care0(dont_care0), field_1(field_1), field_2(field_2), dont_care3(dont_care3), field_3(field_3) {}
	
		field_1_t(field_1_t const & other) = default;
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_2_t {
		val<FUNCTION_MODIFIER_0> field_1;
		
		std::vector<val<IC>> field_2;
		
	
	
		explicit field_2_t
			(val<FUNCTION_MODIFIER_0> const & field_1, std::vector<val<IC>> const & field_2)
			: field_1(field_1), field_2(field_2) {}
	
		field_2_t(field_2_t const & other) = default;
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::optional<field_1_t> field_1;
	
	std::optional<field_2_t> field_2;
	
	val<BLOCK> block;
	


	explicit FUNCTION
		(int32_t documentPosition, int32_t consumedCharacterCount, std::optional<field_1_t> const & field_1, std::optional<field_2_t> const & field_2, val<BLOCK> const & block)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), block(block) {}

	FUNCTION(FUNCTION const & other) = default;
	static FUNCTION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


typedef std::variant<
	val<FUNCTION_MODIFIER_STABILITY>,
	val<FUNCTION_MODIFIER_1>
> FUNCTION_MODIFIER_0_base;

struct FUNCTION_MODIFIER_0: FUNCTION_MODIFIER_0_base {
	static FUNCTION_MODIFIER_0 build(parlex::detail::ast_node const & n);
	explicit FUNCTION_MODIFIER_0(FUNCTION_MODIFIER_0_base const & value) : FUNCTION_MODIFIER_0_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
typedef std::variant<
	val<FUNCTION_MODIFIER_THROWING>,
	val<FUNCTION_MODIFIER_2>
> FUNCTION_MODIFIER_1_base;

struct FUNCTION_MODIFIER_1: FUNCTION_MODIFIER_1_base {
	static FUNCTION_MODIFIER_1 build(parlex::detail::ast_node const & n);
	explicit FUNCTION_MODIFIER_1(FUNCTION_MODIFIER_1_base const & value) : FUNCTION_MODIFIER_1_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
typedef std::variant<
	val<FUNCTION_MODIFIER_ATOMIC>,
	val<FUNCTION_MODIFIER_3>
> FUNCTION_MODIFIER_2_base;

struct FUNCTION_MODIFIER_2: FUNCTION_MODIFIER_2_base {
	static FUNCTION_MODIFIER_2 build(parlex::detail::ast_node const & n);
	explicit FUNCTION_MODIFIER_2(FUNCTION_MODIFIER_2_base const & value) : FUNCTION_MODIFIER_2_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
typedef std::variant<
	val<FUNCTION_MODIFIER_PLATFORM>,
	val<FUNCTION_MODIFIER_4>
> FUNCTION_MODIFIER_3_base;

struct FUNCTION_MODIFIER_3: FUNCTION_MODIFIER_3_base {
	static FUNCTION_MODIFIER_3 build(parlex::detail::ast_node const & n);
	explicit FUNCTION_MODIFIER_3(FUNCTION_MODIFIER_3_base const & value) : FUNCTION_MODIFIER_3_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
typedef std::variant<
	val<FUNCTION_MODIFIER_MODEL>,
	val<FUNCTION_MODIFIER_CALLING_CONVENTION>
> FUNCTION_MODIFIER_4_base;

struct FUNCTION_MODIFIER_4: FUNCTION_MODIFIER_4_base {
	static FUNCTION_MODIFIER_4 build(parlex::detail::ast_node const & n);
	explicit FUNCTION_MODIFIER_4(FUNCTION_MODIFIER_4_base const & value) : FUNCTION_MODIFIER_4_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
struct FUNCTION_MODIFIER_ATOMIC {
	int32_t document_position, consumed_character_count;

	struct field_1_t {
		val<IC> field_1;
		
		std::vector<val<IC>> field_2;
		
		val<FUNCTION_MODIFIER_3> field_3;
		
	
	
		explicit field_1_t
			(val<IC> const & field_1, std::vector<val<IC>> const & field_2, val<FUNCTION_MODIFIER_3> const & field_3)
			: field_1(field_1), field_2(field_2), field_3(field_3) {}
	
		field_1_t(field_1_t const & other) = default;
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_atomic_t> atomic;
	
	std::optional<field_1_t> field_1;
	


	explicit FUNCTION_MODIFIER_ATOMIC
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_atomic_t> const & atomic, std::optional<field_1_t> const & field_1)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), atomic(atomic), field_1(field_1) {}

	FUNCTION_MODIFIER_ATOMIC(FUNCTION_MODIFIER_ATOMIC const & other) = default;
	static FUNCTION_MODIFIER_ATOMIC build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


typedef std::variant<
	parlex::detail::document::text<literal_c_call_t>,
	parlex::detail::document::text<literal_fast_call_t>,
	parlex::detail::document::text<literal_cold_call_t>,
	parlex::detail::document::text<literal_ghc_call_t>,
	parlex::detail::document::text<literal_hipe_call_t>,
	parlex::detail::document::text<literal_webkit_js_call_t>,
	parlex::detail::document::text<literal_any_reg_call_t>,
	parlex::detail::document::text<literal_preserve_most_call_t>,
	parlex::detail::document::text<literal_preserve_all_call_t>,
	parlex::detail::document::text<literal_swift_call_t>,
	parlex::detail::document::text<literal_cxx_fast_tls_call_t>,
	parlex::detail::document::text<literal_first_target_call_t>,
	parlex::detail::document::text<literal_x86_std_call_t>,
	parlex::detail::document::text<literal_X86_fast_call_t>,
	parlex::detail::document::text<literal_arm_apcs_call_t>,
	parlex::detail::document::text<literal_arm_aapcs_call_t>,
	parlex::detail::document::text<literal_arm_aapcs_vfp_call_t>,
	parlex::detail::document::text<literal_msp430_intr_call_t>,
	parlex::detail::document::text<literal_x86_this_call_t>,
	parlex::detail::document::text<literal_ptx_kernel_call_t>,
	parlex::detail::document::text<literal_ptx_device_call_t>,
	parlex::detail::document::text<literal_spir_func_call_t>,
	parlex::detail::document::text<literal_spir_kernel_call_t>,
	parlex::detail::document::text<literal_intel_ocl_bi_call_t>,
	parlex::detail::document::text<literal_x86_64_sysv_call_t>,
	parlex::detail::document::text<literal_x86_64_win64_call_t>,
	parlex::detail::document::text<literal_x86_vector_call_t>,
	parlex::detail::document::text<literal_hhvm_call_t>,
	parlex::detail::document::text<literal_x86_intr_call_t>,
	parlex::detail::document::text<literal_avr_intr_call_t>,
	parlex::detail::document::text<literal_avr_signal_call_t>,
	parlex::detail::document::text<literal_avr_builtin_call_t>
> FUNCTION_MODIFIER_CALLING_CONVENTION_base;

struct FUNCTION_MODIFIER_CALLING_CONVENTION: FUNCTION_MODIFIER_CALLING_CONVENTION_base {
	static FUNCTION_MODIFIER_CALLING_CONVENTION build(parlex::detail::ast_node const & n);
	explicit FUNCTION_MODIFIER_CALLING_CONVENTION(FUNCTION_MODIFIER_CALLING_CONVENTION_base const & value) : FUNCTION_MODIFIER_CALLING_CONVENTION_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
struct FUNCTION_MODIFIER_MODEL {
	int32_t document_position, consumed_character_count;

	struct field_1_t {
		val<IC> field_1;
		
		std::vector<val<IC>> field_2;
		
		val<FUNCTION_MODIFIER_CALLING_CONVENTION> field_3;
		
	
	
		explicit field_1_t
			(val<IC> const & field_1, std::vector<val<IC>> const & field_2, val<FUNCTION_MODIFIER_CALLING_CONVENTION> const & field_3)
			: field_1(field_1), field_2(field_2), field_3(field_3) {}
	
		field_1_t(field_1_t const & other) = default;
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::variant<
		parlex::detail::document::text<literal_pure_t>,
		parlex::detail::document::text<literal_imperative_t>,
		parlex::detail::document::text<literal_opaque_t>
	> model;
	
	std::optional<field_1_t> field_1;
	


	explicit FUNCTION_MODIFIER_MODEL
		(int32_t documentPosition, int32_t consumedCharacterCount, std::variant<
	parlex::detail::document::text<literal_pure_t>,
	parlex::detail::document::text<literal_imperative_t>,
	parlex::detail::document::text<literal_opaque_t>
> const & model, std::optional<field_1_t> const & field_1)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), model(model), field_1(field_1) {}

	FUNCTION_MODIFIER_MODEL(FUNCTION_MODIFIER_MODEL const & other) = default;
	static FUNCTION_MODIFIER_MODEL build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct FUNCTION_MODIFIER_PLATFORM {
	int32_t document_position, consumed_character_count;

	struct field_2_t {
		val<IC> field_1;
		
		std::vector<val<IC>> field_2;
		
		val<PLATFORM> field_3;
		
	
	
		explicit field_2_t
			(val<IC> const & field_1, std::vector<val<IC>> const & field_2, val<PLATFORM> const & field_3)
			: field_1(field_1), field_2(field_2), field_3(field_3) {}
	
		field_2_t(field_2_t const & other) = default;
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_3_t {
		val<IC> field_1;
		
		std::vector<val<IC>> field_2;
		
		val<FUNCTION_MODIFIER_4> field_3;
		
	
	
		explicit field_3_t
			(val<IC> const & field_1, std::vector<val<IC>> const & field_2, val<FUNCTION_MODIFIER_4> const & field_3)
			: field_1(field_1), field_2(field_2), field_3(field_3) {}
	
		field_3_t(field_3_t const & other) = default;
		static field_3_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	val<PLATFORM> field_1;
	
	std::vector<field_2_t> field_2;
	
	std::optional<field_3_t> field_3;
	


	explicit FUNCTION_MODIFIER_PLATFORM
		(int32_t documentPosition, int32_t consumedCharacterCount, val<PLATFORM> const & field_1, std::vector<field_2_t> const & field_2, std::optional<field_3_t> const & field_3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3) {}

	FUNCTION_MODIFIER_PLATFORM(FUNCTION_MODIFIER_PLATFORM const & other) = default;
	static FUNCTION_MODIFIER_PLATFORM build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct FUNCTION_MODIFIER_STABILITY {
	int32_t document_position, consumed_character_count;

	struct field_1_t {
		val<IC> field_1;
		
		std::vector<val<IC>> field_2;
		
		val<FUNCTION_MODIFIER_1> field_3;
		
	
	
		explicit field_1_t
			(val<IC> const & field_1, std::vector<val<IC>> const & field_2, val<FUNCTION_MODIFIER_1> const & field_3)
			: field_1(field_1), field_2(field_2), field_3(field_3) {}
	
		field_1_t(field_1_t const & other) = default;
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::variant<
		parlex::detail::document::text<literal_stable_t>,
		parlex::detail::document::text<literal_unstable_t>
	> stability;
	
	std::optional<field_1_t> field_1;
	


	explicit FUNCTION_MODIFIER_STABILITY
		(int32_t documentPosition, int32_t consumedCharacterCount, std::variant<
	parlex::detail::document::text<literal_stable_t>,
	parlex::detail::document::text<literal_unstable_t>
> const & stability, std::optional<field_1_t> const & field_1)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), stability(stability), field_1(field_1) {}

	FUNCTION_MODIFIER_STABILITY(FUNCTION_MODIFIER_STABILITY const & other) = default;
	static FUNCTION_MODIFIER_STABILITY build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct FUNCTION_MODIFIER_THROWING {
	int32_t document_position, consumed_character_count;

	struct field_1_t {
		std::vector<val<IC>> field_1;
		
		val<ARRAY> field_2;
		
	
	
		explicit field_1_t
			(std::vector<val<IC>> const & field_1, val<ARRAY> const & field_2)
			: field_1(field_1), field_2(field_2) {}
	
		field_1_t(field_1_t const & other) = default;
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_2_t {
		val<IC> field_1;
		
		std::vector<val<IC>> field_2;
		
		val<FUNCTION_MODIFIER_2> field_3;
		
	
	
		explicit field_2_t
			(val<IC> const & field_1, std::vector<val<IC>> const & field_2, val<FUNCTION_MODIFIER_2> const & field_3)
			: field_1(field_1), field_2(field_2), field_3(field_3) {}
	
		field_2_t(field_2_t const & other) = default;
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_throwing_t> throwing;
	
	std::optional<field_1_t> field_1;
	
	std::optional<field_2_t> field_2;
	


	explicit FUNCTION_MODIFIER_THROWING
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_throwing_t> const & throwing, std::optional<field_1_t> const & field_1, std::optional<field_2_t> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), throwing(throwing), field_1(field_1), field_2(field_2) {}

	FUNCTION_MODIFIER_THROWING(FUNCTION_MODIFIER_THROWING const & other) = default;
	static FUNCTION_MODIFIER_THROWING build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct GREATER {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> expression;
	
	std::vector<val<IC>> field_1;
	
	val<GREATER_NODE> greater_node;
	


	explicit GREATER
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & expression, std::vector<val<IC>> const & field_1, val<GREATER_NODE> const & greater_node)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), expression(expression), field_1(field_1), greater_node(greater_node) {}

	GREATER(GREATER const & other) = default;
	static GREATER build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct GREATER_NODE {
	int32_t document_position, consumed_character_count;

	struct field_3_t {
		std::vector<val<IC>> field_1;
		
		val<GREATER_NODE> greater_node;
		
	
	
		explicit field_3_t
			(std::vector<val<IC>> const & field_1, val<GREATER_NODE> const & greater_node)
			: field_1(field_1), greater_node(greater_node) {}
	
		field_3_t(field_3_t const & other) = default;
		static field_3_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::variant<
		parlex::detail::document::text<literal_0x3D_t>,
		parlex::detail::document::text<literal_0x3E_t>,
		parlex::detail::document::text<literal_0x3D0x3E_t>,
		parlex::detail::document::text<literal_0xE20x890xA5_t>
	> field_1;
	
	std::vector<val<IC>> field_2;
	
	val<EXPRESSION> expression;
	
	std::optional<field_3_t> field_3;
	


	explicit GREATER_NODE
		(int32_t documentPosition, int32_t consumedCharacterCount, std::variant<
	parlex::detail::document::text<literal_0x3D_t>,
	parlex::detail::document::text<literal_0x3E_t>,
	parlex::detail::document::text<literal_0x3D0x3E_t>,
	parlex::detail::document::text<literal_0xE20x890xA5_t>
> const & field_1, std::vector<val<IC>> const & field_2, val<EXPRESSION> const & expression, std::optional<field_3_t> const & field_3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), expression(expression), field_3(field_3) {}

	GREATER_NODE(GREATER_NODE const & other) = default;
	static GREATER_NODE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct HAS {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xE20x880x8B_t>,
		parlex::detail::document::text<literal_has_t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit HAS
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0xE20x880x8B_t>,
	parlex::detail::document::text<literal_has_t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	HAS(HAS const & other) = default;
	static HAS build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct HEX {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0x_t> dont_care0;
	
	parlex::detail::document::text<parlex::detail::hexadecimal_digit_t> field_1;
	
	std::vector<parlex::detail::document::text<parlex::detail::hexadecimal_digit_t>> field_2;
	


	explicit HEX
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x_t> const & dont_care0, parlex::detail::document::text<parlex::detail::hexadecimal_digit_t> const & field_1, std::vector<parlex::detail::document::text<parlex::detail::hexadecimal_digit_t>> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), field_2(field_2) {}

	HEX(HEX const & other) = default;
	static HEX build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


typedef std::variant<
	val<COMMENT>,
	val<EMBEDDED_COMMENT>,
	val<END_OF_LINE_COMMENT>,
	val<WS>
> IC_base;

struct IC: IC_base {
	static IC build(parlex::detail::ast_node const & n);
	explicit IC(IC_base const & value) : IC_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
struct IDENTIFIER {
	int32_t document_position, consumed_character_count;

	std::variant<
		parlex::detail::document::text<parlex::detail::letter_t>,
		parlex::detail::document::text<literal___t>
	> head;
	
	std::vector<std::variant<
		parlex::detail::document::text<parlex::detail::letter_t>,
		parlex::detail::document::text<parlex::detail::number_t>,
		parlex::detail::document::text<literal___t>
	>> tail;
	


	explicit IDENTIFIER
		(int32_t documentPosition, int32_t consumedCharacterCount, std::variant<
	parlex::detail::document::text<parlex::detail::letter_t>,
	parlex::detail::document::text<literal___t>
> const & head, std::vector<std::variant<
	parlex::detail::document::text<parlex::detail::letter_t>,
	parlex::detail::document::text<parlex::detail::number_t>,
	parlex::detail::document::text<literal___t>
>> const & tail)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), head(head), tail(tail) {}

	IDENTIFIER(IDENTIFIER const & other) = default;
	static IDENTIFIER build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct IDENTIFIER_SPECIFICATION {
	int32_t document_position, consumed_character_count;

	struct attributes_t {
		val<ATTRIBUTE> attribute;
		
		std::vector<val<IC>> ic;
		
	
	
		explicit attributes_t
			(val<ATTRIBUTE> const & attribute, std::vector<val<IC>> const & ic)
			: attribute(attribute), ic(ic) {}
	
		attributes_t(attributes_t const & other) = default;
		static attributes_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct visibility_t {
		val<VISIBILITY_MODIFIER> visibility_modifier;
		
		std::vector<val<IC>> ic;
		
	
	
		explicit visibility_t
			(val<VISIBILITY_MODIFIER> const & visibility_modifier, std::vector<val<IC>> const & ic)
			: visibility_modifier(visibility_modifier), ic(ic) {}
	
		visibility_t(visibility_t const & other) = default;
		static visibility_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct static__t {
		parlex::detail::document::text<literal_static_t> dont_care0;
		
		std::vector<val<IC>> field_1;
		
	
	
		explicit static__t
			(parlex::detail::document::text<literal_static_t> const & dont_care0, std::vector<val<IC>> const & field_1)
			: dont_care0(dont_care0), field_1(field_1) {}
	
		static__t(static__t const & other) = default;
		static static__t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct extern__t {
		parlex::detail::document::text<literal_extern_t> dont_care0;
		
		std::vector<val<IC>> field_1;
		
	
	
		explicit extern__t
			(parlex::detail::document::text<literal_extern_t> const & dont_care0, std::vector<val<IC>> const & field_1)
			: dont_care0(dont_care0), field_1(field_1) {}
	
		extern__t(extern__t const & other) = default;
		static extern__t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::optional<val<XML_DOC_STRING>> doc;
	
	std::vector<attributes_t> attributes;
	
	std::optional<visibility_t> visibility;
	
	std::optional<static__t> static_;
	
	std::optional<extern__t> extern_;
	
	val<IDENTIFIER> identifier;
	


	explicit IDENTIFIER_SPECIFICATION
		(int32_t documentPosition, int32_t consumedCharacterCount, std::optional<val<XML_DOC_STRING>> const & doc, std::vector<attributes_t> const & attributes, std::optional<visibility_t> const & visibility, std::optional<static__t> const & static_, std::optional<extern__t> const & extern_, val<IDENTIFIER> const & identifier)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), doc(doc), attributes(attributes), visibility(visibility), static_(static_), extern_(extern_), identifier(identifier) {}

	IDENTIFIER_SPECIFICATION(IDENTIFIER_SPECIFICATION const & other) = default;
	static IDENTIFIER_SPECIFICATION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct IF {
	int32_t document_position, consumed_character_count;

	struct field_3_t {
		std::vector<val<IC>> field_1;
		
		parlex::detail::document::text<literal_elif_t> dont_care1;
		
		std::vector<val<IC>> field_2;
		
		val<PARENTHETICAL> condition;
		
		std::vector<val<IC>> field_3;
		
		val<EXPRESSION> invoke;
		
	
	
		explicit field_3_t
			(std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_elif_t> const & dont_care1, std::vector<val<IC>> const & field_2, val<PARENTHETICAL> const & condition, std::vector<val<IC>> const & field_3, val<EXPRESSION> const & invoke)
			: field_1(field_1), dont_care1(dont_care1), field_2(field_2), condition(condition), field_3(field_3), invoke(invoke) {}
	
		field_3_t(field_3_t const & other) = default;
		static field_3_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_4_t {
		std::vector<val<IC>> field_1;
		
		parlex::detail::document::text<literal_else_t> dont_care1;
		
		std::vector<val<IC>> field_2;
		
		val<EXPRESSION> else_invoke;
		
	
	
		explicit field_4_t
			(std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_else_t> const & dont_care1, std::vector<val<IC>> const & field_2, val<EXPRESSION> const & else_invoke)
			: field_1(field_1), dont_care1(dont_care1), field_2(field_2), else_invoke(else_invoke) {}
	
		field_4_t(field_4_t const & other) = default;
		static field_4_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_if_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<PARENTHETICAL> condition;
	
	std::vector<val<IC>> field_2;
	
	val<EXPRESSION> invoke;
	
	std::vector<field_3_t> field_3;
	
	std::optional<field_4_t> field_4;
	


	explicit IF
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_if_t> const & dont_care0, std::vector<val<IC>> const & field_1, val<PARENTHETICAL> const & condition, std::vector<val<IC>> const & field_2, val<EXPRESSION> const & invoke, std::vector<field_3_t> const & field_3, std::optional<field_4_t> const & field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), condition(condition), field_2(field_2), invoke(invoke), field_3(field_3), field_4(field_4) {}

	IF(IF const & other) = default;
	static IF build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct IFF {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xE20x870x94_t>,
		parlex::detail::document::text<literal_0x3C0x3D0x3E_t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit IFF
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0xE20x870x94_t>,
	parlex::detail::document::text<literal_0x3C0x3D0x3E_t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	IFF(IFF const & other) = default;
	static IFF build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct IMPLEMENTS {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_implements_t> dont_care2;
	
	std::vector<val<IC>> field_3;
	
	val<EXPRESSION> field_4;
	


	explicit IMPLEMENTS
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_implements_t> const & dont_care2, std::vector<val<IC>> const & field_3, val<EXPRESSION> const & field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4) {}

	IMPLEMENTS(IMPLEMENTS const & other) = default;
	static IMPLEMENTS build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct IMPLICATION {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xE20x870x92_t>,
		parlex::detail::document::text<literal_0x3D0x3E_t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit IMPLICATION
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0xE20x870x92_t>,
	parlex::detail::document::text<literal_0x3D0x3E_t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	IMPLICATION(IMPLICATION const & other) = default;
	static IMPLICATION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct IMPLICATION_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xE20x870x92_t>,
		parlex::detail::document::text<literal_0x3D0x3E_t>
	> field_3;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_4;
	
	std::vector<val<IC>> field_5;
	
	val<EXPRESSION> field_6;
	


	explicit IMPLICATION_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0xE20x870x92_t>,
	parlex::detail::document::text<literal_0x3D0x3E_t>
> const & field_3, std::variant<
	parlex::detail::document::text<literal_0x3C0x2D_t>,
	parlex::detail::document::text<literal_0xE20x860x90_t>
> const & field_4, std::vector<val<IC>> const & field_5, val<EXPRESSION> const & field_6)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5), field_6(field_6) {}

	IMPLICATION_ASSIGNMENT(IMPLICATION_ASSIGNMENT const & other) = default;
	static IMPLICATION_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct IMPLICIT_TYPE_DEREFERENCE {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0x3C_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	parlex::detail::document::text<literal_0x3E_t> dont_care2;
	


	explicit IMPLICIT_TYPE_DEREFERENCE
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x3C_t> const & dont_care0, std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_0x3E_t> const & dont_care2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), dont_care2(dont_care2) {}

	IMPLICIT_TYPE_DEREFERENCE(IMPLICIT_TYPE_DEREFERENCE const & other) = default;
	static IMPLICIT_TYPE_DEREFERENCE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct IMPORT {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_import_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<EXPRESSION> field_2;
	


	explicit IMPORT
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_import_t> const & dont_care0, std::vector<val<IC>> const & field_1, val<EXPRESSION> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), field_2(field_2) {}

	IMPORT(IMPORT const & other) = default;
	static IMPORT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct IN {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xE20x880x88_t>,
		parlex::detail::document::text<literal_in_t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit IN
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0xE20x880x88_t>,
	parlex::detail::document::text<literal_in_t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	IN(IN const & other) = default;
	static IN build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct INEQUALITY {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xE20x890xA0_t>,
		parlex::detail::document::text<literal_0x2F0x3D_t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit INEQUALITY
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0xE20x890xA0_t>,
	parlex::detail::document::text<literal_0x2F0x3D_t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	INEQUALITY(INEQUALITY const & other) = default;
	static INEQUALITY build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct INHERITANCE_ITEM_PREFIX {
	int32_t document_position, consumed_character_count;

	struct field_1_t2 {
		val<VISIBILITY_MODIFIER> field_1;
		
		val<IC> field_2;
		
		std::vector<val<IC>> field_3;
		
		parlex::detail::document::text<literal_diamond_t> diamond;
		
	
	
		explicit field_1_t2
			(val<VISIBILITY_MODIFIER> const & field_1, val<IC> const & field_2, std::vector<val<IC>> const & field_3, parlex::detail::document::text<literal_diamond_t> const & diamond)
			: field_1(field_1), field_2(field_2), field_3(field_3), diamond(diamond) {}
	
		field_1_t2(field_1_t2 const & other) = default;
		static field_1_t2 build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::variant<
		val<VISIBILITY_MODIFIER>,
		field_1_t2,
		parlex::detail::document::text<literal_diamond_t>
	> field_1;
	
	val<IC> field_2;
	
	std::vector<val<IC>> field_3;
	


	explicit INHERITANCE_ITEM_PREFIX
		(int32_t documentPosition, int32_t consumedCharacterCount, std::variant<
	val<VISIBILITY_MODIFIER>,
	field_1_t2,
	parlex::detail::document::text<literal_diamond_t>
> const & field_1, val<IC> const & field_2, std::vector<val<IC>> const & field_3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3) {}

	INHERITANCE_ITEM_PREFIX(INHERITANCE_ITEM_PREFIX const & other) = default;
	static INHERITANCE_ITEM_PREFIX build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct INHERITANCE_LIST {
	int32_t document_position, consumed_character_count;

	struct field_2_t {
		std::vector<val<IC>> field_1;
		
		parlex::detail::document::text<literal_0x2C_t> dont_care1;
		
		std::vector<val<IC>> field_2;
		
		std::optional<val<INHERITANCE_ITEM_PREFIX>> field_3;
		
		val<EXPRESSION> expression;
		
	
	
		explicit field_2_t
			(std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_0x2C_t> const & dont_care1, std::vector<val<IC>> const & field_2, std::optional<val<INHERITANCE_ITEM_PREFIX>> const & field_3, val<EXPRESSION> const & expression)
			: field_1(field_1), dont_care1(dont_care1), field_2(field_2), field_3(field_3), expression(expression) {}
	
		field_2_t(field_2_t const & other) = default;
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::optional<val<INHERITANCE_ITEM_PREFIX>> field_1;
	
	val<EXPRESSION> expression;
	
	std::vector<field_2_t> field_2;
	


	explicit INHERITANCE_LIST
		(int32_t documentPosition, int32_t consumedCharacterCount, std::optional<val<INHERITANCE_ITEM_PREFIX>> const & field_1, val<EXPRESSION> const & expression, std::vector<field_2_t> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), expression(expression), field_2(field_2) {}

	INHERITANCE_LIST(INHERITANCE_LIST const & other) = default;
	static INHERITANCE_LIST build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct INHERITS {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_inherits_t> dont_care2;
	
	std::vector<val<IC>> field_3;
	
	val<EXPRESSION> field_4;
	


	explicit INHERITS
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_inherits_t> const & dont_care2, std::vector<val<IC>> const & field_3, val<EXPRESSION> const & field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4) {}

	INHERITS(INHERITS const & other) = default;
	static INHERITS build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct INTEGER_DIVISION {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x5C_t> dont_care2;
	
	std::vector<val<IC>> field_3;
	
	val<EXPRESSION> field_4;
	


	explicit INTEGER_DIVISION
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x5C_t> const & dont_care2, std::vector<val<IC>> const & field_3, val<EXPRESSION> const & field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4) {}

	INTEGER_DIVISION(INTEGER_DIVISION const & other) = default;
	static INTEGER_DIVISION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct INTEGER_DIVISION_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x5C_t> dont_care2;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit INTEGER_DIVISION_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x5C_t> const & dont_care2, std::variant<
	parlex::detail::document::text<literal_0x3C0x2D_t>,
	parlex::detail::document::text<literal_0xE20x860x90_t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	INTEGER_DIVISION_ASSIGNMENT(INTEGER_DIVISION_ASSIGNMENT const & other) = default;
	static INTEGER_DIVISION_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct INTERSECTION {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0xE20x880xA9_t> dont_care2;
	
	std::vector<val<IC>> field_3;
	
	val<EXPRESSION> field_4;
	


	explicit INTERSECTION
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0xE20x880xA9_t> const & dont_care2, std::vector<val<IC>> const & field_3, val<EXPRESSION> const & field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4) {}

	INTERSECTION(INTERSECTION const & other) = default;
	static INTERSECTION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct INTERSECTION_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0xE20x880xA9_t> dont_care2;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit INTERSECTION_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0xE20x880xA9_t> const & dont_care2, std::variant<
	parlex::detail::document::text<literal_0x3C0x2D_t>,
	parlex::detail::document::text<literal_0xE20x860x90_t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	INTERSECTION_ASSIGNMENT(INTERSECTION_ASSIGNMENT const & other) = default;
	static INTERSECTION_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct INVOCATION {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> expression;
	
	std::vector<val<IC>> ic;
	
	std::variant<
		val<PARENTHETICAL_INVOCATION>,
		val<ARRAY_INVOCATION>,
		val<TYPE_INVOCATION>
	> args;
	


	explicit INVOCATION
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & expression, std::vector<val<IC>> const & ic, std::variant<
	val<PARENTHETICAL_INVOCATION>,
	val<ARRAY_INVOCATION>,
	val<TYPE_INVOCATION>
> const & args)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), expression(expression), ic(ic), args(args) {}

	INVOCATION(INVOCATION const & other) = default;
	static INVOCATION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct IS {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_is_t> dont_care2;
	
	std::vector<val<IC>> field_3;
	
	val<EXPRESSION> field_4;
	


	explicit IS
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_is_t> const & dont_care2, std::vector<val<IC>> const & field_3, val<EXPRESSION> const & field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4) {}

	IS(IS const & other) = default;
	static IS build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct KLEENE_STAR {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x2A_t> dont_care2;
	


	explicit KLEENE_STAR
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x2A_t> const & dont_care2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2) {}

	KLEENE_STAR(KLEENE_STAR const & other) = default;
	static KLEENE_STAR build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct LESSER {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> expression;
	
	std::vector<val<IC>> ic;
	
	val<LESSER_NODE> lesser_node;
	


	explicit LESSER
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & expression, std::vector<val<IC>> const & ic, val<LESSER_NODE> const & lesser_node)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), expression(expression), ic(ic), lesser_node(lesser_node) {}

	LESSER(LESSER const & other) = default;
	static LESSER build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct LESSER_NODE {
	int32_t document_position, consumed_character_count;

	struct field_2_t {
		std::vector<val<IC>> ic;
		
		val<LESSER_NODE> lesser_node;
		
	
	
		explicit field_2_t
			(std::vector<val<IC>> const & ic, val<LESSER_NODE> const & lesser_node)
			: ic(ic), lesser_node(lesser_node) {}
	
		field_2_t(field_2_t const & other) = default;
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::variant<
		parlex::detail::document::text<literal_0x3D_t>,
		parlex::detail::document::text<literal_0x3C_t>,
		parlex::detail::document::text<literal_0x3D0x3C_t>,
		parlex::detail::document::text<literal_0xE20x890xA4_t>
	> field_1;
	
	std::vector<val<IC>> ic;
	
	val<EXPRESSION> expression;
	
	std::optional<field_2_t> field_2;
	


	explicit LESSER_NODE
		(int32_t documentPosition, int32_t consumedCharacterCount, std::variant<
	parlex::detail::document::text<literal_0x3D_t>,
	parlex::detail::document::text<literal_0x3C_t>,
	parlex::detail::document::text<literal_0x3D0x3C_t>,
	parlex::detail::document::text<literal_0xE20x890xA4_t>
> const & field_1, std::vector<val<IC>> const & ic, val<EXPRESSION> const & expression, std::optional<field_2_t> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), ic(ic), expression(expression), field_2(field_2) {}

	LESSER_NODE(LESSER_NODE const & other) = default;
	static LESSER_NODE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct LIST {
	int32_t document_position, consumed_character_count;

	struct elements_t {
		struct field_2_t {
			std::vector<val<IC>> field_1;
			
			parlex::detail::document::text<literal_0x2C0x20_t> dont_care1;
			
			std::vector<val<IC>> field_2;
			
			val<EXPRESSION> field_3;
			
		
		
			explicit field_2_t
				(std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_0x2C0x20_t> const & dont_care1, std::vector<val<IC>> const & field_2, val<EXPRESSION> const & field_3)
				: field_1(field_1), dont_care1(dont_care1), field_2(field_2), field_3(field_3) {}
		
			field_2_t(field_2_t const & other) = default;
			static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		val<EXPRESSION> field_1;
		
		std::vector<field_2_t> field_2;
		
		std::vector<val<IC>> field_3;
		
	
	
		explicit elements_t
			(val<EXPRESSION> const & field_1, std::vector<field_2_t> const & field_2, std::vector<val<IC>> const & field_3)
			: field_1(field_1), field_2(field_2), field_3(field_3) {}
	
		elements_t(elements_t const & other) = default;
		static elements_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_0x5B0x7C_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	std::optional<elements_t> elements;
	
	parlex::detail::document::text<literal_0x7C0x5D_t> dont_care3;
	


	explicit LIST
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x5B0x7C_t> const & dont_care0, std::vector<val<IC>> const & field_1, std::optional<elements_t> const & elements, parlex::detail::document::text<literal_0x7C0x5D_t> const & dont_care3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), elements(elements), dont_care3(dont_care3) {}

	LIST(LIST const & other) = default;
	static LIST build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct LOCK {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_lock_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<PARENTHETICAL> field_2;
	
	std::vector<val<IC>> field_3;
	
	val<BLOCK> field_4;
	


	explicit LOCK
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_lock_t> const & dont_care0, std::vector<val<IC>> const & field_1, val<PARENTHETICAL> const & field_2, std::vector<val<IC>> const & field_3, val<BLOCK> const & field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4) {}

	LOCK(LOCK const & other) = default;
	static LOCK build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct LOOP {
	int32_t document_position, consumed_character_count;

	std::variant<
		parlex::detail::document::text<literal_while_t>,
		parlex::detail::document::text<literal_until_t>
	> field_1;
	
	std::vector<val<IC>> field_2;
	
	val<PARENTHETICAL> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit LOOP
		(int32_t documentPosition, int32_t consumedCharacterCount, std::variant<
	parlex::detail::document::text<literal_while_t>,
	parlex::detail::document::text<literal_until_t>
> const & field_1, std::vector<val<IC>> const & field_2, val<PARENTHETICAL> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	LOOP(LOOP const & other) = default;
	static LOOP build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct MAGNITUDE {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0x7C_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<EXPRESSION> field_2;
	
	std::vector<val<IC>> field_3;
	
	parlex::detail::document::text<literal_0x7C_t> dont_care4;
	


	explicit MAGNITUDE
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x7C_t> const & dont_care0, std::vector<val<IC>> const & field_1, val<EXPRESSION> const & field_2, std::vector<val<IC>> const & field_3, parlex::detail::document::text<literal_0x7C_t> const & dont_care4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), field_2(field_2), field_3(field_3), dont_care4(dont_care4) {}

	MAGNITUDE(MAGNITUDE const & other) = default;
	static MAGNITUDE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


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


struct MAPS_TO {
	int32_t document_position, consumed_character_count;

	struct field_1_t {
		parlex::detail::document::text<literal_volatile_t> dont_care0;
		
		val<IC> field_1;
		
		std::vector<val<IC>> field_2;
		
	
	
		explicit field_1_t
			(parlex::detail::document::text<literal_volatile_t> const & dont_care0, val<IC> const & field_1, std::vector<val<IC>> const & field_2)
			: dont_care0(dont_care0), field_1(field_1), field_2(field_2) {}
	
		field_1_t(field_1_t const & other) = default;
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_2_t {
		parlex::detail::document::text<literal_const_t> dont_care0;
		
		val<IC> field_1;
		
		std::vector<val<IC>> field_2;
		
	
	
		explicit field_2_t
			(parlex::detail::document::text<literal_const_t> const & dont_care0, val<IC> const & field_1, std::vector<val<IC>> const & field_2)
			: dont_care0(dont_care0), field_1(field_1), field_2(field_2) {}
	
		field_2_t(field_2_t const & other) = default;
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::optional<field_1_t> field_1;
	
	std::optional<field_2_t> field_2;
	
	val<EXPRESSION> lhs;
	
	std::vector<val<IC>> ic1;
	
	std::variant<
		parlex::detail::document::text<literal_0xE20x860x92_t>,
		parlex::detail::document::text<literal_0x2D0x3E_t>
	> field_3;
	
	std::vector<val<IC>> ic2;
	
	val<EXPRESSION> rhs;
	


	explicit MAPS_TO
		(int32_t documentPosition, int32_t consumedCharacterCount, std::optional<field_1_t> const & field_1, std::optional<field_2_t> const & field_2, val<EXPRESSION> const & lhs, std::vector<val<IC>> const & ic1, std::variant<
	parlex::detail::document::text<literal_0xE20x860x92_t>,
	parlex::detail::document::text<literal_0x2D0x3E_t>
> const & field_3, std::vector<val<IC>> const & ic2, val<EXPRESSION> const & rhs)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), lhs(lhs), ic1(ic1), field_3(field_3), ic2(ic2), rhs(rhs) {}

	MAPS_TO(MAPS_TO const & other) = default;
	static MAPS_TO build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct MEMBER_ACCESS {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x2E_t> dont_care2;
	
	std::vector<val<IC>> field_3;
	
	val<IDENTIFIER> field_4;
	


	explicit MEMBER_ACCESS
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x2E_t> const & dont_care2, std::vector<val<IC>> const & field_3, val<IDENTIFIER> const & field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4) {}

	MEMBER_ACCESS(MEMBER_ACCESS const & other) = default;
	static MEMBER_ACCESS build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct MEMBER_OFFSET {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0x40_t> at;
	
	std::vector<val<IC>> ic;
	
	val<NATURAL_NUMBER> offset;
	


	explicit MEMBER_OFFSET
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x40_t> const & at, std::vector<val<IC>> const & ic, val<NATURAL_NUMBER> const & offset)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), at(at), ic(ic), offset(offset) {}

	MEMBER_OFFSET(MEMBER_OFFSET const & other) = default;
	static MEMBER_OFFSET build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct MODULATION {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x25_t> dont_care2;
	
	std::vector<val<IC>> field_3;
	
	val<EXPRESSION> field_4;
	


	explicit MODULATION
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x25_t> const & dont_care2, std::vector<val<IC>> const & field_3, val<EXPRESSION> const & field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4) {}

	MODULATION(MODULATION const & other) = default;
	static MODULATION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct MODULATION_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x25_t> dont_care2;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit MODULATION_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x25_t> const & dont_care2, std::variant<
	parlex::detail::document::text<literal_0x3C0x2D_t>,
	parlex::detail::document::text<literal_0xE20x860x90_t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	MODULATION_ASSIGNMENT(MODULATION_ASSIGNMENT const & other) = default;
	static MODULATION_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct MULTIPLICATION {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x2A_t> dont_care2;
	
	std::vector<val<IC>> field_3;
	
	val<EXPRESSION> field_4;
	


	explicit MULTIPLICATION
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x2A_t> const & dont_care2, std::vector<val<IC>> const & field_3, val<EXPRESSION> const & field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4) {}

	MULTIPLICATION(MULTIPLICATION const & other) = default;
	static MULTIPLICATION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct MULTIPLICATION_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x2A_t> dont_care2;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit MULTIPLICATION_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x2A_t> const & dont_care2, std::variant<
	parlex::detail::document::text<literal_0x3C0x2D_t>,
	parlex::detail::document::text<literal_0xE20x860x90_t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	MULTIPLICATION_ASSIGNMENT(MULTIPLICATION_ASSIGNMENT const & other) = default;
	static MULTIPLICATION_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


typedef std::variant<
	val<CROSS_PRODUCT>,
	val<DOT_PRODUCT>,
	val<MULTIPLICATION>
> MULTIPLICATIVE_OP_base;

struct MULTIPLICATIVE_OP: MULTIPLICATIVE_OP_base {
	static MULTIPLICATIVE_OP build(parlex::detail::ast_node const & n);
	explicit MULTIPLICATIVE_OP(MULTIPLICATIVE_OP_base const & value) : MULTIPLICATIVE_OP_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
struct NAND {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xE20x860x91_t>,
		parlex::detail::document::text<literal_nand_t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit NAND
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0xE20x860x91_t>,
	parlex::detail::document::text<literal_nand_t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	NAND(NAND const & other) = default;
	static NAND build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct NAND_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xE20x860x91_t>,
		parlex::detail::document::text<literal_nand_t>
	> field_3;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_4;
	
	std::vector<val<IC>> field_5;
	
	val<EXPRESSION> field_6;
	


	explicit NAND_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0xE20x860x91_t>,
	parlex::detail::document::text<literal_nand_t>
> const & field_3, std::variant<
	parlex::detail::document::text<literal_0x3C0x2D_t>,
	parlex::detail::document::text<literal_0xE20x860x90_t>
> const & field_4, std::vector<val<IC>> const & field_5, val<EXPRESSION> const & field_6)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5), field_6(field_6) {}

	NAND_ASSIGNMENT(NAND_ASSIGNMENT const & other) = default;
	static NAND_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct NATURAL_NUMBER {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_1;
	
	std::vector<parlex::detail::document::text<parlex::detail::decimal_digit_t>> field_2;
	


	explicit NATURAL_NUMBER
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_1, std::vector<parlex::detail::document::text<parlex::detail::decimal_digit_t>> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2) {}

	NATURAL_NUMBER(NATURAL_NUMBER const & other) = default;
	static NATURAL_NUMBER build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct NEAREST_INTEGER1_t {
	parlex::detail::document::text<literal_0xE20x8C0x8A_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<EXPRESSION> field_2;
	
	std::vector<val<IC>> field_3;
	
	parlex::detail::document::text<literal_0xE20x8C0x89_t> dont_care4;
	


	explicit NEAREST_INTEGER1_t
		(parlex::detail::document::text<literal_0xE20x8C0x8A_t> const & dont_care0, std::vector<val<IC>> const & field_1, val<EXPRESSION> const & field_2, std::vector<val<IC>> const & field_3, parlex::detail::document::text<literal_0xE20x8C0x89_t> const & dont_care4)
		: dont_care0(dont_care0), field_1(field_1), field_2(field_2), field_3(field_3), dont_care4(dont_care4) {}

	NEAREST_INTEGER1_t(NEAREST_INTEGER1_t const & other) = default;
	static NEAREST_INTEGER1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

struct NEAREST_INTEGER2_t {
	parlex::detail::document::text<literal_0x7C__t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<EXPRESSION> field_2;
	
	std::vector<val<IC>> field_3;
	
	parlex::detail::document::text<literal_0x270x7C_t> dont_care4;
	


	explicit NEAREST_INTEGER2_t
		(parlex::detail::document::text<literal_0x7C__t> const & dont_care0, std::vector<val<IC>> const & field_1, val<EXPRESSION> const & field_2, std::vector<val<IC>> const & field_3, parlex::detail::document::text<literal_0x270x7C_t> const & dont_care4)
		: dont_care0(dont_care0), field_1(field_1), field_2(field_2), field_3(field_3), dont_care4(dont_care4) {}

	NEAREST_INTEGER2_t(NEAREST_INTEGER2_t const & other) = default;
	static NEAREST_INTEGER2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

typedef std::variant<
	NEAREST_INTEGER1_t,
	NEAREST_INTEGER2_t
> NEAREST_INTEGER_base;

struct NEAREST_INTEGER: NEAREST_INTEGER_base {
	static NEAREST_INTEGER build(parlex::detail::ast_node const & n);
	explicit NEAREST_INTEGER(NEAREST_INTEGER_base const & value) : NEAREST_INTEGER_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
struct NEGATION {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0x2D_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<EXPRESSION> field_2;
	


	explicit NEGATION
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x2D_t> const & dont_care0, std::vector<val<IC>> const & field_1, val<EXPRESSION> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), field_2(field_2) {}

	NEGATION(NEGATION const & other) = default;
	static NEGATION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct NEGATION_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x2D_t> dont_care2;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_3;
	


	explicit NEGATION_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x2D_t> const & dont_care2, std::variant<
	parlex::detail::document::text<literal_0x3C0x2D_t>,
	parlex::detail::document::text<literal_0xE20x860x90_t>
> const & field_3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3) {}

	NEGATION_ASSIGNMENT(NEGATION_ASSIGNMENT const & other) = default;
	static NEGATION_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct NON_FRACTIONAL {
	int32_t document_position, consumed_character_count;

	std::optional<parlex::detail::document::text<literal_0x2D_t>> field_1;
	
	val<NON_NEG_NON_FRACTIONAL> field_2;
	


	explicit NON_FRACTIONAL
		(int32_t documentPosition, int32_t consumedCharacterCount, std::optional<parlex::detail::document::text<literal_0x2D_t>> const & field_1, val<NON_NEG_NON_FRACTIONAL> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2) {}

	NON_FRACTIONAL(NON_FRACTIONAL const & other) = default;
	static NON_FRACTIONAL build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct NON_NEG_FRACTIONAL1_t {
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_1;
	
	std::vector<parlex::detail::document::text<parlex::detail::decimal_digit_t>> field_2;
	
	parlex::detail::document::text<literal_0x2E_t> dont_care2;
	
	std::vector<parlex::detail::document::text<parlex::detail::decimal_digit_t>> field_3;
	


	explicit NON_NEG_FRACTIONAL1_t
		(parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_1, std::vector<parlex::detail::document::text<parlex::detail::decimal_digit_t>> const & field_2, parlex::detail::document::text<literal_0x2E_t> const & dont_care2, std::vector<parlex::detail::document::text<parlex::detail::decimal_digit_t>> const & field_3)
		: field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3) {}

	NON_NEG_FRACTIONAL1_t(NON_NEG_FRACTIONAL1_t const & other) = default;
	static NON_NEG_FRACTIONAL1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

struct NON_NEG_FRACTIONAL2_t {
	parlex::detail::document::text<literal_0x2E_t> dont_care0;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_1;
	
	std::vector<parlex::detail::document::text<parlex::detail::decimal_digit_t>> field_2;
	


	explicit NON_NEG_FRACTIONAL2_t
		(parlex::detail::document::text<literal_0x2E_t> const & dont_care0, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_1, std::vector<parlex::detail::document::text<parlex::detail::decimal_digit_t>> const & field_2)
		: dont_care0(dont_care0), field_1(field_1), field_2(field_2) {}

	NON_NEG_FRACTIONAL2_t(NON_NEG_FRACTIONAL2_t const & other) = default;
	static NON_NEG_FRACTIONAL2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

typedef std::variant<
	NON_NEG_FRACTIONAL1_t,
	NON_NEG_FRACTIONAL2_t
> NON_NEG_FRACTIONAL_base;

struct NON_NEG_FRACTIONAL: NON_NEG_FRACTIONAL_base {
	static NON_NEG_FRACTIONAL build(parlex::detail::ast_node const & n);
	explicit NON_NEG_FRACTIONAL(NON_NEG_FRACTIONAL_base const & value) : NON_NEG_FRACTIONAL_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
struct NON_NEG_INTEGER1_t {
	val<NON_ZERO_DECIMAL_DIGIT> field_1;
	
	std::vector<parlex::detail::document::text<parlex::detail::decimal_digit_t>> field_2;
	


	explicit NON_NEG_INTEGER1_t
		(val<NON_ZERO_DECIMAL_DIGIT> const & field_1, std::vector<parlex::detail::document::text<parlex::detail::decimal_digit_t>> const & field_2)
		: field_1(field_1), field_2(field_2) {}

	NON_NEG_INTEGER1_t(NON_NEG_INTEGER1_t const & other) = default;
	static NON_NEG_INTEGER1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

typedef std::variant<
	NON_NEG_INTEGER1_t,
	parlex::detail::document::text<literal_0_t>
> NON_NEG_INTEGER_base;

struct NON_NEG_INTEGER: NON_NEG_INTEGER_base {
	static NON_NEG_INTEGER build(parlex::detail::ast_node const & n);
	explicit NON_NEG_INTEGER(NON_NEG_INTEGER_base const & value) : NON_NEG_INTEGER_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
typedef std::variant<
	val<NON_NEG_INTEGER>,
	val<HEX>,
	val<OCTAL>
> NON_NEG_NON_FRACTIONAL_base;

struct NON_NEG_NON_FRACTIONAL: NON_NEG_NON_FRACTIONAL_base {
	static NON_NEG_NON_FRACTIONAL build(parlex::detail::ast_node const & n);
	explicit NON_NEG_NON_FRACTIONAL(NON_NEG_NON_FRACTIONAL_base const & value) : NON_NEG_NON_FRACTIONAL_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
typedef std::variant<
	val<NON_NEG_NON_FRACTIONAL>,
	val<NON_NEG_FRACTIONAL>
> NON_NEG_NUMBER_base;

struct NON_NEG_NUMBER: NON_NEG_NUMBER_base {
	static NON_NEG_NUMBER build(parlex::detail::ast_node const & n);
	explicit NON_NEG_NUMBER(NON_NEG_NUMBER_base const & value) : NON_NEG_NUMBER_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
typedef std::variant<
	parlex::detail::document::text<literal_1_t>,
	parlex::detail::document::text<literal_2_t>,
	parlex::detail::document::text<literal_3_t>,
	parlex::detail::document::text<literal_4_t>,
	parlex::detail::document::text<literal_5_t>,
	parlex::detail::document::text<literal_6_t>,
	parlex::detail::document::text<literal_7_t>,
	parlex::detail::document::text<literal_8_t>,
	parlex::detail::document::text<literal_9_t>
> NON_ZERO_DECIMAL_DIGIT_base;

struct NON_ZERO_DECIMAL_DIGIT: NON_ZERO_DECIMAL_DIGIT_base {
	static NON_ZERO_DECIMAL_DIGIT build(parlex::detail::ast_node const & n);
	explicit NON_ZERO_DECIMAL_DIGIT(NON_ZERO_DECIMAL_DIGIT_base const & value) : NON_ZERO_DECIMAL_DIGIT_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
struct NOR {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xE20x860x93_t>,
		parlex::detail::document::text<literal_nor_t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit NOR
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0xE20x860x93_t>,
	parlex::detail::document::text<literal_nor_t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	NOR(NOR const & other) = default;
	static NOR build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct NOR_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xE20x860x93_t>,
		parlex::detail::document::text<literal_nor_t>
	> field_3;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_4;
	
	std::vector<val<IC>> field_5;
	
	val<EXPRESSION> field_6;
	


	explicit NOR_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0xE20x860x93_t>,
	parlex::detail::document::text<literal_nor_t>
> const & field_3, std::variant<
	parlex::detail::document::text<literal_0x3C0x2D_t>,
	parlex::detail::document::text<literal_0xE20x860x90_t>
> const & field_4, std::vector<val<IC>> const & field_5, val<EXPRESSION> const & field_6)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5), field_6(field_6) {}

	NOR_ASSIGNMENT(NOR_ASSIGNMENT const & other) = default;
	static NOR_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct NOT {
	int32_t document_position, consumed_character_count;

	std::variant<
		parlex::detail::document::text<literal_0xC20xAC_t>,
		parlex::detail::document::text<literal_0x7E_t>
	> field_1;
	
	std::vector<val<IC>> field_2;
	
	val<EXPRESSION> field_3;
	


	explicit NOT
		(int32_t documentPosition, int32_t consumedCharacterCount, std::variant<
	parlex::detail::document::text<literal_0xC20xAC_t>,
	parlex::detail::document::text<literal_0x7E_t>
> const & field_1, std::vector<val<IC>> const & field_2, val<EXPRESSION> const & field_3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3) {}

	NOT(NOT const & other) = default;
	static NOT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct NOT_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xC20xAC_t>,
		parlex::detail::document::text<literal_0x7E_t>
	> field_3;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_4;
	


	explicit NOT_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0xC20xAC_t>,
	parlex::detail::document::text<literal_0x7E_t>
> const & field_3, std::variant<
	parlex::detail::document::text<literal_0x3C0x2D_t>,
	parlex::detail::document::text<literal_0xE20x860x90_t>
> const & field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4) {}

	NOT_ASSIGNMENT(NOT_ASSIGNMENT const & other) = default;
	static NOT_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct NOT_HAS {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xE20x880x8C_t>,
		parlex::detail::document::text<literal_0x2Fhas_t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit NOT_HAS
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0xE20x880x8C_t>,
	parlex::detail::document::text<literal_0x2Fhas_t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	NOT_HAS(NOT_HAS const & other) = default;
	static NOT_HAS build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct NOT_IN {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xE20x880x89_t>,
		parlex::detail::document::text<literal_0x2Fin_t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit NOT_IN
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0xE20x880x89_t>,
	parlex::detail::document::text<literal_0x2Fin_t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	NOT_IN(NOT_IN const & other) = default;
	static NOT_IN build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct NULL_COALESCE {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x3F0x3F_t> dont_care2;
	
	std::vector<val<IC>> field_3;
	
	val<EXPRESSION> field_4;
	


	explicit NULL_COALESCE
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x3F0x3F_t> const & dont_care2, std::vector<val<IC>> const & field_3, val<EXPRESSION> const & field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4) {}

	NULL_COALESCE(NULL_COALESCE const & other) = default;
	static NULL_COALESCE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct NULL_COALESCE_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x3F0x3F_t> dont_care2;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit NULL_COALESCE_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x3F0x3F_t> const & dont_care2, std::variant<
	parlex::detail::document::text<literal_0x3C0x2D_t>,
	parlex::detail::document::text<literal_0xE20x860x90_t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	NULL_COALESCE_ASSIGNMENT(NULL_COALESCE_ASSIGNMENT const & other) = default;
	static NULL_COALESCE_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct OBJECT {
	int32_t document_position, consumed_character_count;

	struct field_2_t {
		parlex::detail::document::text<literal_inheriting_t> dont_care0;
		
		std::vector<val<IC>> field_1;
		
		val<INHERITANCE_LIST> field_2;
		
		std::vector<val<IC>> field_3;
		
	
	
		explicit field_2_t
			(parlex::detail::document::text<literal_inheriting_t> const & dont_care0, std::vector<val<IC>> const & field_1, val<INHERITANCE_LIST> const & field_2, std::vector<val<IC>> const & field_3)
			: dont_care0(dont_care0), field_1(field_1), field_2(field_2), field_3(field_3) {}
	
		field_2_t(field_2_t const & other) = default;
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_3_t {
		parlex::detail::document::text<literal_implementing_t> dont_care0;
		
		std::vector<val<IC>> field_1;
		
		val<INHERITANCE_LIST> field_2;
		
		std::vector<val<IC>> field_3;
		
	
	
		explicit field_3_t
			(parlex::detail::document::text<literal_implementing_t> const & dont_care0, std::vector<val<IC>> const & field_1, val<INHERITANCE_LIST> const & field_2, std::vector<val<IC>> const & field_3)
			: dont_care0(dont_care0), field_1(field_1), field_2(field_2), field_3(field_3) {}
	
		field_3_t(field_3_t const & other) = default;
		static field_3_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_object_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	std::optional<field_2_t> field_2;
	
	std::optional<field_3_t> field_3;
	
	parlex::detail::document::text<literal_0x7B_t> dont_care4;
	
	val<TYPE_SCOPE> field_4;
	
	parlex::detail::document::text<literal_0x7D_t> dont_care6;
	


	explicit OBJECT
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_object_t> const & dont_care0, std::vector<val<IC>> const & field_1, std::optional<field_2_t> const & field_2, std::optional<field_3_t> const & field_3, parlex::detail::document::text<literal_0x7B_t> const & dont_care4, val<TYPE_SCOPE> const & field_4, parlex::detail::document::text<literal_0x7D_t> const & dont_care6)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), field_2(field_2), field_3(field_3), dont_care4(dont_care4), field_4(field_4), dont_care6(dont_care6) {}

	OBJECT(OBJECT const & other) = default;
	static OBJECT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct OCTAL {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0_t> dont_care0;
	
	parlex::detail::document::text<parlex::detail::octal_digit_t> field_1;
	
	std::vector<parlex::detail::document::text<parlex::detail::octal_digit_t>> field_2;
	


	explicit OCTAL
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0_t> const & dont_care0, parlex::detail::document::text<parlex::detail::octal_digit_t> const & field_1, std::vector<parlex::detail::document::text<parlex::detail::octal_digit_t>> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), field_2(field_2) {}

	OCTAL(OCTAL const & other) = default;
	static OCTAL build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


typedef std::variant<
	val<ADD_SUB_ASSIGNMENT>,
	val<ADDITION_ASSIGNMENT>,
	val<AND_ASSIGNMENT>,
	val<BIT_AND_ASSIGNMENT>,
	val<BIT_NOT_ASSIGNMENT>,
	val<BIT_OR_ASSIGNMENT>,
	val<BIT_XOR_ASSIGNMENT>,
	val<COMPOUND_ASSIGNMENT>,
	val<COMPOSITION_ASSIGNMENT>,
	val<CROSS_PRODUCT_ASSIGNMENT>,
	val<DIVISION_ASSIGNMENT>,
	val<EXPONENTIATION_ASSIGNMENT>,
	val<FACTORIAL_ASSIGNMENT>,
	val<IMPLICATION_ASSIGNMENT>,
	val<INTEGER_DIVISION_ASSIGNMENT>,
	val<INTERSECTION_ASSIGNMENT>,
	val<MODULATION_ASSIGNMENT>,
	val<MULTIPLICATION_ASSIGNMENT>,
	val<NAND_ASSIGNMENT>,
	val<NEGATION_ASSIGNMENT>,
	val<NOR_ASSIGNMENT>,
	val<NOT_ASSIGNMENT>,
	val<NULL_COALESCE_ASSIGNMENT>,
	val<OR_ASSIGNMENT>,
	val<PRE_DEC>,
	val<PRE_INC>,
	val<PREPEND_ASSIGNMENT>,
	val<POST_DEC>,
	val<POST_INC>,
	val<RADICAL_ASSIGNMENT>,
	val<SHIFTL_ASSIGNMENT>,
	val<SHIFTR_ASSIGNMENT>,
	val<SUBTRACTION_ASSIGNMENT>,
	val<SYMMETRIC_DIFFERENCE_ASSIGNMENT>,
	val<UNION_ASSIGNMENT>,
	val<XOR_ASSIGNMENT>
> OP_ASSIGNMENT_base;

struct OP_ASSIGNMENT: OP_ASSIGNMENT_base {
	static OP_ASSIGNMENT build(parlex::detail::ast_node const & n);
	explicit OP_ASSIGNMENT(OP_ASSIGNMENT_base const & value) : OP_ASSIGNMENT_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
struct OR {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xE20x880xA8_t>,
		parlex::detail::document::text<literal_or_t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit OR
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0xE20x880xA8_t>,
	parlex::detail::document::text<literal_or_t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	OR(OR const & other) = default;
	static OR build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct OR_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xE20x880xA8_t>,
		parlex::detail::document::text<literal_or_t>
	> field_3;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_4;
	
	std::vector<val<IC>> field_5;
	
	val<EXPRESSION> field_6;
	


	explicit OR_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0xE20x880xA8_t>,
	parlex::detail::document::text<literal_or_t>
> const & field_3, std::variant<
	parlex::detail::document::text<literal_0x3C0x2D_t>,
	parlex::detail::document::text<literal_0xE20x860x90_t>
> const & field_4, std::vector<val<IC>> const & field_5, val<EXPRESSION> const & field_6)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5), field_6(field_6) {}

	OR_ASSIGNMENT(OR_ASSIGNMENT const & other) = default;
	static OR_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


typedef std::variant<
	val<PARAMETER_NATURAL>,
	val<PARAMETER_ANALYTIC>
> PARAMETER_base;

struct PARAMETER: PARAMETER_base {
	static PARAMETER build(parlex::detail::ast_node const & n);
	explicit PARAMETER(PARAMETER_base const & value) : PARAMETER_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
struct PARAMETER_ANALYTIC {
	int32_t document_position, consumed_character_count;

	struct field_2_t {
		std::vector<val<IC>> field_1;
		
		parlex::detail::document::text<literal_0x3D_t> dont_care1;
		
		std::vector<val<IC>> field_2;
		
		val<EXPRESSION> field_3;
		
	
	
		explicit field_2_t
			(std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_0x3D_t> const & dont_care1, std::vector<val<IC>> const & field_2, val<EXPRESSION> const & field_3)
			: field_1(field_1), dont_care1(dont_care1), field_2(field_2), field_3(field_3) {}
	
		field_2_t(field_2_t const & other) = default;
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	val<EXPRESSION> field_1;
	
	std::optional<field_2_t> field_2;
	


	explicit PARAMETER_ANALYTIC
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::optional<field_2_t> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2) {}

	PARAMETER_ANALYTIC(PARAMETER_ANALYTIC const & other) = default;
	static PARAMETER_ANALYTIC build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct PARAMETER_NATURAL1_t {
	struct field_1_t {
		val<TYPE_DEREFERENCE> field_1;
		
		std::vector<val<IC>> field_2;
		
	
	
		explicit field_1_t
			(val<TYPE_DEREFERENCE> const & field_1, std::vector<val<IC>> const & field_2)
			: field_1(field_1), field_2(field_2) {}
	
		field_1_t(field_1_t const & other) = default;
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::optional<field_1_t> field_1;
	
	val<IDENTIFIER> field_2;
	
	std::optional<parlex::detail::document::text<literal_0x2E0x2E0x2E_t>> field_3;
	


	explicit PARAMETER_NATURAL1_t
		(std::optional<field_1_t> const & field_1, val<IDENTIFIER> const & field_2, std::optional<parlex::detail::document::text<literal_0x2E0x2E0x2E_t>> const & field_3)
		: field_1(field_1), field_2(field_2), field_3(field_3) {}

	PARAMETER_NATURAL1_t(PARAMETER_NATURAL1_t const & other) = default;
	static PARAMETER_NATURAL1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

struct PARAMETER_NATURAL2_t {
	struct field_1_t {
		std::variant<
			val<TYPE_DEREFERENCE>,
			val<IMPLICIT_TYPE_DEREFERENCE>
		> field_1;
		
		std::vector<val<IC>> field_2;
		
	
	
		explicit field_1_t
			(std::variant<
		val<TYPE_DEREFERENCE>,
		val<IMPLICIT_TYPE_DEREFERENCE>
	> const & field_1, std::vector<val<IC>> const & field_2)
			: field_1(field_1), field_2(field_2) {}
	
		field_1_t(field_1_t const & other) = default;
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::optional<field_1_t> field_1;
	
	val<IDENTIFIER> field_2;
	
	std::optional<parlex::detail::document::text<literal_0x2E0x2E0x2E_t>> field_3;
	
	std::vector<val<IC>> field_4;
	
	parlex::detail::document::text<literal_0x3D_t> dont_care4;
	
	std::vector<val<IC>> field_5;
	
	val<EXPRESSION> field_6;
	
	std::optional<parlex::detail::document::text<literal_0x2E0x2E0x2E_t>> field_7;
	


	explicit PARAMETER_NATURAL2_t
		(std::optional<field_1_t> const & field_1, val<IDENTIFIER> const & field_2, std::optional<parlex::detail::document::text<literal_0x2E0x2E0x2E_t>> const & field_3, std::vector<val<IC>> const & field_4, parlex::detail::document::text<literal_0x3D_t> const & dont_care4, std::vector<val<IC>> const & field_5, val<EXPRESSION> const & field_6, std::optional<parlex::detail::document::text<literal_0x2E0x2E0x2E_t>> const & field_7)
		: field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), dont_care4(dont_care4), field_5(field_5), field_6(field_6), field_7(field_7) {}

	PARAMETER_NATURAL2_t(PARAMETER_NATURAL2_t const & other) = default;
	static PARAMETER_NATURAL2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

typedef std::variant<
	PARAMETER_NATURAL1_t,
	PARAMETER_NATURAL2_t
> PARAMETER_NATURAL_base;

struct PARAMETER_NATURAL: PARAMETER_NATURAL_base {
	static PARAMETER_NATURAL build(parlex::detail::ast_node const & n);
	explicit PARAMETER_NATURAL(PARAMETER_NATURAL_base const & value) : PARAMETER_NATURAL_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
struct PARENTHETICAL {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0x28_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<EXPRESSION> field_2;
	
	std::vector<val<IC>> field_3;
	
	parlex::detail::document::text<literal_0x29_t> dont_care4;
	


	explicit PARENTHETICAL
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x28_t> const & dont_care0, std::vector<val<IC>> const & field_1, val<EXPRESSION> const & field_2, std::vector<val<IC>> const & field_3, parlex::detail::document::text<literal_0x29_t> const & dont_care4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), field_2(field_2), field_3(field_3), dont_care4(dont_care4) {}

	PARENTHETICAL(PARENTHETICAL const & other) = default;
	static PARENTHETICAL build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct PARENTHETICAL_INVOCATION {
	int32_t document_position, consumed_character_count;

	struct arguments_t {
		val<STANDARD_ARGUMENTS> standard_arguments;
		
		std::vector<val<IC>> ic;
		
	
	
		explicit arguments_t
			(val<STANDARD_ARGUMENTS> const & standard_arguments, std::vector<val<IC>> const & ic)
			: standard_arguments(standard_arguments), ic(ic) {}
	
		arguments_t(arguments_t const & other) = default;
		static arguments_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_0x28_t> dont_care0;
	
	std::vector<val<IC>> ic;
	
	std::optional<arguments_t> arguments;
	
	parlex::detail::document::text<literal_0x29_t> dont_care3;
	


	explicit PARENTHETICAL_INVOCATION
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x28_t> const & dont_care0, std::vector<val<IC>> const & ic, std::optional<arguments_t> const & arguments, parlex::detail::document::text<literal_0x29_t> const & dont_care3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), ic(ic), arguments(arguments), dont_care3(dont_care3) {}

	PARENTHETICAL_INVOCATION(PARENTHETICAL_INVOCATION const & other) = default;
	static PARENTHETICAL_INVOCATION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct PAYLOAD {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<parlex::detail::all_t> field_1;
	
	std::vector<parlex::detail::document::text<parlex::detail::all_t>> field_2;
	


	explicit PAYLOAD
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<parlex::detail::all_t> const & field_1, std::vector<parlex::detail::document::text<parlex::detail::all_t>> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2) {}

	PAYLOAD(PAYLOAD const & other) = default;
	static PAYLOAD build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct PLATFORM {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal___t> dont_care0;
	
	std::variant<
		parlex::detail::document::text<parlex::detail::letter_t>,
		parlex::detail::document::text<parlex::detail::number_t>
	> field_1;
	
	std::vector<std::variant<
		parlex::detail::document::text<parlex::detail::letter_t>,
		parlex::detail::document::text<parlex::detail::number_t>,
		parlex::detail::document::text<literal___t>
	>> field_2;
	


	explicit PLATFORM
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal___t> const & dont_care0, std::variant<
	parlex::detail::document::text<parlex::detail::letter_t>,
	parlex::detail::document::text<parlex::detail::number_t>
> const & field_1, std::vector<std::variant<
	parlex::detail::document::text<parlex::detail::letter_t>,
	parlex::detail::document::text<parlex::detail::number_t>,
	parlex::detail::document::text<literal___t>
>> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), field_2(field_2) {}

	PLATFORM(PLATFORM const & other) = default;
	static PLATFORM build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct POST_DEC {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x2D0x2D_t> dont_care2;
	


	explicit POST_DEC
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x2D0x2D_t> const & dont_care2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2) {}

	POST_DEC(POST_DEC const & other) = default;
	static POST_DEC build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct POST_INC {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x2B0x2B_t> dont_care2;
	


	explicit POST_INC
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x2B0x2B_t> const & dont_care2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2) {}

	POST_INC(POST_INC const & other) = default;
	static POST_INC build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct PREPEND {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x26_t> dont_care2;
	
	std::vector<val<IC>> field_3;
	
	val<EXPRESSION> field_4;
	


	explicit PREPEND
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x26_t> const & dont_care2, std::vector<val<IC>> const & field_3, val<EXPRESSION> const & field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4) {}

	PREPEND(PREPEND const & other) = default;
	static PREPEND build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct PREPEND_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x26_t> dont_care2;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit PREPEND_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x26_t> const & dont_care2, std::variant<
	parlex::detail::document::text<literal_0x3C0x2D_t>,
	parlex::detail::document::text<literal_0xE20x860x90_t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	PREPEND_ASSIGNMENT(PREPEND_ASSIGNMENT const & other) = default;
	static PREPEND_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct PRE_DEC {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0x2D0x2D_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<EXPRESSION> field_2;
	


	explicit PRE_DEC
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x2D0x2D_t> const & dont_care0, std::vector<val<IC>> const & field_1, val<EXPRESSION> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), field_2(field_2) {}

	PRE_DEC(PRE_DEC const & other) = default;
	static PRE_DEC build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct PRE_INC {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0x2B0x2B_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<EXPRESSION> field_2;
	


	explicit PRE_INC
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x2B0x2B_t> const & dont_care0, std::vector<val<IC>> const & field_1, val<EXPRESSION> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), field_2(field_2) {}

	PRE_INC(PRE_INC const & other) = default;
	static PRE_INC build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct RADICAL {
	int32_t document_position, consumed_character_count;

	std::variant<
		parlex::detail::document::text<literal_0xE20x880x9A_t>,
		parlex::detail::document::text<literal_sqrt_t>
	> field_1;
	
	std::vector<val<IC>> field_2;
	
	val<EXPRESSION> field_3;
	


	explicit RADICAL
		(int32_t documentPosition, int32_t consumedCharacterCount, std::variant<
	parlex::detail::document::text<literal_0xE20x880x9A_t>,
	parlex::detail::document::text<literal_sqrt_t>
> const & field_1, std::vector<val<IC>> const & field_2, val<EXPRESSION> const & field_3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3) {}

	RADICAL(RADICAL const & other) = default;
	static RADICAL build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct RADICAL_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xE20x880x9A_t>,
		parlex::detail::document::text<literal_sqrt_t>
	> field_3;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_4;
	


	explicit RADICAL_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0xE20x880x9A_t>,
	parlex::detail::document::text<literal_sqrt_t>
> const & field_3, std::variant<
	parlex::detail::document::text<literal_0x3C0x2D_t>,
	parlex::detail::document::text<literal_0xE20x860x90_t>
> const & field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4) {}

	RADICAL_ASSIGNMENT(RADICAL_ASSIGNMENT const & other) = default;
	static RADICAL_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct RANGE1_t {
	parlex::detail::document::text<literal_0x28_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	parlex::detail::document::text<literal_0x2E0x2E0x2E_t> dont_care2;
	
	std::vector<val<IC>> field_2;
	
	val<EXPRESSION> field_3;
	
	std::vector<val<IC>> field_4;
	
	std::variant<
		parlex::detail::document::text<literal_0x5D_t>,
		parlex::detail::document::text<literal_0x29_t>
	> field_5;
	


	explicit RANGE1_t
		(parlex::detail::document::text<literal_0x28_t> const & dont_care0, std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_0x2E0x2E0x2E_t> const & dont_care2, std::vector<val<IC>> const & field_2, val<EXPRESSION> const & field_3, std::vector<val<IC>> const & field_4, std::variant<
	parlex::detail::document::text<literal_0x5D_t>,
	parlex::detail::document::text<literal_0x29_t>
> const & field_5)
		: dont_care0(dont_care0), field_1(field_1), dont_care2(dont_care2), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	RANGE1_t(RANGE1_t const & other) = default;
	static RANGE1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

struct RANGE2_t {
	std::variant<
		parlex::detail::document::text<literal_0x5B_t>,
		parlex::detail::document::text<literal_0x28_t>
	> field_1;
	
	std::vector<val<IC>> field_2;
	
	val<EXPRESSION> field_3;
	
	std::vector<val<IC>> field_4;
	
	parlex::detail::document::text<literal_0x2E0x2E0x2E_t> dont_care4;
	
	std::vector<val<IC>> field_5;
	
	parlex::detail::document::text<literal_0x29_t> dont_care6;
	


	explicit RANGE2_t
		(std::variant<
	parlex::detail::document::text<literal_0x5B_t>,
	parlex::detail::document::text<literal_0x28_t>
> const & field_1, std::vector<val<IC>> const & field_2, val<EXPRESSION> const & field_3, std::vector<val<IC>> const & field_4, parlex::detail::document::text<literal_0x2E0x2E0x2E_t> const & dont_care4, std::vector<val<IC>> const & field_5, parlex::detail::document::text<literal_0x29_t> const & dont_care6)
		: field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), dont_care4(dont_care4), field_5(field_5), dont_care6(dont_care6) {}

	RANGE2_t(RANGE2_t const & other) = default;
	static RANGE2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

struct RANGE3_t {
	std::variant<
		parlex::detail::document::text<literal_0x28_t>,
		parlex::detail::document::text<literal_0x5B_t>
	> field_01;
	
	std::vector<val<IC>> field_02;
	
	val<EXPRESSION> field_03;
	
	std::vector<val<IC>> field_04;
	
	parlex::detail::document::text<literal_0x2E0x2E0x2E_t> dont_care4;
	
	std::vector<val<IC>> field_05;
	
	val<EXPRESSION> field_06;
	
	std::vector<val<IC>> field_07;
	
	std::variant<
		parlex::detail::document::text<literal_0x5D_t>,
		parlex::detail::document::text<literal_0x29_t>
	> field_08;
	


	explicit RANGE3_t
		(std::variant<
	parlex::detail::document::text<literal_0x28_t>,
	parlex::detail::document::text<literal_0x5B_t>
> const & field_01, std::vector<val<IC>> const & field_02, val<EXPRESSION> const & field_03, std::vector<val<IC>> const & field_04, parlex::detail::document::text<literal_0x2E0x2E0x2E_t> const & dont_care4, std::vector<val<IC>> const & field_05, val<EXPRESSION> const & field_06, std::vector<val<IC>> const & field_07, std::variant<
	parlex::detail::document::text<literal_0x5D_t>,
	parlex::detail::document::text<literal_0x29_t>
> const & field_08)
		: field_01(field_01), field_02(field_02), field_03(field_03), field_04(field_04), dont_care4(dont_care4), field_05(field_05), field_06(field_06), field_07(field_07), field_08(field_08) {}

	RANGE3_t(RANGE3_t const & other) = default;
	static RANGE3_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

typedef std::variant<
	RANGE1_t,
	RANGE2_t,
	RANGE3_t
> RANGE_base;

struct RANGE: RANGE_base {
	static RANGE build(parlex::detail::ast_node const & n);
	explicit RANGE(RANGE_base const & value) : RANGE_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
struct READ_LOCK {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_read_lock_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<PARENTHETICAL> field_2;
	
	std::vector<val<IC>> field_3;
	
	val<EXPRESSION> field_4;
	


	explicit READ_LOCK
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_read_lock_t> const & dont_care0, std::vector<val<IC>> const & field_1, val<PARENTHETICAL> const & field_2, std::vector<val<IC>> const & field_3, val<EXPRESSION> const & field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4) {}

	READ_LOCK(READ_LOCK const & other) = default;
	static READ_LOCK build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct RECORD {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_record_t> dont_care0;
	
	val<IC> field_1;
	
	std::vector<val<IC>> field_2;
	
	val<TYPE> field_3;
	


	explicit RECORD
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_record_t> const & dont_care0, val<IC> const & field_1, std::vector<val<IC>> const & field_2, val<TYPE> const & field_3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), field_2(field_2), field_3(field_3) {}

	RECORD(RECORD const & other) = default;
	static RECORD build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct REGEX {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_R_t> dont_care0;
	
	parlex::detail::document::text<void> field_1;
	


	explicit REGEX
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_R_t> const & dont_care0, parlex::detail::document::text<void> const & field_1)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1) {}

	REGEX(REGEX const & other) = default;
	static REGEX build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


typedef std::variant<
	val<HAS>,
	val<IN>,
	val<NOT_HAS>,
	val<NOT_IN>
> RELATIONAL_COLLECTION_OP_base;

struct RELATIONAL_COLLECTION_OP: RELATIONAL_COLLECTION_OP_base {
	static RELATIONAL_COLLECTION_OP build(parlex::detail::ast_node const & n);
	explicit RELATIONAL_COLLECTION_OP(RELATIONAL_COLLECTION_OP_base const & value) : RELATIONAL_COLLECTION_OP_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
typedef std::variant<
	val<CASTS>,
	val<DOWNCASTS>,
	val<EXACTLY>,
	val<IMPLEMENTS>,
	val<INEQUALITY>,
	val<INHERITS>,
	val<IS>,
	val<RELATIONAL_COLLECTION_OP>,
	val<UPCASTS>
> RELATIONAL_OP_base;

struct RELATIONAL_OP: RELATIONAL_OP_base {
	static RELATIONAL_OP build(parlex::detail::ast_node const & n);
	explicit RELATIONAL_OP(RELATIONAL_OP_base const & value) : RELATIONAL_OP_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
struct RETURN {
	int32_t document_position, consumed_character_count;

	struct field_1_t {
		std::vector<val<IC>> field_1;
		
		parlex::detail::document::text<literal_0x5B_t> dont_care1;
		
		std::vector<val<IC>> field_2;
		
		val<EXPRESSION> field_3;
		
		std::vector<val<IC>> field_4;
		
		parlex::detail::document::text<literal_0x5D_t> dont_care5;
		
	
	
		explicit field_1_t
			(std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_0x5B_t> const & dont_care1, std::vector<val<IC>> const & field_2, val<EXPRESSION> const & field_3, std::vector<val<IC>> const & field_4, parlex::detail::document::text<literal_0x5D_t> const & dont_care5)
			: field_1(field_1), dont_care1(dont_care1), field_2(field_2), field_3(field_3), field_4(field_4), dont_care5(dont_care5) {}
	
		field_1_t(field_1_t const & other) = default;
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_2_t {
		std::vector<val<IC>> field_1;
		
		val<EXPRESSION> field_2;
		
	
	
		explicit field_2_t
			(std::vector<val<IC>> const & field_1, val<EXPRESSION> const & field_2)
			: field_1(field_1), field_2(field_2) {}
	
		field_2_t(field_2_t const & other) = default;
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_return_t> dont_care0;
	
	std::optional<field_1_t> field_1;
	
	std::optional<field_2_t> field_2;
	


	explicit RETURN
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_return_t> const & dont_care0, std::optional<field_1_t> const & field_1, std::optional<field_2_t> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), field_2(field_2) {}

	RETURN(RETURN const & other) = default;
	static RETURN build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct SET {
	int32_t document_position, consumed_character_count;

	struct elements_t {
		struct field_2_t {
			std::vector<val<IC>> field_1;
			
			parlex::detail::document::text<literal_0x2C_t> dont_care1;
			
			std::vector<val<IC>> field_2;
			
			val<EXPRESSION> field_3;
			
		
		
			explicit field_2_t
				(std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_0x2C_t> const & dont_care1, std::vector<val<IC>> const & field_2, val<EXPRESSION> const & field_3)
				: field_1(field_1), dont_care1(dont_care1), field_2(field_2), field_3(field_3) {}
		
			field_2_t(field_2_t const & other) = default;
			static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		val<EXPRESSION> field_1;
		
		std::vector<field_2_t> field_2;
		
		std::vector<val<IC>> field_3;
		
	
	
		explicit elements_t
			(val<EXPRESSION> const & field_1, std::vector<field_2_t> const & field_2, std::vector<val<IC>> const & field_3)
			: field_1(field_1), field_2(field_2), field_3(field_3) {}
	
		elements_t(elements_t const & other) = default;
		static elements_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_0x7B0x7C_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	std::optional<elements_t> elements;
	
	parlex::detail::document::text<literal_0x7C0x7D_t> dont_care3;
	


	explicit SET
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x7B0x7C_t> const & dont_care0, std::vector<val<IC>> const & field_1, std::optional<elements_t> const & elements, parlex::detail::document::text<literal_0x7C0x7D_t> const & dont_care3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), elements(elements), dont_care3(dont_care3) {}

	SET(SET const & other) = default;
	static SET build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct SET_COMPREHENSION {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0x7B_t> dont_care0;
	
	std::vector<val<IC>> field_01;
	
	val<EXPRESSION> field_02;
	
	std::vector<val<IC>> field_03;
	
	parlex::detail::document::text<literal_0x7C_t> dont_care4;
	
	std::vector<val<IC>> field_04;
	
	val<EXPRESSION> field_05;
	
	std::vector<val<IC>> field_06;
	
	parlex::detail::document::text<literal_0x7D_t> dont_care8;
	


	explicit SET_COMPREHENSION
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x7B_t> const & dont_care0, std::vector<val<IC>> const & field_01, val<EXPRESSION> const & field_02, std::vector<val<IC>> const & field_03, parlex::detail::document::text<literal_0x7C_t> const & dont_care4, std::vector<val<IC>> const & field_04, val<EXPRESSION> const & field_05, std::vector<val<IC>> const & field_06, parlex::detail::document::text<literal_0x7D_t> const & dont_care8)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_01(field_01), field_02(field_02), field_03(field_03), dont_care4(dont_care4), field_04(field_04), field_05(field_05), field_06(field_06), dont_care8(dont_care8) {}

	SET_COMPREHENSION(SET_COMPREHENSION const & other) = default;
	static SET_COMPREHENSION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct SHIFTL {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x3C0x3C_t> dont_care2;
	
	std::vector<val<IC>> field_3;
	
	val<EXPRESSION> field_4;
	


	explicit SHIFTL
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x3C0x3C_t> const & dont_care2, std::vector<val<IC>> const & field_3, val<EXPRESSION> const & field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4) {}

	SHIFTL(SHIFTL const & other) = default;
	static SHIFTL build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct SHIFTL_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x3C0x3C_t> dont_care2;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit SHIFTL_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x3C0x3C_t> const & dont_care2, std::variant<
	parlex::detail::document::text<literal_0x3C0x2D_t>,
	parlex::detail::document::text<literal_0xE20x860x90_t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	SHIFTL_ASSIGNMENT(SHIFTL_ASSIGNMENT const & other) = default;
	static SHIFTL_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct SHIFTR {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x3E0x3E_t> dont_care2;
	
	std::vector<val<IC>> field_3;
	
	val<EXPRESSION> field_4;
	


	explicit SHIFTR
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x3E0x3E_t> const & dont_care2, std::vector<val<IC>> const & field_3, val<EXPRESSION> const & field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4) {}

	SHIFTR(SHIFTR const & other) = default;
	static SHIFTR build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct SHIFTR_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x3E0x3E_t> dont_care2;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit SHIFTR_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x3E0x3E_t> const & dont_care2, std::variant<
	parlex::detail::document::text<literal_0x3C0x2D_t>,
	parlex::detail::document::text<literal_0xE20x860x90_t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	SHIFTR_ASSIGNMENT(SHIFTR_ASSIGNMENT const & other) = default;
	static SHIFTR_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct SLICE {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x3A_t> dont_care2;
	
	std::vector<val<IC>> field_3;
	
	val<EXPRESSION> field_4;
	


	explicit SLICE
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x3A_t> const & dont_care2, std::vector<val<IC>> const & field_3, val<EXPRESSION> const & field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4) {}

	SLICE(SLICE const & other) = default;
	static SLICE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct STANDARD_ARGUMENTS {
	int32_t document_position, consumed_character_count;

	struct tail_t {
		struct field_1_t {
			std::vector<val<IC>> ic;
			
			std::variant<
				val<EXPRESSION>,
				val<ARGUMENT_PACK>
			> argument;
			
		
		
			explicit field_1_t
				(std::vector<val<IC>> const & ic, std::variant<
			val<EXPRESSION>,
			val<ARGUMENT_PACK>
		> const & argument)
				: ic(ic), argument(argument) {}
		
			field_1_t(field_1_t const & other) = default;
			static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		std::vector<val<IC>> ic;
		
		parlex::detail::document::text<literal_0x2C_t> dont_care1;
		
		std::optional<field_1_t> field_1;
		
	
	
		explicit tail_t
			(std::vector<val<IC>> const & ic, parlex::detail::document::text<literal_0x2C_t> const & dont_care1, std::optional<field_1_t> const & field_1)
			: ic(ic), dont_care1(dont_care1), field_1(field_1) {}
	
		tail_t(tail_t const & other) = default;
		static tail_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::optional<std::variant<
		val<EXPRESSION>,
		val<ARGUMENT_PACK>
	>> head;
	
	std::vector<tail_t> tail;
	


	explicit STANDARD_ARGUMENTS
		(int32_t documentPosition, int32_t consumedCharacterCount, std::optional<std::variant<
	val<EXPRESSION>,
	val<ARGUMENT_PACK>
>> const & head, std::vector<tail_t> const & tail)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), head(head), tail(tail) {}

	STANDARD_ARGUMENTS(STANDARD_ARGUMENTS const & other) = default;
	static STANDARD_ARGUMENTS build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct STATEMENT {
	int32_t document_position, consumed_character_count;

	std::variant<
		val<ASSIGNMENT>,
		val<BREAK>,
		val<CONTINUE>,
		val<DEFINITION>,
		val<DO>,
		val<EXPRESSION>,
		val<FOR>,
		val<FOR_COLLECTION>,
		val<FREE>,
		val<IMPORT>,
		val<LOCK>,
		val<LOOP>,
		val<OP_ASSIGNMENT>,
		val<READ_LOCK>,
		val<RETURN>,
		val<THROW>,
		val<TRY>,
		val<TYPE_CONSTRAINT>,
		val<WRITE_LOCK>,
		val<USING>
	> value;
	
	std::vector<val<IC>> ic;
	
	parlex::detail::document::text<literal_0x3B_t> dont_care2;
	


	explicit STATEMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, std::variant<
	val<ASSIGNMENT>,
	val<BREAK>,
	val<CONTINUE>,
	val<DEFINITION>,
	val<DO>,
	val<EXPRESSION>,
	val<FOR>,
	val<FOR_COLLECTION>,
	val<FREE>,
	val<IMPORT>,
	val<LOCK>,
	val<LOOP>,
	val<OP_ASSIGNMENT>,
	val<READ_LOCK>,
	val<RETURN>,
	val<THROW>,
	val<TRY>,
	val<TYPE_CONSTRAINT>,
	val<WRITE_LOCK>,
	val<USING>
> const & value, std::vector<val<IC>> const & ic, parlex::detail::document::text<literal_0x3B_t> const & dont_care2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), value(value), ic(ic), dont_care2(dont_care2) {}

	STATEMENT(STATEMENT const & other) = default;
	static STATEMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


typedef std::vector<std::variant<
	val<IC>,
	val<STATEMENT>
>> STATEMENT_SCOPE_base;

struct STATEMENT_SCOPE: STATEMENT_SCOPE_base {
	static STATEMENT_SCOPE build(parlex::detail::ast_node const & n);
	explicit STATEMENT_SCOPE(STATEMENT_SCOPE_base const & value) : STATEMENT_SCOPE_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
struct SUBSET {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> expression;
	
	std::vector<val<IC>> ic;
	
	val<SUBSET_NODE> subset_node;
	


	explicit SUBSET
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & expression, std::vector<val<IC>> const & ic, val<SUBSET_NODE> const & subset_node)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), expression(expression), ic(ic), subset_node(subset_node) {}

	SUBSET(SUBSET const & other) = default;
	static SUBSET build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct SUBSET_NODE {
	int32_t document_position, consumed_character_count;

	struct field_2_t {
		std::vector<val<IC>> ic;
		
		val<SUBSET_NODE> subset_node;
		
	
	
		explicit field_2_t
			(std::vector<val<IC>> const & ic, val<SUBSET_NODE> const & subset_node)
			: ic(ic), subset_node(subset_node) {}
	
		field_2_t(field_2_t const & other) = default;
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::variant<
		parlex::detail::document::text<literal_0x3D_t>,
		parlex::detail::document::text<literal_0xE20x8A0x86_t>,
		parlex::detail::document::text<literal_subs_t>,
		parlex::detail::document::text<literal_0xE20x8A0x82_t>,
		parlex::detail::document::text<literal_psubs_t>
	> field_1;
	
	std::vector<val<IC>> ic;
	
	val<EXPRESSION> expression;
	
	std::optional<field_2_t> field_2;
	


	explicit SUBSET_NODE
		(int32_t documentPosition, int32_t consumedCharacterCount, std::variant<
	parlex::detail::document::text<literal_0x3D_t>,
	parlex::detail::document::text<literal_0xE20x8A0x86_t>,
	parlex::detail::document::text<literal_subs_t>,
	parlex::detail::document::text<literal_0xE20x8A0x82_t>,
	parlex::detail::document::text<literal_psubs_t>
> const & field_1, std::vector<val<IC>> const & ic, val<EXPRESSION> const & expression, std::optional<field_2_t> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), ic(ic), expression(expression), field_2(field_2) {}

	SUBSET_NODE(SUBSET_NODE const & other) = default;
	static SUBSET_NODE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct SUBTRACTION {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x2D_t> dont_care2;
	
	std::vector<val<IC>> field_3;
	
	val<EXPRESSION> field_4;
	


	explicit SUBTRACTION
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x2D_t> const & dont_care2, std::vector<val<IC>> const & field_3, val<EXPRESSION> const & field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4) {}

	SUBTRACTION(SUBTRACTION const & other) = default;
	static SUBTRACTION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct SUBTRACTION_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x2D_t> dont_care2;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit SUBTRACTION_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x2D_t> const & dont_care2, std::variant<
	parlex::detail::document::text<literal_0x3C0x2D_t>,
	parlex::detail::document::text<literal_0xE20x860x90_t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	SUBTRACTION_ASSIGNMENT(SUBTRACTION_ASSIGNMENT const & other) = default;
	static SUBTRACTION_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct SUPERSET {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> expression;
	
	std::vector<val<IC>> ic;
	
	val<SUPERSET_NODE> superset_node;
	


	explicit SUPERSET
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & expression, std::vector<val<IC>> const & ic, val<SUPERSET_NODE> const & superset_node)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), expression(expression), ic(ic), superset_node(superset_node) {}

	SUPERSET(SUPERSET const & other) = default;
	static SUPERSET build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct SUPERSET_NODE {
	int32_t document_position, consumed_character_count;

	struct field_2_t {
		std::vector<val<IC>> ic;
		
		val<SUPERSET_NODE> superset_node;
		
	
	
		explicit field_2_t
			(std::vector<val<IC>> const & ic, val<SUPERSET_NODE> const & superset_node)
			: ic(ic), superset_node(superset_node) {}
	
		field_2_t(field_2_t const & other) = default;
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::variant<
		parlex::detail::document::text<literal_0x3D_t>,
		parlex::detail::document::text<literal_0xE20x8A0x87_t>,
		parlex::detail::document::text<literal_sups_t>,
		parlex::detail::document::text<literal_0xE20x8A0x83_t>,
		parlex::detail::document::text<literal_psups_t>
	> field_1;
	
	std::vector<val<IC>> ic;
	
	val<EXPRESSION> expression;
	
	std::optional<field_2_t> field_2;
	


	explicit SUPERSET_NODE
		(int32_t documentPosition, int32_t consumedCharacterCount, std::variant<
	parlex::detail::document::text<literal_0x3D_t>,
	parlex::detail::document::text<literal_0xE20x8A0x87_t>,
	parlex::detail::document::text<literal_sups_t>,
	parlex::detail::document::text<literal_0xE20x8A0x83_t>,
	parlex::detail::document::text<literal_psups_t>
> const & field_1, std::vector<val<IC>> const & ic, val<EXPRESSION> const & expression, std::optional<field_2_t> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), ic(ic), expression(expression), field_2(field_2) {}

	SUPERSET_NODE(SUPERSET_NODE const & other) = default;
	static SUPERSET_NODE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct SWIZZLE {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xE20x8B0xAE_t>,
		parlex::detail::document::text<literal__swiz__t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit SWIZZLE
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0xE20x8B0xAE_t>,
	parlex::detail::document::text<literal__swiz__t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	SWIZZLE(SWIZZLE const & other) = default;
	static SWIZZLE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct SYMMETRIC_DIFFERENCE {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0xE20x8A0x96_t> dont_care2;
	
	std::vector<val<IC>> field_3;
	
	val<EXPRESSION> field_4;
	


	explicit SYMMETRIC_DIFFERENCE
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0xE20x8A0x96_t> const & dont_care2, std::vector<val<IC>> const & field_3, val<EXPRESSION> const & field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4) {}

	SYMMETRIC_DIFFERENCE(SYMMETRIC_DIFFERENCE const & other) = default;
	static SYMMETRIC_DIFFERENCE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct SYMMETRIC_DIFFERENCE_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0xE20x8A0x96_t> dont_care2;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit SYMMETRIC_DIFFERENCE_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0xE20x8A0x96_t> const & dont_care2, std::variant<
	parlex::detail::document::text<literal_0x3C0x2D_t>,
	parlex::detail::document::text<literal_0xE20x860x90_t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	SYMMETRIC_DIFFERENCE_ASSIGNMENT(SYMMETRIC_DIFFERENCE_ASSIGNMENT const & other) = default;
	static SYMMETRIC_DIFFERENCE_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct THIS {
	int32_t document_position, consumed_character_count;

	struct field_1_t {
		std::vector<val<IC>> field_1;
		
		parlex::detail::document::text<literal_0x5B_t> dont_care1;
		
		std::vector<val<IC>> field_2;
		
		val<EXPRESSION> field_3;
		
		std::vector<val<IC>> field_4;
		
		parlex::detail::document::text<literal_0x5D_t> dont_care5;
		
	
	
		explicit field_1_t
			(std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_0x5B_t> const & dont_care1, std::vector<val<IC>> const & field_2, val<EXPRESSION> const & field_3, std::vector<val<IC>> const & field_4, parlex::detail::document::text<literal_0x5D_t> const & dont_care5)
			: field_1(field_1), dont_care1(dont_care1), field_2(field_2), field_3(field_3), field_4(field_4), dont_care5(dont_care5) {}
	
		field_1_t(field_1_t const & other) = default;
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_this_t> dont_care0;
	
	std::optional<field_1_t> field_1;
	


	explicit THIS
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_this_t> const & dont_care0, std::optional<field_1_t> const & field_1)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1) {}

	THIS(THIS const & other) = default;
	static THIS build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct THIS_FUNC {
	int32_t document_position, consumed_character_count;

	struct field_1_t {
		std::vector<val<IC>> field_1;
		
		parlex::detail::document::text<literal_0x5B_t> dont_care1;
		
		std::vector<val<IC>> field_2;
		
		val<EXPRESSION> field_3;
		
		std::vector<val<IC>> field_4;
		
		parlex::detail::document::text<literal_0x5D_t> dont_care5;
		
	
	
		explicit field_1_t
			(std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_0x5B_t> const & dont_care1, std::vector<val<IC>> const & field_2, val<EXPRESSION> const & field_3, std::vector<val<IC>> const & field_4, parlex::detail::document::text<literal_0x5D_t> const & dont_care5)
			: field_1(field_1), dont_care1(dont_care1), field_2(field_2), field_3(field_3), field_4(field_4), dont_care5(dont_care5) {}
	
		field_1_t(field_1_t const & other) = default;
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_this_func_t> dont_care0;
	
	std::optional<field_1_t> field_1;
	


	explicit THIS_FUNC
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_this_func_t> const & dont_care0, std::optional<field_1_t> const & field_1)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1) {}

	THIS_FUNC(THIS_FUNC const & other) = default;
	static THIS_FUNC build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct THIS_TYPE {
	int32_t document_position, consumed_character_count;

	struct field_1_t {
		std::vector<val<IC>> field_1;
		
		parlex::detail::document::text<literal_0x5B_t> dont_care1;
		
		std::vector<val<IC>> field_2;
		
		val<EXPRESSION> field_3;
		
		std::vector<val<IC>> field_4;
		
		parlex::detail::document::text<literal_0x5D_t> dont_care5;
		
	
	
		explicit field_1_t
			(std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_0x5B_t> const & dont_care1, std::vector<val<IC>> const & field_2, val<EXPRESSION> const & field_3, std::vector<val<IC>> const & field_4, parlex::detail::document::text<literal_0x5D_t> const & dont_care5)
			: field_1(field_1), dont_care1(dont_care1), field_2(field_2), field_3(field_3), field_4(field_4), dont_care5(dont_care5) {}
	
		field_1_t(field_1_t const & other) = default;
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_this_type_t> dont_care0;
	
	std::optional<field_1_t> field_1;
	


	explicit THIS_TYPE
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_this_type_t> const & dont_care0, std::optional<field_1_t> const & field_1)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1) {}

	THIS_TYPE(THIS_TYPE const & other) = default;
	static THIS_TYPE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct THROW {
	int32_t document_position, consumed_character_count;

	struct field_1_t {
		std::vector<val<IC>> field_1;
		
		parlex::detail::document::text<literal_0x5B_t> dont_care1;
		
		std::vector<val<IC>> field_2;
		
		val<EXPRESSION> field_3;
		
		std::vector<val<IC>> field_4;
		
		parlex::detail::document::text<literal_0x5D_t> dont_care5;
		
	
	
		explicit field_1_t
			(std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_0x5B_t> const & dont_care1, std::vector<val<IC>> const & field_2, val<EXPRESSION> const & field_3, std::vector<val<IC>> const & field_4, parlex::detail::document::text<literal_0x5D_t> const & dont_care5)
			: field_1(field_1), dont_care1(dont_care1), field_2(field_2), field_3(field_3), field_4(field_4), dont_care5(dont_care5) {}
	
		field_1_t(field_1_t const & other) = default;
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_2_t {
		std::vector<val<IC>> field_1;
		
		val<EXPRESSION> field_2;
		
	
	
		explicit field_2_t
			(std::vector<val<IC>> const & field_1, val<EXPRESSION> const & field_2)
			: field_1(field_1), field_2(field_2) {}
	
		field_2_t(field_2_t const & other) = default;
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_throw_t> dont_care0;
	
	std::optional<field_1_t> field_1;
	
	std::optional<field_2_t> field_2;
	


	explicit THROW
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_throw_t> const & dont_care0, std::optional<field_1_t> const & field_1, std::optional<field_2_t> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), field_2(field_2) {}

	THROW(THROW const & other) = default;
	static THROW build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct TIME {
	int32_t document_position, consumed_character_count;

	struct field_08_t {
		parlex::detail::document::text<literal_0x2E_t> dont_care0;
		
		parlex::detail::document::text<parlex::detail::decimal_digit_t> field_1;
		
		std::vector<parlex::detail::document::text<parlex::detail::decimal_digit_t>> field_2;
		
	
	
		explicit field_08_t
			(parlex::detail::document::text<literal_0x2E_t> const & dont_care0, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_1, std::vector<parlex::detail::document::text<parlex::detail::decimal_digit_t>> const & field_2)
			: dont_care0(dont_care0), field_1(field_1), field_2(field_2) {}
	
		field_08_t(field_08_t const & other) = default;
		static field_08_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_09_t2 {
		struct field_4_t {
			parlex::detail::document::text<literal_0x3A_t> dont_care0;
			
			parlex::detail::document::text<parlex::detail::decimal_digit_t> field_1;
			
			parlex::detail::document::text<parlex::detail::decimal_digit_t> field_2;
			
		
		
			explicit field_4_t
				(parlex::detail::document::text<literal_0x3A_t> const & dont_care0, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_1, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_2)
				: dont_care0(dont_care0), field_1(field_1), field_2(field_2) {}
		
			field_4_t(field_4_t const & other) = default;
			static field_4_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		std::variant<
			parlex::detail::document::text<literal_0x2B_t>,
			parlex::detail::document::text<literal_0x2D_t>
		> field_1;
		
		parlex::detail::document::text<parlex::detail::decimal_digit_t> field_2;
		
		parlex::detail::document::text<parlex::detail::decimal_digit_t> field_3;
		
		std::optional<field_4_t> field_4;
		
	
	
		explicit field_09_t2
			(std::variant<
		parlex::detail::document::text<literal_0x2B_t>,
		parlex::detail::document::text<literal_0x2D_t>
	> const & field_1, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_2, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_3, std::optional<field_4_t> const & field_4)
			: field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4) {}
	
		field_09_t2(field_09_t2 const & other) = default;
		static field_09_t2 build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::optional<parlex::detail::document::text<literal_0x2D_t>> field_01;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_02;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_03;
	
	parlex::detail::document::text<literal_0x3A_t> dont_care3;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_04;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_05;
	
	parlex::detail::document::text<literal_0x3A_t> dont_care6;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_06;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_07;
	
	std::optional<field_08_t> field_08;
	
	std::optional<std::variant<
		parlex::detail::document::text<literal_Z_t>,
		field_09_t2
	>> field_09;
	


	explicit TIME
		(int32_t documentPosition, int32_t consumedCharacterCount, std::optional<parlex::detail::document::text<literal_0x2D_t>> const & field_01, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_02, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_03, parlex::detail::document::text<literal_0x3A_t> const & dont_care3, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_04, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_05, parlex::detail::document::text<literal_0x3A_t> const & dont_care6, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_06, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_07, std::optional<field_08_t> const & field_08, std::optional<std::variant<
	parlex::detail::document::text<literal_Z_t>,
	field_09_t2
>> const & field_09)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_01(field_01), field_02(field_02), field_03(field_03), dont_care3(dont_care3), field_04(field_04), field_05(field_05), dont_care6(dont_care6), field_06(field_06), field_07(field_07), field_08(field_08), field_09(field_09) {}

	TIME(TIME const & other) = default;
	static TIME build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct TRY {
	int32_t document_position, consumed_character_count;

	struct field_06_t {
		parlex::detail::document::text<literal_catch_t> dont_care0;
		
		std::vector<val<IC>> field_1;
		
		val<EXPRESSION> field_2;
		
	
	
		explicit field_06_t
			(parlex::detail::document::text<literal_catch_t> const & dont_care0, std::vector<val<IC>> const & field_1, val<EXPRESSION> const & field_2)
			: dont_care0(dont_care0), field_1(field_1), field_2(field_2) {}
	
		field_06_t(field_06_t const & other) = default;
		static field_06_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_07_t {
		std::vector<val<IC>> field_1;
		
		parlex::detail::document::text<literal_finally_t> dont_care1;
		
		std::vector<val<IC>> field_2;
		
		val<EXPRESSION> field_3;
		
	
	
		explicit field_07_t
			(std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_finally_t> const & dont_care1, std::vector<val<IC>> const & field_2, val<EXPRESSION> const & field_3)
			: field_1(field_1), dont_care1(dont_care1), field_2(field_2), field_3(field_3) {}
	
		field_07_t(field_07_t const & other) = default;
		static field_07_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_try_t> dont_care0;
	
	std::vector<val<IC>> field_01;
	
	val<EXPRESSION> field_02;
	
	std::vector<val<IC>> field_03;
	
	parlex::detail::document::text<literal_catch_t> dont_care4;
	
	std::vector<val<IC>> field_04;
	
	val<EXPRESSION> field_05;
	
	std::vector<field_06_t> field_06;
	
	std::optional<field_07_t> field_07;
	


	explicit TRY
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_try_t> const & dont_care0, std::vector<val<IC>> const & field_01, val<EXPRESSION> const & field_02, std::vector<val<IC>> const & field_03, parlex::detail::document::text<literal_catch_t> const & dont_care4, std::vector<val<IC>> const & field_04, val<EXPRESSION> const & field_05, std::vector<field_06_t> const & field_06, std::optional<field_07_t> const & field_07)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_01(field_01), field_02(field_02), field_03(field_03), dont_care4(dont_care4), field_04(field_04), field_05(field_05), field_06(field_06), field_07(field_07) {}

	TRY(TRY const & other) = default;
	static TRY build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct TUPLE {
	int32_t document_position, consumed_character_count;

	struct field_3_t {
		std::vector<val<IC>> field_1;
		
		parlex::detail::document::text<literal_0x2C_t> dont_care1;
		
		std::vector<val<IC>> field_2;
		
		val<EXPRESSION> field_3;
		
	
	
		explicit field_3_t
			(std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_0x2C_t> const & dont_care1, std::vector<val<IC>> const & field_2, val<EXPRESSION> const & field_3)
			: field_1(field_1), dont_care1(dont_care1), field_2(field_2), field_3(field_3) {}
	
		field_3_t(field_3_t const & other) = default;
		static field_3_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_0x280x7C_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<EXPRESSION> field_2;
	
	std::vector<field_3_t> field_3;
	
	std::vector<val<IC>> field_4;
	
	parlex::detail::document::text<literal_0x7C0x29_t> dont_care5;
	


	explicit TUPLE
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x280x7C_t> const & dont_care0, std::vector<val<IC>> const & field_1, val<EXPRESSION> const & field_2, std::vector<field_3_t> const & field_3, std::vector<val<IC>> const & field_4, parlex::detail::document::text<literal_0x7C0x29_t> const & dont_care5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), dont_care5(dont_care5) {}

	TUPLE(TUPLE const & other) = default;
	static TUPLE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct TYPE {
	int32_t document_position, consumed_character_count;

	struct field_2_t {
		parlex::detail::document::text<literal_inheriting_t> dont_care0;
		
		std::vector<val<IC>> field_1;
		
		val<INHERITANCE_LIST> field_2;
		
		std::vector<val<IC>> field_3;
		
	
	
		explicit field_2_t
			(parlex::detail::document::text<literal_inheriting_t> const & dont_care0, std::vector<val<IC>> const & field_1, val<INHERITANCE_LIST> const & field_2, std::vector<val<IC>> const & field_3)
			: dont_care0(dont_care0), field_1(field_1), field_2(field_2), field_3(field_3) {}
	
		field_2_t(field_2_t const & other) = default;
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_3_t {
		parlex::detail::document::text<literal_implementing_t> dont_care0;
		
		std::vector<val<IC>> field_1;
		
		val<INHERITANCE_LIST> field_2;
		
		std::vector<val<IC>> field_3;
		
	
	
		explicit field_3_t
			(parlex::detail::document::text<literal_implementing_t> const & dont_care0, std::vector<val<IC>> const & field_1, val<INHERITANCE_LIST> const & field_2, std::vector<val<IC>> const & field_3)
			: dont_care0(dont_care0), field_1(field_1), field_2(field_2), field_3(field_3) {}
	
		field_3_t(field_3_t const & other) = default;
		static field_3_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_type_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	std::optional<field_2_t> field_2;
	
	std::optional<field_3_t> field_3;
	
	parlex::detail::document::text<literal_0x7B_t> dont_care4;
	
	val<TYPE_SCOPE> field_4;
	
	parlex::detail::document::text<literal_0x7D_t> dont_care6;
	


	explicit TYPE
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_type_t> const & dont_care0, std::vector<val<IC>> const & field_1, std::optional<field_2_t> const & field_2, std::optional<field_3_t> const & field_3, parlex::detail::document::text<literal_0x7B_t> const & dont_care4, val<TYPE_SCOPE> const & field_4, parlex::detail::document::text<literal_0x7D_t> const & dont_care6)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), field_2(field_2), field_3(field_3), dont_care4(dont_care4), field_4(field_4), dont_care6(dont_care6) {}

	TYPE(TYPE const & other) = default;
	static TYPE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct TYPE_CONSTRAINT {
	int32_t document_position, consumed_character_count;

	struct tail_t {
		std::vector<val<IC>> ic1;
		
		parlex::detail::document::text<literal_0x2C_t> comma;
		
		std::vector<val<IC>> ic2;
		
		val<TYPE_CONSTRAINT_ELEMENT> type_constraint_element;
		
	
	
		explicit tail_t
			(std::vector<val<IC>> const & ic1, parlex::detail::document::text<literal_0x2C_t> const & comma, std::vector<val<IC>> const & ic2, val<TYPE_CONSTRAINT_ELEMENT> const & type_constraint_element)
			: ic1(ic1), comma(comma), ic2(ic2), type_constraint_element(type_constraint_element) {}
	
		tail_t(tail_t const & other) = default;
		static tail_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	val<TYPE_CONSTRAINT_SPECIFICATION> specification;
	
	std::vector<val<IC>> ic;
	
	val<TYPE_CONSTRAINT_ELEMENT> head;
	
	std::vector<tail_t> tail;
	


	explicit TYPE_CONSTRAINT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<TYPE_CONSTRAINT_SPECIFICATION> const & specification, std::vector<val<IC>> const & ic, val<TYPE_CONSTRAINT_ELEMENT> const & head, std::vector<tail_t> const & tail)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), specification(specification), ic(ic), head(head), tail(tail) {}

	TYPE_CONSTRAINT(TYPE_CONSTRAINT const & other) = default;
	static TYPE_CONSTRAINT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct TYPE_CONSTRAINT_DECLARATION {
	int32_t document_position, consumed_character_count;

	struct args_t {
		std::vector<val<IC>> ic;
		
		val<PARENTHETICAL_INVOCATION> parenthetical_invocation;
		
	
	
		explicit args_t
			(std::vector<val<IC>> const & ic, val<PARENTHETICAL_INVOCATION> const & parenthetical_invocation)
			: ic(ic), parenthetical_invocation(parenthetical_invocation) {}
	
		args_t(args_t const & other) = default;
		static args_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	val<IDENTIFIER_SPECIFICATION> identifier_specification;
	
	std::optional<args_t> args;
	


	explicit TYPE_CONSTRAINT_DECLARATION
		(int32_t documentPosition, int32_t consumedCharacterCount, val<IDENTIFIER_SPECIFICATION> const & identifier_specification, std::optional<args_t> const & args)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), identifier_specification(identifier_specification), args(args) {}

	TYPE_CONSTRAINT_DECLARATION(TYPE_CONSTRAINT_DECLARATION const & other) = default;
	static TYPE_CONSTRAINT_DECLARATION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


typedef std::variant<
	val<TYPE_CONSTRAINT_DECLARATION>,
	val<ASSIGNMENT>,
	val<DEFINITION>
> TYPE_CONSTRAINT_ELEMENT_base;

struct TYPE_CONSTRAINT_ELEMENT: TYPE_CONSTRAINT_ELEMENT_base {
	static TYPE_CONSTRAINT_ELEMENT build(parlex::detail::ast_node const & n);
	explicit TYPE_CONSTRAINT_ELEMENT(TYPE_CONSTRAINT_ELEMENT_base const & value) : TYPE_CONSTRAINT_ELEMENT_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
struct TYPE_CONSTRAINT_SPECIFICATION {
	int32_t document_position, consumed_character_count;

	struct attributes_t {
		val<ATTRIBUTE> attribute;
		
		std::vector<val<IC>> ic;
		
	
	
		explicit attributes_t
			(val<ATTRIBUTE> const & attribute, std::vector<val<IC>> const & ic)
			: attribute(attribute), ic(ic) {}
	
		attributes_t(attributes_t const & other) = default;
		static attributes_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct visibility_t {
		val<VISIBILITY_MODIFIER> visibility_modifier;
		
		std::vector<val<IC>> ic;
		
	
	
		explicit visibility_t
			(val<VISIBILITY_MODIFIER> const & visibility_modifier, std::vector<val<IC>> const & ic)
			: visibility_modifier(visibility_modifier), ic(ic) {}
	
		visibility_t(visibility_t const & other) = default;
		static visibility_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct static__t {
		parlex::detail::document::text<literal_static_t> dont_care0;
		
		std::vector<val<IC>> field_1;
		
	
	
		explicit static__t
			(parlex::detail::document::text<literal_static_t> const & dont_care0, std::vector<val<IC>> const & field_1)
			: dont_care0(dont_care0), field_1(field_1) {}
	
		static__t(static__t const & other) = default;
		static static__t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct extern__t {
		parlex::detail::document::text<literal_extern_t> dont_care0;
		
		std::vector<val<IC>> field_1;
		
	
	
		explicit extern__t
			(parlex::detail::document::text<literal_extern_t> const & dont_care0, std::vector<val<IC>> const & field_1)
			: dont_care0(dont_care0), field_1(field_1) {}
	
		extern__t(extern__t const & other) = default;
		static extern__t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::optional<val<XML_DOC_STRING>> doc;
	
	std::vector<attributes_t> attributes;
	
	std::optional<visibility_t> visibility;
	
	std::optional<static__t> static_;
	
	std::optional<extern__t> extern_;
	
	std::variant<
		val<TYPE_DEREFERENCE>,
		val<VOLATILE_TYPE_DEREFERENCE>,
		val<IMPLICIT_TYPE_DEREFERENCE>,
		val<VOLATILE_IMPLICIT_TYPE_DEREFERENCE>
	> type_dereference;
	


	explicit TYPE_CONSTRAINT_SPECIFICATION
		(int32_t documentPosition, int32_t consumedCharacterCount, std::optional<val<XML_DOC_STRING>> const & doc, std::vector<attributes_t> const & attributes, std::optional<visibility_t> const & visibility, std::optional<static__t> const & static_, std::optional<extern__t> const & extern_, std::variant<
	val<TYPE_DEREFERENCE>,
	val<VOLATILE_TYPE_DEREFERENCE>,
	val<IMPLICIT_TYPE_DEREFERENCE>,
	val<VOLATILE_IMPLICIT_TYPE_DEREFERENCE>
> const & type_dereference)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), doc(doc), attributes(attributes), visibility(visibility), static_(static_), extern_(extern_), type_dereference(type_dereference) {}

	TYPE_CONSTRAINT_SPECIFICATION(TYPE_CONSTRAINT_SPECIFICATION const & other) = default;
	static TYPE_CONSTRAINT_SPECIFICATION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct TYPE_DEREFERENCE {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0x3C_t> dont_care0;
	
	std::vector<val<IC>> ic1;
	
	val<EXPRESSION> expression;
	
	std::vector<val<IC>> ic2;
	
	parlex::detail::document::text<literal_0x3E_t> dont_care4;
	


	explicit TYPE_DEREFERENCE
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x3C_t> const & dont_care0, std::vector<val<IC>> const & ic1, val<EXPRESSION> const & expression, std::vector<val<IC>> const & ic2, parlex::detail::document::text<literal_0x3E_t> const & dont_care4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), ic1(ic1), expression(expression), ic2(ic2), dont_care4(dont_care4) {}

	TYPE_DEREFERENCE(TYPE_DEREFERENCE const & other) = default;
	static TYPE_DEREFERENCE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct TYPE_INVOCATION {
	int32_t document_position, consumed_character_count;

	struct arguments_t {
		val<STANDARD_ARGUMENTS> standard_arguments;
		
		std::vector<val<IC>> ic;
		
	
	
		explicit arguments_t
			(val<STANDARD_ARGUMENTS> const & standard_arguments, std::vector<val<IC>> const & ic)
			: standard_arguments(standard_arguments), ic(ic) {}
	
		arguments_t(arguments_t const & other) = default;
		static arguments_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_0x3C_t> dont_care0;
	
	std::vector<val<IC>> ic;
	
	std::optional<arguments_t> arguments;
	
	parlex::detail::document::text<literal_0x3E_t> dont_care3;
	


	explicit TYPE_INVOCATION
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x3C_t> const & dont_care0, std::vector<val<IC>> const & ic, std::optional<arguments_t> const & arguments, parlex::detail::document::text<literal_0x3E_t> const & dont_care3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), ic(ic), arguments(arguments), dont_care3(dont_care3) {}

	TYPE_INVOCATION(TYPE_INVOCATION const & other) = default;
	static TYPE_INVOCATION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct TYPE_SCOPE {
	int32_t document_position, consumed_character_count;

	struct field_2_t {
		val<TYPE_STATEMENT> field_1;
		
		std::vector<val<IC>> field_2;
		
	
	
		explicit field_2_t
			(val<TYPE_STATEMENT> const & field_1, std::vector<val<IC>> const & field_2)
			: field_1(field_1), field_2(field_2) {}
	
		field_2_t(field_2_t const & other) = default;
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::vector<val<IC>> field_1;
	
	std::vector<field_2_t> field_2;
	


	explicit TYPE_SCOPE
		(int32_t documentPosition, int32_t consumedCharacterCount, std::vector<val<IC>> const & field_1, std::vector<field_2_t> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2) {}

	TYPE_SCOPE(TYPE_SCOPE const & other) = default;
	static TYPE_SCOPE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct TYPE_SCOPE_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	struct field_1_t {
		val<MEMBER_OFFSET> member_offset;
		
		std::vector<val<IC>> ic;
		
	
	
		explicit field_1_t
			(val<MEMBER_OFFSET> const & member_offset, std::vector<val<IC>> const & ic)
			: member_offset(member_offset), ic(ic) {}
	
		field_1_t(field_1_t const & other) = default;
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	val<IDENTIFIER_SPECIFICATION> identifier_specification;
	
	std::vector<val<IC>> ic;
	
	std::optional<field_1_t> field_1;
	
	val<TYPE_SCOPE_ASSIGNMENT_NODE> type_scope_assignment_node;
	


	explicit TYPE_SCOPE_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<IDENTIFIER_SPECIFICATION> const & identifier_specification, std::vector<val<IC>> const & ic, std::optional<field_1_t> const & field_1, val<TYPE_SCOPE_ASSIGNMENT_NODE> const & type_scope_assignment_node)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), identifier_specification(identifier_specification), ic(ic), field_1(field_1), type_scope_assignment_node(type_scope_assignment_node) {}

	TYPE_SCOPE_ASSIGNMENT(TYPE_SCOPE_ASSIGNMENT const & other) = default;
	static TYPE_SCOPE_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct TYPE_SCOPE_ASSIGNMENT_NODE {
	int32_t document_position, consumed_character_count;

	struct field_2_t {
		struct field_1_t {
			val<MEMBER_OFFSET> field_1;
			
			std::vector<val<IC>> ic;
			
		
		
			explicit field_1_t
				(val<MEMBER_OFFSET> const & field_1, std::vector<val<IC>> const & ic)
				: field_1(field_1), ic(ic) {}
		
			field_1_t(field_1_t const & other) = default;
			static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		val<IDENTIFIER_SPECIFICATION> identifier_specification;
		
		std::optional<field_1_t> field_1;
		
		std::vector<val<IC>> field_2;
		
		val<TYPE_SCOPE_ASSIGNMENT_NODE> next;
		
	
	
		explicit field_2_t
			(val<IDENTIFIER_SPECIFICATION> const & identifier_specification, std::optional<field_1_t> const & field_1, std::vector<val<IC>> const & field_2, val<TYPE_SCOPE_ASSIGNMENT_NODE> const & next)
			: identifier_specification(identifier_specification), field_1(field_1), field_2(field_2), next(next) {}
	
		field_2_t(field_2_t const & other) = default;
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::variant<
		parlex::detail::document::text<literal_0xE20x860x90_t>,
		parlex::detail::document::text<literal_0x3C0x2D_t>
	> field_1;
	
	std::vector<val<IC>> ic;
	
	std::variant<
		val<EXPRESSION>,
		field_2_t
	> field_2;
	


	explicit TYPE_SCOPE_ASSIGNMENT_NODE
		(int32_t documentPosition, int32_t consumedCharacterCount, std::variant<
	parlex::detail::document::text<literal_0xE20x860x90_t>,
	parlex::detail::document::text<literal_0x3C0x2D_t>
> const & field_1, std::vector<val<IC>> const & ic, std::variant<
	val<EXPRESSION>,
	field_2_t
> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), ic(ic), field_2(field_2) {}

	TYPE_SCOPE_ASSIGNMENT_NODE(TYPE_SCOPE_ASSIGNMENT_NODE const & other) = default;
	static TYPE_SCOPE_ASSIGNMENT_NODE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct TYPE_SCOPE_TYPE_CONSTRAINT {
	int32_t document_position, consumed_character_count;

	struct tail_t {
		std::vector<val<IC>> ic1;
		
		parlex::detail::document::text<literal_0x2C_t> comma;
		
		std::vector<val<IC>> ic2;
		
		val<TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT> field_1;
		
	
	
		explicit tail_t
			(std::vector<val<IC>> const & ic1, parlex::detail::document::text<literal_0x2C_t> const & comma, std::vector<val<IC>> const & ic2, val<TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT> const & field_1)
			: ic1(ic1), comma(comma), ic2(ic2), field_1(field_1) {}
	
		tail_t(tail_t const & other) = default;
		static tail_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	val<TYPE_CONSTRAINT_SPECIFICATION> constraint;
	
	std::vector<val<IC>> ic;
	
	val<TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT> head;
	
	std::vector<tail_t> tail;
	


	explicit TYPE_SCOPE_TYPE_CONSTRAINT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<TYPE_CONSTRAINT_SPECIFICATION> const & constraint, std::vector<val<IC>> const & ic, val<TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT> const & head, std::vector<tail_t> const & tail)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), constraint(constraint), ic(ic), head(head), tail(tail) {}

	TYPE_SCOPE_TYPE_CONSTRAINT(TYPE_SCOPE_TYPE_CONSTRAINT const & other) = default;
	static TYPE_SCOPE_TYPE_CONSTRAINT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION {
	int32_t document_position, consumed_character_count;

	struct args_t {
		std::vector<val<IC>> ic;
		
		val<PARENTHETICAL_INVOCATION> field_1;
		
	
	
		explicit args_t
			(std::vector<val<IC>> const & ic, val<PARENTHETICAL_INVOCATION> const & field_1)
			: ic(ic), field_1(field_1) {}
	
		args_t(args_t const & other) = default;
		static args_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_1_t {
		std::vector<val<IC>> ic;
		
		val<MEMBER_OFFSET> member_offset;
		
	
	
		explicit field_1_t
			(std::vector<val<IC>> const & ic, val<MEMBER_OFFSET> const & member_offset)
			: ic(ic), member_offset(member_offset) {}
	
		field_1_t(field_1_t const & other) = default;
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	val<IDENTIFIER_SPECIFICATION> identifier_specification;
	
	std::optional<args_t> args;
	
	std::optional<field_1_t> field_1;
	


	explicit TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION
		(int32_t documentPosition, int32_t consumedCharacterCount, val<IDENTIFIER_SPECIFICATION> const & identifier_specification, std::optional<args_t> const & args, std::optional<field_1_t> const & field_1)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), identifier_specification(identifier_specification), args(args), field_1(field_1) {}

	TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION(TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION const & other) = default;
	static TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


typedef std::variant<
	val<TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION>,
	val<TYPE_SCOPE_ASSIGNMENT>,
	val<DEFINITION>
> TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT_base;

struct TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT: TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT_base {
	static TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT build(parlex::detail::ast_node const & n);
	explicit TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT(TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT_base const & value) : TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
struct TYPE_STATEMENT {
	int32_t document_position, consumed_character_count;

	struct field_1_t1 {
		val<VISIBILITY_MODIFIER> field_1;
		
		std::vector<val<IC>> field_2;
		
		parlex::detail::document::text<literal_0x3A_t> dont_care2;
		
	
	
		explicit field_1_t1
			(val<VISIBILITY_MODIFIER> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x3A_t> const & dont_care2)
			: field_1(field_1), field_2(field_2), dont_care2(dont_care2) {}
	
		field_1_t1(field_1_t1 const & other) = default;
		static field_1_t1 build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::variant<
		field_1_t1,
		val<TYPE_SCOPE_TYPE_CONSTRAINT>,
		val<STATEMENT>
	> field_1;
	
	parlex::detail::document::text<literal_0x3B_t> dont_care1;
	


	explicit TYPE_STATEMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, std::variant<
	field_1_t1,
	val<TYPE_SCOPE_TYPE_CONSTRAINT>,
	val<STATEMENT>
> const & field_1, parlex::detail::document::text<literal_0x3B_t> const & dont_care1)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), dont_care1(dont_care1) {}

	TYPE_STATEMENT(TYPE_STATEMENT const & other) = default;
	static TYPE_STATEMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


typedef std::variant<
	val<FACTORIAL>,
	val<NEGATION>,
	val<RADICAL>
> UNARY_ARITHMETIC_OP_base;

struct UNARY_ARITHMETIC_OP: UNARY_ARITHMETIC_OP_base {
	static UNARY_ARITHMETIC_OP build(parlex::detail::ast_node const & n);
	explicit UNARY_ARITHMETIC_OP(UNARY_ARITHMETIC_OP_base const & value) : UNARY_ARITHMETIC_OP_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
typedef std::variant<
	val<ALL>,
	val<EXISTS>,
	val<EXISTS_ONE>,
	val<NOT>
> UNARY_LOGICAL_OP_base;

struct UNARY_LOGICAL_OP: UNARY_LOGICAL_OP_base {
	static UNARY_LOGICAL_OP build(parlex::detail::ast_node const & n);
	explicit UNARY_LOGICAL_OP(UNARY_LOGICAL_OP_base const & value) : UNARY_LOGICAL_OP_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
typedef std::variant<
	val<ALLOCATION>,
	val<CARDINALITY>,
	val<KLEENE_STAR>,
	val<UNARY_ARITHMETIC_OP>,
	val<UNARY_LOGICAL_OP>
> UNARY_OP_base;

struct UNARY_OP: UNARY_OP_base {
	static UNARY_OP build(parlex::detail::ast_node const & n);
	explicit UNARY_OP(UNARY_OP_base const & value) : UNARY_OP_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
struct UNION {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0xE20x880xAA_t> dont_care2;
	
	std::vector<val<IC>> field_3;
	
	val<EXPRESSION> field_4;
	


	explicit UNION
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0xE20x880xAA_t> const & dont_care2, std::vector<val<IC>> const & field_3, val<EXPRESSION> const & field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4) {}

	UNION(UNION const & other) = default;
	static UNION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct UNION_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0xE20x880xAA_t> dont_care2;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit UNION_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0xE20x880xAA_t> const & dont_care2, std::variant<
	parlex::detail::document::text<literal_0x3C0x2D_t>,
	parlex::detail::document::text<literal_0xE20x860x90_t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	UNION_ASSIGNMENT(UNION_ASSIGNMENT const & other) = default;
	static UNION_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct UNIT_DIVISION {
	int32_t document_position, consumed_character_count;

	val<DIMENSION> field_1;
	
	parlex::detail::document::text<literal_0x2F_t> dont_care1;
	
	val<DIMENSION> field_2;
	


	explicit UNIT_DIVISION
		(int32_t documentPosition, int32_t consumedCharacterCount, val<DIMENSION> const & field_1, parlex::detail::document::text<literal_0x2F_t> const & dont_care1, val<DIMENSION> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), dont_care1(dont_care1), field_2(field_2) {}

	UNIT_DIVISION(UNIT_DIVISION const & other) = default;
	static UNIT_DIVISION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct UNIT_EXPONENTIATION {
	int32_t document_position, consumed_character_count;

	val<DIMENSION> field_1;
	
	parlex::detail::document::text<literal_0x5E_t> dont_care1;
	
	val<NON_FRACTIONAL> field_2;
	


	explicit UNIT_EXPONENTIATION
		(int32_t documentPosition, int32_t consumedCharacterCount, val<DIMENSION> const & field_1, parlex::detail::document::text<literal_0x5E_t> const & dont_care1, val<NON_FRACTIONAL> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), dont_care1(dont_care1), field_2(field_2) {}

	UNIT_EXPONENTIATION(UNIT_EXPONENTIATION const & other) = default;
	static UNIT_EXPONENTIATION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct UNIT_MULTIPLICATION {
	int32_t document_position, consumed_character_count;

	val<DIMENSION> field_1;
	
	parlex::detail::document::text<literal_0x2A_t> dont_care1;
	
	val<DIMENSION> field_2;
	


	explicit UNIT_MULTIPLICATION
		(int32_t documentPosition, int32_t consumedCharacterCount, val<DIMENSION> const & field_1, parlex::detail::document::text<literal_0x2A_t> const & dont_care1, val<DIMENSION> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), dont_care1(dont_care1), field_2(field_2) {}

	UNIT_MULTIPLICATION(UNIT_MULTIPLICATION const & other) = default;
	static UNIT_MULTIPLICATION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct UPCASTS {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_upcasts_t> dont_care2;
	
	std::vector<val<IC>> field_3;
	
	val<EXPRESSION> field_4;
	


	explicit UPCASTS
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_upcasts_t> const & dont_care2, std::vector<val<IC>> const & field_3, val<EXPRESSION> const & field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4) {}

	UPCASTS(UPCASTS const & other) = default;
	static UPCASTS build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct USING {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_using_t> dont_care0;
	
	std::vector<val<IC>> field_01;
	
	parlex::detail::document::text<literal_0x28_t> dont_care2;
	
	std::vector<val<IC>> field_02;
	
	val<EXPRESSION> field_03;
	
	std::vector<val<IC>> field_04;
	
	parlex::detail::document::text<literal_0x29_t> dont_care6;
	
	std::vector<val<IC>> field_05;
	
	val<BLOCK> field_06;
	


	explicit USING
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_using_t> const & dont_care0, std::vector<val<IC>> const & field_01, parlex::detail::document::text<literal_0x28_t> const & dont_care2, std::vector<val<IC>> const & field_02, val<EXPRESSION> const & field_03, std::vector<val<IC>> const & field_04, parlex::detail::document::text<literal_0x29_t> const & dont_care6, std::vector<val<IC>> const & field_05, val<BLOCK> const & field_06)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_01(field_01), dont_care2(dont_care2), field_02(field_02), field_03(field_03), field_04(field_04), dont_care6(dont_care6), field_05(field_05), field_06(field_06) {}

	USING(USING const & other) = default;
	static USING build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct VECTOR_NORM {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0x7C0x7C_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<EXPRESSION> field_2;
	
	std::vector<val<IC>> field_3;
	
	parlex::detail::document::text<literal_0x7C0x7C_t> dont_care4;
	


	explicit VECTOR_NORM
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x7C0x7C_t> const & dont_care0, std::vector<val<IC>> const & field_1, val<EXPRESSION> const & field_2, std::vector<val<IC>> const & field_3, parlex::detail::document::text<literal_0x7C0x7C_t> const & dont_care4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), field_2(field_2), field_3(field_3), dont_care4(dont_care4) {}

	VECTOR_NORM(VECTOR_NORM const & other) = default;
	static VECTOR_NORM build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


typedef std::variant<
	parlex::detail::document::text<literal_public_t>,
	parlex::detail::document::text<literal_protected_t>,
	parlex::detail::document::text<literal_protected0x20internal_t>,
	parlex::detail::document::text<literal_internal_t>,
	parlex::detail::document::text<literal_private_t>
> VISIBILITY_MODIFIER_base;

struct VISIBILITY_MODIFIER: VISIBILITY_MODIFIER_base {
	static VISIBILITY_MODIFIER build(parlex::detail::ast_node const & n);
	explicit VISIBILITY_MODIFIER(VISIBILITY_MODIFIER_base const & value) : VISIBILITY_MODIFIER_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
struct VOLATILE_IMPLICIT_TYPE_DEREFERENCE {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0x3C_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	parlex::detail::document::text<literal_volatile_t> dont_care2;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x3E_t> dont_care4;
	


	explicit VOLATILE_IMPLICIT_TYPE_DEREFERENCE
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x3C_t> const & dont_care0, std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_volatile_t> const & dont_care2, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x3E_t> const & dont_care4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), dont_care2(dont_care2), field_2(field_2), dont_care4(dont_care4) {}

	VOLATILE_IMPLICIT_TYPE_DEREFERENCE(VOLATILE_IMPLICIT_TYPE_DEREFERENCE const & other) = default;
	static VOLATILE_IMPLICIT_TYPE_DEREFERENCE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct VOLATILE_TYPE_DEREFERENCE {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0x3C_t> dont_care0;
	
	std::vector<val<IC>> ic1;
	
	parlex::detail::document::text<literal_volatile_t> dont_care2;
	
	std::vector<val<IC>> ic2;
	
	val<EXPRESSION> expression;
	
	std::vector<val<IC>> ic3;
	
	parlex::detail::document::text<literal_0x3E_t> dont_care6;
	


	explicit VOLATILE_TYPE_DEREFERENCE
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x3C_t> const & dont_care0, std::vector<val<IC>> const & ic1, parlex::detail::document::text<literal_volatile_t> const & dont_care2, std::vector<val<IC>> const & ic2, val<EXPRESSION> const & expression, std::vector<val<IC>> const & ic3, parlex::detail::document::text<literal_0x3E_t> const & dont_care6)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), ic1(ic1), dont_care2(dont_care2), ic2(ic2), expression(expression), ic3(ic3), dont_care6(dont_care6) {}

	VOLATILE_TYPE_DEREFERENCE(VOLATILE_TYPE_DEREFERENCE const & other) = default;
	static VOLATILE_TYPE_DEREFERENCE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct WHOLE_NUMBER {
	int32_t document_position, consumed_character_count;

	std::vector<parlex::detail::document::text<literal_0_t>> field_1;
	
	val<NON_ZERO_DECIMAL_DIGIT> field_2;
	
	std::vector<parlex::detail::document::text<parlex::detail::decimal_digit_t>> field_3;
	


	explicit WHOLE_NUMBER
		(int32_t documentPosition, int32_t consumedCharacterCount, std::vector<parlex::detail::document::text<literal_0_t>> const & field_1, val<NON_ZERO_DECIMAL_DIGIT> const & field_2, std::vector<parlex::detail::document::text<parlex::detail::decimal_digit_t>> const & field_3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3) {}

	WHOLE_NUMBER(WHOLE_NUMBER const & other) = default;
	static WHOLE_NUMBER build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct WRITE_LOCK {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_write_lock_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<PARENTHETICAL> field_2;
	
	std::vector<val<IC>> field_3;
	
	val<EXPRESSION> field_4;
	


	explicit WRITE_LOCK
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_write_lock_t> const & dont_care0, std::vector<val<IC>> const & field_1, val<PARENTHETICAL> const & field_2, std::vector<val<IC>> const & field_3, val<EXPRESSION> const & field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4) {}

	WRITE_LOCK(WRITE_LOCK const & other) = default;
	static WRITE_LOCK build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct WS {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<parlex::detail::white_space_t> field_1;
	
	std::vector<parlex::detail::document::text<parlex::detail::white_space_t>> field_2;
	


	explicit WS
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<parlex::detail::white_space_t> const & field_1, std::vector<parlex::detail::document::text<parlex::detail::white_space_t>> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2) {}

	WS(WS const & other) = default;
	static WS build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct XML_DOC_STRING {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0x600x600x60_t> dont_care0;
	
	val<XML_DOC_STRING_INTERIOR> interior;
	
	parlex::detail::document::text<literal_0x600x600x60_t> dont_care2;
	
	std::vector<val<IC>> ic;
	


	explicit XML_DOC_STRING
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x600x600x60_t> const & dont_care0, val<XML_DOC_STRING_INTERIOR> const & interior, parlex::detail::document::text<literal_0x600x600x60_t> const & dont_care2, std::vector<val<IC>> const & ic)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), interior(interior), dont_care2(dont_care2), ic(ic) {}

	XML_DOC_STRING(XML_DOC_STRING const & other) = default;
	static XML_DOC_STRING build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct XML_DOC_STRING_INTERIOR_t {
	parlex::detail::document::text<literal_0x60_t> dont_care0;
	
	val<XML_DOC_STRING_INTERIOR> interior;
	
	parlex::detail::document::text<literal_0x60_t> dont_care2;
	


	explicit XML_DOC_STRING_INTERIOR_t
		(parlex::detail::document::text<literal_0x60_t> const & dont_care0, val<XML_DOC_STRING_INTERIOR> const & interior, parlex::detail::document::text<literal_0x60_t> const & dont_care2)
		: dont_care0(dont_care0), interior(interior), dont_care2(dont_care2) {}

	XML_DOC_STRING_INTERIOR_t(XML_DOC_STRING_INTERIOR_t const & other) = default;
	static XML_DOC_STRING_INTERIOR_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

typedef std::variant<
	val<PAYLOAD>,
	XML_DOC_STRING_INTERIOR_t
> XML_DOC_STRING_INTERIOR_base;

struct XML_DOC_STRING_INTERIOR: XML_DOC_STRING_INTERIOR_base {
	static XML_DOC_STRING_INTERIOR build(parlex::detail::ast_node const & n);
	explicit XML_DOC_STRING_INTERIOR(XML_DOC_STRING_INTERIOR_base const & value) : XML_DOC_STRING_INTERIOR_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
struct XOR {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xE20x8A0x95_t>,
		parlex::detail::document::text<literal_xor_t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit XOR
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0xE20x8A0x95_t>,
	parlex::detail::document::text<literal_xor_t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	XOR(XOR const & other) = default;
	static XOR build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


struct XOR_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xE20x8A0x95_t>,
		parlex::detail::document::text<literal_xor_t>
	> field_3;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_4;
	
	std::vector<val<IC>> field_5;
	
	val<EXPRESSION> field_6;
	


	explicit XOR_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0xE20x8A0x95_t>,
	parlex::detail::document::text<literal_xor_t>
> const & field_3, std::variant<
	parlex::detail::document::text<literal_0x3C0x2D_t>,
	parlex::detail::document::text<literal_0xE20x860x90_t>
> const & field_4, std::vector<val<IC>> const & field_5, val<EXPRESSION> const & field_6)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5), field_6(field_6) {}

	XOR_ASSIGNMENT(XOR_ASSIGNMENT const & other) = default;
	static XOR_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


class plange_grammar : public parlex::detail::grammar {
public:
	static plange_grammar const & get() {
		static plange_grammar value;
		return value;
	}

	uint16_t const ADDITION;
	uint16_t const ADDITION_ASSIGNMENT;
	uint16_t const ADD_SUB;
	uint16_t const ADD_SUB_ASSIGNMENT;
	uint16_t const ALL;
	uint16_t const ALLOCATION;
	uint16_t const AND;
	uint16_t const AND_ASSIGNMENT;
	uint16_t const ARGUMENT_PACK;
	uint16_t const ARRAY;
	uint16_t const ARRAY_ARGUMENTS;
	uint16_t const ARRAY_INDEXER;
	uint16_t const ARRAY_INVOCATION;
	uint16_t const ASM_EXPRESSION;
	uint16_t const ASM_FUNCTION;
	uint16_t const ASM_IDENTIFIER;
	uint16_t const ASM_OP;
	uint16_t const ASM_PTR_ARITHMETIC_ATT;
	uint16_t const ASM_PTR_ARITHMETIC_ATT_REG;
	uint16_t const ASM_PTR_ARITHMETIC_INTEL;
	uint16_t const ASM_SCOPE;
	uint16_t const ASM_STATEMENT;
	uint16_t const ASSIGNMENT;
	uint16_t const ASSIGNMENT_NODE;
	uint16_t const ATTRIBUTE;
	uint16_t const BIJECTION;
	uint16_t const BINARY_ARITHMETIC_OP;
	uint16_t const BINARY_COLLECTION_OP;
	uint16_t const BINARY_LOGICAL_OP;
	uint16_t const BINARY_OP;
	uint16_t const BITWISE_OP;
	uint16_t const BIT_AND;
	uint16_t const BIT_AND_ASSIGNMENT;
	uint16_t const BIT_NOT;
	uint16_t const BIT_NOT_ASSIGNMENT;
	uint16_t const BIT_OR;
	uint16_t const BIT_OR_ASSIGNMENT;
	uint16_t const BIT_XOR;
	uint16_t const BIT_XOR_ASSIGNMENT;
	uint16_t const BLOCK;
	uint16_t const BOOL;
	uint16_t const BREAK;
	uint16_t const CARDINALITY;
	uint16_t const CAST;
	uint16_t const CASTS;
	uint16_t const CEILING;
	uint16_t const COMMENT;
	uint16_t const COMPLEMENT;
	uint16_t const COMPOSITION;
	uint16_t const COMPOSITION_ASSIGNMENT;
	uint16_t const COMPOUND;
	uint16_t const COMPOUND_ASSIGNMENT;
	uint16_t const CONDITIONAL;
	uint16_t const CONSTRUCTIVE_OP;
	uint16_t const CONTINUE;
	uint16_t const CROSS_PRODUCT;
	uint16_t const CROSS_PRODUCT_ASSIGNMENT;
	uint16_t const DATE;
	uint16_t const DATE_TIME;
	uint16_t const DATE_YEAR_DAY;
	uint16_t const DATE_YEAR_MONTH_DAY;
	uint16_t const DEFINITION;
	uint16_t const DELTA;
	uint16_t const DIMENSION;
	uint16_t const DIMENSIONAL_ANALYSIS_OP;
	uint16_t const DIMENSIONAL_NUMBER;
	uint16_t const DIVISION;
	uint16_t const DIVISION_ASSIGNMENT;
	uint16_t const DO;
	uint16_t const DOT_PRODUCT;
	uint16_t const DOWNCASTS;
	uint16_t const EMBEDDED_COMMENT;
	uint16_t const EMBEDDED_COMMENT_INTERIOR;
	uint16_t const EMBEDDED_NEWLINE_STRING;
	uint16_t const EMBEDDED_NEWLINE_STRING_INTERIOR;
	uint16_t const EMBEDDED_STRING;
	uint16_t const EMBEDDED_STRING_INTERIOR;
	uint16_t const END_OF_LINE_COMMENT;
	uint16_t const ENUM;
	uint16_t const ENUM_ELEMENT;
	uint16_t const EQUALITY;
	uint16_t const EQUALITY_NODE;
	uint16_t const EXACTLY;
	uint16_t const EXISTS;
	uint16_t const EXISTS_ONE;
	uint16_t const EXPONENTIATION;
	uint16_t const EXPONENTIATION_ASSIGNMENT;
	uint16_t const EXPRESSION;
	uint16_t const FACTORIAL;
	uint16_t const FACTORIAL_ASSIGNMENT;
	uint16_t const FLOOR;
	uint16_t const FOR;
	uint16_t const FOR_COLLECTION;
	uint16_t const FOR_STEP;
	uint16_t const FOR_STEP_LIST;
	uint16_t const FOR_STEP_NODE;
	uint16_t const FREE;
	uint16_t const FUNCTION;
	uint16_t const FUNCTION_MODIFIER_0;
	uint16_t const FUNCTION_MODIFIER_1;
	uint16_t const FUNCTION_MODIFIER_2;
	uint16_t const FUNCTION_MODIFIER_3;
	uint16_t const FUNCTION_MODIFIER_4;
	uint16_t const FUNCTION_MODIFIER_ATOMIC;
	uint16_t const FUNCTION_MODIFIER_CALLING_CONVENTION;
	uint16_t const FUNCTION_MODIFIER_MODEL;
	uint16_t const FUNCTION_MODIFIER_PLATFORM;
	uint16_t const FUNCTION_MODIFIER_STABILITY;
	uint16_t const FUNCTION_MODIFIER_THROWING;
	uint16_t const GREATER;
	uint16_t const GREATER_NODE;
	uint16_t const HAS;
	uint16_t const HEX;
	uint16_t const IC;
	uint16_t const IDENTIFIER;
	uint16_t const IDENTIFIER_SPECIFICATION;
	uint16_t const IF;
	uint16_t const IFF;
	uint16_t const IMPLEMENTS;
	uint16_t const IMPLICATION;
	uint16_t const IMPLICATION_ASSIGNMENT;
	uint16_t const IMPLICIT_TYPE_DEREFERENCE;
	uint16_t const IMPORT;
	uint16_t const IN;
	uint16_t const INEQUALITY;
	uint16_t const INHERITANCE_ITEM_PREFIX;
	uint16_t const INHERITANCE_LIST;
	uint16_t const INHERITS;
	uint16_t const INTEGER_DIVISION;
	uint16_t const INTEGER_DIVISION_ASSIGNMENT;
	uint16_t const INTERSECTION;
	uint16_t const INTERSECTION_ASSIGNMENT;
	uint16_t const INVOCATION;
	uint16_t const IS;
	uint16_t const KLEENE_STAR;
	uint16_t const LESSER;
	uint16_t const LESSER_NODE;
	uint16_t const LIST;
	uint16_t const LOCK;
	uint16_t const LOOP;
	uint16_t const MAGNITUDE;
	uint16_t const MAP;
	uint16_t const MAPS_TO;
	uint16_t const MEMBER_ACCESS;
	uint16_t const MEMBER_OFFSET;
	uint16_t const MODULATION;
	uint16_t const MODULATION_ASSIGNMENT;
	uint16_t const MULTIPLICATION;
	uint16_t const MULTIPLICATION_ASSIGNMENT;
	uint16_t const MULTIPLICATIVE_OP;
	uint16_t const NAND;
	uint16_t const NAND_ASSIGNMENT;
	uint16_t const NATURAL_NUMBER;
	uint16_t const NEAREST_INTEGER;
	uint16_t const NEGATION;
	uint16_t const NEGATION_ASSIGNMENT;
	uint16_t const NON_FRACTIONAL;
	uint16_t const NON_NEG_FRACTIONAL;
	uint16_t const NON_NEG_INTEGER;
	uint16_t const NON_NEG_NON_FRACTIONAL;
	uint16_t const NON_NEG_NUMBER;
	uint16_t const NON_ZERO_DECIMAL_DIGIT;
	uint16_t const NOR;
	uint16_t const NOR_ASSIGNMENT;
	uint16_t const NOT;
	uint16_t const NOT_ASSIGNMENT;
	uint16_t const NOT_HAS;
	uint16_t const NOT_IN;
	uint16_t const NULL_COALESCE;
	uint16_t const NULL_COALESCE_ASSIGNMENT;
	uint16_t const OBJECT;
	uint16_t const OCTAL;
	uint16_t const OP_ASSIGNMENT;
	uint16_t const OR;
	uint16_t const OR_ASSIGNMENT;
	uint16_t const PARAMETER;
	uint16_t const PARAMETER_ANALYTIC;
	uint16_t const PARAMETER_NATURAL;
	uint16_t const PARENTHETICAL;
	uint16_t const PARENTHETICAL_INVOCATION;
	uint16_t const PAYLOAD;
	uint16_t const PLATFORM;
	uint16_t const POST_DEC;
	uint16_t const POST_INC;
	uint16_t const PREPEND;
	uint16_t const PREPEND_ASSIGNMENT;
	uint16_t const PRE_DEC;
	uint16_t const PRE_INC;
	uint16_t const RADICAL;
	uint16_t const RADICAL_ASSIGNMENT;
	uint16_t const RANGE;
	uint16_t const READ_LOCK;
	uint16_t const RECORD;
	uint16_t const REGEX;
	uint16_t const RELATIONAL_COLLECTION_OP;
	uint16_t const RELATIONAL_OP;
	uint16_t const RETURN;
	uint16_t const SET;
	uint16_t const SET_COMPREHENSION;
	uint16_t const SHIFTL;
	uint16_t const SHIFTL_ASSIGNMENT;
	uint16_t const SHIFTR;
	uint16_t const SHIFTR_ASSIGNMENT;
	uint16_t const SLICE;
	uint16_t const STANDARD_ARGUMENTS;
	uint16_t const STATEMENT;
	uint16_t const STATEMENT_SCOPE;
	uint16_t const SUBSET;
	uint16_t const SUBSET_NODE;
	uint16_t const SUBTRACTION;
	uint16_t const SUBTRACTION_ASSIGNMENT;
	uint16_t const SUPERSET;
	uint16_t const SUPERSET_NODE;
	uint16_t const SWIZZLE;
	uint16_t const SYMMETRIC_DIFFERENCE;
	uint16_t const SYMMETRIC_DIFFERENCE_ASSIGNMENT;
	uint16_t const THIS;
	uint16_t const THIS_FUNC;
	uint16_t const THIS_TYPE;
	uint16_t const THROW;
	uint16_t const TIME;
	uint16_t const TRY;
	uint16_t const TUPLE;
	uint16_t const TYPE;
	uint16_t const TYPE_CONSTRAINT;
	uint16_t const TYPE_CONSTRAINT_DECLARATION;
	uint16_t const TYPE_CONSTRAINT_ELEMENT;
	uint16_t const TYPE_CONSTRAINT_SPECIFICATION;
	uint16_t const TYPE_DEREFERENCE;
	uint16_t const TYPE_INVOCATION;
	uint16_t const TYPE_SCOPE;
	uint16_t const TYPE_SCOPE_ASSIGNMENT;
	uint16_t const TYPE_SCOPE_ASSIGNMENT_NODE;
	uint16_t const TYPE_SCOPE_TYPE_CONSTRAINT;
	uint16_t const TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION;
	uint16_t const TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT;
	uint16_t const TYPE_STATEMENT;
	uint16_t const UNARY_ARITHMETIC_OP;
	uint16_t const UNARY_LOGICAL_OP;
	uint16_t const UNARY_OP;
	uint16_t const UNION;
	uint16_t const UNION_ASSIGNMENT;
	uint16_t const UNIT_DIVISION;
	uint16_t const UNIT_EXPONENTIATION;
	uint16_t const UNIT_MULTIPLICATION;
	uint16_t const UPCASTS;
	uint16_t const USING;
	uint16_t const VECTOR_NORM;
	uint16_t const VISIBILITY_MODIFIER;
	uint16_t const VOLATILE_IMPLICIT_TYPE_DEREFERENCE;
	uint16_t const VOLATILE_TYPE_DEREFERENCE;
	uint16_t const WHOLE_NUMBER;
	uint16_t const WRITE_LOCK;
	uint16_t const WS;
	uint16_t const XML_DOC_STRING;
	uint16_t const XML_DOC_STRING_INTERIOR;
	uint16_t const XOR;
	uint16_t const XOR_ASSIGNMENT;
private:
	plange_grammar();

};

} // namespace plc


#endif //INCLUDED_PLANGE_HPP
