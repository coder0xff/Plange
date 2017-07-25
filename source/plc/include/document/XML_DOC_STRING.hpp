// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_XML_DOC_STRING_HPP
#define INCLUDED_XML_DOC_STRING_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct XML_DOC_STRING_INTERIOR;

struct XML_DOC_STRING {
	erased<XML_DOC_STRING_INTERIOR> field_1;

	XML_DOC_STRING(
		erased<XML_DOC_STRING_INTERIOR> const & field_1
	) : field_1(field_1) {}
};



#endif //INCLUDED_XML_DOC_STRING_HPP
