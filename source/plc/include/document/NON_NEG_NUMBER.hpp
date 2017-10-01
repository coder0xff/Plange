// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_NON_NEG_NUMBER_HPP
#define INCLUDED_NON_NEG_NUMBER_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct NON_NEG_FRACTIONAL;
struct NON_NEG_NON_FRACTIONAL;

typedef std::variant<
	erased<NON_NEG_NON_FRACTIONAL>,
	erased<NON_NEG_FRACTIONAL>
> NON_NEG_NUMBER_base;

struct NON_NEG_NUMBER: NON_NEG_NUMBER_base {
	static NON_NEG_NUMBER build(parlex::details::ast_node const & n);
	explicit NON_NEG_NUMBER(NON_NEG_NUMBER_base const & value) : NON_NEG_NUMBER_base(value) {}
};
} // namespace plc



#endif //INCLUDED_NON_NEG_NUMBER_HPP
