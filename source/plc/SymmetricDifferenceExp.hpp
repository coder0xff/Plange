#ifndef SYMMETRIC_DIFFERENCE_EXP_HPP
#define SYMMETRIC_DIFFERENCE_EXP_HPP

#include "BinaryOpExp.hpp"
class SymmetricDifferenceExp :
	public BinaryOpExp
{
public:
	SymmetricDifferenceExp();
	~SymmetricDifferenceExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //SYMMETRIC_DIFFERENCE_EXP_HPP
