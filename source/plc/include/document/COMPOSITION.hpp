// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_COMPOSITION_HPP
#define INCLUDED_COMPOSITION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct COMPOSITION {
	struct field_3_t {
		enum type {
			literal_0xE20x880x98,
			literal__o_
		} value;
	
		static field_3_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
			static ::std::unordered_map<parlex::details::recognizer const *, type> const table {
				{ &plange_grammar::get().get_literal("literal_0xE20x880x98"), literal_0xE20x880x98 },
				{ &plange_grammar::get().get_literal("literal__o_"), literal__o_ },
			};
			return field_3_t{ table.find(&n.r)->second };
		}
	};


	erased<EXPRESSION> field_1;
	std::vector<erased<IC>> field_2;
	field_3_t field_3;
	std::vector<erased<IC>> field_4;
	erased<EXPRESSION> field_5;


	explicit COMPOSITION(
		erased<EXPRESSION> && field_1,
		std::vector<erased<IC>> && field_2,
		field_3_t && field_3,
		std::vector<erased<IC>> && field_4,
		erased<EXPRESSION> && field_5
	) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), field_5(std::move(field_5)) {}

	COMPOSITION(COMPOSITION const & other) = default;
	COMPOSITION(COMPOSITION && move) = default;

	static COMPOSITION build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_COMPOSITION_HPP
