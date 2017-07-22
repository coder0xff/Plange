// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASM_SCOPE_HPP
#define INCLUDED_ASM_SCOPE_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct ASM_STATEMENT;
struct IC;

typedef std::vector<std::variant<
	erased<IC>,
	erased<ASM_STATEMENT>
>> ASM_SCOPE;

#endif //INCLUDED_ASM_SCOPE_HPP
