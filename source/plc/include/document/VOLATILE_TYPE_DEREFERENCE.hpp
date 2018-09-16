// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_VOLATILE_TYPE_DEREFERENCE_HPP
#define INCLUDED_VOLATILE_TYPE_DEREFERENCE_HPP

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

struct VOLATILE_TYPE_DEREFERENCE {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0x3C_t> dont_care0;
	
	std::vector<erased<IC>> field_1;
	
	parlex::detail::document::text<literal_volatile_t> dont_care2;
	
	std::vector<erased<IC>> field_2;
	
	erased<EXPRESSION> field_3;
	
	std::vector<erased<IC>> field_4;
	
	parlex::detail::document::text<literal_0x3E_t> dont_care6;
	


	explicit VOLATILE_TYPE_DEREFERENCE
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x3C_t> && dont_care0, std::vector<erased<IC>> && field_1, parlex::detail::document::text<literal_volatile_t> && dont_care2, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && field_3, std::vector<erased<IC>> && field_4, parlex::detail::document::text<literal_0x3E_t> && dont_care6)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(std::move(dont_care0)), field_1(std::move(field_1)), dont_care2(std::move(dont_care2)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), dont_care6(std::move(dont_care6)) {}

	VOLATILE_TYPE_DEREFERENCE(VOLATILE_TYPE_DEREFERENCE const & other) = default;
	VOLATILE_TYPE_DEREFERENCE(VOLATILE_TYPE_DEREFERENCE && move) = default;

	static VOLATILE_TYPE_DEREFERENCE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_VOLATILE_TYPE_DEREFERENCE_HPP
