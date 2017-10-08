// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_VISIBILITY_MODIFIER_HPP
#define INCLUDED_VISIBILITY_MODIFIER_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct VISIBILITY_MODIFIER {
	enum type {
		literal_internal,
		literal_private,
		literal_protected,
		literal_protected0x20internal,
		literal_public
	} value;

	static VISIBILITY_MODIFIER build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
		static ::std::unordered_map<parlex::details::recognizer const *, type> const table {
			{ &plange_grammar().get_literal("literal_internal"), literal_internal },
			{ &plange_grammar().get_literal("literal_private"), literal_private },
			{ &plange_grammar().get_literal("literal_protected"), literal_protected },
			{ &plange_grammar().get_literal("literal_protected0x20internal"), literal_protected0x20internal },
			{ &plange_grammar().get_literal("literal_public"), literal_public },
		};
		return VISIBILITY_MODIFIER{ table.find(&n.r)->second };
	}
};



} // namespace plc



#endif //INCLUDED_VISIBILITY_MODIFIER_HPP
