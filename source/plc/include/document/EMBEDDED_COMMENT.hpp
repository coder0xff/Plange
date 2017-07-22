// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EMBEDDED_COMMENT_HPP
#define INCLUDED_EMBEDDED_COMMENT_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct EMBEDDED_COMMENT_INTERIOR;

struct EMBEDDED_COMMENT {
	erased<EMBEDDED_COMMENT_INTERIOR> field_1;

	EMBEDDED_COMMENT(
		erased<EMBEDDED_COMMENT_INTERIOR> const & field_1
	) : field_1(field_1) {}
};



#endif //INCLUDED_EMBEDDED_COMMENT_HPP
