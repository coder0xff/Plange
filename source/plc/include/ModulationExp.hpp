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
	value evaluate(execution_context &exc) const override;
};

#endif //MODULATION_EXP_HPP
