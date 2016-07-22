#ifndef TYPE_EXP_H
#define TYPE_EXP_H

#include "Expression.h"
class TypeExp :
	public Expression
{
public:
	TypeExp();
	~TypeExp();
	value evaluate() const override;
};

#endif //TYPE_EXP_H
