// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_VOLATILE_TYPE_DEREFERENCE_HPP
#define INCLUDED_VOLATILE_TYPE_DEREFERENCE_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct VOLATILE_TYPE_DEREFERENCE {
	parlex::detail::document::text<literal_0x3C_t> dontCare0;
	
	std::vector<erased<IC>> field_1;
	
	parlex::detail::document::text<literal_volatile_t> dontCare2;
	
	std::vector<erased<IC>> field_2;
	
	erased<EXPRESSION> field_3;
	
	std::vector<erased<IC>> field_4;
	
	parlex::detail::document::text<literal_0x3E_t> dontCare6;
	


	explicit VOLATILE_TYPE_DEREFERENCE(
		parlex::detail::document::text<literal_0x3C_t> && dontCare0, std::vector<erased<IC>> && field_1, parlex::detail::document::text<literal_volatile_t> && dontCare2, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && field_3, std::vector<erased<IC>> && field_4, parlex::detail::document::text<literal_0x3E_t> && dontCare6) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), dontCare2(std::move(dontCare2)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), dontCare6(std::move(dontCare6)) {}

	VOLATILE_TYPE_DEREFERENCE(VOLATILE_TYPE_DEREFERENCE const & other) = default;
	VOLATILE_TYPE_DEREFERENCE(VOLATILE_TYPE_DEREFERENCE && move) = default;

	static VOLATILE_TYPE_DEREFERENCE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_VOLATILE_TYPE_DEREFERENCE_HPP
