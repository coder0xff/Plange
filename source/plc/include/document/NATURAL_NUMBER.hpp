// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_NATURAL_NUMBER_HPP
#define INCLUDED_NATURAL_NUMBER_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct NATURAL_NUMBER {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_1;
	
	std::vector<parlex::detail::document::text<parlex::detail::decimal_digit_t>> field_2;
	


	explicit NATURAL_NUMBER
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_1, std::vector<parlex::detail::document::text<parlex::detail::decimal_digit_t>> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2) {}

	NATURAL_NUMBER(NATURAL_NUMBER const & other) = default;
	static NATURAL_NUMBER build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_NATURAL_NUMBER_HPP
