#ifndef PREPEND_EXP_H
#define PREPEND_EXP_H

#include "BinaryOpExp.h"
class PrependExp :
	public BinaryOpExp
{
public:
	PrependExp();
	~PrependExp();

	std::u32string get_name() const override;

};

#endif //PREPEND_EXP_H
