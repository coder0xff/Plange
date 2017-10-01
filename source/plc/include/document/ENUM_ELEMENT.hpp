// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ENUM_ELEMENT_HPP
#define INCLUDED_ENUM_ELEMENT_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EXPRESSION;
struct IC;
struct IDENTIFIER;

struct ENUM_ELEMENT {
	erased<IDENTIFIER> identifier;
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		std::vector<erased<IC>>,
		erased<EXPRESSION>
	>> field_1;


	ENUM_ELEMENT(
		erased<IDENTIFIER> const & identifier,
		std::optional<std::tuple<
			std::vector<erased<IC>>,
			std::vector<erased<IC>>,
			erased<EXPRESSION>
		>> const & field_1
	) : identifier(identifier), field_1(field_1) {}

	static ENUM_ELEMENT build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_ENUM_ELEMENT_HPP
