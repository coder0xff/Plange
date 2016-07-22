#ifndef NOR_EXP_H
#define NOR_EXP_H

#include "BinaryOpExp.h"
class NorExp :
	public BinaryOpExp
{
public:
	NorExp();
	~NorExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //NOR_EXP_H
