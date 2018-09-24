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
		(int32_t documentPosition, int32_t consumedCharacterCount, val<IDENTIFIER_SPECIFICATION> && identifier_specification, std::vector<val<IC>> && ic, val<ASSIGNMENT_NODE> && assignment_node)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), identifier_specification(std::move(identifier_specification)), ic(std::move(ic)), assignment_node(std::move(assignment_node)) {}

	ASSIGNMENT(ASSIGNMENT const & other) = default;
	ASSIGNMENT(ASSIGNMENT && move) = default;

	static ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_ASSIGNMENT_HPP
