// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_MODIFIER_ATOMIC_HPP
#define INCLUDED_FUNCTION_MODIFIER_ATOMIC_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct FUNCTION_MODIFIER_3;
struct IC;

struct FUNCTION_MODIFIER_ATOMIC {
	int32_t document_position, consumed_character_count;

	struct field_1_t {
		val<IC> field_1;
		
		std::vector<val<IC>> field_2;
		
		val<FUNCTION_MODIFIER_3> field_3;
		
	
	
		explicit field_1_t
			(val<IC> && field_1, std::vector<val<IC>> && field_2, val<FUNCTION_MODIFIER_3> && field_3)
			: field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}
	
		field_1_t(field_1_t const & other) = default;
		field_1_t(field_1_t && move) = default;
	
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_atomic_t> atomic;
	
	std::optional<field_1_t> field_1;
	


	explicit FUNCTION_MODIFIER_ATOMIC
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_atomic_t> && atomic, std::optional<field_1_t> && field_1)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), atomic(std::move(atomic)), field_1(std::move(field_1)) {}

	FUNCTION_MODIFIER_ATOMIC(FUNCTION_MODIFIER_ATOMIC const & other) = default;
	FUNCTION_MODIFIER_ATOMIC(FUNCTION_MODIFIER_ATOMIC && move) = default;

	static FUNCTION_MODIFIER_ATOMIC build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_FUNCTION_MODIFIER_ATOMIC_HPP
