// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_WHOLE_NUMBER_HPP
#define INCLUDED_WHOLE_NUMBER_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct WHOLE_NUMBER {
	struct field_1_t {
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
	
		static field_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
			static ::std::unordered_map<parlex::details::recognizer const *, type> const table {
				{ &plange_grammar().get_literal("literal_1"), literal_1 },
				{ &plange_grammar().get_literal("literal_2"), literal_2 },
				{ &plange_grammar().get_literal("literal_3"), literal_3 },
				{ &plange_grammar().get_literal("literal_4"), literal_4 },
				{ &plange_grammar().get_literal("literal_5"), literal_5 },
				{ &plange_grammar().get_literal("literal_6"), literal_6 },
				{ &plange_grammar().get_literal("literal_7"), literal_7 },
				{ &plange_grammar().get_literal("literal_8"), literal_8 },
				{ &plange_grammar().get_literal("literal_9"), literal_9 },
			};
			return field_1_t{ table.find(&n.r)->second };
		}
	};


	struct field_2_t_1_t {
		enum type {
			literal_0,
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
	
		static field_2_t_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
			static ::std::unordered_map<parlex::details::recognizer const *, type> const table {
				{ &plange_grammar().get_literal("literal_0"), literal_0 },
				{ &plange_grammar().get_literal("literal_1"), literal_1 },
				{ &plange_grammar().get_literal("literal_2"), literal_2 },
				{ &plange_grammar().get_literal("literal_3"), literal_3 },
				{ &plange_grammar().get_literal("literal_4"), literal_4 },
				{ &plange_grammar().get_literal("literal_5"), literal_5 },
				{ &plange_grammar().get_literal("literal_6"), literal_6 },
				{ &plange_grammar().get_literal("literal_7"), literal_7 },
				{ &plange_grammar().get_literal("literal_8"), literal_8 },
				{ &plange_grammar().get_literal("literal_9"), literal_9 },
			};
			return field_2_t_1_t{ table.find(&n.r)->second };
		}
	};


	field_1_t field_1;
	std::vector<field_2_t_1_t> field_2;


	explicit WHOLE_NUMBER(
		field_1_t && field_1,
		std::vector<field_2_t_1_t> && field_2
	) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	WHOLE_NUMBER(WHOLE_NUMBER const & other) = default;
	WHOLE_NUMBER(WHOLE_NUMBER && move) = default;

	static WHOLE_NUMBER build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_WHOLE_NUMBER_HPP
