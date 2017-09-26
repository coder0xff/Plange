// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_CEILING_HPP
#define INCLUDED_CEILING_HPP

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
> CEILING_base;

struct CEILING: CEILING_base {
	static std::optional<CEILING> build(std::vector<parlex::details::match>::iterator & i);
	explicit CEILING(CEILING_base const & value) : CEILING_base(value) {}
};
} // namespace plc



#endif //INCLUDED_CEILING_HPP
