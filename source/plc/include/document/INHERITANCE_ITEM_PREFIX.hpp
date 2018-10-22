// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_INHERITANCE_ITEM_PREFIX_HPP
#define INCLUDED_INHERITANCE_ITEM_PREFIX_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct IC;
struct VISIBILITY_MODIFIER;

struct INHERITANCE_ITEM_PREFIX {
	int32_t document_position, consumed_character_count;

	struct field_1_t2 {
		val<VISIBILITY_MODIFIER> field_1;
		
		val<IC> field_2;
		
		std::vector<val<IC>> field_3;
		
		parlex::detail::document::text<literal_diamond_t> diamond;
		
	
	
		explicit field_1_t2
			(val<VISIBILITY_MODIFIER> const & field_1, val<IC> const & field_2, std::vector<val<IC>> const & field_3, parlex::detail::document::text<literal_diamond_t> const & diamond)
			: field_1(field_1), field_2(field_2), field_3(field_3), diamond(diamond) {}
	
		field_1_t2(field_1_t2 const & other) = default;
		static field_1_t2 build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::variant<
		val<VISIBILITY_MODIFIER>,
		field_1_t2,
		parlex::detail::document::text<literal_diamond_t>
	> field_1;
	
	val<IC> field_2;
	
	std::vector<val<IC>> field_3;
	


	explicit INHERITANCE_ITEM_PREFIX
		(int32_t documentPosition, int32_t consumedCharacterCount, std::variant<
	val<VISIBILITY_MODIFIER>,
	field_1_t2,
	parlex::detail::document::text<literal_diamond_t>
> const & field_1, val<IC> const & field_2, std::vector<val<IC>> const & field_3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), field_3(field_3) {}

	INHERITANCE_ITEM_PREFIX(INHERITANCE_ITEM_PREFIX const & other) = default;
	static INHERITANCE_ITEM_PREFIX build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_INHERITANCE_ITEM_PREFIX_HPP
