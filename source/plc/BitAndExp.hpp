#ifndef BIT_AND_EXP_HPP
#define BIT_AND_EXP_HPP

#include "BinaryOpExp.hpp"
class BitAndExp :
	public BinaryOpExp
{
public:
	BitAndExp();
	~BitAndExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //BIT_AND_EXP_HPP
