// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_RECORD_HPP
#define INCLUDED_RECORD_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ICR;
struct TYPE;

struct RECORD {
	parlex::details::document::text<literal_record_t> dontCare0;
	
	std::vector<erased<ICR>> field_1;
	
	erased<TYPE> field_2;
	


	explicit RECORD(
		parlex::details::document::text<literal_record_t> && dontCare0, std::vector<erased<ICR>> && field_1, erased<TYPE> && field_2) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	RECORD(RECORD const & other) = default;
	RECORD(RECORD && move) = default;

	static RECORD build(parlex::details::ast_node const & n);
	static parlex::details::recognizer const & recognizer();

};


} // namespace plc



#endif //INCLUDED_RECORD_HPP
