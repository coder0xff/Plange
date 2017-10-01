// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_CONSTRUCTIVE_OP_HPP
#define INCLUDED_CONSTRUCTIVE_OP_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct COMPOSITION;
struct COMPOUND;
struct NULL_COALESCE;
struct PREPEND;

typedef std::variant<
	erased<COMPOSITION>,
	erased<COMPOUND>,
	erased<PREPEND>,
	erased<NULL_COALESCE>
> CONSTRUCTIVE_OP_base;

struct CONSTRUCTIVE_OP: CONSTRUCTIVE_OP_base {
	static CONSTRUCTIVE_OP build(parlex::details::ast_node const & n);
	explicit CONSTRUCTIVE_OP(CONSTRUCTIVE_OP_base const & value) : CONSTRUCTIVE_OP_base(value) {}
};
} // namespace plc



#endif //INCLUDED_CONSTRUCTIVE_OP_HPP
