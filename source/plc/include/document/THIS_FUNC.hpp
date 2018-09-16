// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_THIS_FUNC_HPP
#define INCLUDED_THIS_FUNC_HPP

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

struct THIS_FUNC {
	int32_t document_position, consumed_character_count;

	struct field_1_t {
		std::vector<erased<IC>> field_1;
		
		parlex::detail::document::text<literal_0x5B_t> dont_care1;
		
		std::vector<erased<IC>> field_2;
		
		erased<EXPRESSION> field_3;
		
		std::vector<erased<IC>> field_4;
		
		parlex::detail::document::text<literal_0x5D_t> dont_care5;
		
	
	
		explicit field_1_t
			(std::vector<erased<IC>> && field_1, parlex::detail::document::text<literal_0x5B_t> && dont_care1, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && field_3, std::vector<erased<IC>> && field_4, parlex::detail::document::text<literal_0x5D_t> && dont_care5)
			: field_1(std::move(field_1)), dont_care1(std::move(dont_care1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), dont_care5(std::move(dont_care5)) {}
	
		field_1_t(field_1_t const & other) = default;
		field_1_t(field_1_t && move) = default;
	
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_this_func_t> dont_care0;
	
	std::optional<field_1_t> field_1;
	


	explicit THIS_FUNC
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_this_func_t> && dont_care0, std::optional<field_1_t> && field_1)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(std::move(dont_care0)), field_1(std::move(field_1)) {}

	THIS_FUNC(THIS_FUNC const & other) = default;
	THIS_FUNC(THIS_FUNC && move) = default;

	static THIS_FUNC build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_THIS_FUNC_HPP
