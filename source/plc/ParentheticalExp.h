#ifndef PARENTHETICAL_EXP
#define PARENTHETICAL_EXP

#include "Expression.h"
class ParentheticalExp :
	public Expression
{
public:
	ParentheticalExp(Expression const & subExpression);
	~ParentheticalExp();
	Expression sub_expression;
};

#endif //PARENTHETICAL_EXP
