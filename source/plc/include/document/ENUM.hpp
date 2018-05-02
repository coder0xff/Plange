// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ENUM_HPP
#define INCLUDED_ENUM_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ENUM_ELEMENT;
struct IC;
struct INHERITANCE_LIST;

struct ENUM {
	struct field_2_t_1_t {
		parlex::detail::document::text<literal_inheriting_t> dontCare0;
		
		std::vector<erased<IC>> field_1;
		
		erased<INHERITANCE_LIST> field_2;
		
		std::vector<erased<IC>> field_3;
		
	
	
		explicit field_2_t_1_t(
			parlex::detail::document::text<literal_inheriting_t> && dontCare0, std::vector<erased<IC>> && field_1, erased<INHERITANCE_LIST> && field_2, std::vector<erased<IC>> && field_3) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}
	
		field_2_t_1_t(field_2_t_1_t const & other) = default;
		field_2_t_1_t(field_2_t_1_t && move) = default;
	
		static field_2_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_3_t_1_t {
		parlex::detail::document::text<literal_implementing_t> dontCare0;
		
		std::vector<erased<IC>> field_1;
		
		erased<INHERITANCE_LIST> field_2;
		
		std::vector<erased<IC>> field_3;
		
	
	
		explicit field_3_t_1_t(
			parlex::detail::document::text<literal_implementing_t> && dontCare0, std::vector<erased<IC>> && field_1, erased<INHERITANCE_LIST> && field_2, std::vector<erased<IC>> && field_3) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}
	
		field_3_t_1_t(field_3_t_1_t const & other) = default;
		field_3_t_1_t(field_3_t_1_t && move) = default;
	
		static field_3_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_4_t_1_t {
		struct field_1_t_1_t {
			std::vector<erased<IC>> field_1;
			
			parlex::detail::document::text<literal_0x3B_t> dontCare1;
			
			std::vector<erased<IC>> field_2;
			
			erased<ENUM_ELEMENT> enum_element;
			
		
		
			explicit field_1_t_1_t(
				std::vector<erased<IC>> && field_1, parlex::detail::document::text<literal_0x3B_t> && dontCare1, std::vector<erased<IC>> && field_2, erased<ENUM_ELEMENT> && enum_element) : field_1(std::move(field_1)), dontCare1(std::move(dontCare1)), field_2(std::move(field_2)), enum_element(std::move(enum_element)) {}
		
			field_1_t_1_t(field_1_t_1_t const & other) = default;
			field_1_t_1_t(field_1_t_1_t && move) = default;
		
			static field_1_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		erased<ENUM_ELEMENT> enum_element;
		
		std::vector<field_1_t_1_t> field_1;
		
	
	
		explicit field_4_t_1_t(
			erased<ENUM_ELEMENT> && enum_element, std::vector<field_1_t_1_t> && field_1) : enum_element(std::move(enum_element)), field_1(std::move(field_1)) {}
	
		field_4_t_1_t(field_4_t_1_t const & other) = default;
		field_4_t_1_t(field_4_t_1_t && move) = default;
	
		static field_4_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_enum_t> dontCare0;
	
	std::vector<erased<IC>> field_1;
	
	std::optional<field_2_t_1_t> field_2;
	
	std::optional<field_3_t_1_t> field_3;
	
	parlex::detail::document::text<literal_0x7B_t> dontCare4;
	
	std::optional<field_4_t_1_t> field_4;
	
	parlex::detail::document::text<literal_0x7D_t> dontCare6;
	


	explicit ENUM(
		parlex::detail::document::text<literal_enum_t> && dontCare0, std::vector<erased<IC>> && field_1, std::optional<field_2_t_1_t> && field_2, std::optional<field_3_t_1_t> && field_3, parlex::detail::document::text<literal_0x7B_t> && dontCare4, std::optional<field_4_t_1_t> && field_4, parlex::detail::document::text<literal_0x7D_t> && dontCare6) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), dontCare4(std::move(dontCare4)), field_4(std::move(field_4)), dontCare6(std::move(dontCare6)) {}

	ENUM(ENUM const & other) = default;
	ENUM(ENUM && move) = default;

	static ENUM build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_ENUM_HPP
