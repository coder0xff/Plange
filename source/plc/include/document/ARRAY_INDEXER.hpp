// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ARRAY_INDEXER_HPP
#define INCLUDED_ARRAY_INDEXER_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

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


	ARRAY_INDEXER(
		std::vector<erased<IC>> const & field_1,
		std::variant<
			erased<ARGUMENT>,
			erased<ARGUMENT_PACK>,
			erased<SLICE>
		> const & field_2
	) : field_1(field_1), field_2(field_2) {}

	static ARRAY_INDEXER build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_ARRAY_INDEXER_HPP
