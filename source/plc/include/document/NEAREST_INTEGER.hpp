// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_NEAREST_INTEGER_HPP
#define INCLUDED_NEAREST_INTEGER_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

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
> NEAREST_INTEGER;

#endif //INCLUDED_NEAREST_INTEGER_HPP
