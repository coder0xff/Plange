// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_MODIFIER_CALLING_CONVENTION_HPP
#define INCLUDED_FUNCTION_MODIFIER_CALLING_CONVENTION_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

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
} // namespace plc



#endif //INCLUDED_FUNCTION_MODIFIER_CALLING_CONVENTION_HPP
