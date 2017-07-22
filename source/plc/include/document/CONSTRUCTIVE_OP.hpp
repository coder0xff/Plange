// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_CONSTRUCTIVE_OP_HPP
#define INCLUDED_CONSTRUCTIVE_OP_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct COMPOSITION;
struct COMPOUND;
struct NULL_COALESCE;
struct PREPEND;

typedef std::variant<
	erased<COMPOSITION>,
	erased<COMPOUND>,
	erased<PREPEND>,
	erased<NULL_COALESCE>
> CONSTRUCTIVE_OP;

#endif //INCLUDED_CONSTRUCTIVE_OP_HPP
