// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_XML_DOC_STRING_INTERIOR_HPP
#define INCLUDED_XML_DOC_STRING_INTERIOR_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct PAYLOAD;
struct XML_DOC_STRING_INTERIOR;

typedef std::variant<
	erased<PAYLOAD>,
	std::tuple<
		erased<XML_DOC_STRING_INTERIOR>
	>
> XML_DOC_STRING_INTERIOR;

#endif //INCLUDED_XML_DOC_STRING_INTERIOR_HPP
