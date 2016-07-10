#ifndef PARENTHETICAL_EXP_H
#define PARENTHETICAL_EXP_H

#include "Expression.h"
class ParentheticalExp :
	public Expression
{
public:
	ParentheticalExp(Expression const & subExpression);
	~ParentheticalExp();
	Expression sub_expression;
};

#endif //PARENTHETICAL_EXP_H
