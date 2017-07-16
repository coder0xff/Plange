// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_RECORD_HPP
#define INCLUDED_RECORD_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct ICR;
struct TYPE;

struct RECORD {
	std::vector<erased<ICR>> field_1;
	erased<TYPE> field_2;

	RECORD(
		std::vector<erased<ICR>> const & field_1,
		erased<TYPE> const & field_2
	) : field_1(field_1), field_2(field_2) {}
};



#endif //INCLUDED_RECORD_HPP
