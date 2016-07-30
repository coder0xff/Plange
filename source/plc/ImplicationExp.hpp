#ifndef IMPLICATION_EXP_HPP
#define IMPLICATION_EXP_HPP

#include "BinaryOpExp.hpp"
class ImplicationExp :
	public BinaryOpExp
{
public:
	ImplicationExp();
	~ImplicationExp();

	std::u32string get_name() const override;
	value evaluate() const override;
};

#endif //IMPLICATION_EXP_HPP
