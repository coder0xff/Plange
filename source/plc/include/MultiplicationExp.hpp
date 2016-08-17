#ifndef MULTIPLICATION_EXP_HPP
#define MULTIPLICATION_EXP_HPP

#include "BinaryOpExp.hpp"
class MultiplicationExp :
	public BinaryOpExp
{
public:
	MultiplicationExp();
	~MultiplicationExp();

	std::u32string get_name() const override;
	value evaluate(execution_context &exc) const override;
};

#endif //MULTIPLICATION_EXP_HPP
