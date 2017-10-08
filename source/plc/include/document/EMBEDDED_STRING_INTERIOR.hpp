// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EMBEDDED_STRING_INTERIOR_HPP
#define INCLUDED_EMBEDDED_STRING_INTERIOR_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EMBEDDED_STRING_INTERIOR;
struct PAYLOAD;

struct EMBEDDED_STRING_INTERIOR_2_t {
	erased<EMBEDDED_STRING_INTERIOR> field_1;


	explicit EMBEDDED_STRING_INTERIOR_2_t(
		erased<EMBEDDED_STRING_INTERIOR> && field_1
	) : field_1(std::move(field_1)) {}

	EMBEDDED_STRING_INTERIOR_2_t(EMBEDDED_STRING_INTERIOR_2_t const & other) = default;
	EMBEDDED_STRING_INTERIOR_2_t(EMBEDDED_STRING_INTERIOR_2_t && move) = default;

	static EMBEDDED_STRING_INTERIOR_2_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};

typedef std::variant<
	erased<PAYLOAD>,
	EMBEDDED_STRING_INTERIOR_2_t
> EMBEDDED_STRING_INTERIOR_base;

struct EMBEDDED_STRING_INTERIOR: EMBEDDED_STRING_INTERIOR_base {
	static EMBEDDED_STRING_INTERIOR build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);
	explicit EMBEDDED_STRING_INTERIOR(EMBEDDED_STRING_INTERIOR_base const & value) : EMBEDDED_STRING_INTERIOR_base(value) {}
};
} // namespace plc



#endif //INCLUDED_EMBEDDED_STRING_INTERIOR_HPP
