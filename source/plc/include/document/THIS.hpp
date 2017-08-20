// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_THIS_HPP
#define INCLUDED_THIS_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct EXPRESSION;
struct IC;

struct THIS {
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		std::vector<erased<IC>>,
		erased<EXPRESSION>,
		std::vector<erased<IC>>
	>> field_1;

	THIS(
		std::optional<std::tuple<
			std::vector<erased<IC>>,
			std::vector<erased<IC>>,
			erased<EXPRESSION>,
			std::vector<erased<IC>>
		>> const & field_1
	) : field_1(field_1) {}
};



#endif //INCLUDED_THIS_HPP