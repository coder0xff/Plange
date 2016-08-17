#ifndef MEMBER_ACCESS_EXP_HPP
#define MEMBER_ACCESS_EXP_HPP

#include "Expression.hpp"
class MemberAccessExp :
	public Expression
{
public:
	MemberAccessExp();
	~MemberAccessExp();
	value evaluate(execution_context &exc) const override;
};

#endif //MEMBER_ACCESS_EXP_HPP
