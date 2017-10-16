// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_WHOLE_NUMBER_HPP
#define INCLUDED_WHOLE_NUMBER_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct WHOLE_NUMBER {
	std::variant<
		literal_1_t,
		literal_2_t,
		literal_3_t,
		literal_4_t,
		literal_5_t,
		literal_6_t,
		literal_7_t,
		literal_8_t,
		literal_9_t
	> field_1;
	
	std::vector<std::variant<
		literal_0_t,
		literal_1_t,
		literal_2_t,
		literal_3_t,
		literal_4_t,
		literal_5_t,
		literal_6_t,
		literal_7_t,
		literal_8_t,
		literal_9_t
	>> field_2;
	


	explicit WHOLE_NUMBER(
		std::variant<
			literal_1_t,
			literal_2_t,
			literal_3_t,
			literal_4_t,
			literal_5_t,
			literal_6_t,
			literal_7_t,
			literal_8_t,
			literal_9_t
		> && field_1, std::vector<std::variant<
			literal_0_t,
			literal_1_t,
			literal_2_t,
			literal_3_t,
			literal_4_t,
			literal_5_t,
			literal_6_t,
			literal_7_t,
			literal_8_t,
			literal_9_t
		>> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	WHOLE_NUMBER(WHOLE_NUMBER const & other) = default;
	WHOLE_NUMBER(WHOLE_NUMBER && move) = default;

	static WHOLE_NUMBER build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_WHOLE_NUMBER_HPP
