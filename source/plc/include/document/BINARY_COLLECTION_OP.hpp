// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_BINARY_COLLECTION_OP_HPP
#define INCLUDED_BINARY_COLLECTION_OP_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct BIJECTION;
struct INTERSECTION;
struct SYMMETRIC_DIFFERENCE;
struct UNION;

typedef std::variant<
	erased<BIJECTION>,
	erased<INTERSECTION>,
	erased<SYMMETRIC_DIFFERENCE>,
	erased<UNION>
> BINARY_COLLECTION_OP_base;

struct BINARY_COLLECTION_OP: BINARY_COLLECTION_OP_base {
	static BINARY_COLLECTION_OP build(std::u32string const & document, parlex::details::ast_node const & n);
	explicit BINARY_COLLECTION_OP(BINARY_COLLECTION_OP_base const & value) : BINARY_COLLECTION_OP_base(value) {}
};
} // namespace plc



#endif //INCLUDED_BINARY_COLLECTION_OP_HPP
