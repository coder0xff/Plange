// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DELTA_HPP
#define INCLUDED_DELTA_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EXPRESSION;
struct WHOLE_NUMBER;

struct DELTA {
	std::variant<
		literal_0xCE0x94_t,
		literal__delta__t
	> field_1;
	std::optional<std::tuple<
		erased<WHOLE_NUMBER>
	>> field_2;
	erased<EXPRESSION> expression;


	DELTA(
		std::variant<
			literal_0xCE0x94_t,
			literal__delta__t
		> const & field_1,
		std::optional<std::tuple<
			erased<WHOLE_NUMBER>
		>> const & field_2,
		erased<EXPRESSION> const & expression
	) : field_1(field_1), field_2(field_2), expression(expression) {}

	static std::optional<DELTA> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_DELTA_HPP
