// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DATE_TIME_HPP
#define INCLUDED_DATE_TIME_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct DATE;
struct TIME;

struct DATE_TIME {
	erased<DATE> field_1;
	
	parlex::details::document::text<literal_T_t> dontCare1;
	
	erased<TIME> field_2;
	


	explicit DATE_TIME(
		erased<DATE> && field_1, parlex::details::document::text<literal_T_t> && dontCare1, erased<TIME> && field_2) : field_1(std::move(field_1)), dontCare1(std::move(dontCare1)), field_2(std::move(field_2)) {}

	DATE_TIME(DATE_TIME const & other) = default;
	DATE_TIME(DATE_TIME && move) = default;

	static DATE_TIME build(parlex::details::ast_node const & n);
	static parlex::details::recognizer const & recognizer();

};


} // namespace plc



#endif //INCLUDED_DATE_TIME_HPP
