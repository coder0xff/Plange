// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_RECORD_HPP
#define INCLUDED_RECORD_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct IC;
struct TYPE;

struct RECORD {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_record_t> dont_care0;
	
	val<IC> field_1;
	
	std::vector<val<IC>> field_2;
	
	val<TYPE> field_3;
	


	explicit RECORD
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_record_t> const & dont_care0, val<IC> const & field_1, std::vector<val<IC>> const & field_2, val<TYPE> const & field_3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(dont_care0), field_1(field_1), field_2(field_2), field_3(field_3) {}

	RECORD(RECORD const & other) = default;
	static RECORD build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_RECORD_HPP
