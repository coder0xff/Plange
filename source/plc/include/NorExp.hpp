#ifndef NOR_EXP_HPP
#define NOR_EXP_HPP

#include "BinaryOpExp.hpp"
class NorExp :
	public BinaryOpExp
{
public:
	NorExp();
	~NorExp();

	std::u32string get_name() const override;
	value evaluate(execution_context &exc) const override;
};

#endif //NOR_EXP_HPP
