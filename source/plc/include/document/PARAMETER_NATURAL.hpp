// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_PARAMETER_NATURAL_HPP
#define INCLUDED_PARAMETER_NATURAL_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EXPRESSION;
struct IC;
struct IDENTIFIER;
struct IMPLICIT_TYPE_DEREFERENCE;
struct TYPE_DEREFERENCE;

typedef std::variant<
	std::tuple<
		std::optional<std::tuple<
			erased<TYPE_DEREFERENCE>,
			std::vector<erased<IC>>
		>>,
		erased<IDENTIFIER>,
		bool
	>,
	std::tuple<
		std::optional<std::tuple<
			std::variant<
				erased<TYPE_DEREFERENCE>,
				erased<IMPLICIT_TYPE_DEREFERENCE>
			>,
			std::vector<erased<IC>>
		>>,
		erased<IDENTIFIER>,
		bool,
		std::vector<erased<IC>>,
		std::vector<erased<IC>>,
		erased<EXPRESSION>,
		bool
	>
> PARAMETER_NATURAL_base;

struct PARAMETER_NATURAL: PARAMETER_NATURAL_base {
	static std::optional<PARAMETER_NATURAL> build(std::vector<parlex::details::match>::iterator & i);
	explicit PARAMETER_NATURAL(PARAMETER_NATURAL_base const & value) : PARAMETER_NATURAL_base(value) {}
};
} // namespace plc



#endif //INCLUDED_PARAMETER_NATURAL_HPP
