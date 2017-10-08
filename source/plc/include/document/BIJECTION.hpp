// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_BIJECTION_HPP
#define INCLUDED_BIJECTION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct BIJECTION {
	struct field_3_t {
		enum type {
			literal_0x3C0x2D0x3E,
			literal_0xE20x860x94
		} value;
	
		static field_3_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
			static ::std::unordered_map<parlex::details::recognizer const *, type> const table {
				{ &plange_grammar().get_literal("literal_0x3C0x2D0x3E"), literal_0x3C0x2D0x3E },
				{ &plange_grammar().get_literal("literal_0xE20x860x94"), literal_0xE20x860x94 },
			};
			return field_3_t{ table.find(&n.r)->second };
		}
	};


	erased<EXPRESSION> field_1;
	std::vector<erased<IC>> field_2;
	field_3_t field_3;
	std::vector<erased<IC>> field_4;
	erased<EXPRESSION> field_5;


	explicit BIJECTION(
		erased<EXPRESSION> && field_1,
		std::vector<erased<IC>> && field_2,
		field_3_t && field_3,
		std::vector<erased<IC>> && field_4,
		erased<EXPRESSION> && field_5
	) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), field_5(std::move(field_5)) {}

	BIJECTION(BIJECTION const & other) = default;
	BIJECTION(BIJECTION && move) = default;

	static BIJECTION build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_BIJECTION_HPP
