#ifndef CROSS_PRODUCT_EXP_H
#define CROSS_PRODUCT_EXP_H

#include "BinaryOpExp.h"
class CrossProductExp :
	public BinaryOpExp
{
public:
	CrossProductExp();
	~CrossProductExp();

	std::u32string get_name() const override;

};

#endif //CROSS_PRODUCT_EXP_H
