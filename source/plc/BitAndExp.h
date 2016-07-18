#ifndef BIT_AND_EXP_H
#define BIT_AND_EXP_H

#include "BinaryOpExp.h"
class BitAndExp :
	public BinaryOpExp
{
public:
	BitAndExp();
	~BitAndExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //BIT_AND_EXP_H
