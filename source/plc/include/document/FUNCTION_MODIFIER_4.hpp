// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_MODIFIER_4_HPP
#define INCLUDED_FUNCTION_MODIFIER_4_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct FUNCTION_MODIFIER_CALLING_CONVENTION;
struct FUNCTION_MODIFIER_MODEL;

typedef std::variant<
	erased<FUNCTION_MODIFIER_MODEL>,
	erased<FUNCTION_MODIFIER_CALLING_CONVENTION>
> FUNCTION_MODIFIER_4_base;

struct FUNCTION_MODIFIER_4: FUNCTION_MODIFIER_4_base {
	static FUNCTION_MODIFIER_4 build(parlex::detail::ast_node const & n);
	explicit FUNCTION_MODIFIER_4(FUNCTION_MODIFIER_4_base const & value) : FUNCTION_MODIFIER_4_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
} // namespace plc



#endif //INCLUDED_FUNCTION_MODIFIER_4_HPP
