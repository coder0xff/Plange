// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DATE_HPP
#define INCLUDED_DATE_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct DATE_YEAR_DAY;
struct DATE_YEAR_MONTH_DAY;

typedef std::variant<
	erased<DATE_YEAR_MONTH_DAY>,
	erased<DATE_YEAR_DAY>
> DATE_base;

struct DATE: DATE_base {
	static DATE build(parlex::details::ast_node const & n);
	explicit DATE(DATE_base const & value) : DATE_base(value) {}
	static parlex::details::recognizer const & recognizer();
};
} // namespace plc



#endif //INCLUDED_DATE_HPP
