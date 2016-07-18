#ifndef PARENTHETICAL_EXP_H
#define PARENTHETICAL_EXP_H

#include "ParentExp.h"

class ParentheticalExp :
	public ParentExp
{
public:
	ParentheticalExp(Expression const & subExpression);
	~ParentheticalExp();
	value evaluate() const override;
};

#endif //PARENTHETICAL_EXP_H
