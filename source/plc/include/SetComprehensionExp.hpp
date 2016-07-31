#ifndef SET_COMPREHENSION_EXP_HPP
#define SET_COMPREHENSION_EXP_HPP

#include "Expression.hpp"
class SetComprehensionExp :
	public Expression
{
public:
	SetComprehensionExp();
	~SetComprehensionExp();
	value evaluate() const override;
};

#endif //SET_COMPREHENSION_EXP_HPP
