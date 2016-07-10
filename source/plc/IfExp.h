#ifndef IF_EXP_H
#define IF_EXP_H

#include "Expression.h"
#include <vector>

class IfExp :
	public Expression
{
public:
	IfExp();
	~IfExp();
	std::vector<std::pair<Expression, Expression>> pairs;
	Expression else_;
};

#endif //IF_EXP_H
