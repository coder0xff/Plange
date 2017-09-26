// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_BREAK_HPP
#define INCLUDED_BREAK_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EXPRESSION;
struct IC;
struct ICR;
struct IDENTIFIER;

struct BREAK {
	std::optional<std::variant<
		std::tuple<
			std::vector<erased<IC>>,
			std::vector<erased<IC>>,
			erased<EXPRESSION>,
			std::vector<erased<IC>>
		>,
		std::tuple<
			std::vector<erased<ICR>>,
			erased<IDENTIFIER>
		>
	>> field_1;


	BREAK(
		std::optional<std::variant<
			std::tuple<
				std::vector<erased<IC>>,
				std::vector<erased<IC>>,
				erased<EXPRESSION>,
				std::vector<erased<IC>>
			>,
			std::tuple<
				std::vector<erased<ICR>>,
				erased<IDENTIFIER>
			>
		>> const & field_1
	) : field_1(field_1) {}

	static std::optional<BREAK> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_BREAK_HPP
