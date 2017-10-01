// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DECLARATION_HPP
#define INCLUDED_DECLARATION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct IC;
struct IDENTIFIER;
struct XML_DOC_STRING;

struct DECLARATION {
	std::optional<std::tuple<
		erased<XML_DOC_STRING>,
		std::vector<erased<IC>>
	>> field_1;
	erased<IDENTIFIER> identifier;


	DECLARATION(
		std::optional<std::tuple<
			erased<XML_DOC_STRING>,
			std::vector<erased<IC>>
		>> const & field_1,
		erased<IDENTIFIER> const & identifier
	) : field_1(field_1), identifier(identifier) {}

	static DECLARATION build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_DECLARATION_HPP
