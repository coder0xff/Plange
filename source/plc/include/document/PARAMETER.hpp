// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_PARAMETER_HPP
#define INCLUDED_PARAMETER_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct PARAMETER_ANALYTIC;
struct PARAMETER_NATURAL;

typedef std::variant<
	erased<PARAMETER_NATURAL>,
	erased<PARAMETER_ANALYTIC>
> PARAMETER_base;

struct PARAMETER: PARAMETER_base {
	static std::optional<PARAMETER> build(std::vector<parlex::details::match>::iterator & i);
	explicit PARAMETER(PARAMETER_base const & value) : PARAMETER_base(value) {}
};
} // namespace plc



#endif //INCLUDED_PARAMETER_HPP
