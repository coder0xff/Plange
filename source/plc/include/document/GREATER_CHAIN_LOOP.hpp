// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_GREATER_CHAIN_LOOP_HPP
#define INCLUDED_GREATER_CHAIN_LOOP_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct GREATER_CHAIN_LOOP;
struct IC;

struct GREATER_CHAIN_LOOP {
	struct field_1_t {
		enum type {
			literal_0x3D,
			literal_0x3D0x3E,
			literal_0x3E,
			literal_0xE20x890xA5
		} value;
	
		static field_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
			static ::std::unordered_map<parlex::details::recognizer const *, type> const table {
				{ &plange_grammar::get().get_literal("literal_0x3D"), literal_0x3D },
				{ &plange_grammar::get().get_literal("literal_0x3D0x3E"), literal_0x3D0x3E },
				{ &plange_grammar::get().get_literal("literal_0x3E"), literal_0x3E },
				{ &plange_grammar::get().get_literal("literal_0xE20x890xA5"), literal_0xE20x890xA5 },
			};
			return field_1_t{ table.find(&n.r)->second };
		}
	};


	struct field_3_t_1_t {
		std::vector<erased<IC>> field_1;
		erased<GREATER_CHAIN_LOOP> greater_chain_loop;
	
	
		explicit field_3_t_1_t(
			std::vector<erased<IC>> && field_1,
			erased<GREATER_CHAIN_LOOP> && greater_chain_loop
		) : field_1(std::move(field_1)), greater_chain_loop(std::move(greater_chain_loop)) {}
	
		field_3_t_1_t(field_3_t_1_t const & other) = default;
		field_3_t_1_t(field_3_t_1_t && move) = default;
	
		static field_3_t_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);
	
	};

	field_1_t field_1;
	std::vector<erased<IC>> field_2;
	erased<EXPRESSION> expression;
	std::optional<field_3_t_1_t> field_3;


	explicit GREATER_CHAIN_LOOP(
		field_1_t && field_1,
		std::vector<erased<IC>> && field_2,
		erased<EXPRESSION> && expression,
		std::optional<field_3_t_1_t> && field_3
	) : field_1(std::move(field_1)), field_2(std::move(field_2)), expression(std::move(expression)), field_3(std::move(field_3)) {}

	GREATER_CHAIN_LOOP(GREATER_CHAIN_LOOP const & other) = default;
	GREATER_CHAIN_LOOP(GREATER_CHAIN_LOOP && move) = default;

	static GREATER_CHAIN_LOOP build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_GREATER_CHAIN_LOOP_HPP
