#ifndef IN_EXP_HPP
#define IN_EXP_HPP

#include "BinaryOpExp.hpp"
class InExp :
	public BinaryOpExp
{
public:
	InExp();
	~InExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //IN_EXP_HPP
