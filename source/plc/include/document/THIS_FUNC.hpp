// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_THIS_FUNC_HPP
#define INCLUDED_THIS_FUNC_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct THIS_FUNC {
	struct field_1_t_1_t {
		std::vector<erased<IC>> field_1;
		std::vector<erased<IC>> field_2;
		erased<EXPRESSION> field_3;
		std::vector<erased<IC>> field_4;
	
	
		explicit field_1_t_1_t(
			std::vector<erased<IC>> && field_1,
			std::vector<erased<IC>> && field_2,
			erased<EXPRESSION> && field_3,
			std::vector<erased<IC>> && field_4
		) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)) {}
	
		field_1_t_1_t(field_1_t_1_t const & other) = default;
		field_1_t_1_t(field_1_t_1_t && move) = default;
	
		static field_1_t_1_t build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);
	
	};

	std::optional<field_1_t_1_t> field_1;


	explicit THIS_FUNC(
		std::optional<field_1_t_1_t> && field_1
	) : field_1(std::move(field_1)) {}

	THIS_FUNC(THIS_FUNC const & other) = default;
	THIS_FUNC(THIS_FUNC && move) = default;

	static THIS_FUNC build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_THIS_FUNC_HPP
