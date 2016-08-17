#ifndef SUBTRACTION_EXP_HPP
#define SUBTRACTION_EXP_HPP

#include "BinaryOpExp.hpp"
class SubtractionExp :
	public BinaryOpExp
{
public:
	SubtractionExp();
	~SubtractionExp();

	std::u32string get_name() const override;
	value evaluate(execution_context &exc) const override;
};

#endif //SUBTRACTION_EXP_HPP
