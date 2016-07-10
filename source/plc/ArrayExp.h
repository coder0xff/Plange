#ifndef ARRAY_EXP_H
#define ARRAY_EXP_H

#include "Expression.h"
#include <vector>

class ArrayExp :
	public Expression {
public:
	ArrayExp();
	~ArrayExp();
	std::vector<Expression> elements;
};

#endif //ARRAY_EXP_H
