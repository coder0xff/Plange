// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EMBEDDED_NEWLINE_STRING_INTERIOR_HPP
#define INCLUDED_EMBEDDED_NEWLINE_STRING_INTERIOR_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EMBEDDED_NEWLINE_STRING_INTERIOR;

struct EMBEDDED_NEWLINE_STRING_INTERIOR_1_t {
	parlex::details::document::text<literal_0x0A_t> dontCare0;
	
	std::vector<parlex::details::document::text<parlex::details::all_t>> payload;
	
	parlex::details::document::text<literal_0x0A_t> dontCare2;
	


	explicit EMBEDDED_NEWLINE_STRING_INTERIOR_1_t(
		parlex::details::document::text<literal_0x0A_t> && dontCare0, std::vector<parlex::details::document::text<parlex::details::all_t>> && payload, parlex::details::document::text<literal_0x0A_t> && dontCare2) : dontCare0(std::move(dontCare0)), payload(std::move(payload)), dontCare2(std::move(dontCare2)) {}

	EMBEDDED_NEWLINE_STRING_INTERIOR_1_t(EMBEDDED_NEWLINE_STRING_INTERIOR_1_t const & other) = default;
	EMBEDDED_NEWLINE_STRING_INTERIOR_1_t(EMBEDDED_NEWLINE_STRING_INTERIOR_1_t && move) = default;

	static EMBEDDED_NEWLINE_STRING_INTERIOR_1_t build(parlex::details::behavior::node const * b, parlex::details::document::walk & w);
};

struct EMBEDDED_NEWLINE_STRING_INTERIOR_2_t {
	parlex::details::document::text<literal_0x22_t> dontCare0;
	
	erased<EMBEDDED_NEWLINE_STRING_INTERIOR> field_1;
	
	parlex::details::document::text<literal_0x22_t> dontCare2;
	


	explicit EMBEDDED_NEWLINE_STRING_INTERIOR_2_t(
		parlex::details::document::text<literal_0x22_t> && dontCare0, erased<EMBEDDED_NEWLINE_STRING_INTERIOR> && field_1, parlex::details::document::text<literal_0x22_t> && dontCare2) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), dontCare2(std::move(dontCare2)) {}

	EMBEDDED_NEWLINE_STRING_INTERIOR_2_t(EMBEDDED_NEWLINE_STRING_INTERIOR_2_t const & other) = default;
	EMBEDDED_NEWLINE_STRING_INTERIOR_2_t(EMBEDDED_NEWLINE_STRING_INTERIOR_2_t && move) = default;

	static EMBEDDED_NEWLINE_STRING_INTERIOR_2_t build(parlex::details::behavior::node const * b, parlex::details::document::walk & w);
};

typedef std::variant<
	EMBEDDED_NEWLINE_STRING_INTERIOR_1_t,
	EMBEDDED_NEWLINE_STRING_INTERIOR_2_t
> EMBEDDED_NEWLINE_STRING_INTERIOR_base;

struct EMBEDDED_NEWLINE_STRING_INTERIOR: EMBEDDED_NEWLINE_STRING_INTERIOR_base {
	static EMBEDDED_NEWLINE_STRING_INTERIOR build(parlex::details::ast_node const & n);
	explicit EMBEDDED_NEWLINE_STRING_INTERIOR(EMBEDDED_NEWLINE_STRING_INTERIOR_base const & value) : EMBEDDED_NEWLINE_STRING_INTERIOR_base(value) {}
	static parlex::details::recognizer const & recognizer();
};
} // namespace plc



#endif //INCLUDED_EMBEDDED_NEWLINE_STRING_INTERIOR_HPP
