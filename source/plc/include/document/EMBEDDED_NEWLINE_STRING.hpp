// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EMBEDDED_NEWLINE_STRING_HPP
#define INCLUDED_EMBEDDED_NEWLINE_STRING_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EMBEDDED_NEWLINE_STRING_INTERIOR;

struct EMBEDDED_NEWLINE_STRING {
	erased<EMBEDDED_NEWLINE_STRING_INTERIOR> field_1;


	explicit EMBEDDED_NEWLINE_STRING(
		erased<EMBEDDED_NEWLINE_STRING_INTERIOR> && field_1
	) : field_1(std::move(field_1)) {}

	EMBEDDED_NEWLINE_STRING(EMBEDDED_NEWLINE_STRING const & other) = default;
	EMBEDDED_NEWLINE_STRING(EMBEDDED_NEWLINE_STRING && move) = default;

	static EMBEDDED_NEWLINE_STRING build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_EMBEDDED_NEWLINE_STRING_HPP
