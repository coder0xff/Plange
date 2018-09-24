// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_SET_COMPREHENSION_HPP
#define INCLUDED_SET_COMPREHENSION_HPP

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

struct SET_COMPREHENSION {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0x7B_t> dont_care0;
	
	std::vector<val<IC>> field_01;
	
	val<EXPRESSION> field_02;
	
	std::vector<val<IC>> field_03;
	
	parlex::detail::document::text<literal_0x7C_t> dont_care4;
	
	std::vector<val<IC>> field_04;
	
	val<EXPRESSION> field_05;
	
	std::vector<val<IC>> field_06;
	
	parlex::detail::document::text<literal_0x7D_t> dont_care8;
	


	explicit SET_COMPREHENSION
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x7B_t> && dont_care0, std::vector<val<IC>> && field_01, val<EXPRESSION> && field_02, std::vector<val<IC>> && field_03, parlex::detail::document::text<literal_0x7C_t> && dont_care4, std::vector<val<IC>> && field_04, val<EXPRESSION> && field_05, std::vector<val<IC>> && field_06, parlex::detail::document::text<literal_0x7D_t> && dont_care8)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(std::move(dont_care0)), field_01(std::move(field_01)), field_02(std::move(field_02)), field_03(std::move(field_03)), dont_care4(std::move(dont_care4)), field_04(std::move(field_04)), field_05(std::move(field_05)), field_06(std::move(field_06)), dont_care8(std::move(dont_care8)) {}

	SET_COMPREHENSION(SET_COMPREHENSION const & other) = default;
	SET_COMPREHENSION(SET_COMPREHENSION && move) = default;

	static SET_COMPREHENSION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_SET_COMPREHENSION_HPP
