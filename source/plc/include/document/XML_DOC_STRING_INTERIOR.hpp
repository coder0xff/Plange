// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_XML_DOC_STRING_INTERIOR_HPP
#define INCLUDED_XML_DOC_STRING_INTERIOR_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct PAYLOAD;
struct XML_DOC_STRING_INTERIOR;

struct XML_DOC_STRING_INTERIOR_2_t {
	erased<XML_DOC_STRING_INTERIOR> field_1;
	


	explicit XML_DOC_STRING_INTERIOR_2_t(
		erased<XML_DOC_STRING_INTERIOR> && field_1) : field_1(std::move(field_1)) {}

	XML_DOC_STRING_INTERIOR_2_t(XML_DOC_STRING_INTERIOR_2_t const & other) = default;
	XML_DOC_STRING_INTERIOR_2_t(XML_DOC_STRING_INTERIOR_2_t && move) = default;

	static XML_DOC_STRING_INTERIOR_2_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);

};

typedef std::variant<
	erased<PAYLOAD>,
	XML_DOC_STRING_INTERIOR_2_t
> XML_DOC_STRING_INTERIOR_base;

struct XML_DOC_STRING_INTERIOR: XML_DOC_STRING_INTERIOR_base {
	static XML_DOC_STRING_INTERIOR build(std::u32string const & document, parlex::details::ast_node const & n);
	explicit XML_DOC_STRING_INTERIOR(XML_DOC_STRING_INTERIOR_base const & value) : XML_DOC_STRING_INTERIOR_base(value) {}
};
} // namespace plc



#endif //INCLUDED_XML_DOC_STRING_INTERIOR_HPP
