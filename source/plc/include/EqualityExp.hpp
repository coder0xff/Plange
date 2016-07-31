#ifndef EQUALITY_EXP_HPP
#define EQUALITY_EXP_HPP

#include "BinaryOpExp.hpp"
class EqualityExp :
	public BinaryOpExp
{
public:
	EqualityExp();
	~EqualityExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //EQUALITY_EXP_HPP
