// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_MODIFIER_2_HPP
#define INCLUDED_FUNCTION_MODIFIER_2_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct FUNCTION_MODIFIER_3;
struct FUNCTION_MODIFIER_ATOMIC;

typedef std::variant<
	erased<FUNCTION_MODIFIER_ATOMIC>,
	erased<FUNCTION_MODIFIER_3>
> FUNCTION_MODIFIER_2_base;

struct FUNCTION_MODIFIER_2: FUNCTION_MODIFIER_2_base {
	static FUNCTION_MODIFIER_2 build(std::u32string const & document, parlex::details::ast_node const & n);
	explicit FUNCTION_MODIFIER_2(FUNCTION_MODIFIER_2_base const & value) : FUNCTION_MODIFIER_2_base(value) {}
};
} // namespace plc



#endif //INCLUDED_FUNCTION_MODIFIER_2_HPP
