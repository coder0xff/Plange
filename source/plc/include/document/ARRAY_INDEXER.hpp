// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ARRAY_INDEXER_HPP
#define INCLUDED_ARRAY_INDEXER_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ARGUMENT;
struct ARGUMENT_PACK;
struct IC;
struct SLICE;

struct ARRAY_INDEXER {
	std::vector<erased<IC>> field_1;
	
	std::variant<
		erased<ARGUMENT>,
		erased<ARGUMENT_PACK>,
		erased<SLICE>
	> field_2;
	


	explicit ARRAY_INDEXER(
		std::vector<erased<IC>> && field_1, std::variant<
			erased<ARGUMENT>,
			erased<ARGUMENT_PACK>,
			erased<SLICE>
		> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	ARRAY_INDEXER(ARRAY_INDEXER const & other) = default;
	ARRAY_INDEXER(ARRAY_INDEXER && move) = default;

	static ARRAY_INDEXER build(parlex::details::ast_node const & n);
	static parlex::details::recognizer const & recognizer();

};


} // namespace plc



#endif //INCLUDED_ARRAY_INDEXER_HPP
