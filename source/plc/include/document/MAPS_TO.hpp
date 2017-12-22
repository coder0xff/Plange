// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_MAPS_TO_HPP
#define INCLUDED_MAPS_TO_HPP

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

struct MAPS_TO {
	erased<EXPRESSION> field_1;
	
	std::vector<erased<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xE20x860x92_t>,
		parlex::detail::document::text<literal_0x2D0x3E_t>
	> field_3;
	
	std::vector<erased<IC>> field_4;
	
	erased<EXPRESSION> field_5;
	


	explicit MAPS_TO(
		erased<EXPRESSION> && field_1, std::vector<erased<IC>> && field_2, std::variant<
			parlex::detail::document::text<literal_0xE20x860x92_t>,
			parlex::detail::document::text<literal_0x2D0x3E_t>
		> && field_3, std::vector<erased<IC>> && field_4, erased<EXPRESSION> && field_5) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), field_5(std::move(field_5)) {}

	MAPS_TO(MAPS_TO const & other) = default;
	MAPS_TO(MAPS_TO && move) = default;

	static MAPS_TO build(parlex::detail::ast_node const & n);
	static parlex::detail::recognizer const & recognizer();

};


} // namespace plc



#endif //INCLUDED_MAPS_TO_HPP
