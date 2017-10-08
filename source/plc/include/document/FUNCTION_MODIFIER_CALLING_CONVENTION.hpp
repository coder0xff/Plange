// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_MODIFIER_CALLING_CONVENTION_HPP
#define INCLUDED_FUNCTION_MODIFIER_CALLING_CONVENTION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct FUNCTION_MODIFIER_CALLING_CONVENTION {
	enum type {
		literal_X86_fast_call,
		literal_any_reg_call,
		literal_arm_aapcs_call,
		literal_arm_aapcs_vfp_call,
		literal_arm_apcs_call,
		literal_avr_builtin_call,
		literal_avr_intr_call,
		literal_avr_signal_call,
		literal_c_call,
		literal_cold_call,
		literal_cxx_fast_tls_call,
		literal_fast_call,
		literal_first_target_call,
		literal_ghc_call,
		literal_hhvm_call,
		literal_hipe_call,
		literal_intel_ocl_bi_call,
		literal_msp430_intr_call,
		literal_preserve_all_call,
		literal_preserve_most_call,
		literal_ptx_device_call,
		literal_ptx_kernel_call,
		literal_spir_func_call,
		literal_spir_kernel_call,
		literal_swift_call,
		literal_webkit_js_call,
		literal_x86_64_sysv_call,
		literal_x86_64_win64_call,
		literal_x86_intr_call,
		literal_x86_std_call,
		literal_x86_this_call,
		literal_x86_vector_call
	} value;

	static FUNCTION_MODIFIER_CALLING_CONVENTION build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
		static ::std::unordered_map<parlex::details::recognizer const *, type> const table {
			{ &plange_grammar().get_literal("literal_X86_fast_call"), literal_X86_fast_call },
			{ &plange_grammar().get_literal("literal_any_reg_call"), literal_any_reg_call },
			{ &plange_grammar().get_literal("literal_arm_aapcs_call"), literal_arm_aapcs_call },
			{ &plange_grammar().get_literal("literal_arm_aapcs_vfp_call"), literal_arm_aapcs_vfp_call },
			{ &plange_grammar().get_literal("literal_arm_apcs_call"), literal_arm_apcs_call },
			{ &plange_grammar().get_literal("literal_avr_builtin_call"), literal_avr_builtin_call },
			{ &plange_grammar().get_literal("literal_avr_intr_call"), literal_avr_intr_call },
			{ &plange_grammar().get_literal("literal_avr_signal_call"), literal_avr_signal_call },
			{ &plange_grammar().get_literal("literal_c_call"), literal_c_call },
			{ &plange_grammar().get_literal("literal_cold_call"), literal_cold_call },
			{ &plange_grammar().get_literal("literal_cxx_fast_tls_call"), literal_cxx_fast_tls_call },
			{ &plange_grammar().get_literal("literal_fast_call"), literal_fast_call },
			{ &plange_grammar().get_literal("literal_first_target_call"), literal_first_target_call },
			{ &plange_grammar().get_literal("literal_ghc_call"), literal_ghc_call },
			{ &plange_grammar().get_literal("literal_hhvm_call"), literal_hhvm_call },
			{ &plange_grammar().get_literal("literal_hipe_call"), literal_hipe_call },
			{ &plange_grammar().get_literal("literal_intel_ocl_bi_call"), literal_intel_ocl_bi_call },
			{ &plange_grammar().get_literal("literal_msp430_intr_call"), literal_msp430_intr_call },
			{ &plange_grammar().get_literal("literal_preserve_all_call"), literal_preserve_all_call },
			{ &plange_grammar().get_literal("literal_preserve_most_call"), literal_preserve_most_call },
			{ &plange_grammar().get_literal("literal_ptx_device_call"), literal_ptx_device_call },
			{ &plange_grammar().get_literal("literal_ptx_kernel_call"), literal_ptx_kernel_call },
			{ &plange_grammar().get_literal("literal_spir_func_call"), literal_spir_func_call },
			{ &plange_grammar().get_literal("literal_spir_kernel_call"), literal_spir_kernel_call },
			{ &plange_grammar().get_literal("literal_swift_call"), literal_swift_call },
			{ &plange_grammar().get_literal("literal_webkit_js_call"), literal_webkit_js_call },
			{ &plange_grammar().get_literal("literal_x86_64_sysv_call"), literal_x86_64_sysv_call },
			{ &plange_grammar().get_literal("literal_x86_64_win64_call"), literal_x86_64_win64_call },
			{ &plange_grammar().get_literal("literal_x86_intr_call"), literal_x86_intr_call },
			{ &plange_grammar().get_literal("literal_x86_std_call"), literal_x86_std_call },
			{ &plange_grammar().get_literal("literal_x86_this_call"), literal_x86_this_call },
			{ &plange_grammar().get_literal("literal_x86_vector_call"), literal_x86_vector_call },
		};
		return FUNCTION_MODIFIER_CALLING_CONVENTION{ table.find(&n.r)->second };
	}
};



} // namespace plc



#endif //INCLUDED_FUNCTION_MODIFIER_CALLING_CONVENTION_HPP
