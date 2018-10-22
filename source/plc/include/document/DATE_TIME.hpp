// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DATE_TIME_HPP
#define INCLUDED_DATE_TIME_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct DATE;
struct TIME;

struct DATE_TIME {
	int32_t document_position, consumed_character_count;

	val<DATE> field_1;
	
	parlex::detail::document::text<literal_T_t> dont_care1;
	
	val<TIME> field_2;
	


	explicit DATE_TIME
		(int32_t documentPosition, int32_t consumedCharacterCount, val<DATE> const & field_1, parlex::detail::document::text<literal_T_t> const & dont_care1, val<TIME> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), dont_care1(dont_care1), field_2(field_2) {}

	DATE_TIME(DATE_TIME const & other) = default;
	static DATE_TIME build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_DATE_TIME_HPP
