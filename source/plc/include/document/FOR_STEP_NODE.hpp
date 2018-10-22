// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FOR_STEP_NODE_HPP
#define INCLUDED_FOR_STEP_NODE_HPP

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
struct FOR_STEP_NODE;
struct IC;
struct IDENTIFIER;

struct FOR_STEP_NODE {
	int32_t document_position, consumed_character_count;

	struct value_t {
		val<IDENTIFIER> identifier;
		
		std::vector<val<IC>> ic;
		
		val<FOR_STEP_NODE> next;
		
	
	
		explicit value_t
			(val<IDENTIFIER> const & identifier, std::vector<val<IC>> const & ic, val<FOR_STEP_NODE> const & next)
			: identifier(identifier), ic(ic), next(next) {}
	
		value_t(value_t const & other) = default;
		static value_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::variant<
		parlex::detail::document::text<literal_0xE20x860x90_t>,
		parlex::detail::document::text<literal_0x3C0x2D_t>
	> field_1;
	
	std::vector<val<IC>> ic;
	
	std::variant<
		val<EXPRESSION>,
		value_t
	> value;
	


	explicit FOR_STEP_NODE
		(int32_t documentPosition, int32_t consumedCharacterCount, std::variant<
	parlex::detail::document::text<literal_0xE20x860x90_t>,
	parlex::detail::document::text<literal_0x3C0x2D_t>
> const & field_1, std::vector<val<IC>> const & ic, std::variant<
	val<EXPRESSION>,
	value_t
> const & value)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), ic(ic), value(value) {}

	FOR_STEP_NODE(FOR_STEP_NODE const & other) = default;
	static FOR_STEP_NODE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_FOR_STEP_NODE_HPP
