#ifndef POST_INC_EXP_H
#define POST_INC_EXP_H

#include "UnaryOpExp.h"
class PostIncExp :
	public UnaryOpExp
{
public:
	PostIncExp(Expression const & subExpression);
	~PostIncExp();

	std::u32string get_name() const override;
	bool get_postfix() const override;
	value evaluate() const override;
};

#endif //POST_INC_EXP_H
