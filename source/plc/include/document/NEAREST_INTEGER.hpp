// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_NEAREST_INTEGER_HPP
#define INCLUDED_NEAREST_INTEGER_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

typedef std::variant<
	std::tuple<
		std::vector<erased<IC>>,
		erased<EXPRESSION>,
		std::vector<erased<IC>>
	>,
	std::tuple<
		std::vector<erased<IC>>,
		erased<EXPRESSION>,
		std::vector<erased<IC>>
	>
> NEAREST_INTEGER_base;

struct NEAREST_INTEGER: NEAREST_INTEGER_base {
	static std::optional<NEAREST_INTEGER> build(std::vector<parlex::details::match>::iterator & i);
	explicit NEAREST_INTEGER(NEAREST_INTEGER_base const & value) : NEAREST_INTEGER_base(value) {}
};
} // namespace plc



#endif //INCLUDED_NEAREST_INTEGER_HPP
