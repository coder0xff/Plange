#include "ParentExp.h"

ParentExp::ParentExp(Expression const & subExpression) : sub_expression(clone(subExpression))
{

}

ParentExp::ParentExp(ParentExp const & other) : sub_expression(clone(other))
{

}
