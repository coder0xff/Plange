// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_COMMENT_HPP
#define INCLUDED_COMMENT_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct COMMENT {
	int field_1;


	explicit COMMENT(
		int && field_1
	) : field_1(std::move(field_1)) {}

	COMMENT(COMMENT const & other) = default;
	COMMENT(COMMENT && move) = default;

	static COMMENT build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_COMMENT_HPP
