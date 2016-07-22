#ifndef COMPLEMENT_EXP_H
#define COMPLEMENT_EXP_H

#include "UnaryOpExp.h"
class ComplementExp :
	public UnaryOpExp
{
public:
	ComplementExp(Expression const & subExpression);
	~ComplementExp();

	std::u32string get_name() const override;
	bool get_postfix() const override;
	value evaluate() const override;
};

#endif //COMPLEMENT_EXP_H
