// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_BLOCK_HPP
#define INCLUDED_BLOCK_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct STATEMENT_SCOPE;

struct BLOCK {
	erased<STATEMENT_SCOPE> field_1;


	BLOCK(
		erased<STATEMENT_SCOPE> const & field_1
	) : field_1(field_1) {}

	static std::optional<BLOCK> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_BLOCK_HPP
