// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_BLOCK_HPP
#define INCLUDED_BLOCK_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct STATEMENT_SCOPE;

struct BLOCK {
	erased<STATEMENT_SCOPE> field_1;


	explicit BLOCK(
		erased<STATEMENT_SCOPE> && field_1
	) : field_1(std::move(field_1)) {}

	BLOCK(BLOCK const & other) = default;
	BLOCK(BLOCK && move) = default;

	static BLOCK build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_BLOCK_HPP
