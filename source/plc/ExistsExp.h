#ifndef EXISTS_EXP_H
#define EXISTS_EXP_H

#include "UnaryOpExp.h"
class ExistsExp :
	public UnaryOpExp
{
public:
	ExistsExp(Expression const & subExpression);
	~ExistsExp();

	std::u32string get_name() const override;
	bool get_postfix() const override;
	value evaluate() const override;
};

#endif //EXISTS_EXP_H
