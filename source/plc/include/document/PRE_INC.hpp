// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_PRE_INC_HPP
#define INCLUDED_PRE_INC_HPP

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

struct PRE_INC {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0x2B0x2B_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<EXPRESSION> field_2;
	


	explicit PRE_INC
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x2B0x2B_t> const & dont_care0, std::vector<val<IC>> const & field_1, val<EXPRESSION> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), field_2(field_2) {}

	PRE_INC(PRE_INC const & other) = default;
	static PRE_INC build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_PRE_INC_HPP
