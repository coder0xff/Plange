// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_OCTAL_HPP
#define INCLUDED_OCTAL_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct OCTAL {
	int field_2;


	explicit OCTAL(
		int && field_2
	) : field_2(std::move(field_2)) {}

	OCTAL(OCTAL const & other) = default;
	OCTAL(OCTAL && move) = default;

	static OCTAL build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_OCTAL_HPP
