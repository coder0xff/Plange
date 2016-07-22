#ifndef SET_COMPREHENSION_EXP_H
#define SET_COMPREHENSION_EXP_H

#include "Expression.h"
class SetComprehensionExp :
	public Expression
{
public:
	SetComprehensionExp();
	~SetComprehensionExp();
	value evaluate() const override;
};

#endif //SET_COMPREHENSION_EXP_H
