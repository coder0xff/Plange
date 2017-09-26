// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_STATEMENT_HPP
#define INCLUDED_TYPE_STATEMENT_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct IC;
struct STATEMENT;
struct TYPE_SCOPE_TYPE_CONSTRAINT;
struct VISIBILITY_MODIFIER;

typedef std::variant<
	std::tuple<
		erased<VISIBILITY_MODIFIER>,
		std::vector<erased<IC>>
	>,
	erased<TYPE_SCOPE_TYPE_CONSTRAINT>,
	erased<STATEMENT>
> TYPE_STATEMENT_base;

struct TYPE_STATEMENT: TYPE_STATEMENT_base {
	static std::optional<TYPE_STATEMENT> build(std::vector<parlex::details::match>::iterator & i);
	explicit TYPE_STATEMENT(TYPE_STATEMENT_base const & value) : TYPE_STATEMENT_base(value) {}
};
} // namespace plc



#endif //INCLUDED_TYPE_STATEMENT_HPP
