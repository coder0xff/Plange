// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_SWIZZLE_HPP
#define INCLUDED_SWIZZLE_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct SWIZZLE {
	struct field_3_t {
		enum type {
			literal_0xE20x8B0xAE,
			literal__swiz_
		} value;
	
		static field_3_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
			static ::std::unordered_map<parlex::details::recognizer const *, type> const table {
				{ &plange_grammar::get().get_literal("literal_0xE20x8B0xAE"), literal_0xE20x8B0xAE },
				{ &plange_grammar::get().get_literal("literal__swiz_"), literal__swiz_ },
			};
			return field_3_t{ table.find(&n.r)->second };
		}
	};


	erased<EXPRESSION> field_1;
	std::vector<erased<IC>> field_2;
	field_3_t field_3;
	std::vector<erased<IC>> field_4;
	erased<EXPRESSION> field_5;


	explicit SWIZZLE(
		erased<EXPRESSION> && field_1,
		std::vector<erased<IC>> && field_2,
		field_3_t && field_3,
		std::vector<erased<IC>> && field_4,
		erased<EXPRESSION> && field_5
	) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), field_5(std::move(field_5)) {}

	SWIZZLE(SWIZZLE const & other) = default;
	SWIZZLE(SWIZZLE && move) = default;

	static SWIZZLE build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_SWIZZLE_HPP
