// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_IMPLICIT_TYPE_DEREFERENCE_HPP
#define INCLUDED_IMPLICIT_TYPE_DEREFERENCE_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct IC;

struct IMPLICIT_TYPE_DEREFERENCE {
	std::vector<erased<IC>> field_1;


	explicit IMPLICIT_TYPE_DEREFERENCE(
		std::vector<erased<IC>> && field_1
	) : field_1(std::move(field_1)) {}

	IMPLICIT_TYPE_DEREFERENCE(IMPLICIT_TYPE_DEREFERENCE const & other) = default;
	IMPLICIT_TYPE_DEREFERENCE(IMPLICIT_TYPE_DEREFERENCE && move) = default;

	static IMPLICIT_TYPE_DEREFERENCE build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_IMPLICIT_TYPE_DEREFERENCE_HPP
