// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_RECORD_HPP
#define INCLUDED_RECORD_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct ICR;
struct TYPE;

struct RECORD {
	std::vector<erased<ICR>> field_1;
	erased<TYPE> field_2;


	RECORD(
		std::vector<erased<ICR>> const & field_1,
		erased<TYPE> const & field_2
	) : field_1(field_1), field_2(field_2) {}

	static std::optional<RECORD> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_RECORD_HPP
