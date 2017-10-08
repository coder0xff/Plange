// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ALL_HPP
#define INCLUDED_ALL_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct ALL {
	struct field_1_t {
		enum type {
			literal_0xE20x880x80,
			literal_all
		} value;
	
		static field_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
			static ::std::unordered_map<parlex::details::recognizer const *, type> const table {
				{ &plange_grammar().get_literal("literal_0xE20x880x80"), literal_0xE20x880x80 },
				{ &plange_grammar().get_literal("literal_all"), literal_all },
			};
			return field_1_t{ table.find(&n.r)->second };
		}
	};


	field_1_t field_1;
	std::vector<erased<IC>> field_2;
	erased<EXPRESSION> field_3;


	explicit ALL(
		field_1_t && field_1,
		std::vector<erased<IC>> && field_2,
		erased<EXPRESSION> && field_3
	) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}

	ALL(ALL const & other) = default;
	ALL(ALL && move) = default;

	static ALL build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_ALL_HPP
