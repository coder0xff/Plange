#ifndef DOT_PRODUCT_EXP_HPP
#define DOT_PRODUCT_EXP_HPP

#include "BinaryOpExp.hpp"
class DotProductExp :
	public BinaryOpExp
{
public:
	DotProductExp();
	~DotProductExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //DOT_PRODUCT_EXP_HPP
