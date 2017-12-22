// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_STRING_HPP
#define INCLUDED_STRING_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

typedef std::string STRING_base;

struct STRING: STRING_base {
	static STRING build(std::u32string const & document, parlex::detail::ast_node const & n);
	explicit STRING(STRING_base const & value) : STRING_base(value) {}
};
} // namespace plc



#endif //INCLUDED_STRING_HPP
