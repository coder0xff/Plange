// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_WHOLE_NUMBER_HPP
#define INCLUDED_WHOLE_NUMBER_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct WHOLE_NUMBER {
	std::variant<
		parlex::detail::document::text<literal_1_t>,
		parlex::detail::document::text<literal_2_t>,
		parlex::detail::document::text<literal_3_t>,
		parlex::detail::document::text<literal_4_t>,
		parlex::detail::document::text<literal_5_t>,
		parlex::detail::document::text<literal_6_t>,
		parlex::detail::document::text<literal_7_t>,
		parlex::detail::document::text<literal_8_t>,
		parlex::detail::document::text<literal_9_t>
	> field_1;
	
	std::vector<std::variant<
		parlex::detail::document::text<literal_0_t>,
		parlex::detail::document::text<literal_1_t>,
		parlex::detail::document::text<literal_2_t>,
		parlex::detail::document::text<literal_3_t>,
		parlex::detail::document::text<literal_4_t>,
		parlex::detail::document::text<literal_5_t>,
		parlex::detail::document::text<literal_6_t>,
		parlex::detail::document::text<literal_7_t>,
		parlex::detail::document::text<literal_8_t>,
		parlex::detail::document::text<literal_9_t>
	>> field_2;
	


	explicit WHOLE_NUMBER(
		std::variant<
			parlex::detail::document::text<literal_1_t>,
			parlex::detail::document::text<literal_2_t>,
			parlex::detail::document::text<literal_3_t>,
			parlex::detail::document::text<literal_4_t>,
			parlex::detail::document::text<literal_5_t>,
			parlex::detail::document::text<literal_6_t>,
			parlex::detail::document::text<literal_7_t>,
			parlex::detail::document::text<literal_8_t>,
			parlex::detail::document::text<literal_9_t>
		> && field_1, std::vector<std::variant<
			parlex::detail::document::text<literal_0_t>,
			parlex::detail::document::text<literal_1_t>,
			parlex::detail::document::text<literal_2_t>,
			parlex::detail::document::text<literal_3_t>,
			parlex::detail::document::text<literal_4_t>,
			parlex::detail::document::text<literal_5_t>,
			parlex::detail::document::text<literal_6_t>,
			parlex::detail::document::text<literal_7_t>,
			parlex::detail::document::text<literal_8_t>,
			parlex::detail::document::text<literal_9_t>
		>> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	WHOLE_NUMBER(WHOLE_NUMBER const & other) = default;
	WHOLE_NUMBER(WHOLE_NUMBER && move) = default;

	static WHOLE_NUMBER build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_WHOLE_NUMBER_HPP
