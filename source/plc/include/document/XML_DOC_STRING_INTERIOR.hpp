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

struct XML_DOC_STRING_INTERIOR;

struct XML_DOC_STRING_INTERIOR_1_t {
	parlex::details::document::text<literal_0x60_t> dontCare0;
	
	erased<XML_DOC_STRING_INTERIOR> field_1;
	
	parlex::details::document::text<literal_0x60_t> dontCare2;
	


	explicit XML_DOC_STRING_INTERIOR_1_t(
		parlex::details::document::text<literal_0x60_t> && dontCare0, erased<XML_DOC_STRING_INTERIOR> && field_1, parlex::details::document::text<literal_0x60_t> && dontCare2) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), dontCare2(std::move(dontCare2)) {}

	XML_DOC_STRING_INTERIOR_1_t(XML_DOC_STRING_INTERIOR_1_t const & other) = default;
	XML_DOC_STRING_INTERIOR_1_t(XML_DOC_STRING_INTERIOR_1_t && move) = default;

	static XML_DOC_STRING_INTERIOR_1_t build(parlex::details::behavior::node const * b, parlex::details::document::walk & w);
};

typedef std::variant<
	std::vector<parlex::details::document::text<parlex::details::all_t>>,
	XML_DOC_STRING_INTERIOR_1_t
> XML_DOC_STRING_INTERIOR_base;

struct XML_DOC_STRING_INTERIOR: XML_DOC_STRING_INTERIOR_base {
	static XML_DOC_STRING_INTERIOR build(parlex::details::ast_node const & n);
	explicit XML_DOC_STRING_INTERIOR(XML_DOC_STRING_INTERIOR_base const & value) : XML_DOC_STRING_INTERIOR_base(value) {}
	static parlex::details::recognizer const & recognizer();
};
} // namespace plc



#endif //INCLUDED_XML_DOC_STRING_INTERIOR_HPP
