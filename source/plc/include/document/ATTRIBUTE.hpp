// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ATTRIBUTE_HPP
#define INCLUDED_ATTRIBUTE_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct ATTRIBUTE {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0x40_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<EXPRESSION> expression;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x40_t> dont_care4;
	


	explicit ATTRIBUTE
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x40_t> const & dont_care0, std::vector<val<IC>> const & field_1, val<EXPRESSION> const & expression, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x40_t> const & dont_care4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), expression(expression), field_2(field_2), dont_care4(dont_care4) {}

	ATTRIBUTE(ATTRIBUTE const & other) = default;
	static ATTRIBUTE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_ATTRIBUTE_HPP
