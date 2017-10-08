// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DATE_YEAR_MONTH_DAY_HPP
#define INCLUDED_DATE_YEAR_MONTH_DAY_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct DATE_YEAR_MONTH_DAY {


	explicit DATE_YEAR_MONTH_DAY(
	) {}

	DATE_YEAR_MONTH_DAY(DATE_YEAR_MONTH_DAY const & other) = default;
	DATE_YEAR_MONTH_DAY(DATE_YEAR_MONTH_DAY && move) = default;

	static DATE_YEAR_MONTH_DAY build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_DATE_YEAR_MONTH_DAY_HPP
