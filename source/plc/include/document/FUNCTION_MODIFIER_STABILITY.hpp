// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_MODIFIER_STABILITY_HPP
#define INCLUDED_FUNCTION_MODIFIER_STABILITY_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct FUNCTION_MODIFIER_1;
struct ICR;

struct FUNCTION_MODIFIER_STABILITY {
	struct field_1_t_1_t {
		erased<ICR> field_1;
		
		erased<FUNCTION_MODIFIER_1> field_2;
		
	
	
		explicit field_1_t_1_t(
			erased<ICR> && field_1, erased<FUNCTION_MODIFIER_1> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_1_t_1_t(field_1_t_1_t const & other) = default;
		field_1_t_1_t(field_1_t_1_t && move) = default;
	
		static field_1_t_1_t build(parlex::details::behavior::node const * b, parlex::details::document::walk & w);
	};

	std::variant<
		parlex::details::document::text<literal_stable_t>,
		parlex::details::document::text<literal_unstable_t>
	> stability;
	
	std::optional<field_1_t_1_t> field_1;
	


	explicit FUNCTION_MODIFIER_STABILITY(
		std::variant<
			parlex::details::document::text<literal_stable_t>,
			parlex::details::document::text<literal_unstable_t>
		> && stability, std::optional<field_1_t_1_t> && field_1) : stability(std::move(stability)), field_1(std::move(field_1)) {}

	FUNCTION_MODIFIER_STABILITY(FUNCTION_MODIFIER_STABILITY const & other) = default;
	FUNCTION_MODIFIER_STABILITY(FUNCTION_MODIFIER_STABILITY && move) = default;

	static FUNCTION_MODIFIER_STABILITY build(parlex::details::ast_node const & n);
	static parlex::details::recognizer const & recognizer();

};


} // namespace plc



#endif //INCLUDED_FUNCTION_MODIFIER_STABILITY_HPP
