// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DELTA_HPP
#define INCLUDED_DELTA_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct WHOLE_NUMBER;

struct DELTA {
	struct field_1_t {
		enum type {
			literal_0xCE0x94,
			literal__delta_
		} value;
	
		static field_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
			static ::std::unordered_map<parlex::details::recognizer const *, type> const table {
				{ &plange_grammar().get_literal("literal_0xCE0x94"), literal_0xCE0x94 },
				{ &plange_grammar().get_literal("literal__delta_"), literal__delta_ },
			};
			return field_1_t{ table.find(&n.r)->second };
		}
	};


	struct field_2_t_1_t {
		erased<WHOLE_NUMBER> whole_number;
	
	
		explicit field_2_t_1_t(
			erased<WHOLE_NUMBER> && whole_number
		) : whole_number(std::move(whole_number)) {}
	
		field_2_t_1_t(field_2_t_1_t const & other) = default;
		field_2_t_1_t(field_2_t_1_t && move) = default;
	
		static field_2_t_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);
	
	};

	field_1_t field_1;
	std::optional<field_2_t_1_t> field_2;
	erased<EXPRESSION> expression;


	explicit DELTA(
		field_1_t && field_1,
		std::optional<field_2_t_1_t> && field_2,
		erased<EXPRESSION> && expression
	) : field_1(std::move(field_1)), field_2(std::move(field_2)), expression(std::move(expression)) {}

	DELTA(DELTA const & other) = default;
	DELTA(DELTA && move) = default;

	static DELTA build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_DELTA_HPP
