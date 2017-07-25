// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_MODIFIER_4_HPP
#define INCLUDED_FUNCTION_MODIFIER_4_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct FUNCTION_MODIFIER_CALLING_CONVENTION;
struct FUNCTION_MODIFIER_MODEL;

typedef std::variant<
	erased<FUNCTION_MODIFIER_MODEL>,
	erased<FUNCTION_MODIFIER_CALLING_CONVENTION>
> FUNCTION_MODIFIER_4;

#endif //INCLUDED_FUNCTION_MODIFIER_4_HPP
