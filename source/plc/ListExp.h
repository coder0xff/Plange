#ifndef LIST_EXP_H
#define LIST_EXP_H

#include "Expression.h"
#include <vector>

class ListExp :
	public Expression
{
public:
	ListExp();
	~ListExp();
	std::vector<Expression> elements;
};

#endif //LIST_EXP_H
