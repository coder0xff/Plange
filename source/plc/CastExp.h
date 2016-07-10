#ifndef CAST_EXP_H
#define CAST_EXP_H

#include "Expression.h"
class CastExp :
	public Expression
{
public:
	CastExp();
	~CastExp();
	Expression target_type;
	Expression value;
};

#endif //CAST_EXP_H