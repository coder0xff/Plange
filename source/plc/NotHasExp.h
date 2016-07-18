#ifndef NOT_HAS_EXP_H
#define NOT_HAS_EXP_H

#include "BinaryOpExp.h"
class NotHasExp :
	public BinaryOpExp
{
public:
	NotHasExp();
	~NotHasExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //NOT_HAS_EXP_H
