// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DATE_HPP
#define INCLUDED_DATE_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct DATE_YEAR_DAY;
struct DATE_YEAR_MONTH_DAY;

typedef std::variant<
	erased<DATE_YEAR_MONTH_DAY>,
	erased<DATE_YEAR_DAY>
> DATE_base;

struct DATE: DATE_base {
	static std::optional<DATE> build(std::vector<parlex::details::match>::iterator & i);
	explicit DATE(DATE_base const & value) : DATE_base(value) {}
};
} // namespace plc



#endif //INCLUDED_DATE_HPP
