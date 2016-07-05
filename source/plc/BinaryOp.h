#ifndef BINARY_OP_H
#define BINARY_OP_H

#include "Expression.h"
#include <string>

class BinaryOp : public Expression
{
public:
	BinaryOp();
	~BinaryOp();
	virtual std::u32string name() const = 0;
	Expression left;
	Expression right;
};

#endif //BINARY_OP_H