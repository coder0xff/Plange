#ifndef ADD_SUB_EXP_HPP
#define ADD_SUB_EXP_HPP

#include "BinaryOpExp.hpp"
class AddSubExp :
	public BinaryOpExp
{
public:
	AddSubExp();
	~AddSubExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //ADD_SUB_EXP_HPP
