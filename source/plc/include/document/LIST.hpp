// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_LIST_HPP
#define INCLUDED_LIST_HPP

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

struct LIST {
	struct elements_t_1_t {
		struct field_2_t_1_t {
			std::vector<erased<IC>> field_1;
			
			parlex::detail::document::text<literal_0x2C0x20_t> dontCare1;
			
			std::vector<erased<IC>> field_2;
			
			erased<EXPRESSION> field_3;
			
		
		
			explicit field_2_t_1_t(
				std::vector<erased<IC>> && field_1, parlex::detail::document::text<literal_0x2C0x20_t> && dontCare1, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && field_3) : field_1(std::move(field_1)), dontCare1(std::move(dontCare1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}
		
			field_2_t_1_t(field_2_t_1_t const & other) = default;
			field_2_t_1_t(field_2_t_1_t && move) = default;
		
			static field_2_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		erased<EXPRESSION> field_1;
		
		std::vector<field_2_t_1_t> field_2;
		
		std::vector<erased<IC>> field_3;
		
	
	
		explicit elements_t_1_t(
			erased<EXPRESSION> && field_1, std::vector<field_2_t_1_t> && field_2, std::vector<erased<IC>> && field_3) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}
	
		elements_t_1_t(elements_t_1_t const & other) = default;
		elements_t_1_t(elements_t_1_t && move) = default;
	
		static elements_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_0x5B0x7C_t> dontCare0;
	
	std::vector<erased<IC>> field_1;
	
	std::optional<elements_t_1_t> elements;
	
	parlex::detail::document::text<literal_0x7C0x5D_t> dontCare3;
	


	explicit LIST(
		parlex::detail::document::text<literal_0x5B0x7C_t> && dontCare0, std::vector<erased<IC>> && field_1, std::optional<elements_t_1_t> && elements, parlex::detail::document::text<literal_0x7C0x5D_t> && dontCare3) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), elements(std::move(elements)), dontCare3(std::move(dontCare3)) {}

	LIST(LIST const & other) = default;
	LIST(LIST && move) = default;

	static LIST build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_LIST_HPP
