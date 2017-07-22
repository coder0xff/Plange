// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_VOLATILE_IMPLICIT_TYPE_DEREFERENCE_HPP
#define INCLUDED_VOLATILE_IMPLICIT_TYPE_DEREFERENCE_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct IC;

struct VOLATILE_IMPLICIT_TYPE_DEREFERENCE {
	std::vector<erased<IC>> field_1;
	std::vector<erased<IC>> field_2;

	VOLATILE_IMPLICIT_TYPE_DEREFERENCE(
		std::vector<erased<IC>> const & field_1,
		std::vector<erased<IC>> const & field_2
	) : field_1(field_1), field_2(field_2) {}
};



#endif //INCLUDED_VOLATILE_IMPLICIT_TYPE_DEREFERENCE_HPP
