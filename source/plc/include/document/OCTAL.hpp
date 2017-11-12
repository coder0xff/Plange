// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_OCTAL_HPP
#define INCLUDED_OCTAL_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct OCTAL {
	parlex::details::document::text<literal_0_t> dontCare0;
	
	parlex::details::document::text<parlex::details::octal_digit_t> field_1;
	
	std::vector<parlex::details::document::text<parlex::details::octal_digit_t>> field_2;
	


	explicit OCTAL(
		parlex::details::document::text<literal_0_t> && dontCare0, parlex::details::document::text<parlex::details::octal_digit_t> && field_1, std::vector<parlex::details::document::text<parlex::details::octal_digit_t>> && field_2) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	OCTAL(OCTAL const & other) = default;
	OCTAL(OCTAL && move) = default;

	static OCTAL build(parlex::details::ast_node const & n);
	static parlex::details::recognizer const & recognizer();

};


} // namespace plc



#endif //INCLUDED_OCTAL_HPP
