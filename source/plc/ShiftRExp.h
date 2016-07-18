#ifndef SHIFT_R_EXP_H
#define SHIFT_R_EXP_H

#include "BinaryOpExp.h"
class ShiftRExp :
	public BinaryOpExp
{
public:
	ShiftRExp();
	~ShiftRExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //SHIFT_R_EXP_H
