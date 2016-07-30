#ifndef AND_EXP_HPP
#define AND_EXP_HPP

#include "BinaryOpExp.hpp"
class AndExp :
	public BinaryOpExp
{
public:
	AndExp();
	~AndExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //AND_EXP_HPP
