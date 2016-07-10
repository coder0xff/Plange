#ifndef COMPOUND_EXP_H
#define COMPOUND_EXP_H

#include "BinaryOpExp.h"
class CompoundExp :
	public BinaryOpExp
{
public:
	CompoundExp();
	~CompoundExp();

	std::u32string get_name() const override;

};

#endif //COMPOUND_EXP_H
