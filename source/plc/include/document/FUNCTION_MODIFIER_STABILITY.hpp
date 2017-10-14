// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_MODIFIER_STABILITY_HPP
#define INCLUDED_FUNCTION_MODIFIER_STABILITY_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct FUNCTION_MODIFIER_1;
struct ICR;

struct FUNCTION_MODIFIER_STABILITY {
	struct stability_t {
		enum type {
			literal_stable,
			literal_unstable
		} value;
	
		static stability_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
			static ::std::unordered_map<parlex::details::recognizer const *, type> const table {
				{ &plange_grammar::get().get_literal("literal_stable"), literal_stable },
				{ &plange_grammar::get().get_literal("literal_unstable"), literal_unstable },
			};
			return stability_t{ table.find(&n.r)->second };
		}
	};


	struct field_1_t_1_t {
		erased<ICR> field_1;
		erased<FUNCTION_MODIFIER_1> field_2;
	
	
		explicit field_1_t_1_t(
			erased<ICR> && field_1,
			erased<FUNCTION_MODIFIER_1> && field_2
		) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_1_t_1_t(field_1_t_1_t const & other) = default;
		field_1_t_1_t(field_1_t_1_t && move) = default;
	
		static field_1_t_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);
	
	};

	stability_t stability;
	std::optional<field_1_t_1_t> field_1;


	explicit FUNCTION_MODIFIER_STABILITY(
		stability_t && stability,
		std::optional<field_1_t_1_t> && field_1
	) : stability(std::move(stability)), field_1(std::move(field_1)) {}

	FUNCTION_MODIFIER_STABILITY(FUNCTION_MODIFIER_STABILITY const & other) = default;
	FUNCTION_MODIFIER_STABILITY(FUNCTION_MODIFIER_STABILITY && move) = default;

	static FUNCTION_MODIFIER_STABILITY build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_FUNCTION_MODIFIER_STABILITY_HPP
