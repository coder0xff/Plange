#ifndef SYMMETRIC_DIFFERENCE_EXP_H
#define SYMMETRIC_DIFFERENCE_EXP_H

#include "BinaryOpExp.h"
class SymmetricDifferenceExp :
	public BinaryOpExp
{
public:
	SymmetricDifferenceExp();
	~SymmetricDifferenceExp();

	std::u32string get_name() const override;

};

#endif //SYMMETRIC_DIFFERENCE_EXP_H
