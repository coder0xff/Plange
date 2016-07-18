#include "UnaryOpExp.h"



UnaryOpExp::UnaryOpExp(Expression const & subExpression) : sub_expression(clone(subExpression))
{
}


UnaryOpExp::UnaryOpExp(UnaryOpExp const & other) : sub_expression(clone(*other.sub_expression))
{

}

UnaryOpExp::~UnaryOpExp()
{
}
