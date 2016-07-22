#ifndef BIT_XOR_EXP_H
#define BIT_XOR_EXP_H

#include "BinaryOpExp.h"
class BitXorExp :
	public BinaryOpExp
{
public:
	BitXorExp();
	~BitXorExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //BIT_XOR_EXP_H
