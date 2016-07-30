#ifndef INEQUALITY_EXP_HPP
#define INEQUALITY_EXP_HPP

#include "BinaryOpExp.hpp"
class InequalityExp :
	public BinaryOpExp
{
public:
	InequalityExp();
	~InequalityExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //INEQUALITY_EXP_HPP
