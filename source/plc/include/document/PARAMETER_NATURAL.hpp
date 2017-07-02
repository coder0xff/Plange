// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_PARAMETER_NATURAL_HPP
#define INCLUDED_PARAMETER_NATURAL_HPP

struct EXPRESSION;
struct IC;
struct IDENTIFIER;
struct IMPLICIT_TYPE_DEREFERENCE;
struct TYPE_DEREFERENCE;

typedef std::variant<
	std::tuple<
		std::optional<std::tuple<
			erased<TYPE_DEREFERENCE>,
			std::vector<erased<IC>>
		>>,
		erased<IDENTIFIER>,
		bool
	>,
	std::tuple<
		std::optional<std::tuple<
			std::variant<
				erased<TYPE_DEREFERENCE>,
				erased<IMPLICIT_TYPE_DEREFERENCE>
			>,
			std::vector<erased<IC>>
		>>,
		erased<IDENTIFIER>,
		bool,
		std::vector<erased<IC>>,
		std::vector<erased<IC>>,
		erased<EXPRESSION>,
		bool
	>
> PARAMETER_NATURAL;

#endif //INCLUDED_PARAMETER_NATURAL_HPP
