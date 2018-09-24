// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TIME_HPP
#define INCLUDED_TIME_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct TIME {
	int32_t document_position, consumed_character_count;

	struct field_08_t {
		parlex::detail::document::text<literal_0x2E_t> dont_care0;
		
		parlex::detail::document::text<parlex::detail::decimal_digit_t> field_1;
		
		std::vector<parlex::detail::document::text<parlex::detail::decimal_digit_t>> field_2;
		
	
	
		explicit field_08_t
			(parlex::detail::document::text<literal_0x2E_t> && dont_care0, parlex::detail::document::text<parlex::detail::decimal_digit_t> && field_1, std::vector<parlex::detail::document::text<parlex::detail::decimal_digit_t>> && field_2)
			: dont_care0(std::move(dont_care0)), field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_08_t(field_08_t const & other) = default;
		field_08_t(field_08_t && move) = default;
	
		static field_08_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_09_t2 {
		struct field_4_t {
			parlex::detail::document::text<literal_0x3A_t> dont_care0;
			
			parlex::detail::document::text<parlex::detail::decimal_digit_t> field_1;
			
			parlex::detail::document::text<parlex::detail::decimal_digit_t> field_2;
			
		
		
			explicit field_4_t
				(parlex::detail::document::text<literal_0x3A_t> && dont_care0, parlex::detail::document::text<parlex::detail::decimal_digit_t> && field_1, parlex::detail::document::text<parlex::detail::decimal_digit_t> && field_2)
				: dont_care0(std::move(dont_care0)), field_1(std::move(field_1)), field_2(std::move(field_2)) {}
		
			field_4_t(field_4_t const & other) = default;
			field_4_t(field_4_t && move) = default;
		
			static field_4_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		std::variant<
			parlex::detail::document::text<literal_0x2B_t>,
			parlex::detail::document::text<literal_0x2D_t>
		> field_1;
		
		parlex::detail::document::text<parlex::detail::decimal_digit_t> field_2;
		
		parlex::detail::document::text<parlex::detail::decimal_digit_t> field_3;
		
		std::optional<field_4_t> field_4;
		
	
	
		explicit field_09_t2
			(std::variant<
		parlex::detail::document::text<literal_0x2B_t>,
		parlex::detail::document::text<literal_0x2D_t>
	> && field_1, parlex::detail::document::text<parlex::detail::decimal_digit_t> && field_2, parlex::detail::document::text<parlex::detail::decimal_digit_t> && field_3, std::optional<field_4_t> && field_4)
			: field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)) {}
	
		field_09_t2(field_09_t2 const & other) = default;
		field_09_t2(field_09_t2 && move) = default;
	
		static field_09_t2 build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::optional<parlex::detail::document::text<literal_0x2D_t>> field_01;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_02;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_03;
	
	parlex::detail::document::text<literal_0x3A_t> dont_care3;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_04;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_05;
	
	parlex::detail::document::text<literal_0x3A_t> dont_care6;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_06;
	
	parlex::detail::document::text<parlex::detail::decimal_digit_t> field_07;
	
	std::optional<field_08_t> field_08;
	
	std::optional<std::variant<
		parlex::detail::document::text<literal_Z_t>,
		field_09_t2
	>> field_09;
	


	explicit TIME
		(int32_t documentPosition, int32_t consumedCharacterCount, std::optional<parlex::detail::document::text<literal_0x2D_t>> && field_01, parlex::detail::document::text<parlex::detail::decimal_digit_t> && field_02, parlex::detail::document::text<parlex::detail::decimal_digit_t> && field_03, parlex::detail::document::text<literal_0x3A_t> && dont_care3, parlex::detail::document::text<parlex::detail::decimal_digit_t> && field_04, parlex::detail::document::text<parlex::detail::decimal_digit_t> && field_05, parlex::detail::document::text<literal_0x3A_t> && dont_care6, parlex::detail::document::text<parlex::detail::decimal_digit_t> && field_06, parlex::detail::document::text<parlex::detail::decimal_digit_t> && field_07, std::optional<field_08_t> && field_08, std::optional<std::variant<
	parlex::detail::document::text<literal_Z_t>,
	field_09_t2
>> && field_09)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_01(std::move(field_01)), field_02(std::move(field_02)), field_03(std::move(field_03)), dont_care3(std::move(dont_care3)), field_04(std::move(field_04)), field_05(std::move(field_05)), dont_care6(std::move(dont_care6)), field_06(std::move(field_06)), field_07(std::move(field_07)), field_08(std::move(field_08)), field_09(std::move(field_09)) {}

	TIME(TIME const & other) = default;
	TIME(TIME && move) = default;

	static TIME build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_TIME_HPP
