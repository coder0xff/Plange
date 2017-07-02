// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_PARENTHETICAL_INVOCATION_HPP
#define INCLUDED_PARENTHETICAL_INVOCATION_HPP

struct ARGUMENT;
struct ARGUMENT_PACK;
struct EXPRESSION;
struct IC;

struct PARENTHETICAL_INVOCATION {
	erased<EXPRESSION> field_1;
	std::vector<erased<IC>> field_2;
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		std::variant<
			erased<ARGUMENT>,
			erased<ARGUMENT_PACK>
		>
	>> field_3;
	std::vector<std::tuple<
		std::vector<erased<IC>>,
		std::optional<std::tuple<
			std::vector<erased<IC>>,
			std::variant<
				erased<ARGUMENT>,
				erased<ARGUMENT_PACK>
			>
		>>
	>> field_4;
	std::vector<erased<IC>> field_5;
};



#endif //INCLUDED_PARENTHETICAL_INVOCATION_HPP
