// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_XML_DOC_STRING_HPP
#define INCLUDED_XML_DOC_STRING_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct XML_DOC_STRING_INTERIOR;

struct XML_DOC_STRING {
	erased<XML_DOC_STRING_INTERIOR> field_1;


	XML_DOC_STRING(
		erased<XML_DOC_STRING_INTERIOR> const & field_1
	) : field_1(field_1) {}

	static std::optional<XML_DOC_STRING> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_XML_DOC_STRING_HPP
