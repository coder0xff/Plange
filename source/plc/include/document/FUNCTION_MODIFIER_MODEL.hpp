// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_MODIFIER_MODEL_HPP
#define INCLUDED_FUNCTION_MODIFIER_MODEL_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct FUNCTION_MODIFIER_CALLING_CONVENTION;
struct ICR;

struct FUNCTION_MODIFIER_MODEL {
	struct model_t {
		enum type {
			literal_imperative,
			literal_opaque,
			literal_pure
		} value;
	
		static model_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
			static ::std::unordered_map<parlex::details::recognizer const *, type> const table {
				{ &plange_grammar::get().get_literal("literal_imperative"), literal_imperative },
				{ &plange_grammar::get().get_literal("literal_opaque"), literal_opaque },
				{ &plange_grammar::get().get_literal("literal_pure"), literal_pure },
			};
			return model_t{ table.find(&n.r)->second };
		}
	};


	struct field_1_t_1_t {
		erased<ICR> field_1;
		erased<FUNCTION_MODIFIER_CALLING_CONVENTION> field_2;
	
	
		explicit field_1_t_1_t(
			erased<ICR> && field_1,
			erased<FUNCTION_MODIFIER_CALLING_CONVENTION> && field_2
		) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_1_t_1_t(field_1_t_1_t const & other) = default;
		field_1_t_1_t(field_1_t_1_t && move) = default;
	
		static field_1_t_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);
	
	};

	model_t model;
	std::optional<field_1_t_1_t> field_1;


	explicit FUNCTION_MODIFIER_MODEL(
		model_t && model,
		std::optional<field_1_t_1_t> && field_1
	) : model(std::move(model)), field_1(std::move(field_1)) {}

	FUNCTION_MODIFIER_MODEL(FUNCTION_MODIFIER_MODEL const & other) = default;
	FUNCTION_MODIFIER_MODEL(FUNCTION_MODIFIER_MODEL && move) = default;

	static FUNCTION_MODIFIER_MODEL build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_FUNCTION_MODIFIER_MODEL_HPP
