// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_VOLATILE_TYPE_DEREFERENCE_HPP
#define INCLUDED_VOLATILE_TYPE_DEREFERENCE_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct VOLATILE_TYPE_DEREFERENCE {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0x3C_t> dont_care0;
	
	std::vector<val<IC>> ic1;
	
	parlex::detail::document::text<literal_volatile_t> dont_care2;
	
	std::vector<val<IC>> ic2;
	
	val<EXPRESSION> expression;
	
	std::vector<val<IC>> ic3;
	
	parlex::detail::document::text<literal_0x3E_t> dont_care6;
	


	explicit VOLATILE_TYPE_DEREFERENCE
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x3C_t> const & dont_care0, std::vector<val<IC>> const & ic1, parlex::detail::document::text<literal_volatile_t> const & dont_care2, std::vector<val<IC>> const & ic2, val<EXPRESSION> const & expression, std::vector<val<IC>> const & ic3, parlex::detail::document::text<literal_0x3E_t> const & dont_care6)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), ic1(ic1), dont_care2(dont_care2), ic2(ic2), expression(expression), ic3(ic3), dont_care6(dont_care6) {}

	VOLATILE_TYPE_DEREFERENCE(VOLATILE_TYPE_DEREFERENCE const & other) = default;
	static VOLATILE_TYPE_DEREFERENCE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_VOLATILE_TYPE_DEREFERENCE_HPP
