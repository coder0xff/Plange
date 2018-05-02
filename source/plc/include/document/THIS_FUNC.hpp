// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_THIS_FUNC_HPP
#define INCLUDED_THIS_FUNC_HPP

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

struct THIS_FUNC {
	struct field_1_t_1_t {
		std::vector<erased<IC>> field_1;
		
		parlex::detail::document::text<literal_0x5B_t> dontCare1;
		
		std::vector<erased<IC>> field_2;
		
		erased<EXPRESSION> field_3;
		
		std::vector<erased<IC>> field_4;
		
		parlex::detail::document::text<literal_0x5D_t> dontCare5;
		
	
	
		explicit field_1_t_1_t(
			std::vector<erased<IC>> && field_1, parlex::detail::document::text<literal_0x5B_t> && dontCare1, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && field_3, std::vector<erased<IC>> && field_4, parlex::detail::document::text<literal_0x5D_t> && dontCare5) : field_1(std::move(field_1)), dontCare1(std::move(dontCare1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), dontCare5(std::move(dontCare5)) {}
	
		field_1_t_1_t(field_1_t_1_t const & other) = default;
		field_1_t_1_t(field_1_t_1_t && move) = default;
	
		static field_1_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_this_func_t> dontCare0;
	
	std::optional<field_1_t_1_t> field_1;
	


	explicit THIS_FUNC(
		parlex::detail::document::text<literal_this_func_t> && dontCare0, std::optional<field_1_t_1_t> && field_1) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)) {}

	THIS_FUNC(THIS_FUNC const & other) = default;
	THIS_FUNC(THIS_FUNC && move) = default;

	static THIS_FUNC build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_THIS_FUNC_HPP
