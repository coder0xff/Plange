// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_INHERITANCE_LIST_HPP
#define INCLUDED_INHERITANCE_LIST_HPP

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
struct INHERITANCE_ITEM_PREFIX;

struct INHERITANCE_LIST {
	struct field_2_t_1_t {
		std::vector<erased<IC>> field_1;
		
		parlex::detail::document::text<literal_0x2C_t> dontCare1;
		
		std::vector<erased<IC>> field_2;
		
		std::optional<erased<INHERITANCE_ITEM_PREFIX>> field_3;
		
		erased<EXPRESSION> expression;
		
	
	
		explicit field_2_t_1_t(
			std::vector<erased<IC>> && field_1, parlex::detail::document::text<literal_0x2C_t> && dontCare1, std::vector<erased<IC>> && field_2, std::optional<erased<INHERITANCE_ITEM_PREFIX>> && field_3, erased<EXPRESSION> && expression) : field_1(std::move(field_1)), dontCare1(std::move(dontCare1)), field_2(std::move(field_2)), field_3(std::move(field_3)), expression(std::move(expression)) {}
	
		field_2_t_1_t(field_2_t_1_t const & other) = default;
		field_2_t_1_t(field_2_t_1_t && move) = default;
	
		static field_2_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::optional<erased<INHERITANCE_ITEM_PREFIX>> field_1;
	
	erased<EXPRESSION> expression;
	
	std::vector<field_2_t_1_t> field_2;
	


	explicit INHERITANCE_LIST(
		std::optional<erased<INHERITANCE_ITEM_PREFIX>> && field_1, erased<EXPRESSION> && expression, std::vector<field_2_t_1_t> && field_2) : field_1(std::move(field_1)), expression(std::move(expression)), field_2(std::move(field_2)) {}

	INHERITANCE_LIST(INHERITANCE_LIST const & other) = default;
	INHERITANCE_LIST(INHERITANCE_LIST && move) = default;

	static INHERITANCE_LIST build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_INHERITANCE_LIST_HPP
