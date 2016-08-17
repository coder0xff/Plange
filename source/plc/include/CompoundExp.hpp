#ifndef COMPOUND_EXP_HPP
#define COMPOUND_EXP_HPP

#include "BinaryOpExp.hpp"
class CompoundExp :
	public BinaryOpExp
{
public:
	CompoundExp();
	~CompoundExp();

	std::u32string get_name() const override;
	value evaluate(execution_context &exc) const override;
};

#endif //COMPOUND_EXP_HPP
