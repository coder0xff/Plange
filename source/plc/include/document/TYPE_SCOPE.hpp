// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_SCOPE_HPP
#define INCLUDED_TYPE_SCOPE_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct IC;
struct TYPE_STATEMENT;

struct TYPE_SCOPE {
	struct field_2_t_1_t {
		erased<TYPE_STATEMENT> field_1;
		std::vector<erased<IC>> field_2;
	
	
		explicit field_2_t_1_t(
			erased<TYPE_STATEMENT> && field_1,
			std::vector<erased<IC>> && field_2
		) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_2_t_1_t(field_2_t_1_t const & other) = default;
		field_2_t_1_t(field_2_t_1_t && move) = default;
	
		static field_2_t_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);
	
	};

	std::vector<erased<IC>> field_1;
	std::vector<field_2_t_1_t> field_2;


	explicit TYPE_SCOPE(
		std::vector<erased<IC>> && field_1,
		std::vector<field_2_t_1_t> && field_2
	) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	TYPE_SCOPE(TYPE_SCOPE const & other) = default;
	TYPE_SCOPE(TYPE_SCOPE && move) = default;

	static TYPE_SCOPE build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_TYPE_SCOPE_HPP
