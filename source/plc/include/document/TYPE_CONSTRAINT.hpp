// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_CONSTRAINT_HPP
#define INCLUDED_TYPE_CONSTRAINT_HPP

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
struct TYPE_CONSTRAINT_CHAIN;
struct TYPE_CONSTRAINT_HEAD;

struct TYPE_CONSTRAINT {
	int32_t document_position, consumed_character_count;

	val<TYPE_CONSTRAINT_HEAD> field_1;
	
	std::vector<val<IC>> field_2;
	
	val<TYPE_CONSTRAINT_CHAIN> field_3;
	


	explicit TYPE_CONSTRAINT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<TYPE_CONSTRAINT_HEAD> && field_1, std::vector<val<IC>> && field_2, val<TYPE_CONSTRAINT_CHAIN> && field_3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}

	TYPE_CONSTRAINT(TYPE_CONSTRAINT const & other) = default;
	TYPE_CONSTRAINT(TYPE_CONSTRAINT && move) = default;

	static TYPE_CONSTRAINT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_TYPE_CONSTRAINT_HPP
