#ifndef MEMBER_ACCESS_EXP_H
#define MEMBER_ACCESS_EXP_H

#include "Expression.h"
class MemberAccessExp :
	public Expression
{
public:
	MemberAccessExp();
	~MemberAccessExp();
	value evaluate() const override;
};

#endif //MEMBER_ACCESS_EXP_H
