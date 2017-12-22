// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_THIS_TYPE_HPP
#define INCLUDED_THIS_TYPE_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct THIS_TYPE {
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
	
		static field_1_t_1_t build(parlex::detail::behavior::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_this_type_t> dontCare0;
	
	std::optional<field_1_t_1_t> field_1;
	


	explicit THIS_TYPE(
		parlex::detail::document::text<literal_this_type_t> && dontCare0, std::optional<field_1_t_1_t> && field_1) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)) {}

	THIS_TYPE(THIS_TYPE const & other) = default;
	THIS_TYPE(THIS_TYPE && move) = default;

	static THIS_TYPE build(parlex::detail::ast_node const & n);
	static parlex::detail::recognizer const & recognizer();

};


} // namespace plc



#endif //INCLUDED_THIS_TYPE_HPP
