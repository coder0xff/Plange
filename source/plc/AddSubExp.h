#ifndef ADD_SUB_EXP_H
#define ADD_SUB_EXP_H

#include "BinaryOpExp.h"
class AddSubExp :
	public BinaryOpExp
{
public:
	AddSubExp();
	~AddSubExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //ADD_SUB_EXP_H
