// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_OCTAL_HPP
#define INCLUDED_OCTAL_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct OCTAL {
	int field_2;


	OCTAL(
		int const & field_2
	) : field_2(field_2) {}

	static OCTAL build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_OCTAL_HPP
