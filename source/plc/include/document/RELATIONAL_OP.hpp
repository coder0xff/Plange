// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_RELATIONAL_OP_HPP
#define INCLUDED_RELATIONAL_OP_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct CASTS;
struct DOWNCASTS;
struct EXACTLY;
struct IMPLEMENTS;
struct INEQUALITY;
struct INHERITS;
struct IS;
struct RELATIONAL_COLLECTION_OP;
struct UPCASTS;

typedef std::variant<
	erased<CASTS>,
	erased<DOWNCASTS>,
	erased<EXACTLY>,
	erased<IMPLEMENTS>,
	erased<INEQUALITY>,
	erased<INHERITS>,
	erased<IS>,
	erased<RELATIONAL_COLLECTION_OP>,
	erased<UPCASTS>
> RELATIONAL_OP_base;

struct RELATIONAL_OP: RELATIONAL_OP_base {
	static RELATIONAL_OP build(parlex::detail::ast_node const & n);
	explicit RELATIONAL_OP(RELATIONAL_OP_base const & value) : RELATIONAL_OP_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
} // namespace plc



#endif //INCLUDED_RELATIONAL_OP_HPP
