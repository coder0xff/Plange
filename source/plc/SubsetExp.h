#ifndef SUBSET_EXP_H
#define SUBSET_EXP_H

#include "BinaryOpExp.h"
class SubsetExp :
	public BinaryOpExp
{
public:
	SubsetExp();
	~SubsetExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //SUBSET_EXP_H
