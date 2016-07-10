#ifndef MULTIPLICATION_EXP_H
#define MULTIPLICATION_EXP_H

#include "BinaryOpExp.h"
class MultiplicationExp :
	public BinaryOpExp
{
public:
	MultiplicationExp();
	~MultiplicationExp();

	std::u32string get_name() const override;

};

#endif //MULTIPLICATION_EXP_H
