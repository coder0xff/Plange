// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_XML_DOC_STRING_HPP
#define INCLUDED_XML_DOC_STRING_HPP

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
struct XML_DOC_STRING_INTERIOR;

struct XML_DOC_STRING {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0x600x600x60_t> dont_care0;
	
	val<XML_DOC_STRING_INTERIOR> interior;
	
	parlex::detail::document::text<literal_0x600x600x60_t> dont_care2;
	
	std::vector<val<IC>> ic;
	


	explicit XML_DOC_STRING
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x600x600x60_t> && dont_care0, val<XML_DOC_STRING_INTERIOR> && interior, parlex::detail::document::text<literal_0x600x600x60_t> && dont_care2, std::vector<val<IC>> && ic)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(std::move(dont_care0)), interior(std::move(interior)), dont_care2(std::move(dont_care2)), ic(std::move(ic)) {}

	XML_DOC_STRING(XML_DOC_STRING const & other) = default;
	XML_DOC_STRING(XML_DOC_STRING && move) = default;

	static XML_DOC_STRING build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_XML_DOC_STRING_HPP
