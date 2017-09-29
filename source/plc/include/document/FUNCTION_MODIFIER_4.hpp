// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_MODIFIER_4_HPP
#define INCLUDED_FUNCTION_MODIFIER_4_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct FUNCTION_MODIFIER_CALLING_CONVENTION;
struct FUNCTION_MODIFIER_MODEL;

typedef std::variant<
	erased<FUNCTION_MODIFIER_MODEL>,
	erased<FUNCTION_MODIFIER_CALLING_CONVENTION>
> FUNCTION_MODIFIER_4_base;

struct FUNCTION_MODIFIER_4: FUNCTION_MODIFIER_4_base {
	static std::optional<FUNCTION_MODIFIER_4> build(std::vector<parlex::details::match>::iterator & i);
	explicit FUNCTION_MODIFIER_4(FUNCTION_MODIFIER_4_base const & value) : FUNCTION_MODIFIER_4_base(value) {}
};
} // namespace plc



#endif //INCLUDED_FUNCTION_MODIFIER_4_HPP
