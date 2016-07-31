#ifndef BINARY_OP_EXP_HPP
#define BINARY_OP_EXP_HPP

#include "Expression.hpp"
#include <string>
#include <memory>

class BinaryOpExp : public Expression {
public:
	BinaryOpExp();
	BinaryOpExp(BinaryOpExp const & other);
	~BinaryOpExp();
	virtual std::u32string get_name() const = 0;
	std::unique_ptr<Expression> left;
	std::unique_ptr<Expression> right;
	virtual value evaluate() const = 0;
};

#endif //BINARY_OP_EXP_HPP
