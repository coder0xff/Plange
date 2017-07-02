// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_BREAK_HPP
#define INCLUDED_BREAK_HPP

struct EXPRESSION;
struct IC;
struct ICR;
struct IDENTIFIER;

struct BREAK {
	std::optional<std::variant<
		std::tuple<
			std::vector<erased<IC>>,
			std::vector<erased<IC>>,
			erased<EXPRESSION>,
			std::vector<erased<IC>>
		>,
		std::tuple<
			std::vector<erased<ICR>>,
			erased<IDENTIFIER>
		>
	>> field_1;
};



#endif //INCLUDED_BREAK_HPP
