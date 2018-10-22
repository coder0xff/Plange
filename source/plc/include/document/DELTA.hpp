// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DELTA_HPP
#define INCLUDED_DELTA_HPP

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
struct WHOLE_NUMBER;

struct DELTA {
	int32_t document_position, consumed_character_count;

	struct field_2_t {
		parlex::detail::document::text<literal_0x5E_t> dont_care0;
		
		val<WHOLE_NUMBER> whole_number;
		
	
	
		explicit field_2_t
			(parlex::detail::document::text<literal_0x5E_t> const & dont_care0, val<WHOLE_NUMBER> const & whole_number)
			: dont_care0(dont_care0), whole_number(whole_number) {}
	
		field_2_t(field_2_t const & other) = default;
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::variant<
		parlex::detail::document::text<literal_0xCE0x94_t>,
		parlex::detail::document::text<literal__delta__t>
	> field_1;
	
	std::optional<field_2_t> field_2;
	
	val<EXPRESSION> expression;
	


	explicit DELTA
		(int32_t documentPosition, int32_t consumedCharacterCount, std::variant<
	parlex::detail::document::text<literal_0xCE0x94_t>,
	parlex::detail::document::text<literal__delta__t>
> const & field_1, std::optional<field_2_t> const & field_2, val<EXPRESSION> const & expression)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), field_2(field_2), expression(expression) {}

	DELTA(DELTA const & other) = default;
	static DELTA build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_DELTA_HPP
