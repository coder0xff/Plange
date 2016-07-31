#ifndef ALLOCATION_EXP_HPP
#define ALLOCATION_EXP_HPP

#include "Expression.hpp"
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

#endif //ALLOCATION_EXP_HPP
