// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FLOOR_HPP
#define INCLUDED_FLOOR_HPP

struct EXPRESSION;
struct IC;

typedef std::variant<
	std::tuple<
		std::vector<erased<IC>>,
		erased<EXPRESSION>,
		std::vector<erased<IC>>
	>,
	std::tuple<
		std::vector<erased<IC>>,
		erased<EXPRESSION>,
		std::vector<erased<IC>>
	>
> FLOOR;

#endif //INCLUDED_FLOOR_HPP
