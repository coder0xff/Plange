#ifndef NON_NEGATIVE_NUMBER_EXP_HPP
#define NON_NEGATIVE_NUMBER_EXP_HPP

#include "Expression.h"
#include <string>

class NonNegativeNumberExp :
	public Expression {
public:
	NonNegativeNumberExp(std::u32string const & asString);
	~NonNegativeNumberExp();
	std::u32string as_string;
	value evaluate() const override;
};

#endif //NON_NEGATIVE_NUMBER_EXP_HPP
