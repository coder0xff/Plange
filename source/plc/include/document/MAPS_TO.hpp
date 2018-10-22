// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_MAPS_TO_HPP
#define INCLUDED_MAPS_TO_HPP

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

struct MAPS_TO {
	int32_t document_position, consumed_character_count;

	struct field_1_t {
		parlex::detail::document::text<literal_volatile_t> dont_care0;
		
		val<IC> field_1;
		
		std::vector<val<IC>> field_2;
		
	
	
		explicit field_1_t
			(parlex::detail::document::text<literal_volatile_t> const & dont_care0, val<IC> const & field_1, std::vector<val<IC>> const & field_2)
			: dont_care0(dont_care0), field_1(field_1), field_2(field_2) {}
	
		field_1_t(field_1_t const & other) = default;
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_2_t {
		parlex::detail::document::text<literal_const_t> dont_care0;
		
		val<IC> field_1;
		
		std::vector<val<IC>> field_2;
		
	
	
		explicit field_2_t
			(parlex::detail::document::text<literal_const_t> const & dont_care0, val<IC> const & field_1, std::vector<val<IC>> const & field_2)
			: dont_care0(dont_care0), field_1(field_1), field_2(field_2) {}
	
		field_2_t(field_2_t const & other) = default;
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::optional<field_1_t> field_1;
	
	std::optional<field_2_t> field_2;
	
	val<EXPRESSION> lhs;
	
	std::vector<val<IC>> ic1;
	
	std::variant<
		parlex::detail::document::text<literal_0xE20x860x92_t>,
		parlex::detail::document::text<literal_0x2D0x3E_t>
	> field_3;
	
	std::vector<val<IC>> ic2;
	
	val<EXPRESSION> rhs;
	


	explicit MAPS_TO
		(int32_t documentPosition, int32_t consumedCharacterCount, std::optional<field_1_t> const & field_1, std::optional<field_2_t> const & field_2, val<EXPRESSION> const & lhs, std::vector<val<IC>> const & ic1, std::variant<
	parlex::detail::document::text<literal_0xE20x860x92_t>,
	parlex::detail::document::text<literal_0x2D0x3E_t>
> const & field_3, std::vector<val<IC>> const & ic2, val<EXPRESSION> const & rhs)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), lhs(lhs), ic1(ic1), field_3(field_3), ic2(ic2), rhs(rhs) {}

	MAPS_TO(MAPS_TO const & other) = default;
	static MAPS_TO build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_MAPS_TO_HPP
