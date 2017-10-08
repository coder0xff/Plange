// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_RANGE_HPP
#define INCLUDED_RANGE_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct RANGE_1_t {
	struct field_5_t {
		enum type {
			literal_0x29,
			literal_0x5D
		} value;
	
		static field_5_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
			static ::std::unordered_map<parlex::details::recognizer const *, type> const table {
				{ &plange_grammar().get_literal("literal_0x29"), literal_0x29 },
				{ &plange_grammar().get_literal("literal_0x5D"), literal_0x5D },
			};
			return field_5_t{ table.find(&n.r)->second };
		}
	};


	std::vector<erased<IC>> field_1;
	std::vector<erased<IC>> field_2;
	erased<EXPRESSION> field_3;
	std::vector<erased<IC>> field_4;
	field_5_t field_5;


	explicit RANGE_1_t(
		std::vector<erased<IC>> && field_1,
		std::vector<erased<IC>> && field_2,
		erased<EXPRESSION> && field_3,
		std::vector<erased<IC>> && field_4,
		field_5_t && field_5
	) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), field_5(std::move(field_5)) {}

	RANGE_1_t(RANGE_1_t const & other) = default;
	RANGE_1_t(RANGE_1_t && move) = default;

	static RANGE_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};

struct RANGE_2_t {
	struct field_1_t {
		enum type {
			literal_0x28,
			literal_0x5B
		} value;
	
		static field_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
			static ::std::unordered_map<parlex::details::recognizer const *, type> const table {
				{ &plange_grammar().get_literal("literal_0x28"), literal_0x28 },
				{ &plange_grammar().get_literal("literal_0x5B"), literal_0x5B },
			};
			return field_1_t{ table.find(&n.r)->second };
		}
	};


	field_1_t field_1;
	std::vector<erased<IC>> field_2;
	erased<EXPRESSION> field_3;
	std::vector<erased<IC>> field_4;
	std::vector<erased<IC>> field_5;


	explicit RANGE_2_t(
		field_1_t && field_1,
		std::vector<erased<IC>> && field_2,
		erased<EXPRESSION> && field_3,
		std::vector<erased<IC>> && field_4,
		std::vector<erased<IC>> && field_5
	) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), field_5(std::move(field_5)) {}

	RANGE_2_t(RANGE_2_t const & other) = default;
	RANGE_2_t(RANGE_2_t && move) = default;

	static RANGE_2_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};

struct RANGE_3_t {
	struct field_1_t {
		enum type {
			literal_0x28,
			literal_0x5B
		} value;
	
		static field_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
			static ::std::unordered_map<parlex::details::recognizer const *, type> const table {
				{ &plange_grammar().get_literal("literal_0x28"), literal_0x28 },
				{ &plange_grammar().get_literal("literal_0x5B"), literal_0x5B },
			};
			return field_1_t{ table.find(&n.r)->second };
		}
	};


	struct field_8_t {
		enum type {
			literal_0x29,
			literal_0x5D
		} value;
	
		static field_8_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
			static ::std::unordered_map<parlex::details::recognizer const *, type> const table {
				{ &plange_grammar().get_literal("literal_0x29"), literal_0x29 },
				{ &plange_grammar().get_literal("literal_0x5D"), literal_0x5D },
			};
			return field_8_t{ table.find(&n.r)->second };
		}
	};


	field_1_t field_1;
	std::vector<erased<IC>> field_2;
	erased<EXPRESSION> field_3;
	std::vector<erased<IC>> field_4;
	std::vector<erased<IC>> field_5;
	erased<EXPRESSION> field_6;
	std::vector<erased<IC>> field_7;
	field_8_t field_8;


	explicit RANGE_3_t(
		field_1_t && field_1,
		std::vector<erased<IC>> && field_2,
		erased<EXPRESSION> && field_3,
		std::vector<erased<IC>> && field_4,
		std::vector<erased<IC>> && field_5,
		erased<EXPRESSION> && field_6,
		std::vector<erased<IC>> && field_7,
		field_8_t && field_8
	) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), field_5(std::move(field_5)), field_6(std::move(field_6)), field_7(std::move(field_7)), field_8(std::move(field_8)) {}

	RANGE_3_t(RANGE_3_t const & other) = default;
	RANGE_3_t(RANGE_3_t && move) = default;

	static RANGE_3_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};

typedef std::variant<
	RANGE_1_t,
	RANGE_2_t,
	RANGE_3_t
> RANGE_base;

struct RANGE: RANGE_base {
	static RANGE build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);
	explicit RANGE(RANGE_base const & value) : RANGE_base(value) {}
};
} // namespace plc



#endif //INCLUDED_RANGE_HPP
