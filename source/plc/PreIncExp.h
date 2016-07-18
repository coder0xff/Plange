#ifndef PRE_INC_EXP_H
#define PRE_INC_EXP_H

#include "UnaryOpExp.h"
class PreIncExp :
	public UnaryOpExp
{
public:
	PreIncExp(Expression const & subExpression);
	~PreIncExp();

	std::u32string get_name() const override;
	bool get_postfix() const override;
	value evaluate() const override;
};

#endif //PRE_INC_EXP_H
