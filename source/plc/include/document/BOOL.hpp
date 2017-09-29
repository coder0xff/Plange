// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_BOOL_HPP
#define INCLUDED_BOOL_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

typedef std::variant<
	literal_true_t,
	literal_false_t
> BOOL_base;

struct BOOL: BOOL_base {
	static std::optional<BOOL> build(std::vector<parlex::details::match>::iterator & i);
	explicit BOOL(BOOL_base const & value) : BOOL_base(value) {}
};
} // namespace plc



#endif //INCLUDED_BOOL_HPP
