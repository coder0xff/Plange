#ifndef POST_DEC_EXP_H
#define POST_DEC_EXP_H

#include "UnaryOpExp.h"
class PostDecExp :
	public UnaryOpExp
{
public:
	PostDecExp(Expression const & subExpression);
	~PostDecExp();

	std::u32string get_name() const override;
	bool get_postfix() const override;
	value evaluate() const override;
};

#endif //POST_DEC_EXP_H
