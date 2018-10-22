// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FREE_HPP
#define INCLUDED_FREE_HPP

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

struct FREE {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_free_t> dont_care0;
	
	std::vector<val<IC>> ic;
	
	val<EXPRESSION> field_1;
	


	explicit FREE
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_free_t> const & dont_care0, std::vector<val<IC>> const & ic, val<EXPRESSION> const & field_1)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), ic(ic), field_1(field_1) {}

	FREE(FREE const & other) = default;
	static FREE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_FREE_HPP
