// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_VOLATILE_IMPLICIT_TYPE_DEREFERENCE_HPP
#define INCLUDED_VOLATILE_IMPLICIT_TYPE_DEREFERENCE_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct IC;

struct VOLATILE_IMPLICIT_TYPE_DEREFERENCE {
	parlex::details::document::text<literal_0x3C_t> dontCare0;
	
	std::vector<erased<IC>> field_1;
	
	parlex::details::document::text<literal_volatile_t> dontCare2;
	
	std::vector<erased<IC>> field_2;
	
	parlex::details::document::text<literal_0x3E_t> dontCare4;
	


	explicit VOLATILE_IMPLICIT_TYPE_DEREFERENCE(
		parlex::details::document::text<literal_0x3C_t> && dontCare0, std::vector<erased<IC>> && field_1, parlex::details::document::text<literal_volatile_t> && dontCare2, std::vector<erased<IC>> && field_2, parlex::details::document::text<literal_0x3E_t> && dontCare4) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), dontCare2(std::move(dontCare2)), field_2(std::move(field_2)), dontCare4(std::move(dontCare4)) {}

	VOLATILE_IMPLICIT_TYPE_DEREFERENCE(VOLATILE_IMPLICIT_TYPE_DEREFERENCE const & other) = default;
	VOLATILE_IMPLICIT_TYPE_DEREFERENCE(VOLATILE_IMPLICIT_TYPE_DEREFERENCE && move) = default;

	static VOLATILE_IMPLICIT_TYPE_DEREFERENCE build(parlex::details::ast_node const & n);
	static parlex::details::recognizer const & recognizer();

};


} // namespace plc



#endif //INCLUDED_VOLATILE_IMPLICIT_TYPE_DEREFERENCE_HPP
