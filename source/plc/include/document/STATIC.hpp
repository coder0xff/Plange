// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_STATIC_HPP
#define INCLUDED_STATIC_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

typedef parlex::details::document::text<literal_static_t> STATIC_base;

struct STATIC: STATIC_base {
	static STATIC build(parlex::details::ast_node const & n);
	explicit STATIC(STATIC_base const & value) : STATIC_base(value) {}
	static parlex::details::recognizer const & recognizer();
};
} // namespace plc



#endif //INCLUDED_STATIC_HPP
