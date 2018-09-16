﻿// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_IMPLEMENTS_HPP
#define INCLUDED_IMPLEMENTS_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct IMPLEMENTS {
	int32_t document_position, consumed_character_count;

	erased<EXPRESSION> field_1;
	
	std::vector<erased<IC>> field_2;
	
	parlex::detail::document::text<literal_implements_t> dont_care2;
	
	std::vector<erased<IC>> field_3;
	
	erased<EXPRESSION> field_4;
	


	explicit IMPLEMENTS
		(int32_t documentPosition, int32_t consumedCharacterCount, erased<EXPRESSION> && field_1, std::vector<erased<IC>> && field_2, parlex::detail::document::text<literal_implements_t> && dont_care2, std::vector<erased<IC>> && field_3, erased<EXPRESSION> && field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(std::move(field_1)), field_2(std::move(field_2)), dont_care2(std::move(dont_care2)), field_3(std::move(field_3)), field_4(std::move(field_4)) {}

	IMPLEMENTS(IMPLEMENTS const & other) = default;
	IMPLEMENTS(IMPLEMENTS && move) = default;

	static IMPLEMENTS build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_IMPLEMENTS_HPP
