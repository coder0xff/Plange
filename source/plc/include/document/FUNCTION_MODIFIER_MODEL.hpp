// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_MODIFIER_MODEL_HPP
#define INCLUDED_FUNCTION_MODIFIER_MODEL_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

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
	
		static field_1_t_1_t build(parlex::details::behavior::node const * b, parlex::details::document::walk & w);
	};

	std::variant<
		parlex::details::document::text<literal_pure_t>,
		parlex::details::document::text<literal_imperative_t>,
		parlex::details::document::text<literal_opaque_t>
	> model;
	
	std::optional<field_1_t_1_t> field_1;
	


	explicit FUNCTION_MODIFIER_MODEL(
		std::variant<
			parlex::details::document::text<literal_pure_t>,
			parlex::details::document::text<literal_imperative_t>,
			parlex::details::document::text<literal_opaque_t>
		> && model, std::optional<field_1_t_1_t> && field_1) : model(std::move(model)), field_1(std::move(field_1)) {}

	FUNCTION_MODIFIER_MODEL(FUNCTION_MODIFIER_MODEL const & other) = default;
	FUNCTION_MODIFIER_MODEL(FUNCTION_MODIFIER_MODEL && move) = default;

	static FUNCTION_MODIFIER_MODEL build(parlex::details::ast_node const & n);
	static parlex::details::recognizer const & recognizer();

};


} // namespace plc



#endif //INCLUDED_FUNCTION_MODIFIER_MODEL_HPP
