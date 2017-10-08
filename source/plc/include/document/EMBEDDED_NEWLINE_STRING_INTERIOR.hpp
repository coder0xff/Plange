// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EMBEDDED_NEWLINE_STRING_INTERIOR_HPP
#define INCLUDED_EMBEDDED_NEWLINE_STRING_INTERIOR_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EMBEDDED_NEWLINE_STRING_INTERIOR;
struct PAYLOAD;

struct EMBEDDED_NEWLINE_STRING_INTERIOR_1_t {
	erased<PAYLOAD> field_1;


	explicit EMBEDDED_NEWLINE_STRING_INTERIOR_1_t(
		erased<PAYLOAD> && field_1
	) : field_1(std::move(field_1)) {}

	EMBEDDED_NEWLINE_STRING_INTERIOR_1_t(EMBEDDED_NEWLINE_STRING_INTERIOR_1_t const & other) = default;
	EMBEDDED_NEWLINE_STRING_INTERIOR_1_t(EMBEDDED_NEWLINE_STRING_INTERIOR_1_t && move) = default;

	static EMBEDDED_NEWLINE_STRING_INTERIOR_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};

struct EMBEDDED_NEWLINE_STRING_INTERIOR_2_t {
	erased<EMBEDDED_NEWLINE_STRING_INTERIOR> field_1;


	explicit EMBEDDED_NEWLINE_STRING_INTERIOR_2_t(
		erased<EMBEDDED_NEWLINE_STRING_INTERIOR> && field_1
	) : field_1(std::move(field_1)) {}

	EMBEDDED_NEWLINE_STRING_INTERIOR_2_t(EMBEDDED_NEWLINE_STRING_INTERIOR_2_t const & other) = default;
	EMBEDDED_NEWLINE_STRING_INTERIOR_2_t(EMBEDDED_NEWLINE_STRING_INTERIOR_2_t && move) = default;

	static EMBEDDED_NEWLINE_STRING_INTERIOR_2_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};

typedef std::variant<
	EMBEDDED_NEWLINE_STRING_INTERIOR_1_t,
	EMBEDDED_NEWLINE_STRING_INTERIOR_2_t
> EMBEDDED_NEWLINE_STRING_INTERIOR_base;

struct EMBEDDED_NEWLINE_STRING_INTERIOR: EMBEDDED_NEWLINE_STRING_INTERIOR_base {
	static EMBEDDED_NEWLINE_STRING_INTERIOR build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);
	explicit EMBEDDED_NEWLINE_STRING_INTERIOR(EMBEDDED_NEWLINE_STRING_INTERIOR_base const & value) : EMBEDDED_NEWLINE_STRING_INTERIOR_base(value) {}
};
} // namespace plc



#endif //INCLUDED_EMBEDDED_NEWLINE_STRING_INTERIOR_HPP
