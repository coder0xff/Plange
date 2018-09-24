// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EMBEDDED_NEWLINE_STRING_INTERIOR_HPP
#define INCLUDED_EMBEDDED_NEWLINE_STRING_INTERIOR_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EMBEDDED_NEWLINE_STRING_INTERIOR;
struct PAYLOAD;

struct EMBEDDED_NEWLINE_STRING_INTERIOR1_t {
	parlex::detail::document::text<literal_0x0A_t> dont_care0;
	
	val<PAYLOAD> payload;
	
	parlex::detail::document::text<literal_0x0A_t> dont_care2;
	


	explicit EMBEDDED_NEWLINE_STRING_INTERIOR1_t
		(parlex::detail::document::text<literal_0x0A_t> && dont_care0, val<PAYLOAD> && payload, parlex::detail::document::text<literal_0x0A_t> && dont_care2)
		: dont_care0(std::move(dont_care0)), payload(std::move(payload)), dont_care2(std::move(dont_care2)) {}

	EMBEDDED_NEWLINE_STRING_INTERIOR1_t(EMBEDDED_NEWLINE_STRING_INTERIOR1_t const & other) = default;
	EMBEDDED_NEWLINE_STRING_INTERIOR1_t(EMBEDDED_NEWLINE_STRING_INTERIOR1_t && move) = default;

	static EMBEDDED_NEWLINE_STRING_INTERIOR1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

struct EMBEDDED_NEWLINE_STRING_INTERIOR2_t {
	parlex::detail::document::text<literal_0x22_t> dont_care0;
	
	val<EMBEDDED_NEWLINE_STRING_INTERIOR> field_1;
	
	parlex::detail::document::text<literal_0x22_t> dont_care2;
	


	explicit EMBEDDED_NEWLINE_STRING_INTERIOR2_t
		(parlex::detail::document::text<literal_0x22_t> && dont_care0, val<EMBEDDED_NEWLINE_STRING_INTERIOR> && field_1, parlex::detail::document::text<literal_0x22_t> && dont_care2)
		: dont_care0(std::move(dont_care0)), field_1(std::move(field_1)), dont_care2(std::move(dont_care2)) {}

	EMBEDDED_NEWLINE_STRING_INTERIOR2_t(EMBEDDED_NEWLINE_STRING_INTERIOR2_t const & other) = default;
	EMBEDDED_NEWLINE_STRING_INTERIOR2_t(EMBEDDED_NEWLINE_STRING_INTERIOR2_t && move) = default;

	static EMBEDDED_NEWLINE_STRING_INTERIOR2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

typedef std::variant<
	EMBEDDED_NEWLINE_STRING_INTERIOR1_t,
	EMBEDDED_NEWLINE_STRING_INTERIOR2_t
> EMBEDDED_NEWLINE_STRING_INTERIOR_base;

struct EMBEDDED_NEWLINE_STRING_INTERIOR: EMBEDDED_NEWLINE_STRING_INTERIOR_base {
	static EMBEDDED_NEWLINE_STRING_INTERIOR build(parlex::detail::ast_node const & n);
	explicit EMBEDDED_NEWLINE_STRING_INTERIOR(EMBEDDED_NEWLINE_STRING_INTERIOR_base const & value) : EMBEDDED_NEWLINE_STRING_INTERIOR_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
} // namespace plc



#endif //INCLUDED_EMBEDDED_NEWLINE_STRING_INTERIOR_HPP
