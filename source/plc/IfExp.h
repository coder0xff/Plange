#ifndef IF_EXP_H
#define IF_EXP_H

#include "Expression.h"
#include <vector>
#include <memory>

class IfExp :
	public Expression
{
public:
	IfExp();
	IfExp(IfExp const & other);
	~IfExp();
	std::vector<std::pair<std::unique_ptr<Expression>, std::unique_ptr<Expression>>> pairs;
	std::unique_ptr<Expression> else_;
	value evaluate() const override;
};

#endif //IF_EXP_H
