#ifndef PROPERTY_EXP_H
#define PROPERTY_EXP_H

#include "Expression.h"
class PropertyExp :
	public Expression
{
public:
	PropertyExp();
	~PropertyExp();
	value evaluate() const override;
};

#endif //PROPERTY_EXP_H
