// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_VOLATILE_IMPLICIT_TYPE_DEREFERENCE_HPP
#define INCLUDED_VOLATILE_IMPLICIT_TYPE_DEREFERENCE_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct IC;

struct VOLATILE_IMPLICIT_TYPE_DEREFERENCE {
	std::vector<erased<IC>> field_1;
	std::vector<erased<IC>> field_2;


	VOLATILE_IMPLICIT_TYPE_DEREFERENCE(
		std::vector<erased<IC>> const & field_1,
		std::vector<erased<IC>> const & field_2
	) : field_1(field_1), field_2(field_2) {}

	static std::optional<VOLATILE_IMPLICIT_TYPE_DEREFERENCE> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_VOLATILE_IMPLICIT_TYPE_DEREFERENCE_HPP
