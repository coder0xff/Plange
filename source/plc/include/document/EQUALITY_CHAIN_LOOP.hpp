// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EQUALITY_CHAIN_LOOP_HPP
#define INCLUDED_EQUALITY_CHAIN_LOOP_HPP

struct EQUALITY_CHAIN_LOOP;
struct EXPRESSION;
struct IC;

struct EQUALITY_CHAIN_LOOP {
	erased<EXPRESSION> EXPRESSION;
	std::vector<erased<IC>> field_1;
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		erased<EQUALITY_CHAIN_LOOP>
	>> field_2;
};



#endif //INCLUDED_EQUALITY_CHAIN_LOOP_HPP
