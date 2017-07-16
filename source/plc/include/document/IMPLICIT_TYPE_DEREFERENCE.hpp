// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_IMPLICIT_TYPE_DEREFERENCE_HPP
#define INCLUDED_IMPLICIT_TYPE_DEREFERENCE_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct IC;

struct IMPLICIT_TYPE_DEREFERENCE {
	std::vector<erased<IC>> field_1;

	IMPLICIT_TYPE_DEREFERENCE(
		std::vector<erased<IC>> const & field_1
	) : field_1(field_1) {}
};



#endif //INCLUDED_IMPLICIT_TYPE_DEREFERENCE_HPP
