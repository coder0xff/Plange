// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_BOOL_HPP
#define INCLUDED_BOOL_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct BOOL {
	enum type {
		literal_false,
		literal_true
	} value;

	static BOOL build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
		static ::std::unordered_map<parlex::details::recognizer const *, type> const table {
			{ &plange_grammar::get().get_literal("literal_false"), literal_false },
			{ &plange_grammar::get().get_literal("literal_true"), literal_true },
		};
		return BOOL{ table.find(&n.r)->second };
	}
};



} // namespace plc



#endif //INCLUDED_BOOL_HPP
