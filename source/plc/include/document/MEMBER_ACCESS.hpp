// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_MEMBER_ACCESS_HPP
#define INCLUDED_MEMBER_ACCESS_HPP

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
struct IDENTIFIER;

struct MEMBER_ACCESS {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x2E_t> dont_care2;
	
	std::vector<val<IC>> field_3;
	
	val<IDENTIFIER> field_4;
	


	explicit MEMBER_ACCESS
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, parlex::detail::document::text<literal_0x2E_t> const & dont_care2, std::vector<val<IC>> const & field_3, val<IDENTIFIER> const & field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), dont_care2(dont_care2), field_3(field_3), field_4(field_4) {}

	MEMBER_ACCESS(MEMBER_ACCESS const & other) = default;
	static MEMBER_ACCESS build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_MEMBER_ACCESS_HPP
