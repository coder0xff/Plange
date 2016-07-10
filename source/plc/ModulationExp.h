#ifndef MODULATION_EXP_H
#define MODULATION_EXP_H

#include "BinaryOpExp.h"
class ModulationExp :
	public BinaryOpExp
{
public:
	ModulationExp();
	~ModulationExp();

	std::u32string get_name() const override;

};

#endif //MODULATION_EXP_H
