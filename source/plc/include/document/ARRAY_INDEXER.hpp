// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ARRAY_INDEXER_HPP
#define INCLUDED_ARRAY_INDEXER_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ARGUMENT_PACK;
struct EXPRESSION;
struct SLICE;

typedef std::variant<
	val<EXPRESSION>,
	val<ARGUMENT_PACK>,
	val<SLICE>
> ARRAY_INDEXER_base;

struct ARRAY_INDEXER: ARRAY_INDEXER_base {
	static ARRAY_INDEXER build(parlex::detail::ast_node const & n);
	explicit ARRAY_INDEXER(ARRAY_INDEXER_base const & value) : ARRAY_INDEXER_base(value) {}
	static parlex::detail::acceptor const & acceptor();
};
} // namespace plc



#endif //INCLUDED_ARRAY_INDEXER_HPP
