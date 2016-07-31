#ifndef MODULATION_EXP_HPP
#define MODULATION_EXP_HPP

#include "BinaryOpExp.hpp"
class ModulationExp :
	public BinaryOpExp
{
public:
	ModulationExp();
	~ModulationExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //MODULATION_EXP_HPP
