// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TIME_HPP
#define INCLUDED_TIME_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct TIME {
	struct field_8_t_1_t {
		int field_2;
	
	
		explicit field_8_t_1_t(
			int && field_2
		) : field_2(std::move(field_2)) {}
	
		field_8_t_1_t(field_8_t_1_t const & other) = default;
		field_8_t_1_t(field_8_t_1_t && move) = default;
	
		static field_8_t_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);
	
	};

	struct field_9_t_1_t_1_t {
		struct field_1_t {
			enum type {
				literal_0x2B,
				literal_0x2D
			} value;
		
			static field_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
				static ::std::unordered_map<parlex::details::recognizer const *, type> const table {
					{ &plange_grammar().get_literal("literal_0x2B"), literal_0x2B },
					{ &plange_grammar().get_literal("literal_0x2D"), literal_0x2D },
				};
				return field_1_t{ table.find(&n.r)->second };
			}
		};
	
	
		struct field_4_t_1_t {
		
		
			explicit field_4_t_1_t(
			) {}
		
			field_4_t_1_t(field_4_t_1_t const & other) = default;
			field_4_t_1_t(field_4_t_1_t && move) = default;
		
			static field_4_t_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);
		
		};
	
		field_1_t field_1;
		std::optional<field_4_t_1_t> field_4;
	
	
		explicit field_9_t_1_t_1_t(
			field_1_t && field_1,
			std::optional<field_4_t_1_t> && field_4
		) : field_1(std::move(field_1)), field_4(std::move(field_4)) {}
	
		field_9_t_1_t_1_t(field_9_t_1_t_1_t const & other) = default;
		field_9_t_1_t_1_t(field_9_t_1_t_1_t && move) = default;
	
		static field_9_t_1_t_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);
	
	};

	bool field_1;
	std::optional<field_8_t_1_t> field_8;
	std::optional<std::variant<
		literal_Z_t,
		field_9_t_1_t_1_t
	>> field_9;


	explicit TIME(
		bool && field_1,
		std::optional<field_8_t_1_t> && field_8,
		std::optional<std::variant<
			literal_Z_t,
			field_9_t_1_t_1_t
		>> && field_9
	) : field_1(std::move(field_1)), field_8(std::move(field_8)), field_9(std::move(field_9)) {}

	TIME(TIME const & other) = default;
	TIME(TIME && move) = default;

	static TIME build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_TIME_HPP
