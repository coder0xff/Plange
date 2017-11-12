// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DELTA_HPP
#define INCLUDED_DELTA_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct WHOLE_NUMBER;

struct DELTA {
	struct field_2_t_1_t {
		parlex::details::document::text<literal_0x5E_t> dontCare0;
		
		erased<WHOLE_NUMBER> whole_number;
		
	
	
		explicit field_2_t_1_t(
			parlex::details::document::text<literal_0x5E_t> && dontCare0, erased<WHOLE_NUMBER> && whole_number) : dontCare0(std::move(dontCare0)), whole_number(std::move(whole_number)) {}
	
		field_2_t_1_t(field_2_t_1_t const & other) = default;
		field_2_t_1_t(field_2_t_1_t && move) = default;
	
		static field_2_t_1_t build(parlex::details::behavior::node const * b, parlex::details::document::walk & w);
	};

	std::variant<
		parlex::details::document::text<literal_0xCE0x94_t>,
		parlex::details::document::text<literal__delta__t>
	> field_1;
	
	std::optional<field_2_t_1_t> field_2;
	
	erased<EXPRESSION> expression;
	


	explicit DELTA(
		std::variant<
			parlex::details::document::text<literal_0xCE0x94_t>,
			parlex::details::document::text<literal__delta__t>
		> && field_1, std::optional<field_2_t_1_t> && field_2, erased<EXPRESSION> && expression) : field_1(std::move(field_1)), field_2(std::move(field_2)), expression(std::move(expression)) {}

	DELTA(DELTA const & other) = default;
	DELTA(DELTA && move) = default;

	static DELTA build(parlex::details::ast_node const & n);
	static parlex::details::recognizer const & recognizer();

};


} // namespace plc



#endif //INCLUDED_DELTA_HPP
