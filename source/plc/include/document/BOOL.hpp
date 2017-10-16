// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_BOOL_HPP
#define INCLUDED_BOOL_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

typedef std::variant<
	literal_true_t,
	literal_false_t
> BOOL_base;

struct BOOL: BOOL_base {
	static BOOL build(std::u32string const & document, parlex::details::ast_node const & n);
	explicit BOOL(BOOL_base const & value) : BOOL_base(value) {}
};
} // namespace plc



#endif //INCLUDED_BOOL_HPP
