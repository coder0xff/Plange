// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_REGEX_HPP
#define INCLUDED_REGEX_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct STRING;

struct REGEX {
	erased<STRING> field_1;


	REGEX(
		erased<STRING> const & field_1
	) : field_1(field_1) {}

	static REGEX build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_REGEX_HPP
