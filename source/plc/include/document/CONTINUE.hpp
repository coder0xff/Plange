// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_CONTINUE_HPP
#define INCLUDED_CONTINUE_HPP

struct EXPRESSION;
struct IC;
struct ICR;
struct IDENTIFIER;

struct CONTINUE {
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



#endif //INCLUDED_CONTINUE_HPP
