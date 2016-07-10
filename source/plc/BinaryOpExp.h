#ifndef BINARY_OP_EXP_H
#define BINARY_OP_EXP_H

#include "Expression.h"
#include <string>

class BinaryOpExp : public Expression {
public:
	BinaryOpExp();
	~BinaryOpExp();
	virtual std::u32string name() const = 0;
	Expression left;
	Expression right;
};

#endif //BINARY_OP_EXP_H
