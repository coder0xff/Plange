// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EQUALITY_CHAIN_LOOP_HPP
#define INCLUDED_EQUALITY_CHAIN_LOOP_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EQUALITY_CHAIN_LOOP;
struct EXPRESSION;
struct IC;

struct EQUALITY_CHAIN_LOOP {
	struct field_2_t_1_t {
		std::vector<erased<IC>> field_1;
		
		erased<EQUALITY_CHAIN_LOOP> equality_chain_loop;
		
	
	
		explicit field_2_t_1_t(
			std::vector<erased<IC>> && field_1, erased<EQUALITY_CHAIN_LOOP> && equality_chain_loop) : field_1(std::move(field_1)), equality_chain_loop(std::move(equality_chain_loop)) {}
	
		field_2_t_1_t(field_2_t_1_t const & other) = default;
		field_2_t_1_t(field_2_t_1_t && move) = default;
	
		static field_2_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_0x3D_t> dontCare0;
	
	std::vector<erased<IC>> field_1;
	
	erased<EXPRESSION> expression;
	
	std::optional<field_2_t_1_t> field_2;
	


	explicit EQUALITY_CHAIN_LOOP(
		parlex::detail::document::text<literal_0x3D_t> && dontCare0, std::vector<erased<IC>> && field_1, erased<EXPRESSION> && expression, std::optional<field_2_t_1_t> && field_2) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), expression(std::move(expression)), field_2(std::move(field_2)) {}

	EQUALITY_CHAIN_LOOP(EQUALITY_CHAIN_LOOP const & other) = default;
	EQUALITY_CHAIN_LOOP(EQUALITY_CHAIN_LOOP && move) = default;

	static EQUALITY_CHAIN_LOOP build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_EQUALITY_CHAIN_LOOP_HPP
