// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_STATEMENT_HPP
#define INCLUDED_TYPE_STATEMENT_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

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
> TYPE_STATEMENT;

#endif //INCLUDED_TYPE_STATEMENT_HPP
