#ifndef INEQUALITY_EXP_H
#define INEQUALITY_EXP_H

#include "BinaryOpExp.h"
class InequalityExp :
	public BinaryOpExp
{
public:
	InequalityExp();
	~InequalityExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //INEQUALITY_EXP_H
