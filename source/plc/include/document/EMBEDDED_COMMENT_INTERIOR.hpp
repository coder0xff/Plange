// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EMBEDDED_COMMENT_INTERIOR_HPP
#define INCLUDED_EMBEDDED_COMMENT_INTERIOR_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EMBEDDED_COMMENT_INTERIOR;
struct PAYLOAD;

struct EMBEDDED_COMMENT_INTERIOR_2_t {
	erased<EMBEDDED_COMMENT_INTERIOR> field_1;
	


	explicit EMBEDDED_COMMENT_INTERIOR_2_t(
		erased<EMBEDDED_COMMENT_INTERIOR> && field_1) : field_1(std::move(field_1)) {}

	EMBEDDED_COMMENT_INTERIOR_2_t(EMBEDDED_COMMENT_INTERIOR_2_t const & other) = default;
	EMBEDDED_COMMENT_INTERIOR_2_t(EMBEDDED_COMMENT_INTERIOR_2_t && move) = default;

	static EMBEDDED_COMMENT_INTERIOR_2_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);

};

typedef std::variant<
	erased<PAYLOAD>,
	EMBEDDED_COMMENT_INTERIOR_2_t
> EMBEDDED_COMMENT_INTERIOR_base;

struct EMBEDDED_COMMENT_INTERIOR: EMBEDDED_COMMENT_INTERIOR_base {
	static EMBEDDED_COMMENT_INTERIOR build(std::u32string const & document, parlex::details::ast_node const & n);
	explicit EMBEDDED_COMMENT_INTERIOR(EMBEDDED_COMMENT_INTERIOR_base const & value) : EMBEDDED_COMMENT_INTERIOR_base(value) {}
};
} // namespace plc



#endif //INCLUDED_EMBEDDED_COMMENT_INTERIOR_HPP
