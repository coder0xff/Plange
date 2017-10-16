// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TRY_HPP
#define INCLUDED_TRY_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct TRY {
	struct field_6_t_1_t {
		std::vector<erased<IC>> field_1;
		
		erased<EXPRESSION> field_2;
		
	
	
		explicit field_6_t_1_t(
			std::vector<erased<IC>> && field_1, erased<EXPRESSION> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_6_t_1_t(field_6_t_1_t const & other) = default;
		field_6_t_1_t(field_6_t_1_t && move) = default;
	
		static field_6_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
	
	};

	struct field_7_t_1_t {
		std::vector<erased<IC>> field_1;
		
		std::vector<erased<IC>> field_2;
		
		erased<EXPRESSION> field_3;
		
	
	
		explicit field_7_t_1_t(
			std::vector<erased<IC>> && field_1, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && field_3) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}
	
		field_7_t_1_t(field_7_t_1_t const & other) = default;
		field_7_t_1_t(field_7_t_1_t && move) = default;
	
		static field_7_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
	
	};

	std::vector<erased<IC>> field_1;
	
	erased<EXPRESSION> field_2;
	
	std::vector<erased<IC>> field_3;
	
	std::vector<erased<IC>> field_4;
	
	erased<EXPRESSION> field_5;
	
	std::vector<field_6_t_1_t> field_6;
	
	std::optional<field_7_t_1_t> field_7;
	


	explicit TRY(
		std::vector<erased<IC>> && field_1, erased<EXPRESSION> && field_2, std::vector<erased<IC>> && field_3, std::vector<erased<IC>> && field_4, erased<EXPRESSION> && field_5, std::vector<field_6_t_1_t> && field_6, std::optional<field_7_t_1_t> && field_7) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), field_5(std::move(field_5)), field_6(std::move(field_6)), field_7(std::move(field_7)) {}

	TRY(TRY const & other) = default;
	TRY(TRY && move) = default;

	static TRY build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_TRY_HPP
