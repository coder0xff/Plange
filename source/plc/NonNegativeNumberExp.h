#ifndef NON_NEGATIVE_NUMBER_H
#define NON_NEGATIVE_NUMBER_H

#include "Expression.h"
#include <string>

class NonNegativeNumberExp :
	public Expression {
public:
	NonNegativeNumberExp(std::u32string const & asString);
	~NonNegativeNumberExp();
	std::u32string as_string;
};

#endif //NON_NEGATIVE_NUMBER_H
