// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ARRAY_INVOCATION_HPP
#define INCLUDED_ARRAY_INVOCATION_HPP

struct ARRAY_INDEXER;
struct EXPRESSION;
struct IC;

struct ARRAY_INVOCATION {
	erased<EXPRESSION> field_1;
	std::optional<erased<ARRAY_INDEXER>> field_2;
	std::vector<std::tuple<
		std::vector<erased<IC>>,
		std::optional<erased<ARRAY_INDEXER>>
	>> field_3;
	std::vector<erased<IC>> field_4;
};



#endif //INCLUDED_ARRAY_INVOCATION_HPP
