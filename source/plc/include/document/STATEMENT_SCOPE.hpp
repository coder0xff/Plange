// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_STATEMENT_SCOPE_HPP
#define INCLUDED_STATEMENT_SCOPE_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct IC;
struct STATEMENT;

typedef std::vector<std::variant<
	erased<IC>,
	erased<STATEMENT>
>> STATEMENT_SCOPE;

#endif //INCLUDED_STATEMENT_SCOPE_HPP
