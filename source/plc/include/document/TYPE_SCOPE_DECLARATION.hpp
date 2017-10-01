// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_SCOPE_DECLARATION_HPP
#define INCLUDED_TYPE_SCOPE_DECLARATION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct IC;
struct IDENTIFIER;
struct MEMBER_OFFSET;
struct XML_DOC_STRING;

struct TYPE_SCOPE_DECLARATION {
	std::optional<std::tuple<
		erased<XML_DOC_STRING>,
		std::vector<erased<IC>>
	>> field_1;
	erased<IDENTIFIER> field_2;
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		erased<MEMBER_OFFSET>
	>> field_3;


	TYPE_SCOPE_DECLARATION(
		std::optional<std::tuple<
			erased<XML_DOC_STRING>,
			std::vector<erased<IC>>
		>> const & field_1,
		erased<IDENTIFIER> const & field_2,
		std::optional<std::tuple<
			std::vector<erased<IC>>,
			erased<MEMBER_OFFSET>
		>> const & field_3
	) : field_1(field_1), field_2(field_2), field_3(field_3) {}

	static TYPE_SCOPE_DECLARATION build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_TYPE_SCOPE_DECLARATION_HPP
