#ifndef ALLOCATION_EXP_H
#define ALLOCATION_EXP_H

#include "Expression.h"

class AllocationExp :
	public Expression {
public:
	AllocationExp();
	~AllocationExp();
	Expression argument;
};

#endif //ALLOCATION_EXP_H
