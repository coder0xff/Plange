// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ARGUMENT_PACK_HPP
#define INCLUDED_ARGUMENT_PACK_HPP

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

struct ARGUMENT_PACK {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> expression;
	
	std::vector<val<IC>> field_1;
	
	parlex::detail::document::text<literal_0x2E0x2E0x2E_t> dont_care2;
	


	explicit ARGUMENT_PACK
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & expression, std::vector<val<IC>> const & field_1, parlex::detail::document::text<literal_0x2E0x2E0x2E_t> const & dont_care2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), expression(expression), field_1(field_1), dont_care2(dont_care2) {}

	ARGUMENT_PACK(ARGUMENT_PACK const & other) = default;
	static ARGUMENT_PACK build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_ARGUMENT_PACK_HPP
