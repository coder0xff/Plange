// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EMBEDDED_COMMENT_INTERIOR_HPP
#define INCLUDED_EMBEDDED_COMMENT_INTERIOR_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EMBEDDED_COMMENT_INTERIOR;

struct EMBEDDED_COMMENT_INTERIOR_1_t {
	parlex::detail::document::text<literal_0x2A_t> dontCare0;
	
	erased<EMBEDDED_COMMENT_INTERIOR> field_1;
	
	parlex::detail::document::text<literal_0x2A_t> dontCare2;
	


	explicit EMBEDDED_COMMENT_INTERIOR_1_t(
		parlex::detail::document::text<literal_0x2A_t> && dontCare0, erased<EMBEDDED_COMMENT_INTERIOR> && field_1, parlex::detail::document::text<literal_0x2A_t> && dontCare2) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), dontCare2(std::move(dontCare2)) {}

	EMBEDDED_COMMENT_INTERIOR_1_t(EMBEDDED_COMMENT_INTERIOR_1_t const & other) = default;
	EMBEDDED_COMMENT_INTERIOR_1_t(EMBEDDED_COMMENT_INTERIOR_1_t && move) = default;

	static EMBEDDED_COMMENT_INTERIOR_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
};

typedef std::variant<
	std::vector<parlex::detail::document::text<parlex::detail::all_t>>,
	EMBEDDED_COMMENT_INTERIOR_1_t
> EMBEDDED_COMMENT_INTERIOR_base;

struct EMBEDDED_COMMENT_INTERIOR: EMBEDDED_COMMENT_INTERIOR_base {
	static EMBEDDED_COMMENT_INTERIOR build(parlex::detail::ast_node const & n);
	explicit EMBEDDED_COMMENT_INTERIOR(EMBEDDED_COMMENT_INTERIOR_base const & value) : EMBEDDED_COMMENT_INTERIOR_base(value) {}
	static parlex::detail::state_machine const & state_machine();
};
} // namespace plc



#endif //INCLUDED_EMBEDDED_COMMENT_INTERIOR_HPP
