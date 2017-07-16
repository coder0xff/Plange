// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DECLARATION_HPP
#define INCLUDED_DECLARATION_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct IC;
struct IDENTIFIER;
struct XML_DOC_STRING;

struct DECLARATION {
	std::optional<std::tuple<
		erased<XML_DOC_STRING>,
		std::vector<erased<IC>>
	>> field_1;
	erased<IDENTIFIER> IDENTIFIER;

	DECLARATION(
		std::optional<std::tuple<
			erased<XML_DOC_STRING>,
			std::vector<erased<IC>>
		>> const & field_1,
		erased<IDENTIFIER> const & IDENTIFIER
	) : field_1(field_1), IDENTIFIER(IDENTIFIER) {}
};



#endif //INCLUDED_DECLARATION_HPP
