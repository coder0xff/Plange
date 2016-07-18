#ifndef DIVISION_EXP_H
#define DIVISION_EXP_H

#include "BinaryOpExp.h"
class DivisionExp :
	public BinaryOpExp
{
public:
	DivisionExp();
	~DivisionExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //DIVISION_EXP_H
