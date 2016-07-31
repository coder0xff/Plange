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
	value evaluate() const override;
};

#endif //NOR_EXP_HPP
