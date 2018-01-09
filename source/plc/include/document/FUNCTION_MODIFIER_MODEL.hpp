// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_MODIFIER_MODEL_HPP
#define INCLUDED_FUNCTION_MODIFIER_MODEL_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct FUNCTION_MODIFIER_CALLING_CONVENTION;
struct ICR;

struct FUNCTION_MODIFIER_MODEL {
	struct field_1_t_1_t {
		erased<ICR> field_1;
		
		erased<FUNCTION_MODIFIER_CALLING_CONVENTION> field_2;
		
	
	
		explicit field_1_t_1_t(
			erased<ICR> && field_1, erased<FUNCTION_MODIFIER_CALLING_CONVENTION> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_1_t_1_t(field_1_t_1_t const & other) = default;
		field_1_t_1_t(field_1_t_1_t && move) = default;
	
		static field_1_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::variant<
		parlex::detail::document::text<literal_pure_t>,
		parlex::detail::document::text<literal_imperative_t>,
		parlex::detail::document::text<literal_opaque_t>
	> model;
	
	std::optional<field_1_t_1_t> field_1;
	


	explicit FUNCTION_MODIFIER_MODEL(
		std::variant<
			parlex::detail::document::text<literal_pure_t>,
			parlex::detail::document::text<literal_imperative_t>,
			parlex::detail::document::text<literal_opaque_t>
		> && model, std::optional<field_1_t_1_t> && field_1) : model(std::move(model)), field_1(std::move(field_1)) {}

	FUNCTION_MODIFIER_MODEL(FUNCTION_MODIFIER_MODEL const & other) = default;
	FUNCTION_MODIFIER_MODEL(FUNCTION_MODIFIER_MODEL && move) = default;

	static FUNCTION_MODIFIER_MODEL build(parlex::detail::ast_node const & n);
	static parlex::detail::state_machine const & state_machine();

};


} // namespace plc



#endif //INCLUDED_FUNCTION_MODIFIER_MODEL_HPP
