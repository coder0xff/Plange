// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DOT_PRODUCT_HPP
#define INCLUDED_DOT_PRODUCT_HPP

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

struct DOT_PRODUCT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xE20x8B0x85_t>,
		parlex::detail::document::text<literal__dot__t>
	> field_3;
	
	std::vector<val<IC>> field_4;
	
	val<EXPRESSION> field_5;
	


	explicit DOT_PRODUCT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & field_1, std::vector<val<IC>> const & field_2, std::variant<
	parlex::detail::document::text<literal_0xE20x8B0x85_t>,
	parlex::detail::document::text<literal__dot__t>
> const & field_3, std::vector<val<IC>> const & field_4, val<EXPRESSION> const & field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	DOT_PRODUCT(DOT_PRODUCT const & other) = default;
	static DOT_PRODUCT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_DOT_PRODUCT_HPP
