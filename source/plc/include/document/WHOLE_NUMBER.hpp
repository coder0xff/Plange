// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_WHOLE_NUMBER_HPP
#define INCLUDED_WHOLE_NUMBER_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct WHOLE_NUMBER {
	std::variant<
		literal_1_t,
		literal_2_t,
		literal_3_t,
		literal_4_t,
		literal_5_t,
		literal_6_t,
		literal_7_t,
		literal_8_t,
		literal_9_t
	> field_1;
	std::vector<std::variant<
		literal_0_t,
		literal_1_t,
		literal_2_t,
		literal_3_t,
		literal_4_t,
		literal_5_t,
		literal_6_t,
		literal_7_t,
		literal_8_t,
		literal_9_t
	>> field_2;


	WHOLE_NUMBER(
		std::variant<
			literal_1_t,
			literal_2_t,
			literal_3_t,
			literal_4_t,
			literal_5_t,
			literal_6_t,
			literal_7_t,
			literal_8_t,
			literal_9_t
		> const & field_1,
		std::vector<std::variant<
			literal_0_t,
			literal_1_t,
			literal_2_t,
			literal_3_t,
			literal_4_t,
			literal_5_t,
			literal_6_t,
			literal_7_t,
			literal_8_t,
			literal_9_t
		>> const & field_2
	) : field_1(field_1), field_2(field_2) {}

	static std::optional<WHOLE_NUMBER> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_WHOLE_NUMBER_HPP
