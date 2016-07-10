#ifndef EXPONENTIATION_EXP_H
#define EXPONENTIATION_EXP_H

#include "BinaryOpExp.h"
class ExponentiationExp :
	public BinaryOpExp
{
public:
	ExponentiationExp();
	~ExponentiationExp();

	std::u32string get_name() const override;

};

#endif //EXPONENTIATION_EXP_H
