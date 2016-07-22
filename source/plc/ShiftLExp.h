#ifndef SHIFT_L_EXP_H
#define SHIFT_L_EXP_H

#include "BinaryOpExp.h"
class ShiftLExp :
	public BinaryOpExp
{
public:
	ShiftLExp();
	~ShiftLExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //SHIFT_L_EXP_H
