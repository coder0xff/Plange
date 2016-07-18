#ifndef EQUALITY_EXP_H
#define EQUALITY_EXP_H

#include "BinaryOpExp.h"
class EqualityExp :
	public BinaryOpExp
{
public:
	EqualityExp();
	~EqualityExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //EQUALITY_EXP_H
