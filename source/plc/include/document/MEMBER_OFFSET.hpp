// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_MEMBER_OFFSET_HPP
#define INCLUDED_MEMBER_OFFSET_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct IC;
struct WHOLE_NUMBER;

struct MEMBER_OFFSET {
	std::vector<erased<IC>> field_1;
	erased<WHOLE_NUMBER> field_2;

	MEMBER_OFFSET(
		std::vector<erased<IC>> const & field_1,
		erased<WHOLE_NUMBER> const & field_2
	) : field_1(field_1), field_2(field_2) {}
};



#endif //INCLUDED_MEMBER_OFFSET_HPP
