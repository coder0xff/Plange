// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TUPLE_HPP
#define INCLUDED_TUPLE_HPP

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

struct TUPLE {
	struct field_3_t_1_t {
		std::vector<erased<IC>> field_1;
		
		std::vector<erased<IC>> field_2;
		
		erased<EXPRESSION> field_3;
		
	
	
		explicit field_3_t_1_t(
			std::vector<erased<IC>> && field_1, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && field_3) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}
	
		field_3_t_1_t(field_3_t_1_t const & other) = default;
		field_3_t_1_t(field_3_t_1_t && move) = default;
	
		static field_3_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
	
	};

	std::vector<erased<IC>> field_1;
	
	erased<EXPRESSION> field_2;
	
	std::vector<field_3_t_1_t> field_3;
	
	std::vector<erased<IC>> field_4;
	


	explicit TUPLE(
		std::vector<erased<IC>> && field_1, erased<EXPRESSION> && field_2, std::vector<field_3_t_1_t> && field_3, std::vector<erased<IC>> && field_4) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)) {}

	TUPLE(TUPLE const & other) = default;
	TUPLE(TUPLE && move) = default;

	static TUPLE build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_TUPLE_HPP
