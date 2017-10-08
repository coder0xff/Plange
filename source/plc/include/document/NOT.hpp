// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_NOT_HPP
#define INCLUDED_NOT_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct NOT {
	struct field_1_t {
		enum type {
			literal_0x7E,
			literal_0xC20xAC
		} value;
	
		static field_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
			static ::std::unordered_map<parlex::details::recognizer const *, type> const table {
				{ &plange_grammar().get_literal("literal_0x7E"), literal_0x7E },
				{ &plange_grammar().get_literal("literal_0xC20xAC"), literal_0xC20xAC },
			};
			return field_1_t{ table.find(&n.r)->second };
		}
	};


	field_1_t field_1;
	std::vector<erased<IC>> field_2;
	erased<EXPRESSION> field_3;


	explicit NOT(
		field_1_t && field_1,
		std::vector<erased<IC>> && field_2,
		erased<EXPRESSION> && field_3
	) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}

	NOT(NOT const & other) = default;
	NOT(NOT && move) = default;

	static NOT build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_NOT_HPP
