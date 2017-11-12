// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EMBEDDED_COMMENT_HPP
#define INCLUDED_EMBEDDED_COMMENT_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EMBEDDED_COMMENT_INTERIOR;

struct EMBEDDED_COMMENT {
	parlex::details::document::text<literal_0x2F0x2A0x2A0x2A_t> dontCare0;
	
	erased<EMBEDDED_COMMENT_INTERIOR> field_1;
	
	parlex::details::document::text<literal_0x2A0x2A0x2A0x2F_t> dontCare2;
	


	explicit EMBEDDED_COMMENT(
		parlex::details::document::text<literal_0x2F0x2A0x2A0x2A_t> && dontCare0, erased<EMBEDDED_COMMENT_INTERIOR> && field_1, parlex::details::document::text<literal_0x2A0x2A0x2A0x2F_t> && dontCare2) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), dontCare2(std::move(dontCare2)) {}

	EMBEDDED_COMMENT(EMBEDDED_COMMENT const & other) = default;
	EMBEDDED_COMMENT(EMBEDDED_COMMENT && move) = default;

	static EMBEDDED_COMMENT build(parlex::details::ast_node const & n);
	static parlex::details::recognizer const & recognizer();

};


} // namespace plc



#endif //INCLUDED_EMBEDDED_COMMENT_HPP
