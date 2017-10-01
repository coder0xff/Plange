// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_END_OF_LINE_COMMENT_HPP
#define INCLUDED_END_OF_LINE_COMMENT_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct END_OF_LINE_COMMENT {
	int field_1;


	END_OF_LINE_COMMENT(
		int const & field_1
	) : field_1(field_1) {}

	static END_OF_LINE_COMMENT build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_END_OF_LINE_COMMENT_HPP
