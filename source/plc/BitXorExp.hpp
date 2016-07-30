#ifndef BIT_XOR_EXP_HPP
#define BIT_XOR_EXP_HPP

#include "BinaryOpExp.hpp"
class BitXorExp :
	public BinaryOpExp
{
public:
	BitXorExp();
	~BitXorExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //BIT_XOR_EXP_HPP
