// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EMBEDDED_NEWLINE_STRING_HPP
#define INCLUDED_EMBEDDED_NEWLINE_STRING_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EMBEDDED_NEWLINE_STRING_INTERIOR;

struct EMBEDDED_NEWLINE_STRING {
	parlex::details::document::text<literal_0x220x220x22_t> dontCare0;
	
	erased<EMBEDDED_NEWLINE_STRING_INTERIOR> field_1;
	
	parlex::details::document::text<literal_0x220x220x22_t> dontCare2;
	


	explicit EMBEDDED_NEWLINE_STRING(
		parlex::details::document::text<literal_0x220x220x22_t> && dontCare0, erased<EMBEDDED_NEWLINE_STRING_INTERIOR> && field_1, parlex::details::document::text<literal_0x220x220x22_t> && dontCare2) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), dontCare2(std::move(dontCare2)) {}

	EMBEDDED_NEWLINE_STRING(EMBEDDED_NEWLINE_STRING const & other) = default;
	EMBEDDED_NEWLINE_STRING(EMBEDDED_NEWLINE_STRING && move) = default;

	static EMBEDDED_NEWLINE_STRING build(parlex::details::ast_node const & n);
	static parlex::details::recognizer const & recognizer();

};


} // namespace plc



#endif //INCLUDED_EMBEDDED_NEWLINE_STRING_HPP
