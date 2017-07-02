// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_LIST_HPP
#define INCLUDED_LIST_HPP

struct EXPRESSION;
struct IC;

struct LIST {
	std::vector<erased<IC>> field_1;
	std::optional<std::tuple<
		erased<EXPRESSION>,
		std::vector<std::tuple<
			std::vector<erased<IC>>,
			std::vector<erased<IC>>,
			erased<EXPRESSION>
		>>,
		std::vector<erased<IC>>
	>> field_2;
};



#endif //INCLUDED_LIST_HPP
