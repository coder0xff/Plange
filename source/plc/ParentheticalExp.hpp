#ifndef PARENTHETICAL_EXP_HPP
#define PARENTHETICAL_EXP_HPP

#include "ParentExp.h"

class ParentheticalExp :
	public ParentExp
{
public:
	ParentheticalExp(Expression const & subExpression);
	~ParentheticalExp();
	value evaluate() const override;
};

#endif //PARENTHETICAL_EXP_HPP
