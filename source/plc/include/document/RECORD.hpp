// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_RECORD_HPP
#define INCLUDED_RECORD_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ICR;
struct TYPE;

struct RECORD {
	std::vector<erased<ICR>> field_1;
	erased<TYPE> field_2;


	explicit RECORD(
		std::vector<erased<ICR>> && field_1,
		erased<TYPE> && field_2
	) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	RECORD(RECORD const & other) = default;
	RECORD(RECORD && move) = default;

	static RECORD build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_RECORD_HPP
