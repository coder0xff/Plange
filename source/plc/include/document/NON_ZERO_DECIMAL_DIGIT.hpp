// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_NON_ZERO_DECIMAL_DIGIT_HPP
#define INCLUDED_NON_ZERO_DECIMAL_DIGIT_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

typedef std::variant<
	literal_1_t,
	literal_2_t,
	literal_3_t,
	literal_4_t,
	literal_5_t,
	literal_6_t,
	literal_7_t,
	literal_8_t,
	literal_9_t
> NON_ZERO_DECIMAL_DIGIT_base;

struct NON_ZERO_DECIMAL_DIGIT: NON_ZERO_DECIMAL_DIGIT_base {
	static std::optional<NON_ZERO_DECIMAL_DIGIT> build(std::vector<parlex::details::match>::iterator & i);
	explicit NON_ZERO_DECIMAL_DIGIT(NON_ZERO_DECIMAL_DIGIT_base const & value) : NON_ZERO_DECIMAL_DIGIT_base(value) {}
};
} // namespace plc



#endif //INCLUDED_NON_ZERO_DECIMAL_DIGIT_HPP
