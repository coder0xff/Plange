// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_RELATIONAL_COLLECTION_OP_HPP
#define INCLUDED_RELATIONAL_COLLECTION_OP_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct HAS;
struct IN;
struct NOT_HAS;
struct NOT_IN;

typedef std::variant<
	erased<HAS>,
	erased<IN>,
	erased<NOT_HAS>,
	erased<NOT_IN>
> RELATIONAL_COLLECTION_OP_base;

struct RELATIONAL_COLLECTION_OP: RELATIONAL_COLLECTION_OP_base {
	static RELATIONAL_COLLECTION_OP build(parlex::detail::ast_node const & n);
	explicit RELATIONAL_COLLECTION_OP(RELATIONAL_COLLECTION_OP_base const & value) : RELATIONAL_COLLECTION_OP_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
} // namespace plc



#endif //INCLUDED_RELATIONAL_COLLECTION_OP_HPP
