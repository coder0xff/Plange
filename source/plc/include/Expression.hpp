#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP
#include <memory>

class value;

class Expression {
public:
	Expression();
	virtual ~Expression();
	virtual value evaluate() const = 0;
	static std::unique_ptr<Expression> clone(Expression const & other);
};

#endif //EXPRESSION_HPP
