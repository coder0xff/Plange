// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN_HPP
#define INCLUDED_TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct DEFINITION;
struct IC;
struct TYPE_SCOPE_ASSIGNMENT_CHAIN;
struct TYPE_SCOPE_DECLARATION;
struct TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN;
struct XML_DOC_STRING;

struct TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN {
	struct field_1_t_1_t {
		erased<XML_DOC_STRING> field_1;
		
		std::vector<erased<IC>> field_2;
		
	
	
		explicit field_1_t_1_t(
			erased<XML_DOC_STRING> && field_1, std::vector<erased<IC>> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_1_t_1_t(field_1_t_1_t const & other) = default;
		field_1_t_1_t(field_1_t_1_t && move) = default;
	
		static field_1_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_3_t_1_t {
		std::vector<erased<IC>> field_1;
		
		parlex::detail::document::text<literal_0x2C_t> dontCare1;
		
		std::vector<erased<IC>> field_2;
		
		erased<TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN> field_3;
		
	
	
		explicit field_3_t_1_t(
			std::vector<erased<IC>> && field_1, parlex::detail::document::text<literal_0x2C_t> && dontCare1, std::vector<erased<IC>> && field_2, erased<TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN> && field_3) : field_1(std::move(field_1)), dontCare1(std::move(dontCare1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}
	
		field_3_t_1_t(field_3_t_1_t const & other) = default;
		field_3_t_1_t(field_3_t_1_t && move) = default;
	
		static field_3_t_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::optional<field_1_t_1_t> field_1;
	
	std::variant<
		erased<TYPE_SCOPE_DECLARATION>,
		erased<TYPE_SCOPE_ASSIGNMENT_CHAIN>,
		erased<DEFINITION>
	> field_2;
	
	std::optional<field_3_t_1_t> field_3;
	


	explicit TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN(
		std::optional<field_1_t_1_t> && field_1, std::variant<
			erased<TYPE_SCOPE_DECLARATION>,
			erased<TYPE_SCOPE_ASSIGNMENT_CHAIN>,
			erased<DEFINITION>
		> && field_2, std::optional<field_3_t_1_t> && field_3) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}

	TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN(TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN const & other) = default;
	TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN(TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN && move) = default;

	static TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN_HPP
