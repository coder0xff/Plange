// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_POST_INC_HPP
#define INCLUDED_POST_INC_HPP

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

struct POST_INC {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	parlex::detail::document::text<literal_0x2B0x2B_t> dont_care2;
	


	explicit POST_INC
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> && field_1, std::vector<val<IC>> && field_2, parlex::detail::document::text<literal_0x2B0x2B_t> && dont_care2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(std::move(field_1)), field_2(std::move(field_2)), dont_care2(std::move(dont_care2)) {}

	POST_INC(POST_INC const & other) = default;
	POST_INC(POST_INC && move) = default;

	static POST_INC build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_POST_INC_HPP
