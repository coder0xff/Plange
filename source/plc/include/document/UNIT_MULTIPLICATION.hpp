// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_UNIT_MULTIPLICATION_HPP
#define INCLUDED_UNIT_MULTIPLICATION_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct DIMENSION;

struct UNIT_MULTIPLICATION {
	int32_t document_position, consumed_character_count;

	val<DIMENSION> field_1;
	
	parlex::detail::document::text<literal_0x2A_t> dont_care1;
	
	val<DIMENSION> field_2;
	


	explicit UNIT_MULTIPLICATION
		(int32_t documentPosition, int32_t consumedCharacterCount, val<DIMENSION> && field_1, parlex::detail::document::text<literal_0x2A_t> && dont_care1, val<DIMENSION> && field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(std::move(field_1)), dont_care1(std::move(dont_care1)), field_2(std::move(field_2)) {}

	UNIT_MULTIPLICATION(UNIT_MULTIPLICATION const & other) = default;
	UNIT_MULTIPLICATION(UNIT_MULTIPLICATION && move) = default;

	static UNIT_MULTIPLICATION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_UNIT_MULTIPLICATION_HPP
