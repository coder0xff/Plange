// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_NON_ZERO_DECIMAL_DIGIT_HPP
#define INCLUDED_NON_ZERO_DECIMAL_DIGIT_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct NON_ZERO_DECIMAL_DIGIT {
	enum type {
		literal_1,
		literal_2,
		literal_3,
		literal_4,
		literal_5,
		literal_6,
		literal_7,
		literal_8,
		literal_9
	} value;

	static NON_ZERO_DECIMAL_DIGIT build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
		static ::std::unordered_map<parlex::details::recognizer const *, type> const table {
			{ &plange_grammar::get().get_literal("literal_1"), literal_1 },
			{ &plange_grammar::get().get_literal("literal_2"), literal_2 },
			{ &plange_grammar::get().get_literal("literal_3"), literal_3 },
			{ &plange_grammar::get().get_literal("literal_4"), literal_4 },
			{ &plange_grammar::get().get_literal("literal_5"), literal_5 },
			{ &plange_grammar::get().get_literal("literal_6"), literal_6 },
			{ &plange_grammar::get().get_literal("literal_7"), literal_7 },
			{ &plange_grammar::get().get_literal("literal_8"), literal_8 },
			{ &plange_grammar::get().get_literal("literal_9"), literal_9 },
		};
		return NON_ZERO_DECIMAL_DIGIT{ table.find(&n.r)->second };
	}
};



} // namespace plc



#endif //INCLUDED_NON_ZERO_DECIMAL_DIGIT_HPP
