// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_INVOCATION_HPP
#define INCLUDED_TYPE_INVOCATION_HPP

struct ARGUMENT;
struct ARGUMENT_PACK;
struct EXPRESSION;
struct IC;

struct TYPE_INVOCATION {
	erased<EXPRESSION> field_1;
	std::tuple<
		std::optional<std::tuple<
			std::vector<erased<IC>>,
			std::variant<
				erased<ARGUMENT>,
				erased<ARGUMENT_PACK>
			>
		>>,
		std::vector<std::tuple<
			std::vector<erased<IC>>,
			std::optional<std::tuple<
				std::vector<erased<IC>>,
				std::variant<
					erased<ARGUMENT>,
					erased<ARGUMENT_PACK>
				>
			>>
		>>,
		std::vector<erased<IC>>
	> field_2;
};



#endif //INCLUDED_TYPE_INVOCATION_HPP
