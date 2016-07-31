#ifndef EXPONENTIATION_EXP_HPP
#define EXPONENTIATION_EXP_HPP

#include "BinaryOpExp.hpp"
class ExponentiationExp :
	public BinaryOpExp
{
public:
	ExponentiationExp();
	~ExponentiationExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //EXPONENTIATION_EXP_HPP
