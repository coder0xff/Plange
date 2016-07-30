#ifndef PRE_INC_EXP_HPP
#define PRE_INC_EXP_HPP

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

#endif //PRE_INC_EXP_HPP
