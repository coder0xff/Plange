#ifndef NOT_IN_EXP_H
#define NOT_IN_EXP_H

#include "BinaryOpExp.h"
class NotInExp :
	public BinaryOpExp
{
public:
	NotInExp();
	~NotInExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //NOT_IN_EXP_H
