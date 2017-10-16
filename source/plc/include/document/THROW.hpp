// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_THROW_HPP
#define INCLUDED_THROW_HPP

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

struct THROW {
	struct field_1_t_1_t {
		std::vector<erased<IC>> field_1;
		
		std::vector<erased<IC>> field_2;
		
		erased<EXPRESSION> field_3;
		
		std::vector<erased<IC>> field_4;
		
	
	
		explicit field_1_t_1_t(
			std::vector<erased<IC>> && field_1, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && field_3, std::vector<erased<IC>> && field_4) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)) {}
	
		field_1_t_1_t(field_1_t_1_t const & other) = default;
		field_1_t_1_t(field_1_t_1_t && move) = default;
	
		static field_1_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
	
	};

	struct field_2_t_1_t {
		std::vector<erased<IC>> field_1;
		
		erased<EXPRESSION> field_2;
		
	
	
		explicit field_2_t_1_t(
			std::vector<erased<IC>> && field_1, erased<EXPRESSION> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_2_t_1_t(field_2_t_1_t const & other) = default;
		field_2_t_1_t(field_2_t_1_t && move) = default;
	
		static field_2_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
	
	};

	std::optional<field_1_t_1_t> field_1;
	
	std::optional<field_2_t_1_t> field_2;
	


	explicit THROW(
		std::optional<field_1_t_1_t> && field_1, std::optional<field_2_t_1_t> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	THROW(THROW const & other) = default;
	THROW(THROW && move) = default;

	static THROW build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_THROW_HPP
