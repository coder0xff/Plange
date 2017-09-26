// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_MEMBER_OFFSET_HPP
#define INCLUDED_MEMBER_OFFSET_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct IC;
struct WHOLE_NUMBER;

struct MEMBER_OFFSET {
	std::vector<erased<IC>> field_1;
	erased<WHOLE_NUMBER> field_2;


	MEMBER_OFFSET(
		std::vector<erased<IC>> const & field_1,
		erased<WHOLE_NUMBER> const & field_2
	) : field_1(field_1), field_2(field_2) {}

	static std::optional<MEMBER_OFFSET> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_MEMBER_OFFSET_HPP
