// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ARRAY_INVOCATION_HPP
#define INCLUDED_ARRAY_INVOCATION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ARRAY_INDEXER;
struct EXPRESSION;
struct IC;

struct ARRAY_INVOCATION {
	struct field_3_t_1_t {
		std::vector<erased<IC>> field_1;
		
		std::optional<erased<ARRAY_INDEXER>> field_2;
		
	
	
		explicit field_3_t_1_t(
			std::vector<erased<IC>> && field_1, std::optional<erased<ARRAY_INDEXER>> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_3_t_1_t(field_3_t_1_t const & other) = default;
		field_3_t_1_t(field_3_t_1_t && move) = default;
	
		static field_3_t_1_t build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w);
	
	};

	erased<EXPRESSION> field_1;
	
	std::optional<erased<ARRAY_INDEXER>> field_2;
	
	std::vector<field_3_t_1_t> field_3;
	
	std::vector<erased<IC>> field_4;
	


	explicit ARRAY_INVOCATION(
		erased<EXPRESSION> && field_1, std::optional<erased<ARRAY_INDEXER>> && field_2, std::vector<field_3_t_1_t> && field_3, std::vector<erased<IC>> && field_4) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)) {}

	ARRAY_INVOCATION(ARRAY_INVOCATION const & other) = default;
	ARRAY_INVOCATION(ARRAY_INVOCATION && move) = default;

	static ARRAY_INVOCATION build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_ARRAY_INVOCATION_HPP
