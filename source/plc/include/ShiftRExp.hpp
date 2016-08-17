#ifndef SHIFT_R_EXP_HPP
#define SHIFT_R_EXP_HPP

#include "BinaryOpExp.hpp"
class ShiftRExp :
	public BinaryOpExp
{
public:
	ShiftRExp();
	~ShiftRExp();

	std::u32string get_name() const override;
	value evaluate(execution_context &exc) const override;
};

#endif //SHIFT_R_EXP_HPP
