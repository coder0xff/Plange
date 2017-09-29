// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_HPP
#define INCLUDED_FUNCTION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct BLOCK;
struct FUNCTION_MODIFIER_0;
struct IC;
struct PARAMETER;

struct FUNCTION {
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		std::optional<std::tuple<
			erased<PARAMETER>,
			std::vector<std::tuple<
				std::vector<erased<IC>>,
				std::vector<erased<IC>>,
				erased<PARAMETER>
			>>,
			std::vector<erased<IC>>
		>>,
		std::vector<erased<IC>>
	>> field_1;
	std::optional<std::tuple<
		erased<FUNCTION_MODIFIER_0>,
		std::vector<erased<IC>>
	>> field_2;
	erased<BLOCK> block;


	FUNCTION(
		std::optional<std::tuple<
			std::vector<erased<IC>>,
			std::optional<std::tuple<
				erased<PARAMETER>,
				std::vector<std::tuple<
					std::vector<erased<IC>>,
					std::vector<erased<IC>>,
					erased<PARAMETER>
				>>,
				std::vector<erased<IC>>
			>>,
			std::vector<erased<IC>>
		>> const & field_1,
		std::optional<std::tuple<
			erased<FUNCTION_MODIFIER_0>,
			std::vector<erased<IC>>
		>> const & field_2,
		erased<BLOCK> const & block
	) : field_1(field_1), field_2(field_2), block(block) {}

	static std::optional<FUNCTION> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_FUNCTION_HPP
