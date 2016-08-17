#ifndef SHIFT_L_EXP_HPP
#define SHIFT_L_EXP_HPP

#include "BinaryOpExp.hpp"
class ShiftLExp :
	public BinaryOpExp
{
public:
	ShiftLExp();
	~ShiftLExp();

	std::u32string get_name() const override;
	value evaluate(execution_context &exc) const override;
};

#endif //SHIFT_L_EXP_HPP
