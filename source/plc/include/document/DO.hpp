// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DO_HPP
#define INCLUDED_DO_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;
struct PARENTHETICAL;

struct DO {
	struct field_2_t_1_t {
		struct field_2_t {
			enum type {
				literal_until,
				literal_while
			} value;
		
			static field_2_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
				static ::std::unordered_map<parlex::details::recognizer const *, type> const table {
					{ &plange_grammar::get().get_literal("literal_until"), literal_until },
					{ &plange_grammar::get().get_literal("literal_while"), literal_while },
				};
				return field_2_t{ table.find(&n.r)->second };
			}
		};
	
	
		std::vector<erased<IC>> field_1;
		field_2_t field_2;
		std::vector<erased<IC>> field_3;
		erased<PARENTHETICAL> condition;
	
	
		explicit field_2_t_1_t(
			std::vector<erased<IC>> && field_1,
			field_2_t && field_2,
			std::vector<erased<IC>> && field_3,
			erased<PARENTHETICAL> && condition
		) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), condition(std::move(condition)) {}
	
		field_2_t_1_t(field_2_t_1_t const & other) = default;
		field_2_t_1_t(field_2_t_1_t && move) = default;
	
		static field_2_t_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);
	
	};

	std::vector<erased<IC>> field_1;
	erased<EXPRESSION> expression;
	std::optional<field_2_t_1_t> field_2;


	explicit DO(
		std::vector<erased<IC>> && field_1,
		erased<EXPRESSION> && expression,
		std::optional<field_2_t_1_t> && field_2
	) : field_1(std::move(field_1)), expression(std::move(expression)), field_2(std::move(field_2)) {}

	DO(DO const & other) = default;
	DO(DO && move) = default;

	static DO build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_DO_HPP
