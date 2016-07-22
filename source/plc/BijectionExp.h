#ifndef BIJECTION_EXP_H
#define BIJECTION_EXP_H

#include "BinaryOpExp.h"
class BijectionExp :
	public BinaryOpExp
{
public:
	BijectionExp();
	~BijectionExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //BIJECTION_EXP_H
