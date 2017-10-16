// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_XML_DOC_STRING_HPP
#define INCLUDED_XML_DOC_STRING_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct XML_DOC_STRING_INTERIOR;

struct XML_DOC_STRING {
	erased<XML_DOC_STRING_INTERIOR> field_1;
	


	explicit XML_DOC_STRING(
		erased<XML_DOC_STRING_INTERIOR> && field_1) : field_1(std::move(field_1)) {}

	XML_DOC_STRING(XML_DOC_STRING const & other) = default;
	XML_DOC_STRING(XML_DOC_STRING && move) = default;

	static XML_DOC_STRING build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_XML_DOC_STRING_HPP
