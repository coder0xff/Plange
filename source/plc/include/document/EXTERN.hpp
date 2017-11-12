// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EXTERN_HPP
#define INCLUDED_EXTERN_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

typedef parlex::details::document::text<literal_extern_t> EXTERN_base;

struct EXTERN: EXTERN_base {
	static EXTERN build(parlex::details::ast_node const & n);
	explicit EXTERN(EXTERN_base const & value) : EXTERN_base(value) {}
	static parlex::details::recognizer const & recognizer();
};
} // namespace plc



#endif //INCLUDED_EXTERN_HPP
