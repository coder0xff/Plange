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
			(parlex::detail::document::text<literal_0x2E_t> const & dont_care0, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_1, std::vector<parlex::detail::document::text<parlex::detail::decimal_digit_t>> const & field_2)
			: dont_care0(dont_care0), field_1(field_1), field_2(field_2) {}
	
		field_08_t(field_08_t const & other) = default;
		static field_08_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_09_t2 {
		struct field_4_t {
			parlex::detail::document::text<literal_0x3A_t> dont_care0;
			
			parlex::detail::document::text<parlex::detail::decimal_digit_t> field_1;
			
			parlex::detail::document::text<parlex::detail::decimal_digit_t> field_2;
			
		
		
			explicit field_4_t
				(parlex::detail::document::text<literal_0x3A_t> const & dont_care0, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_1, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_2)
				: dont_care0(dont_care0), field_1(field_1), field_2(field_2) {}
		
			field_4_t(field_4_t const & other) = default;
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
	> const & field_1, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_2, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_3, std::optional<field_4_t> const & field_4)
			: field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4) {}
	
		field_09_t2(field_09_t2 const & other) = default;
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
		(int32_t documentPosition, int32_t consumedCharacterCount, std::optional<parlex::detail::document::text<literal_0x2D_t>> const & field_01, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_02, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_03, parlex::detail::document::text<literal_0x3A_t> const & dont_care3, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_04, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_05, parlex::detail::document::text<literal_0x3A_t> const & dont_care6, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_06, parlex::detail::document::text<parlex::detail::decimal_digit_t> const & field_07, std::optional<field_08_t> const & field_08, std::optional<std::variant<
	parlex::detail::document::text<literal_Z_t>,
	field_09_t2
>> const & field_09)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_01(field_01), field_02(field_02), field_03(field_03), dont_care3(dont_care3), field_04(field_04), field_05(field_05), dont_care6(dont_care6), field_06(field_06), field_07(field_07), field_08(field_08), field_09(field_09) {}

	TIME(TIME const & other) = default;
	static TIME build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_TIME_HPP
