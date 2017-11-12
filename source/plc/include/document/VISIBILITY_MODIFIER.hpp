// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_VISIBILITY_MODIFIER_HPP
#define INCLUDED_VISIBILITY_MODIFIER_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

typedef std::variant<
	parlex::details::document::text<literal_public_t>,
	parlex::details::document::text<literal_protected_t>,
	parlex::details::document::text<literal_protected0x20internal_t>,
	parlex::details::document::text<literal_internal_t>,
	parlex::details::document::text<literal_private_t>
> VISIBILITY_MODIFIER_base;

struct VISIBILITY_MODIFIER: VISIBILITY_MODIFIER_base {
	static VISIBILITY_MODIFIER build(parlex::details::ast_node const & n);
	explicit VISIBILITY_MODIFIER(VISIBILITY_MODIFIER_base const & value) : VISIBILITY_MODIFIER_base(value) {}
	static parlex::details::recognizer const & recognizer();
};
} // namespace plc



#endif //INCLUDED_VISIBILITY_MODIFIER_HPP
