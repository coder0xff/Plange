#ifndef GREATER_THAN_EXP_H
#define GREATER_THAN_EXP_H

#include "BinaryOpExp.h"
class GreaterThanExp :
	public BinaryOpExp
{
public:
	GreaterThanExp();
	~GreaterThanExp();

	std::u32string get_name() const override;

};

#endif //GREATER_THAN_EXP_H
