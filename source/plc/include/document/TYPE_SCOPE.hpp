// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_SCOPE_HPP
#define INCLUDED_TYPE_SCOPE_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct IC;
struct TYPE_STATEMENT;

struct TYPE_SCOPE {
	int32_t document_position, consumed_character_count;

	struct field_2_t {
		erased<TYPE_STATEMENT> field_1;
		
		std::vector<erased<IC>> field_2;
		
	
	
		explicit field_2_t
			(erased<TYPE_STATEMENT> && field_1, std::vector<erased<IC>> && field_2)
			: field_1(std::move(field_1)), field_2(std::move(field_2)) {}
	
		field_2_t(field_2_t const & other) = default;
		field_2_t(field_2_t && move) = default;
	
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::vector<erased<IC>> field_1;
	
	std::vector<field_2_t> field_2;
	


	explicit TYPE_SCOPE
		(int32_t documentPosition, int32_t consumedCharacterCount, std::vector<erased<IC>> && field_1, std::vector<field_2_t> && field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	TYPE_SCOPE(TYPE_SCOPE const & other) = default;
	TYPE_SCOPE(TYPE_SCOPE && move) = default;

	static TYPE_SCOPE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_TYPE_SCOPE_HPP
