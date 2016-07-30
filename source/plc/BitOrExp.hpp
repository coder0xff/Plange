#ifndef BIT_OR_EXP_HPP
#define BIT_OR_EXP_HPP

#include "BinaryOpExp.hpp"
class BitOrExp :
	public BinaryOpExp
{
public:
	BitOrExp();
	~BitOrExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //BIT_OR_EXP_HPP
