// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_BLOCK_HPP
#define INCLUDED_BLOCK_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct STATEMENT_SCOPE;

struct BLOCK {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0x7B_t> dont_care0;
	
	erased<STATEMENT_SCOPE> field_1;
	
	parlex::detail::document::text<literal_0x7D_t> dont_care2;
	


	explicit BLOCK
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x7B_t> && dont_care0, erased<STATEMENT_SCOPE> && field_1, parlex::detail::document::text<literal_0x7D_t> && dont_care2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(std::move(dont_care0)), field_1(std::move(field_1)), dont_care2(std::move(dont_care2)) {}

	BLOCK(BLOCK const & other) = default;
	BLOCK(BLOCK && move) = default;

	static BLOCK build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_BLOCK_HPP
