#ifndef SUBTRACTION_EXP_H
#define SUBTRACTION_EXP_H

#include "BinaryOpExp.h"
class SubtractionExp :
	public BinaryOpExp
{
public:
	SubtractionExp();
	~SubtractionExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //SUBTRACTION_EXP_H
