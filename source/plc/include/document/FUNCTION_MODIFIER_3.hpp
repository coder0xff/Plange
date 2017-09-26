// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_MODIFIER_3_HPP
#define INCLUDED_FUNCTION_MODIFIER_3_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct FUNCTION_MODIFIER_4;
struct FUNCTION_MODIFIER_PLATFORM;

typedef std::variant<
	erased<FUNCTION_MODIFIER_PLATFORM>,
	erased<FUNCTION_MODIFIER_4>
> FUNCTION_MODIFIER_3_base;

struct FUNCTION_MODIFIER_3: FUNCTION_MODIFIER_3_base {
	static std::optional<FUNCTION_MODIFIER_3> build(std::vector<parlex::details::match>::iterator & i);
	explicit FUNCTION_MODIFIER_3(FUNCTION_MODIFIER_3_base const & value) : FUNCTION_MODIFIER_3_base(value) {}
};
} // namespace plc



#endif //INCLUDED_FUNCTION_MODIFIER_3_HPP
