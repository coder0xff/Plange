#ifndef PARENTHETICAL_EXP_HPP
#define PARENTHETICAL_EXP_HPP

#include "ParentExp.hpp"

class ParentheticalExp :
	public ParentExp
{
public:
	ParentheticalExp(Expression const & subExpression);
	~ParentheticalExp();
	value evaluate(execution_context &exc) const override;
};

#endif //PARENTHETICAL_EXP_HPP
