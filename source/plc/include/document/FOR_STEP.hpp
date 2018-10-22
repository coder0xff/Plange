// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FOR_STEP_HPP
#define INCLUDED_FOR_STEP_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct FOR_STEP_NODE;
struct IC;
struct IDENTIFIER;

struct FOR_STEP {
	int32_t document_position, consumed_character_count;

	val<IDENTIFIER> identifier;
	
	std::vector<val<IC>> ic;
	
	val<FOR_STEP_NODE> for_step_node;
	


	explicit FOR_STEP
		(int32_t documentPosition, int32_t consumedCharacterCount, val<IDENTIFIER> const & identifier, std::vector<val<IC>> const & ic, val<FOR_STEP_NODE> const & for_step_node)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), identifier(identifier), ic(ic), for_step_node(for_step_node) {}

	FOR_STEP(FOR_STEP const & other) = default;
	static FOR_STEP build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_FOR_STEP_HPP
