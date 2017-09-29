// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_MODIFIER_ATOMIC_HPP
#define INCLUDED_FUNCTION_MODIFIER_ATOMIC_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct FUNCTION_MODIFIER_3;
struct ICR;

struct FUNCTION_MODIFIER_ATOMIC {
	std::optional<std::tuple<
		erased<ICR>,
		erased<FUNCTION_MODIFIER_3>
	>> field_1;


	FUNCTION_MODIFIER_ATOMIC(
		std::optional<std::tuple<
			erased<ICR>,
			erased<FUNCTION_MODIFIER_3>
		>> const & field_1
	) : field_1(field_1) {}

	static std::optional<FUNCTION_MODIFIER_ATOMIC> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_FUNCTION_MODIFIER_ATOMIC_HPP
