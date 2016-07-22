#include "BinaryOpExp.h"


BinaryOpExp::BinaryOpExp() {}


BinaryOpExp::BinaryOpExp(BinaryOpExp const & other) : left(clone(*other.left)), right(clone(*other.right))
{

}

BinaryOpExp::~BinaryOpExp() {}
