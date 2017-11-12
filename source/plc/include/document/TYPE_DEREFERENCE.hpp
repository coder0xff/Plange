// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_DEREFERENCE_HPP
#define INCLUDED_TYPE_DEREFERENCE_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct TYPE_DEREFERENCE {
	parlex::details::document::text<literal_0x3C_t> dontCare0;
	
	std::vector<erased<IC>> field_1;
	
	erased<EXPRESSION> field_2;
	
	std::vector<erased<IC>> field_3;
	
	parlex::details::document::text<literal_0x3E_t> dontCare4;
	


	explicit TYPE_DEREFERENCE(
		parlex::details::document::text<literal_0x3C_t> && dontCare0, std::vector<erased<IC>> && field_1, erased<EXPRESSION> && field_2, std::vector<erased<IC>> && field_3, parlex::details::document::text<literal_0x3E_t> && dontCare4) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), dontCare4(std::move(dontCare4)) {}

	TYPE_DEREFERENCE(TYPE_DEREFERENCE const & other) = default;
	TYPE_DEREFERENCE(TYPE_DEREFERENCE && move) = default;

	static TYPE_DEREFERENCE build(parlex::details::ast_node const & n);
	static parlex::details::recognizer const & recognizer();

};


} // namespace plc



#endif //INCLUDED_TYPE_DEREFERENCE_HPP
