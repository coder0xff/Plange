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
	value evaluate() const override;
};

#endif //MULTIPLICATION_EXP_HPP
