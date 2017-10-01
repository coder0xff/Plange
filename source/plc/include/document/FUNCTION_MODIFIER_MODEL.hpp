// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_MODIFIER_MODEL_HPP
#define INCLUDED_FUNCTION_MODIFIER_MODEL_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct FUNCTION_MODIFIER_CALLING_CONVENTION;
struct ICR;

struct FUNCTION_MODIFIER_MODEL {
	std::variant<
		literal_pure_t,
		literal_imperative_t,
		literal_opaque_t
	> model;
	std::optional<std::tuple<
		erased<ICR>,
		erased<FUNCTION_MODIFIER_CALLING_CONVENTION>
	>> field_1;


	FUNCTION_MODIFIER_MODEL(
		std::variant<
			literal_pure_t,
			literal_imperative_t,
			literal_opaque_t
		> const & model,
		std::optional<std::tuple<
			erased<ICR>,
			erased<FUNCTION_MODIFIER_CALLING_CONVENTION>
		>> const & field_1
	) : model(model), field_1(field_1) {}

	static FUNCTION_MODIFIER_MODEL build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_FUNCTION_MODIFIER_MODEL_HPP
