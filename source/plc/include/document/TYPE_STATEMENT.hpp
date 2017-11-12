// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_STATEMENT_HPP
#define INCLUDED_TYPE_STATEMENT_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct IC;
struct STATEMENT;
struct TYPE_SCOPE_TYPE_CONSTRAINT;
struct VISIBILITY_MODIFIER;

struct TYPE_STATEMENT_1_t {
	erased<VISIBILITY_MODIFIER> field_1;
	
	std::vector<erased<IC>> field_2;
	
	parlex::details::document::text<literal_0x3A_t> dontCare2;
	


	explicit TYPE_STATEMENT_1_t(
		erased<VISIBILITY_MODIFIER> && field_1, std::vector<erased<IC>> && field_2, parlex::details::document::text<literal_0x3A_t> && dontCare2) : field_1(std::move(field_1)), field_2(std::move(field_2)), dontCare2(std::move(dontCare2)) {}

	TYPE_STATEMENT_1_t(TYPE_STATEMENT_1_t const & other) = default;
	TYPE_STATEMENT_1_t(TYPE_STATEMENT_1_t && move) = default;

	static TYPE_STATEMENT_1_t build(parlex::details::behavior::node const * b, parlex::details::document::walk & w);
};

typedef std::variant<
	TYPE_STATEMENT_1_t,
	erased<TYPE_SCOPE_TYPE_CONSTRAINT>,
	erased<STATEMENT>
> TYPE_STATEMENT_base;

struct TYPE_STATEMENT: TYPE_STATEMENT_base {
	static TYPE_STATEMENT build(parlex::details::ast_node const & n);
	explicit TYPE_STATEMENT(TYPE_STATEMENT_base const & value) : TYPE_STATEMENT_base(value) {}
	static parlex::details::recognizer const & recognizer();
};
} // namespace plc



#endif //INCLUDED_TYPE_STATEMENT_HPP
