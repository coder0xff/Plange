// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_MODIFIER_0_HPP
#define INCLUDED_FUNCTION_MODIFIER_0_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct FUNCTION_MODIFIER_1;
struct FUNCTION_MODIFIER_STABILITY;

typedef std::variant<
	erased<FUNCTION_MODIFIER_STABILITY>,
	erased<FUNCTION_MODIFIER_1>
> FUNCTION_MODIFIER_0_base;

struct FUNCTION_MODIFIER_0: FUNCTION_MODIFIER_0_base {
	static std::optional<FUNCTION_MODIFIER_0> build(std::vector<parlex::details::match>::iterator & i);
	explicit FUNCTION_MODIFIER_0(FUNCTION_MODIFIER_0_base const & value) : FUNCTION_MODIFIER_0_base(value) {}
};
} // namespace plc



#endif //INCLUDED_FUNCTION_MODIFIER_0_HPP
