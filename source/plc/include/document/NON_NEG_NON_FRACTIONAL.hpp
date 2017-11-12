// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_NON_NEG_NON_FRACTIONAL_HPP
#define INCLUDED_NON_NEG_NON_FRACTIONAL_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct HEX;
struct NON_NEG_INTEGER;
struct OCTAL;

typedef std::variant<
	erased<NON_NEG_INTEGER>,
	erased<HEX>,
	erased<OCTAL>
> NON_NEG_NON_FRACTIONAL_base;

struct NON_NEG_NON_FRACTIONAL: NON_NEG_NON_FRACTIONAL_base {
	static NON_NEG_NON_FRACTIONAL build(parlex::details::ast_node const & n);
	explicit NON_NEG_NON_FRACTIONAL(NON_NEG_NON_FRACTIONAL_base const & value) : NON_NEG_NON_FRACTIONAL_base(value) {}
	static parlex::details::recognizer const & recognizer();
};
} // namespace plc



#endif //INCLUDED_NON_NEG_NON_FRACTIONAL_HPP
