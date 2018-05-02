// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASM_SCOPE_HPP
#define INCLUDED_ASM_SCOPE_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ASM_STATEMENT;
struct IC;

typedef std::vector<std::variant<
	erased<IC>,
	erased<ASM_STATEMENT>
>> ASM_SCOPE_base;

struct ASM_SCOPE: ASM_SCOPE_base {
	static ASM_SCOPE build(parlex::detail::ast_node const & n);
	explicit ASM_SCOPE(ASM_SCOPE_base const & value) : ASM_SCOPE_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
} // namespace plc



#endif //INCLUDED_ASM_SCOPE_HPP
