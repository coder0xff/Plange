// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_OCTAL_HPP
#define INCLUDED_OCTAL_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct OCTAL {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0_t> dont_care0;
	
	parlex::detail::document::text<parlex::detail::octal_digit_t> field_1;
	
	std::vector<parlex::detail::document::text<parlex::detail::octal_digit_t>> field_2;
	


	explicit OCTAL
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0_t> && dont_care0, parlex::detail::document::text<parlex::detail::octal_digit_t> && field_1, std::vector<parlex::detail::document::text<parlex::detail::octal_digit_t>> && field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(std::move(dont_care0)), field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	OCTAL(OCTAL const & other) = default;
	OCTAL(OCTAL && move) = default;

	static OCTAL build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_OCTAL_HPP
