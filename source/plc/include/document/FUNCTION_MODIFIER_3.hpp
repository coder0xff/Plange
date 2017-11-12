// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_MODIFIER_3_HPP
#define INCLUDED_FUNCTION_MODIFIER_3_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct FUNCTION_MODIFIER_4;
struct FUNCTION_MODIFIER_PLATFORM;

typedef std::variant<
	erased<FUNCTION_MODIFIER_PLATFORM>,
	erased<FUNCTION_MODIFIER_4>
> FUNCTION_MODIFIER_3_base;

struct FUNCTION_MODIFIER_3: FUNCTION_MODIFIER_3_base {
	static FUNCTION_MODIFIER_3 build(parlex::details::ast_node const & n);
	explicit FUNCTION_MODIFIER_3(FUNCTION_MODIFIER_3_base const & value) : FUNCTION_MODIFIER_3_base(value) {}
	static parlex::details::recognizer const & recognizer();
};
} // namespace plc



#endif //INCLUDED_FUNCTION_MODIFIER_3_HPP
