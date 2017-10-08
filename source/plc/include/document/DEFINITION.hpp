// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DEFINITION_HPP
#define INCLUDED_DEFINITION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;
struct IDENTIFIER;
struct XML_DOC_STRING;

struct DEFINITION {
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

	std::optional<field_1_t_1_t> field_1;
	erased<IDENTIFIER> identifier;
	std::vector<erased<IC>> field_2;
	std::vector<erased<IC>> field_3;
	erased<EXPRESSION> expression;


	explicit DEFINITION(
		std::optional<field_1_t_1_t> && field_1,
		erased<IDENTIFIER> && identifier,
		std::vector<erased<IC>> && field_2,
		std::vector<erased<IC>> && field_3,
		erased<EXPRESSION> && expression
	) : field_1(std::move(field_1)), identifier(std::move(identifier)), field_2(std::move(field_2)), field_3(std::move(field_3)), expression(std::move(expression)) {}

	DEFINITION(DEFINITION const & other) = default;
	DEFINITION(DEFINITION && move) = default;

	static DEFINITION build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_DEFINITION_HPP
