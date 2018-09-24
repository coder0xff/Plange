// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DEFINITION_HPP
#define INCLUDED_DEFINITION_HPP

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
struct IDENTIFIER_SPECIFICATION;

struct DEFINITION {
	int32_t document_position, consumed_character_count;

	val<IDENTIFIER_SPECIFICATION> identifier_specification;
	
	std::vector<val<IC>> field_1;
	
	parlex::detail::document::text<literal_0x3A0x3D_t> dont_care2;
	
	std::vector<val<IC>> field_2;
	
	val<EXPRESSION> expression;
	


	explicit DEFINITION
		(int32_t documentPosition, int32_t consumedCharacterCount, val<IDENTIFIER_SPECIFICATION> && identifier_specification, std::vector<val<IC>> && field_1, parlex::detail::document::text<literal_0x3A0x3D_t> && dont_care2, std::vector<val<IC>> && field_2, val<EXPRESSION> && expression)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), identifier_specification(std::move(identifier_specification)), field_1(std::move(field_1)), dont_care2(std::move(dont_care2)), field_2(std::move(field_2)), expression(std::move(expression)) {}

	DEFINITION(DEFINITION const & other) = default;
	DEFINITION(DEFINITION && move) = default;

	static DEFINITION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_DEFINITION_HPP
