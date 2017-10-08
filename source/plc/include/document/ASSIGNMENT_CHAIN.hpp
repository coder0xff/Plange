// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASSIGNMENT_CHAIN_HPP
#define INCLUDED_ASSIGNMENT_CHAIN_HPP

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
struct XML_DOC_STRING;

struct ASSIGNMENT_CHAIN {
	struct field_1_t_1_t {
		erased<XML_DOC_STRING> xml_doc_string;
		std::vector<erased<IC>> field_1;
	
	
		explicit field_1_t_1_t(
			erased<XML_DOC_STRING> && xml_doc_string,
			std::vector<erased<IC>> && field_1
		) : xml_doc_string(std::move(xml_doc_string)), field_1(std::move(field_1)) {}
	
		field_1_t_1_t(field_1_t_1_t const & other) = default;
		field_1_t_1_t(field_1_t_1_t && move) = default;
	
		static field_1_t_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);
	
	};

	struct field_3_t {
		enum type {
			literal_0x3C0x2D,
			literal_0xE20x860x90
		} value;
	
		static field_3_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
			static ::std::unordered_map<parlex::details::recognizer const *, type> const table {
				{ &plange_grammar().get_literal("literal_0x3C0x2D"), literal_0x3C0x2D },
				{ &plange_grammar().get_literal("literal_0xE20x860x90"), literal_0xE20x860x90 },
			};
			return field_3_t{ table.find(&n.r)->second };
		}
	};


	std::optional<field_1_t_1_t> field_1;
	erased<IDENTIFIER> identifier;
	std::vector<erased<IC>> field_2;
	field_3_t field_3;
	std::vector<erased<IC>> field_4;
	std::variant<
		erased<EXPRESSION>,
		erased<ASSIGNMENT_CHAIN>
	> field_5;


	explicit ASSIGNMENT_CHAIN(
		std::optional<field_1_t_1_t> && field_1,
		erased<IDENTIFIER> && identifier,
		std::vector<erased<IC>> && field_2,
		field_3_t && field_3,
		std::vector<erased<IC>> && field_4,
		std::variant<
			erased<EXPRESSION>,
			erased<ASSIGNMENT_CHAIN>
		> && field_5
	) : field_1(std::move(field_1)), identifier(std::move(identifier)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), field_5(std::move(field_5)) {}

	ASSIGNMENT_CHAIN(ASSIGNMENT_CHAIN const & other) = default;
	ASSIGNMENT_CHAIN(ASSIGNMENT_CHAIN && move) = default;

	static ASSIGNMENT_CHAIN build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_ASSIGNMENT_CHAIN_HPP
