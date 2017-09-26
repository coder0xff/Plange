// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_WS_HPP
#define INCLUDED_WS_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct WS {
	int field_2;


	WS(
		int const & field_2
	) : field_2(field_2) {}

	static std::optional<WS> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_WS_HPP
