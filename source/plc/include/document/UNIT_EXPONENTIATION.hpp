// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_UNIT_EXPONENTIATION_HPP
#define INCLUDED_UNIT_EXPONENTIATION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct DIMENSION;
struct NON_FRACTIONAL;

struct UNIT_EXPONENTIATION {
	erased<DIMENSION> field_1;
	
	parlex::details::document::text<literal_0x5E_t> dontCare1;
	
	erased<NON_FRACTIONAL> field_2;
	


	explicit UNIT_EXPONENTIATION(
		erased<DIMENSION> && field_1, parlex::details::document::text<literal_0x5E_t> && dontCare1, erased<NON_FRACTIONAL> && field_2) : field_1(std::move(field_1)), dontCare1(std::move(dontCare1)), field_2(std::move(field_2)) {}

	UNIT_EXPONENTIATION(UNIT_EXPONENTIATION const & other) = default;
	UNIT_EXPONENTIATION(UNIT_EXPONENTIATION && move) = default;

	static UNIT_EXPONENTIATION build(parlex::details::ast_node const & n);
	static parlex::details::recognizer const & recognizer();

};


} // namespace plc



#endif //INCLUDED_UNIT_EXPONENTIATION_HPP
