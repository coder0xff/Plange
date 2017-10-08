// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_SUBSET_CHAIN_LOOP_HPP
#define INCLUDED_SUBSET_CHAIN_LOOP_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;
struct SUBSET_CHAIN_LOOP;

struct SUBSET_CHAIN_LOOP {
	struct field_1_t {
		enum type {
			literal_0x3D,
			literal_0xE20x8A0x82,
			literal_0xE20x8A0x86,
			literal_psubs,
			literal_subs
		} value;
	
		static field_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
			static ::std::unordered_map<parlex::details::recognizer const *, type> const table {
				{ &plange_grammar().get_literal("literal_0x3D"), literal_0x3D },
				{ &plange_grammar().get_literal("literal_0xE20x8A0x82"), literal_0xE20x8A0x82 },
				{ &plange_grammar().get_literal("literal_0xE20x8A0x86"), literal_0xE20x8A0x86 },
				{ &plange_grammar().get_literal("literal_psubs"), literal_psubs },
				{ &plange_grammar().get_literal("literal_subs"), literal_subs },
			};
			return field_1_t{ table.find(&n.r)->second };
		}
	};


	struct field_4_t_1_t {
		std::vector<erased<IC>> field_1;
		erased<SUBSET_CHAIN_LOOP> field_2;
	
	
		explicit field_4_t_1_t(
			std::vector<erased<IC>> && field_1,
			erased<SUBSET_CHAIN_LOOP> && field_2
		) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_4_t_1_t(field_4_t_1_t const & other) = default;
		field_4_t_1_t(field_4_t_1_t && move) = default;
	
		static field_4_t_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);
	
	};

	field_1_t field_1;
	std::vector<erased<IC>> field_2;
	erased<EXPRESSION> field_3;
	std::optional<field_4_t_1_t> field_4;


	explicit SUBSET_CHAIN_LOOP(
		field_1_t && field_1,
		std::vector<erased<IC>> && field_2,
		erased<EXPRESSION> && field_3,
		std::optional<field_4_t_1_t> && field_4
	) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)) {}

	SUBSET_CHAIN_LOOP(SUBSET_CHAIN_LOOP const & other) = default;
	SUBSET_CHAIN_LOOP(SUBSET_CHAIN_LOOP && move) = default;

	static SUBSET_CHAIN_LOOP build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_SUBSET_CHAIN_LOOP_HPP
