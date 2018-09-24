// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_SUBSET_NODE_HPP
#define INCLUDED_SUBSET_NODE_HPP

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
struct SUBSET_NODE;

struct SUBSET_NODE {
	int32_t document_position, consumed_character_count;

	struct field_2_t {
		std::vector<val<IC>> ic;
		
		val<SUBSET_NODE> subset_node;
		
	
	
		explicit field_2_t
			(std::vector<val<IC>> && ic, val<SUBSET_NODE> && subset_node)
			: ic(std::move(ic)), subset_node(std::move(subset_node)) {}
	
		field_2_t(field_2_t const & other) = default;
		field_2_t(field_2_t && move) = default;
	
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::variant<
		parlex::detail::document::text<literal_0x3D_t>,
		parlex::detail::document::text<literal_0xE20x8A0x86_t>,
		parlex::detail::document::text<literal_subs_t>,
		parlex::detail::document::text<literal_0xE20x8A0x82_t>,
		parlex::detail::document::text<literal_psubs_t>
	> field_1;
	
	std::vector<val<IC>> ic;
	
	val<EXPRESSION> expression;
	
	std::optional<field_2_t> field_2;
	


	explicit SUBSET_NODE
		(int32_t documentPosition, int32_t consumedCharacterCount, std::variant<
	parlex::detail::document::text<literal_0x3D_t>,
	parlex::detail::document::text<literal_0xE20x8A0x86_t>,
	parlex::detail::document::text<literal_subs_t>,
	parlex::detail::document::text<literal_0xE20x8A0x82_t>,
	parlex::detail::document::text<literal_psubs_t>
> && field_1, std::vector<val<IC>> && ic, val<EXPRESSION> && expression, std::optional<field_2_t> && field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(std::move(field_1)), ic(std::move(ic)), expression(std::move(expression)), field_2(std::move(field_2)) {}

	SUBSET_NODE(SUBSET_NODE const & other) = default;
	SUBSET_NODE(SUBSET_NODE && move) = default;

	static SUBSET_NODE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_SUBSET_NODE_HPP
