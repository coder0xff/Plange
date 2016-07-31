#include "CastExp.hpp"


CastExp::CastExp(Expression const & subExpression, Expression const & targetType) : ParentExp(subExpression), target_type(clone(targetType))
{

}

CastExp::CastExp(CastExp const & other) : ParentExp(*other.sub_expression), target_type(clone(*other.target_type))
{

}


CastExp::~CastExp()
{
}
