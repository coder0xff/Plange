#ifndef PROPER_SUBSET_EXP_H
#define PROPER_SUBSET_EXP_H

#include "BinaryOpExp.h"
class ProperSubsetExp :
	public BinaryOpExp
{
public:
	ProperSubsetExp();
	~ProperSubsetExp();

	std::u32string get_name() const override;

};

#endif //PROPER_SUBSET_EXP_H