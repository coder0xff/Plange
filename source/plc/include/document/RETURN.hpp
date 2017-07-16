// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_RETURN_HPP
#define INCLUDED_RETURN_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct EXPRESSION;
struct IC;

struct RETURN {
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		std::vector<erased<IC>>,
		erased<EXPRESSION>,
		std::vector<erased<IC>>
	>> field_1;
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		erased<EXPRESSION>
	>> field_2;

	RETURN(
		std::optional<std::tuple<
			std::vector<erased<IC>>,
			std::vector<erased<IC>>,
			erased<EXPRESSION>,
			std::vector<erased<IC>>
		>> const & field_1,
		std::optional<std::tuple<
			std::vector<erased<IC>>,
			erased<EXPRESSION>
		>> const & field_2
	) : field_1(field_1), field_2(field_2) {}
};



#endif //INCLUDED_RETURN_HPP
