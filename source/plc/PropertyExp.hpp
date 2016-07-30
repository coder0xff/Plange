#ifndef PROPERTY_EXP_HPP
#define PROPERTY_EXP_HPP

#include "Expression.h"
class PropertyExp :
	public Expression
{
public:
	PropertyExp();
	~PropertyExp();
	value evaluate() const override;
};

#endif //PROPERTY_EXP_HPP
