// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_SCOPE_ASSIGNMENT_CHAIN_HPP
#define INCLUDED_TYPE_SCOPE_ASSIGNMENT_CHAIN_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ASSIGNMENT_CHAIN;
struct EXPRESSION;
struct IC;
struct IDENTIFIER;
struct MEMBER_OFFSET;
struct XML_DOC_STRING;

struct TYPE_SCOPE_ASSIGNMENT_CHAIN {
	struct field_1_t_1_t {
		erased<XML_DOC_STRING> field_1;
		std::vector<erased<IC>> field_2;
	
	
		explicit field_1_t_1_t(
			erased<XML_DOC_STRING> && field_1,
			std::vector<erased<IC>> && field_2
		) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_1_t_1_t(field_1_t_1_t const & other) = default;
		field_1_t_1_t(field_1_t_1_t && move) = default;
	
		static field_1_t_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);
	
	};

	struct field_3_t_1_t {
		std::vector<erased<IC>> field_1;
		erased<MEMBER_OFFSET> field_2;
	
	
		explicit field_3_t_1_t(
			std::vector<erased<IC>> && field_1,
			erased<MEMBER_OFFSET> && field_2
		) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_3_t_1_t(field_3_t_1_t const & other) = default;
		field_3_t_1_t(field_3_t_1_t && move) = default;
	
		static field_3_t_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);
	
	};

	struct field_5_t {
		enum type {
			literal_0x3C0x2D,
			literal_0xE20x860x90
		} value;
	
		static field_5_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
			static ::std::unordered_map<parlex::details::recognizer const *, type> const table {
				{ &plange_grammar().get_literal("literal_0x3C0x2D"), literal_0x3C0x2D },
				{ &plange_grammar().get_literal("literal_0xE20x860x90"), literal_0xE20x860x90 },
			};
			return field_5_t{ table.find(&n.r)->second };
		}
	};


	std::optional<field_1_t_1_t> field_1;
	erased<IDENTIFIER> field_2;
	std::optional<field_3_t_1_t> field_3;
	std::vector<erased<IC>> field_4;
	field_5_t field_5;
	std::vector<erased<IC>> field_6;
	std::variant<
		erased<EXPRESSION>,
		erased<ASSIGNMENT_CHAIN>
	> field_7;


	explicit TYPE_SCOPE_ASSIGNMENT_CHAIN(
		std::optional<field_1_t_1_t> && field_1,
		erased<IDENTIFIER> && field_2,
		std::optional<field_3_t_1_t> && field_3,
		std::vector<erased<IC>> && field_4,
		field_5_t && field_5,
		std::vector<erased<IC>> && field_6,
		std::variant<
			erased<EXPRESSION>,
			erased<ASSIGNMENT_CHAIN>
		> && field_7
	) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), field_5(std::move(field_5)), field_6(std::move(field_6)), field_7(std::move(field_7)) {}

	TYPE_SCOPE_ASSIGNMENT_CHAIN(TYPE_SCOPE_ASSIGNMENT_CHAIN const & other) = default;
	TYPE_SCOPE_ASSIGNMENT_CHAIN(TYPE_SCOPE_ASSIGNMENT_CHAIN && move) = default;

	static TYPE_SCOPE_ASSIGNMENT_CHAIN build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_TYPE_SCOPE_ASSIGNMENT_CHAIN_HPP
