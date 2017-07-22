// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EMBEDDED_STRING_HPP
#define INCLUDED_EMBEDDED_STRING_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct EMBEDDED_STRING_INTERIOR;

struct EMBEDDED_STRING {
	erased<EMBEDDED_STRING_INTERIOR> field_1;

	EMBEDDED_STRING(
		erased<EMBEDDED_STRING_INTERIOR> const & field_1
	) : field_1(field_1) {}
};



#endif //INCLUDED_EMBEDDED_STRING_HPP
