// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_SET_HPP
#define INCLUDED_SET_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct SET {
	std::vector<erased<IC>> field_1;
	std::optional<std::tuple<
		erased<EXPRESSION>,
		std::vector<std::tuple<
			std::vector<erased<IC>>,
			std::vector<erased<IC>>,
			erased<EXPRESSION>
		>>,
		std::vector<erased<IC>>
	>> field_2;


	SET(
		std::vector<erased<IC>> const & field_1,
		std::optional<std::tuple<
			erased<EXPRESSION>,
			std::vector<std::tuple<
				std::vector<erased<IC>>,
				std::vector<erased<IC>>,
				erased<EXPRESSION>
			>>,
			std::vector<erased<IC>>
		>> const & field_2
	) : field_1(field_1), field_2(field_2) {}

	static std::optional<SET> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_SET_HPP
