#ifndef DIVISION_EXP_HPP
#define DIVISION_EXP_HPP

#include "BinaryOpExp.hpp"
class DivisionExp :
	public BinaryOpExp
{
public:
	DivisionExp();
	~DivisionExp();

	std::u32string get_name() const override;
	value evaluate(execution_context &exc) const override;
};

#endif //DIVISION_EXP_HPP
