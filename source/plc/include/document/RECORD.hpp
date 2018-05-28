// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_RECORD_HPP
#define INCLUDED_RECORD_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct IC;
struct TYPE;

struct RECORD {
	parlex::detail::document::text<literal_record_t> dontCare0;
	
	erased<IC> field_1;
	
	std::vector<erased<IC>> field_2;
	
	erased<TYPE> field_3;
	


	explicit RECORD(
		parlex::detail::document::text<literal_record_t> && dontCare0, erased<IC> && field_1, std::vector<erased<IC>> && field_2, erased<TYPE> && field_3) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}

	RECORD(RECORD const & other) = default;
	RECORD(RECORD && move) = default;

	static RECORD build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_RECORD_HPP
