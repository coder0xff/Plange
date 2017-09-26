// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EMBEDDED_NEWLINE_STRING_HPP
#define INCLUDED_EMBEDDED_NEWLINE_STRING_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EMBEDDED_NEWLINE_STRING_INTERIOR;

struct EMBEDDED_NEWLINE_STRING {
	erased<EMBEDDED_NEWLINE_STRING_INTERIOR> field_1;


	EMBEDDED_NEWLINE_STRING(
		erased<EMBEDDED_NEWLINE_STRING_INTERIOR> const & field_1
	) : field_1(field_1) {}

	static std::optional<EMBEDDED_NEWLINE_STRING> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_EMBEDDED_NEWLINE_STRING_HPP
