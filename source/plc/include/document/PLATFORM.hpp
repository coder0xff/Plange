// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_PLATFORM_HPP
#define INCLUDED_PLATFORM_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct PLATFORM {
	struct field_1_t {
		enum type {
			field_1_t_1_t,
			field_1_t_2_t
		} value;
	
		static field_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
			static ::std::unordered_map<parlex::details::recognizer const *, type> const table {
				{ &plange_grammar::get().get_literal("field_1_t_1_t"), field_1_t_1_t },
				{ &plange_grammar::get().get_literal("field_1_t_2_t"), field_1_t_2_t },
			};
			return field_1_t{ table.find(&n.r)->second };
		}
	};


	struct field_2_t_1_t {
		enum type {
			field_2_t_1_t_1_t,
			field_2_t_1_t_2_t,
			literal__
		} value;
	
		static field_2_t_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
			static ::std::unordered_map<parlex::details::recognizer const *, type> const table {
				{ &plange_grammar::get().get_literal("field_2_t_1_t_1_t"), field_2_t_1_t_1_t },
				{ &plange_grammar::get().get_literal("field_2_t_1_t_2_t"), field_2_t_1_t_2_t },
				{ &plange_grammar::get().get_literal("literal__"), literal__ },
			};
			return field_2_t_1_t{ table.find(&n.r)->second };
		}
	};


	field_1_t field_1;
	std::vector<field_2_t_1_t> field_2;


	explicit PLATFORM(
		field_1_t && field_1,
		std::vector<field_2_t_1_t> && field_2
	) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	PLATFORM(PLATFORM const & other) = default;
	PLATFORM(PLATFORM && move) = default;

	static PLATFORM build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_PLATFORM_HPP
