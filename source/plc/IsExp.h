#ifndef IS_EXP_H
#define IS_EXP_H

#include "BinaryOpExp.h"
class IsExp :
	public BinaryOpExp
{
public:
	IsExp();
	~IsExp();

	std::u32string get_name() const override;

};

#endif //IS_EXP_H
