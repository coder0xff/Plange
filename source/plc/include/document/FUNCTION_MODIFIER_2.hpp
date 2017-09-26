// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_MODIFIER_2_HPP
#define INCLUDED_FUNCTION_MODIFIER_2_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct FUNCTION_MODIFIER_3;
struct FUNCTION_MODIFIER_ATOMIC;

typedef std::variant<
	erased<FUNCTION_MODIFIER_ATOMIC>,
	erased<FUNCTION_MODIFIER_3>
> FUNCTION_MODIFIER_2_base;

struct FUNCTION_MODIFIER_2: FUNCTION_MODIFIER_2_base {
	static std::optional<FUNCTION_MODIFIER_2> build(std::vector<parlex::details::match>::iterator & i);
	explicit FUNCTION_MODIFIER_2(FUNCTION_MODIFIER_2_base const & value) : FUNCTION_MODIFIER_2_base(value) {}
};
} // namespace plc



#endif //INCLUDED_FUNCTION_MODIFIER_2_HPP
