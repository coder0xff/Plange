#ifndef PRE_DEC_EXP_HPP
#define PRE_DEC_EXP_HPP

#include "UnaryOpExp.h"
class PreDecExp :
	public UnaryOpExp
{
public:
	PreDecExp(Expression const & subExpression);
	~PreDecExp();

	std::u32string get_name() const override;
	bool get_postfix() const override;
	value evaluate() const override;
};

#endif //PRE_DEC_EXP_HPP
