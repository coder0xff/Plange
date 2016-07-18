#ifndef BIT_OR_EXP_H
#define BIT_OR_EXP_H

#include "BinaryOpExp.h"
class BitOrExp :
	public BinaryOpExp
{
public:
	BitOrExp();
	~BitOrExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //BIT_OR_EXP_H
