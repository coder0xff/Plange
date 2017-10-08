// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DATE_TIME_HPP
#define INCLUDED_DATE_TIME_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct DATE;
struct TIME;

struct DATE_TIME {
	erased<DATE> field_1;
	erased<TIME> field_2;


	explicit DATE_TIME(
		erased<DATE> && field_1,
		erased<TIME> && field_2
	) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	DATE_TIME(DATE_TIME const & other) = default;
	DATE_TIME(DATE_TIME && move) = default;

	static DATE_TIME build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_DATE_TIME_HPP
