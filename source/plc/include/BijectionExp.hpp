#ifndef BIJECTION_EXP_HPP
#define BIJECTION_EXP_HPP

#include "BinaryOpExp.hpp"
class BijectionExp :
	public BinaryOpExp
{
public:
	BijectionExp();
	~BijectionExp();

	std::u32string get_name() const override;
	value evaluate(execution_context &exc) const override;
};

#endif //BIJECTION_EXP_HPP
