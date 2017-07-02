// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_RETURN_HPP
#define INCLUDED_RETURN_HPP

struct EXPRESSION;
struct IC;

struct RETURN {
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		std::vector<erased<IC>>,
		erased<EXPRESSION>,
		std::vector<erased<IC>>
	>> field_1;
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		erased<EXPRESSION>
	>> field_2;
};



#endif //INCLUDED_RETURN_HPP
