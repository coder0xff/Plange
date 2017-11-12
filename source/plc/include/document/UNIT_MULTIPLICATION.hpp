// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_UNIT_MULTIPLICATION_HPP
#define INCLUDED_UNIT_MULTIPLICATION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct DIMENSION;

struct UNIT_MULTIPLICATION {
	erased<DIMENSION> field_1;
	
	parlex::details::document::text<literal_0x2A_t> dontCare1;
	
	erased<DIMENSION> field_2;
	


	explicit UNIT_MULTIPLICATION(
		erased<DIMENSION> && field_1, parlex::details::document::text<literal_0x2A_t> && dontCare1, erased<DIMENSION> && field_2) : field_1(std::move(field_1)), dontCare1(std::move(dontCare1)), field_2(std::move(field_2)) {}

	UNIT_MULTIPLICATION(UNIT_MULTIPLICATION const & other) = default;
	UNIT_MULTIPLICATION(UNIT_MULTIPLICATION && move) = default;

	static UNIT_MULTIPLICATION build(parlex::details::ast_node const & n);
	static parlex::details::recognizer const & recognizer();

};


} // namespace plc



#endif //INCLUDED_UNIT_MULTIPLICATION_HPP
