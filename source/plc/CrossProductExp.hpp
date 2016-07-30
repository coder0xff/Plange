#ifndef CROSS_PRODUCT_EXP_HPP
#define CROSS_PRODUCT_EXP_HPP

#include "BinaryOpExp.hpp"
class CrossProductExp :
	public BinaryOpExp
{
public:
	CrossProductExp();
	~CrossProductExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //CROSS_PRODUCT_EXP_HPP
