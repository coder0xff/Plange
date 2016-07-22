#ifndef ALLOCATION_EXP_H
#define ALLOCATION_EXP_H

#include "Expression.h"
#include <memory>

class AllocationExp :
	public Expression {
public:
	AllocationExp();
	AllocationExp(AllocationExp const & other);
	~AllocationExp();
	std::unique_ptr<Expression> argument;
	value evaluate() const override;
};

#endif //ALLOCATION_EXP_H
