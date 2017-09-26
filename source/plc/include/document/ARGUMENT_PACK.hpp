// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ARGUMENT_PACK_HPP
#define INCLUDED_ARGUMENT_PACK_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct ARGUMENT_PACK {
	erased<EXPRESSION> field_1;
	std::vector<erased<IC>> field_2;


	ARGUMENT_PACK(
		erased<EXPRESSION> const & field_1,
		std::vector<erased<IC>> const & field_2
	) : field_1(field_1), field_2(field_2) {}

	static std::optional<ARGUMENT_PACK> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_ARGUMENT_PACK_HPP
