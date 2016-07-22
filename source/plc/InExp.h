#ifndef IN_EXP_H
#define IN_EXP_H

#include "BinaryOpExp.h"
class InExp :
	public BinaryOpExp
{
public:
	InExp();
	~InExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //IN_EXP_H
