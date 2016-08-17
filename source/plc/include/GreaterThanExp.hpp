#ifndef GREATER_THAN_EXP_HPP
#define GREATER_THAN_EXP_HPP

#include "BinaryOpExp.hpp"
class GreaterThanExp :
	public BinaryOpExp
{
public:
	GreaterThanExp();
	~GreaterThanExp();

	std::u32string get_name() const override;
	value evaluate(execution_context &exc) const override;
};

#endif //GREATER_THAN_EXP_HPP
