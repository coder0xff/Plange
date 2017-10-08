// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_CROSS_PRODUCT_HPP
#define INCLUDED_CROSS_PRODUCT_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct CROSS_PRODUCT {
	struct field_3_t {
		enum type {
			literal_0xC30x97,
			literal__x_
		} value;
	
		static field_3_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
			static ::std::unordered_map<parlex::details::recognizer const *, type> const table {
				{ &plange_grammar().get_literal("literal_0xC30x97"), literal_0xC30x97 },
				{ &plange_grammar().get_literal("literal__x_"), literal__x_ },
			};
			return field_3_t{ table.find(&n.r)->second };
		}
	};


	erased<EXPRESSION> field_1;
	std::vector<erased<IC>> field_2;
	field_3_t field_3;
	std::vector<erased<IC>> field_4;
	erased<EXPRESSION> field_5;


	explicit CROSS_PRODUCT(
		erased<EXPRESSION> && field_1,
		std::vector<erased<IC>> && field_2,
		field_3_t && field_3,
		std::vector<erased<IC>> && field_4,
		erased<EXPRESSION> && field_5
	) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), field_5(std::move(field_5)) {}

	CROSS_PRODUCT(CROSS_PRODUCT const & other) = default;
	CROSS_PRODUCT(CROSS_PRODUCT && move) = default;

	static CROSS_PRODUCT build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_CROSS_PRODUCT_HPP
