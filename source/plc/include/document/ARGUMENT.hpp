// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ARGUMENT_HPP
#define INCLUDED_ARGUMENT_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EXPRESSION;

typedef erased<EXPRESSION> ARGUMENT_base;

struct ARGUMENT: ARGUMENT_base {
	static std::optional<ARGUMENT> build(std::vector<parlex::details::match>::iterator & i);
	explicit ARGUMENT(ARGUMENT_base const & value) : ARGUMENT_base(value) {}
};
} // namespace plc



#endif //INCLUDED_ARGUMENT_HPP
