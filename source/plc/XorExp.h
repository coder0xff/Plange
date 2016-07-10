#ifndef XOR_EXP_H
#define XOR_EXP_H

#include "BinaryOpExp.h"
class XorExp :
	public BinaryOpExp
{
public:
	XorExp();
	~XorExp();

	std::u32string get_name() const override;

};

#endif //XOR_EXP_H
