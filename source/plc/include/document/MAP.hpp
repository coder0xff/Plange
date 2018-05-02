// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_MAP_HPP
#define INCLUDED_MAP_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct MAP {
	struct field_1_t_1_t {
		struct field_6_t_1_t {
			std::vector<erased<IC>> field_1;
			
			parlex::detail::document::text<literal_0x2C_t> dontCare1;
			
			std::vector<erased<IC>> field_2;
			
			erased<EXPRESSION> field_3;
			
			std::vector<erased<IC>> field_4;
			
			parlex::detail::document::text<literal_0x3A_t> dontCare5;
			
			std::vector<erased<IC>> field_5;
			
			erased<EXPRESSION> field_6;
			
		
		
			explicit field_6_t_1_t(
				std::vector<erased<IC>> && field_1, parlex::detail::document::text<literal_0x2C_t> && dontCare1, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && field_3, std::vector<erased<IC>> && field_4, parlex::detail::document::text<literal_0x3A_t> && dontCare5, std::vector<erased<IC>> && field_5, erased<EXPRESSION> && field_6) : field_1(std::move(field_1)), dontCare1(std::move(dontCare1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), dontCare5(std::move(dontCare5)), field_5(std::move(field_5)), field_6(std::move(field_6)) {}
		
			field_6_t_1_t(field_6_t_1_t const & other) = default;
			field_6_t_1_t(field_6_t_1_t && move) = default;
		
			static field_6_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		std::vector<erased<IC>> field_1;
		
		erased<EXPRESSION> field_2;
		
		std::vector<erased<IC>> field_3;
		
		parlex::detail::document::text<literal_0x3A_t> dontCare3;
		
		std::vector<erased<IC>> field_4;
		
		erased<EXPRESSION> field_5;
		
		std::vector<field_6_t_1_t> field_6;
		
	
	
		explicit field_1_t_1_t(
			std::vector<erased<IC>> && field_1, erased<EXPRESSION> && field_2, std::vector<erased<IC>> && field_3, parlex::detail::document::text<literal_0x3A_t> && dontCare3, std::vector<erased<IC>> && field_4, erased<EXPRESSION> && field_5, std::vector<field_6_t_1_t> && field_6) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), dontCare3(std::move(dontCare3)), field_4(std::move(field_4)), field_5(std::move(field_5)), field_6(std::move(field_6)) {}
	
		field_1_t_1_t(field_1_t_1_t const & other) = default;
		field_1_t_1_t(field_1_t_1_t && move) = default;
	
		static field_1_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_0x7B_t> dontCare0;
	
	std::optional<field_1_t_1_t> field_1;
	
	std::vector<erased<IC>> field_2;
	
	parlex::detail::document::text<literal_0x7D_t> dontCare3;
	


	explicit MAP(
		parlex::detail::document::text<literal_0x7B_t> && dontCare0, std::optional<field_1_t_1_t> && field_1, std::vector<erased<IC>> && field_2, parlex::detail::document::text<literal_0x7D_t> && dontCare3) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), field_2(std::move(field_2)), dontCare3(std::move(dontCare3)) {}

	MAP(MAP const & other) = default;
	MAP(MAP && move) = default;

	static MAP build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_MAP_HPP
