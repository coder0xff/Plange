// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_XML_DOC_STRING_INTERIOR_HPP
#define INCLUDED_XML_DOC_STRING_INTERIOR_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct PAYLOAD;
struct XML_DOC_STRING_INTERIOR;

typedef std::variant<
	erased<PAYLOAD>,
	std::tuple<
		erased<XML_DOC_STRING_INTERIOR>
	>
> XML_DOC_STRING_INTERIOR_base;

struct XML_DOC_STRING_INTERIOR: XML_DOC_STRING_INTERIOR_base {
	static std::optional<XML_DOC_STRING_INTERIOR> build(std::vector<parlex::details::match>::iterator & i);
	explicit XML_DOC_STRING_INTERIOR(XML_DOC_STRING_INTERIOR_base const & value) : XML_DOC_STRING_INTERIOR_base(value) {}
};
} // namespace plc



#endif //INCLUDED_XML_DOC_STRING_INTERIOR_HPP
