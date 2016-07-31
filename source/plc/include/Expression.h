#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <memory>

class value;

class Expression {
public:
	Expression();
	virtual ~Expression();
	virtual value evaluate() const = 0;
	static std::unique_ptr<Expression> clone(Expression const & other);
};

#endif //EXPRESSION_H
