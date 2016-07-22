#ifndef KLEENE_STAR_EXP_H
#define KLEENE_STAR_EXP_H

#include "UnaryOpExp.h"
class KleeneStarExp :
	public UnaryOpExp
{
public:
	KleeneStarExp(Expression const & subExpression);
	~KleeneStarExp();

	std::u32string get_name() const override;
	bool get_postfix() const override;
	value evaluate() const override;
};

#endif //KLEENE_STAR_EXP_H
