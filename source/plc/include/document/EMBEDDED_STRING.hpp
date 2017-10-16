// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EMBEDDED_STRING_HPP
#define INCLUDED_EMBEDDED_STRING_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EMBEDDED_STRING_INTERIOR;

struct EMBEDDED_STRING {
	erased<EMBEDDED_STRING_INTERIOR> field_1;
	


	explicit EMBEDDED_STRING(
		erased<EMBEDDED_STRING_INTERIOR> && field_1) : field_1(std::move(field_1)) {}

	EMBEDDED_STRING(EMBEDDED_STRING const & other) = default;
	EMBEDDED_STRING(EMBEDDED_STRING && move) = default;

	static EMBEDDED_STRING build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_EMBEDDED_STRING_HPP
