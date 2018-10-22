// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_WHOLE_NUMBER_HPP
#define INCLUDED_WHOLE_NUMBER_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct NON_ZERO_DECIMAL_DIGIT;

struct WHOLE_NUMBER {
	int32_t document_position, consumed_character_count;

	std::vector<parlex::detail::document::text<literal_0_t>> field_1;
	
	val<NON_ZERO_DECIMAL_DIGIT> field_2;
	
	std::vector<parlex::detail::document::text<parlex::detail::decimal_digit_t>> field_3;
	


	explicit WHOLE_NUMBER
		(int32_t documentPosition, int32_t consumedCharacterCount, std::vector<parlex::detail::document::text<literal_0_t>> const & field_1, val<NON_ZERO_DECIMAL_DIGIT> const & field_2, std::vector<parlex::detail::document::text<parlex::detail::decimal_digit_t>> const & field_3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3) {}

	WHOLE_NUMBER(WHOLE_NUMBER const & other) = default;
	static WHOLE_NUMBER build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_WHOLE_NUMBER_HPP
