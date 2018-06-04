#ifndef INCLUDED_PLANGE_LITERALS_HPP
#define INCLUDED_PLANGE_LITERALS_HPP

#include "parlex/detail/document.hpp"

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
} // namespace plc


#endif //INCLUDED_PLANGE_LITERALS_HPP
