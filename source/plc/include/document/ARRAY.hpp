// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ARRAY_HPP
#define INCLUDED_ARRAY_HPP

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

struct ARRAY {
	struct field_2_t_1_t {
		struct field_1_t_1_t {
			std::vector<erased<IC>> field_1;
			
			parlex::detail::document::text<literal_0x2C_t> dontCare1;
			
			std::vector<erased<IC>> field_2;
			
			erased<EXPRESSION> expression;
			
		
		
			explicit field_1_t_1_t(
				std::vector<erased<IC>> && field_1, parlex::detail::document::text<literal_0x2C_t> && dontCare1, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && expression) : field_1(std::move(field_1)), dontCare1(std::move(dontCare1)), field_2(std::move(field_2)), expression(std::move(expression)) {}
		
			field_1_t_1_t(field_1_t_1_t const & other) = default;
			field_1_t_1_t(field_1_t_1_t && move) = default;
		
			static field_1_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		erased<EXPRESSION> expression;
		
		std::vector<field_1_t_1_t> field_1;
		
		std::vector<erased<IC>> field_2;
		
	
	
		explicit field_2_t_1_t(
			erased<EXPRESSION> && expression, std::vector<field_1_t_1_t> && field_1, std::vector<erased<IC>> && field_2) : expression(std::move(expression)), field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_2_t_1_t(field_2_t_1_t const & other) = default;
		field_2_t_1_t(field_2_t_1_t && move) = default;
	
		static field_2_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_0x5B_t> dontCare0;
	
	std::vector<erased<IC>> field_1;
	
	std::optional<field_2_t_1_t> field_2;
	
	parlex::detail::document::text<literal_0x5D_t> dontCare3;
	


	explicit ARRAY(
		parlex::detail::document::text<literal_0x5B_t> && dontCare0, std::vector<erased<IC>> && field_1, std::optional<field_2_t_1_t> && field_2, parlex::detail::document::text<literal_0x5D_t> && dontCare3) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), field_2(std::move(field_2)), dontCare3(std::move(dontCare3)) {}

	ARRAY(ARRAY const & other) = default;
	ARRAY(ARRAY && move) = default;

	static ARRAY build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_ARRAY_HPP
