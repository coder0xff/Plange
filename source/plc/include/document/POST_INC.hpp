// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_POST_INC_HPP
#define INCLUDED_POST_INC_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct POST_INC {
	erased<EXPRESSION> field_1;
	std::vector<erased<IC>> field_2;


	POST_INC(
		erased<EXPRESSION> const & field_1,
		std::vector<erased<IC>> const & field_2
	) : field_1(field_1), field_2(field_2) {}

	static std::optional<POST_INC> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_POST_INC_HPP
