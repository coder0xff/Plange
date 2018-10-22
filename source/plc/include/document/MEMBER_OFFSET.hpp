// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_MEMBER_OFFSET_HPP
#define INCLUDED_MEMBER_OFFSET_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct IC;
struct NATURAL_NUMBER;

struct MEMBER_OFFSET {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0x40_t> at;
	
	std::vector<val<IC>> ic;
	
	val<NATURAL_NUMBER> offset;
	


	explicit MEMBER_OFFSET
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x40_t> const & at, std::vector<val<IC>> const & ic, val<NATURAL_NUMBER> const & offset)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), at(at), ic(ic), offset(offset) {}

	MEMBER_OFFSET(MEMBER_OFFSET const & other) = default;
	static MEMBER_OFFSET build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_MEMBER_OFFSET_HPP
