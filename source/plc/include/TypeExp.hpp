#ifndef TYPE_EXP_HPP
#define TYPE_EXP_HPP

#include "Expression.hpp"
class TypeExp :
	public Expression
{
public:
	TypeExp();
	~TypeExp();
	value evaluate() const override;
};

#endif //TYPE_EXP_HPP
