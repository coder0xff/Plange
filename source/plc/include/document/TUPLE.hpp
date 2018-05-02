// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TUPLE_HPP
#define INCLUDED_TUPLE_HPP

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

struct TUPLE {
	struct field_3_t_1_t {
		std::vector<erased<IC>> field_1;
		
		parlex::detail::document::text<literal_0x2C_t> dontCare1;
		
		std::vector<erased<IC>> field_2;
		
		erased<EXPRESSION> field_3;
		
	
	
		explicit field_3_t_1_t(
			std::vector<erased<IC>> && field_1, parlex::detail::document::text<literal_0x2C_t> && dontCare1, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && field_3) : field_1(std::move(field_1)), dontCare1(std::move(dontCare1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}
	
		field_3_t_1_t(field_3_t_1_t const & other) = default;
		field_3_t_1_t(field_3_t_1_t && move) = default;
	
		static field_3_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_0x280x7C_t> dontCare0;
	
	std::vector<erased<IC>> field_1;
	
	erased<EXPRESSION> field_2;
	
	std::vector<field_3_t_1_t> field_3;
	
	std::vector<erased<IC>> field_4;
	
	parlex::detail::document::text<literal_0x7C0x29_t> dontCare5;
	


	explicit TUPLE(
		parlex::detail::document::text<literal_0x280x7C_t> && dontCare0, std::vector<erased<IC>> && field_1, erased<EXPRESSION> && field_2, std::vector<field_3_t_1_t> && field_3, std::vector<erased<IC>> && field_4, parlex::detail::document::text<literal_0x7C0x29_t> && dontCare5) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), dontCare5(std::move(dontCare5)) {}

	TUPLE(TUPLE const & other) = default;
	TUPLE(TUPLE && move) = default;

	static TUPLE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_TUPLE_HPP
