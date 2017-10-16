// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_VOLATILE_TYPE_DEREFERENCE_HPP
#define INCLUDED_VOLATILE_TYPE_DEREFERENCE_HPP

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

struct VOLATILE_TYPE_DEREFERENCE {
	std::vector<erased<IC>> field_1;
	
	std::vector<erased<IC>> field_2;
	
	erased<EXPRESSION> field_3;
	
	std::vector<erased<IC>> field_4;
	


	explicit VOLATILE_TYPE_DEREFERENCE(
		std::vector<erased<IC>> && field_1, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && field_3, std::vector<erased<IC>> && field_4) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)) {}

	VOLATILE_TYPE_DEREFERENCE(VOLATILE_TYPE_DEREFERENCE const & other) = default;
	VOLATILE_TYPE_DEREFERENCE(VOLATILE_TYPE_DEREFERENCE && move) = default;

	static VOLATILE_TYPE_DEREFERENCE build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_VOLATILE_TYPE_DEREFERENCE_HPP
