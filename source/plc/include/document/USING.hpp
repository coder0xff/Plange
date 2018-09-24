// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_USING_HPP
#define INCLUDED_USING_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct BLOCK;
struct EXPRESSION;
struct IC;

struct USING {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_using_t> dont_care0;
	
	std::vector<val<IC>> field_01;
	
	parlex::detail::document::text<literal_0x28_t> dont_care2;
	
	std::vector<val<IC>> field_02;
	
	val<EXPRESSION> field_03;
	
	std::vector<val<IC>> field_04;
	
	parlex::detail::document::text<literal_0x29_t> dont_care6;
	
	std::vector<val<IC>> field_05;
	
	val<BLOCK> field_06;
	


	explicit USING
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_using_t> && dont_care0, std::vector<val<IC>> && field_01, parlex::detail::document::text<literal_0x28_t> && dont_care2, std::vector<val<IC>> && field_02, val<EXPRESSION> && field_03, std::vector<val<IC>> && field_04, parlex::detail::document::text<literal_0x29_t> && dont_care6, std::vector<val<IC>> && field_05, val<BLOCK> && field_06)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(std::move(dont_care0)), field_01(std::move(field_01)), dont_care2(std::move(dont_care2)), field_02(std::move(field_02)), field_03(std::move(field_03)), field_04(std::move(field_04)), dont_care6(std::move(dont_care6)), field_05(std::move(field_05)), field_06(std::move(field_06)) {}

	USING(USING const & other) = default;
	USING(USING && move) = default;

	static USING build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_USING_HPP
