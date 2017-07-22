// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ARRAY_INDEXER_HPP
#define INCLUDED_ARRAY_INDEXER_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

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
};



#endif //INCLUDED_ARRAY_INDEXER_HPP
