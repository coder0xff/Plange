// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_SUPERSET_CHAIN_LOOP_HPP
#define INCLUDED_SUPERSET_CHAIN_LOOP_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;
struct SUPERSET_CHAIN_LOOP;

struct SUPERSET_CHAIN_LOOP {
	struct field_1_t {
		enum type {
			literal_0x3D,
			literal_0xE20x8A0x83,
			literal_0xE20x8A0x87,
			literal_psups,
			literal_sups
		} value;
	
		static field_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
			static ::std::unordered_map<parlex::details::recognizer const *, type> const table {
				{ &plange_grammar().get_literal("literal_0x3D"), literal_0x3D },
				{ &plange_grammar().get_literal("literal_0xE20x8A0x83"), literal_0xE20x8A0x83 },
				{ &plange_grammar().get_literal("literal_0xE20x8A0x87"), literal_0xE20x8A0x87 },
				{ &plange_grammar().get_literal("literal_psups"), literal_psups },
				{ &plange_grammar().get_literal("literal_sups"), literal_sups },
			};
			return field_1_t{ table.find(&n.r)->second };
		}
	};


	struct field_4_t_1_t {
		std::vector<erased<IC>> field_1;
		erased<SUPERSET_CHAIN_LOOP> field_2;
	
	
		explicit field_4_t_1_t(
			std::vector<erased<IC>> && field_1,
			erased<SUPERSET_CHAIN_LOOP> && field_2
		) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_4_t_1_t(field_4_t_1_t const & other) = default;
		field_4_t_1_t(field_4_t_1_t && move) = default;
	
		static field_4_t_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);
	
	};

	field_1_t field_1;
	std::vector<erased<IC>> field_2;
	erased<EXPRESSION> field_3;
	std::optional<field_4_t_1_t> field_4;


	explicit SUPERSET_CHAIN_LOOP(
		field_1_t && field_1,
		std::vector<erased<IC>> && field_2,
		erased<EXPRESSION> && field_3,
		std::optional<field_4_t_1_t> && field_4
	) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)) {}

	SUPERSET_CHAIN_LOOP(SUPERSET_CHAIN_LOOP const & other) = default;
	SUPERSET_CHAIN_LOOP(SUPERSET_CHAIN_LOOP && move) = default;

	static SUPERSET_CHAIN_LOOP build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_SUPERSET_CHAIN_LOOP_HPP
