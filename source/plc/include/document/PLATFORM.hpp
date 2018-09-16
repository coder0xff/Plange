// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_PLATFORM_HPP
#define INCLUDED_PLATFORM_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct PLATFORM {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal___t> dont_care0;
	
	std::variant<
		parlex::detail::document::text<parlex::detail::letter_t>,
		parlex::detail::document::text<parlex::detail::number_t>
	> field_1;
	
	std::vector<std::variant<
		parlex::detail::document::text<parlex::detail::letter_t>,
		parlex::detail::document::text<parlex::detail::number_t>,
		parlex::detail::document::text<literal___t>
	>> field_2;
	


	explicit PLATFORM
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal___t> && dont_care0, std::variant<
	parlex::detail::document::text<parlex::detail::letter_t>,
	parlex::detail::document::text<parlex::detail::number_t>
> && field_1, std::vector<std::variant<
	parlex::detail::document::text<parlex::detail::letter_t>,
	parlex::detail::document::text<parlex::detail::number_t>,
	parlex::detail::document::text<literal___t>
>> && field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(std::move(dont_care0)), field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	PLATFORM(PLATFORM const & other) = default;
	PLATFORM(PLATFORM && move) = default;

	static PLATFORM build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_PLATFORM_HPP
