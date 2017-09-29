// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_SCOPE_DECLARATION_HPP
#define INCLUDED_TYPE_SCOPE_DECLARATION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

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

	static std::optional<TYPE_SCOPE_DECLARATION> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_TYPE_SCOPE_DECLARATION_HPP
