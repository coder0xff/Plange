// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASSIGNMENT_HPP
#define INCLUDED_ASSIGNMENT_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ASSIGNMENT_NODE;
struct IC;
struct IDENTIFIER_SPECIFICATION;

struct ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<IDENTIFIER_SPECIFICATION> identifier_specification;
	
	std::vector<val<IC>> ic;
	
	val<ASSIGNMENT_NODE> assignment_node;
	


	explicit ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<IDENTIFIER_SPECIFICATION> const & identifier_specification, std::vector<val<IC>> const & ic, val<ASSIGNMENT_NODE> const & assignment_node)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), identifier_specification(identifier_specification), ic(ic), assignment_node(assignment_node) {}

	ASSIGNMENT(ASSIGNMENT const & other) = default;
	static ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_ASSIGNMENT_HPP
